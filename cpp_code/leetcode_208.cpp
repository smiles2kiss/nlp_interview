class Trie {
public:
    bool isEnd;
    Trie *next[26];
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *p = this;
        for (auto c : word) {
            if (p->next[c - 'a'] == NULL) {
                p->next[c - 'a'] = new Trie();
            }
            p = p->next[c - 'a'];
        }
        p->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* p = this;
        for (auto c : word) {
            p = p->next[c - 'a'];
            if (p == NULL) return false;
        }
        return p->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* p = this;
        for (auto c : prefix) {
            p = p->next[c - 'a'];
            if (p == NULL) return false;
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
