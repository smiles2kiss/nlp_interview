class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (int num: nums) map[num]++;
        vector<pair<int, int>> res;
        for (auto iter: map) res.push_back(make_pair(iter.second, iter.first));
        sort(res.begin(), res.end(), greater<pair<int, int>>()); // ½µÐò
        vector<int> result;
        for (int i = 0; i < k; i++) result.push_back(res[i].second);
        return result;
    }
};
