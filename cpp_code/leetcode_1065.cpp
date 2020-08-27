class WordDict {
    struct node {
        bool isEnd;
        node* next[26];
        node() {isEnd=false; memset(next, NULL, sizeof(next));}
    };

    public:
        node* root = new node();
        void addWord(string word) {
            node* p = root;
            for (auto c : word) {
                if (p->next[c - 'a'] == NULL) 
                    p->next[c - 'a'] = new node();
                p = p->next[c - 'a'];
            }
            p->isEnd = true;
        } 

        bool search(string word) {
            node* p = root;
            for (auto c : word) {
                p = p->next[c - 'a'];
                if (p == NULL) return false;
            }
            return p->isEnd;
        }
};


class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        WordDict dict;
        for (auto word:words) dict.addWord(word);
        vector<vector<int>> results;
        bool result1 = dict.search("story");
        bool result2 = dict.search("stor");

        int len = text.length();
        for (int i = 0; i < len; i++) { // start
            for (int j = i; j < len; j++) { // end
                string str = text.substr(i, j + 1 - i);
                if (dict.search(str) == true) 
                    results.push_back(vector<int>({i, j}));
                
            }
        }
        return results;
    }
};
