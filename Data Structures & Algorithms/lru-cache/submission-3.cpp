#include <unordered_map>
#include <memory>
#include <utility>

class LRUCache {
private:
    struct Node {
        std::pair<int, int> m_key_value;
        std::shared_ptr<Node> m_next;
        std::weak_ptr<Node> m_prev; // weak_ptr quebra o ciclo de memória
    };

    struct List {
        std::shared_ptr<Node> m_head = nullptr;
        std::shared_ptr<Node> m_tail = nullptr;
        int m_size = 0;
    };

    std::unordered_map<int, std::shared_ptr<Node>> cache_map;
    List cache_values;
    int max_cap;

    // Move um nó já existente na lista para a cabeça
    void moveToHead(std::shared_ptr<Node> node) {
        if (cache_values.m_head == node) {
            return;
        }

        auto prev_node = node->m_prev.lock();
        auto next_node = node->m_next;

        // Desconecta o nó da posição atual
        if (prev_node) {
            prev_node->m_next = next_node;
        }

        if (next_node) {
            next_node->m_prev = prev_node;
        } else {
            // Se era a cauda, atualiza a cauda para o nó anterior
            cache_values.m_tail = prev_node;
        }

        // Coloca na cabeça
        node->m_next = cache_values.m_head;
        node->m_prev.reset();
        
        if (cache_values.m_head) {
            cache_values.m_head->m_prev = node;
        }
        cache_values.m_head = node;
    }

public:
    LRUCache(int capacity) {
        max_cap = capacity;
    }
    
    int get(int key) {
        auto it = cache_map.find(key);
        if (it == cache_map.end()) {
            return -1;
        }

        auto cache_hit_address = it->second;
        moveToHead(cache_hit_address);

        return cache_hit_address->m_key_value.second;
    }
    
    void put(int key, int value) {
        auto it = cache_map.find(key);

        // Caso 1: A chave já existe -> atualiza valor e joga para o início
        if (it != cache_map.end()) {
            auto node = it->second;
            node->m_key_value.second = value;
            moveToHead(node);
            return;
        }

        // Caso 2: Capacidade atingida -> remove a cauda (LRU)
        if (cache_values.m_size == max_cap) {
            auto removed_node = cache_values.m_tail;

            if (removed_node) {
                cache_map.erase(removed_node->m_key_value.first);

                auto prev_node = removed_node->m_prev.lock();
                if (prev_node) {
                    prev_node->m_next = nullptr;
                    cache_values.m_tail = prev_node;
                } else {
                    // Capacidade 1: a cauda também era a cabeça
                    cache_values.m_head = nullptr;
                    cache_values.m_tail = nullptr;
                }

                cache_values.m_size--;
            }
        }

        // Cria o novo nó
        auto node = std::make_shared<Node>();
        node->m_key_value = {key, value};

        // Insere na cabeça da lista
        node->m_next = cache_values.m_head;
        node->m_prev.reset();

        if (cache_values.m_head != nullptr) {
            cache_values.m_head->m_prev = node;
        }
        cache_values.m_head = node;

        // Se a lista estava vazia, o novo nó também é a cauda
        if (cache_values.m_tail == nullptr) {
            cache_values.m_tail = node;
        }

        cache_map[key] = node;
        cache_values.m_size++;
    }
};