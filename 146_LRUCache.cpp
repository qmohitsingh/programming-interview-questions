
/*
Refrence : https://leetcode.com/problems/lru-cache/discuss/831993/C%2B%2B-90.04-and-37.81.-Proper-solution-for-this-problem-easy-to-implement-using-std%3A%3Alist
*/
class LRUCache {
public:
    
    list<pair<int,int>> li;
    unordered_map<int, list<pair<int,int>>::iterator> map;
    int sz;
    int maxSz;
    
    LRUCache(int capacity) {
        maxSz = capacity;
        sz = 0;
    }
    
    int get(int key) {
        if (map.find(key) == map.end())
            return -1;
        
        li.push_front({key, map[key]->second});
        li.erase(map[key]);
        map[key] = li.begin();
        
        return map[key]->second;
    }
    
    void put(int key, int value) {
        if (map.find(key) == map.end()) {
            li.push_front({key, value});
            map[key] = li.begin();
            sz++;
            if (sz <= maxSz)
                return ;
            map.erase(li.back().first);
            li.pop_back();
            sz--;
        } else {
            li.push_front({key, value});
            li.erase(map[key]);
            map[key] = li.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
