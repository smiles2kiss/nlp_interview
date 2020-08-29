# include<iostream>
# include<algorithm>
# include<string>
# include<string.h>

using namespace std;

// 字母种类: 26 
const int kind = 26;

struct TrieNode {
	bool isEnd; // 判断是否是单词
	TrieNode* next[kind];
	// 构造函数 
	TrieNode() {
		memset(next, NULL, sizeof(next));
		isEnd = false;
	}
	// 析构函数 
	~TrieNode() {
		for (int i = 0; i < kind; i++) {
			if (next[i]) delete next[i];
		}	
	}
};

class Trie {
	TrieNode* root;
public:
	Trie() {
		root = new TrieNode();
	}
	~Trie() {
		delete root;
	}
	
	void insert(string word) {
		TrieNode *p = root;
		for(auto c : word) {
			if (p->next[c - 'a'] == NULL) 
				p->next[c - 'a'] = new TrieNode();
			p = p->next[c - 'a'];
		} 
		p->isEnd = true;
	}
	
	bool search(string word) {
		TrieNode* p = root;
		for (auto c : word) {
			p = p->next[c - 'a'];
			if (p == NULL) return false;
		}
		return p->isEnd;
	}
	
	// 前缀查找 
	bool startWith(string prefix) {
		TrieNode* p = root;
		for (auto c : prefix) {
			p = p->next[c - 'a'];
			if (p == NULL) return false;
		}
		return true;
	}
};


int main() {
	Trie trie;
	trie.insert("abc");
	trie.insert("ac");
	bool result = trie.search("ac");
	cout << result << endl;
	return 0;
} 
