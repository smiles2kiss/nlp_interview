class Solution {
public:
    string frequencySort(string s) {
        // ´ó¸ù¶Ñ
        unordered_map<char, int> hash_table;
        for (auto ch:s) hash_table[ch]++;

        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> q;
        for (auto item:hash_table) q.push(make_pair(item.second, item.first));

        string result = "";
        while (!q.empty()) {
            pair<int, char> item = q.top(); q.pop();
            result = result + string(item.first, item.second);
        }
        return result;
    }
};
