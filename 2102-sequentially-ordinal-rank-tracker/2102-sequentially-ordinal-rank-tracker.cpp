class SORTracker {
    struct location {
        int score;
        string name;
        
        location(int score, string name): score(score), name(name) {}
        
        bool operator<(const location &l) const {
            return score > l.score || (score == l.score && name < l.name);
        }
    };
    set<location> scenes;
    set<location>::iterator cur;
public:
    SORTracker() {}
    
    void add(string name, int score) {
        auto scene = location(score, name);
        if (scenes.empty()) {
            scenes.insert(scene);
            cur = scenes.begin();
            return;
        }
        
        scenes.insert(scene);
        if (cur == scenes.end() || scene < *cur) 
            cur--;
    }
    
    string get() {
        string ans = cur->name;
        cur++;
        return ans;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */