/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

*/

class LRUCache {
public:
    map<int,int> mp;
    int sz=0;
    list<int> lst;
    
    LRUCache(int capacity) {
    
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sz=capacity;
        mp.clear();
        lst.clear();
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end()) return -1;
        
        lst.remove(key);
        lst.push_back(key);
        return mp[key];
    }
    
    void put(int key, int value) {
        if(sz==0) return;
        
        if(mp.find(key)!=mp.end()){
            lst.remove(key);
            lst.push_back(key);
            mp[key]=value;
            return;
        }
        if(lst.size()<sz){
            lst.push_back(key);
            mp[key]=value;
            return;
        }
        map<int,int> :: iterator it=mp.find(lst.front());
        mp.erase(it);
        lst.pop_front();
        lst.push_back(key);
        mp[key]=value;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
