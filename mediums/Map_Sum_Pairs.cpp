struct TrieNode{
    unordered_map<char, TrieNode*> next;
    int val;
};

class MapSum {
    TrieNode* trie;
    unordered_map<string, int> dict;
public:
    MapSum() {
        trie = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *curr = trie;
        int oldVal = 0;
        if(dict.find(key) == dict.end()){
            dict.insert({key, val});
        }else{
            oldVal = dict[key];
            dict[key] = val;
        }
        
        for(auto c : key){
            auto it = curr->next.find(c);
            if(it == curr->next.end()){
                TrieNode *n = new TrieNode();
                n->val = val;
                curr->next[c] = n;
                curr = n;
            }else{
                curr = it->second;
                if(oldVal)
                    curr->val = curr->val - oldVal + val;
                else
                    curr->val += val;
            }
        }
    }
    
    int sum(string prefix) {
        TrieNode *curr = trie;
        
        for(auto c : prefix){
            auto it = curr->next.find(c);
            if(it == curr->next.end()) return 0;
            curr = it->second;
        }
        
        return curr->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */