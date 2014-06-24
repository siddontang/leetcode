#include "leetcode.h"

class LRUCache{
public:
    typedef pair<int, int> KVPair_t;
    typedef list<KVPair_t> ListKV_t;
    typedef map<int, ListKV_t::iterator> MapCache_t;

    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        MapCache_t::iterator it = caches.find(key);
        if (it != caches.end())
        {   
            kvs.splice(kvs.begin(), kvs, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void set(int key, int value) {
        MapCache_t::iterator it = caches.find(key);
        if(it == caches.end()) {
            if(int(kvs.size()) == maxSize) {
                int k = kvs.back().first;
                caches.erase(k);
                kvs.pop_back();
            }

            kvs.push_front(KVPair_t(key, value));
            caches[key] = kvs.begin();
        } else {
            caches[key]->second = value;
            kvs.splice(kvs.begin(), kvs, it->second);
        }     
    }

private:
    int maxSize;
    MapCache_t caches;
    ListKV_t kvs; 
};

int main() {
    LRUCache c(2);
    c.set(2,1);
    c.set(1,1);
    cout << c.get(2) << endl;
    c.set(4,1);

    cout << c.get(1) << endl;
    cout << c.get(2) << endl;

    return 0;
}