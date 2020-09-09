class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        unordered_map<int, int> hash_table;
        hash_table[0] = 0;
        vector<vector<int>> results;
        long long pre = 0;
        for (int i = 1; i <= target - 1; i++) {
            pre = pre + i;
            if (hash_table.find(pre - target) != hash_table.end()) {
                int idx = hash_table[pre - target];
                vector<int> result;
                for (int j = idx + 1; j <= i; j++) 
                    result.push_back(j);
                results.push_back(result);
            }
            hash_table[pre] = i;
        }
        return results;
    }
};
