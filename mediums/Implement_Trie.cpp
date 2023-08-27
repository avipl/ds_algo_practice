struct tree{
    unordered_map<char, tree*> node;
    bool isWord = false;
};

class Trie {
    tree *t;
public:
    Trie() {
        t = new tree();
    }
    
    void insert(string word) {
        tree* curr = t;
        for(auto c : word){
            auto it = curr->node.find(c);
            if(it == curr->node.end()){
                curr->node.insert({c, new tree()});
                curr = curr->node[c];
            }else curr = it->second;
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        tree* curr = t;
        for(auto c : word){
            auto it = curr->node.find(c);
            if(it == curr->node.end()) return false;
            curr = it->second;
        }
        if(curr->isWord) return true;
        
        return false;
    }
    
    bool startsWith(string prefix) {
        tree* curr = t;
        for(auto c : prefix){
            auto it = curr->node.find(c);
            if(it == curr->node.end()) return false;
            curr = it->second;
        }
    
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */