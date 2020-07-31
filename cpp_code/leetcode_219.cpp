class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (map.find(num) == map.end()) {
                vector<int> temp = vector({i});
                map[num] = temp;
            } else {
                map[num].push_back(i);
            }
        }
        for (auto item: map) {
            int num = item.first;
            vector<int> idxs = item.second;
            int size = idxs.size();
            if (size > 1) {
                sort(idxs.begin(), idxs.end());
                for (int i = 0; i < size - 1; i++) {
                    for (int j = i + 1; j < size; j++) {
                        if (idxs[j] - idxs[i] <= k)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};
