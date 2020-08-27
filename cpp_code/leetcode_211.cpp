# include<iostream>
# include<string.h>

using namespace std;


class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct node {
        bool isEnd;
        node* next[26];
        node() {isEnd = false; memset(next, NULL, sizeof(next));}
    };

    node* root;
    WordDictionary() {
        root = new node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        node *p = root;
        for (auto c : word) {
            if (p->next[c - 'a'] == NULL)
                p->next[c - 'a'] = new node();
            p = p->next[c - 'a'];
        }
        p->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
//    bool search(string word) {
//        node *p = root;
//        for (auto c : word) {
//            p = p->next[c - 'a'];
//            if (p == NULL) return false;
//        }
//        return p->isEnd;
//    }

	bool search(string word) {
		return subSearch(root, word);
	}
	
	bool subSearch(node* p, string word) {
		if (p == NULL) return false;
		for (int i = 0; i < word.length(); i++) {
			if (word[i] == '.') {
				for (int j = 0; j < 26; j++) 
					if (subSearch(p->next[j], word.substr(i + 1))) return true;
				return false;
			}
			int idx = word[i] - 'a';
			if (p->next[idx] == NULL) return false;
			p = p->next[idx];
		}
		return p->isEnd;
	}
};

int main() {
	WordDictionary dict;
	dict.addWord("bad");
	dict.addWord("dad");
	dict.addWord("mad");
	bool res = dict.search("bad");
	cout << res << endl;
	return 0;
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
