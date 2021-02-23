class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        unordered_map<int, int> hash_table;
        for (int i = 0; i < numbers.size(); i++) {
            int num = numbers[i];
            if (!hash_table.empty() && hash_table.find(target-num) != hash_table.end()) {
                res.push_back(hash_table[target-num]+1);
                res.push_back(i+1);
                break;
            }
            hash_table[num] = i;
        }
        return res;
    }
};
