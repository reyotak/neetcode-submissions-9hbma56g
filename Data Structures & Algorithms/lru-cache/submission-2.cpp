#include <unordered_map>
#include <list>
#include <utility>

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }

        // Move o nó acedido para o início da lista em O(1) (MRU)
        items.splice(items.begin(), items, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        // Caso 1: A chave já existe -> atualiza valor e move para a frente
        if (it != cache.end()) {
            items.splice(items.begin(), items, it->second);
            it->second->second = value;
            return;
        }

        // Caso 2: Capacidade esgotada -> remove o elemento menos recente (LRU - fim da lista)
        if (items.size() == cap) {
            int lru_key = items.back().first;
            items.pop_back();
            cache.erase(lru_key);
        }

        // Insere o novo elemento no início (MRU)
        items.emplace_front(key, value);
        cache[key] = items.begin();
    }

private:
    int cap;
    // Lista duplamente ligada: armazena pares {key, value}
    std::list<std::pair<int, int>> items;
    // Mapeia a chave para o iterador exato do nó na lista
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
};