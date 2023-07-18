class LRUCache {
public:
    list<pair<int,int>>l;
    unordered_map<int,list<pair<int,int>>::iterator>umap;
    int size;
    
    LRUCache(int capacity) {
        
        size = capacity;
    }
    
    int get(int key) {
        
        if(umap.find(key) == umap.end()) return -1;
        l.splice(begin(l), l, umap[key]);
        return umap[key]->second;
    }
    
    void put(int key, int value) {
        
        if(umap.find(key) != umap.end()){
            l.splice(begin(l), l, umap[key]);
            umap[key]->second = value; 
            return;
        }
        if(l.size() == size){
            auto d_key = l.back().first;
            l.pop_back();
            umap.erase(d_key);
        }
            l.push_front({key, value});
            umap[key] = begin(l);
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */