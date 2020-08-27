class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        // 可能有重复的情况
        vector<int> pos1, pos2;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) pos1.push_back(i);
            if (words[i] == word2) pos2.push_back(i);
        }
        int res = INT_MAX;
        for (auto i : pos1) {
            for (auto j : pos2) {
                res = min(res, abs(i - j));
            }
        }
        return res;
    }
};
