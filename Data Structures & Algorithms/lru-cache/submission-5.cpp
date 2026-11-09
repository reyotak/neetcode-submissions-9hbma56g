class LRUCache {

private:
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> m_cache;
    std::list<int> m_order;
    int m_max_cap;

public:
    LRUCache(int capacity) : 
        m_max_cap(capacity) 
    {}
    
    int get(int key) {
        // find the node
        if (m_cache.find(key) == m_cache.end()) {
            return -1;
        }

        // move the node to the start of the list
        m_order.splice(m_order.begin(), m_order, m_cache[key].second);

        // return the value
        return m_cache[key].first;
    }
    
    void put(int key, int value) {
        // check if already in the cache, if so move to front
        if (m_cache.find(key) != m_cache.end()) {
            m_order.splice(m_order.begin(), m_order, m_cache[key].second);
            m_cache[key] = {value, m_order.begin()};
            return;
        }

        // check if at max capacity, if so remove the last element
        if (m_order.size() >= m_max_cap) {
            int last = m_order.back();
            m_cache.erase(last);
            m_order.pop_back();
        }

        // add the new key value in the start of the order
        m_order.push_front(key);
        auto it = m_order.begin();
        m_cache[key] = {value, it};
    }
};
