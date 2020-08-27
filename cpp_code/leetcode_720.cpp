class Solution {
public:
    struct cmp_less
    {
        bool operator()(pair<int, string> a,pair<int, string> b)
        {
            if(a.first == b.first)  return a.second >= b.second;
            else return a.first > b.first;
        }
    };
    struct cmp_great
    {
        // 第一个元素按照降序排列
        // 第二个元素按照升序排列
        bool operator()(pair<int, string> a,pair<int, string> b)
        {
            if(a.first == b.first)  return a.second >= b.second;
            else return a.first < b.first;
        }
    };

    string longestWord(vector<string>& words) {
        int len = words.size();
        if (len == 0) return "";

        unordered_map<string, int> hash_table;
        sort(words.begin(), words.end());
        for (int i = 0; i < len; i++) {
            string str = words[i];
            string sub_str = str.substr(0, str.length() - 1);
            if (str.length() > 1) {
                if (hash_table.find(sub_str) != hash_table.end()) 
                    hash_table[str] = hash_table[sub_str] + 1;
                else 
                    hash_table[str] = 0;
            }
            else {
                hash_table[str] = 1;
            }
        }
        
        // priority_queue<pair<int, string>, vector<pair<int, string>>, 
        //                less<pair<int, string>> > heap;
        priority_queue< pair<int, string>, vector<pair<int, string>>, cmp_great> heap;
        for (auto item: hash_table) {
            string word = item.first;
            int count = item.second;
            heap.push(make_pair(count, word));
        }
        while (!heap.empty()) {
            pair<int, string> item = heap.top();
            heap.pop();
            if (item.first == item.second.length())
                return item.second;
        }
        return "";
    }
};
