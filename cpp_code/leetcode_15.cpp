class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.size() < 2)
            return results;

        sort(nums.begin(), nums.end());

        int flag = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                flag = i;
                break;
            }
        }
        if (flag == nums.size() - 1)
            return results;
        if (flag == 0) {
            if (flag + 2 < nums.size()) {
                if (nums[flag] == 0 && nums[flag+1] == 0 && nums[flag+2] == 0) {
                    vector<int> result;
                    result.push_back(0);
                    result.push_back(0);
                    result.push_back(0);
                    results.push_back(result);
                }
            }
            return results;
        }

        if (flag > 0) {
            for (int i = 0; i < flag; i++) {
                for (int j = flag + 1; j < nums.size(); j++) {
                    if (nums[i] + nums[j] == 0) {
                        vector<int> result;
                        result.push_back(nums[i]);
                        result.push_back(0);
                        result.push_back(nums[j]);
                        if (find(results.begin(), results.end(), result) == results.end())
                            results.push_back(result);
                    }
                }
            }
        }
        vector<int> temp;
        if (flag > 0 && flag < nums.size() && flag + 2 < nums.size()) {
            if (nums[flag] == 0 && nums[flag+1] == 0 && nums[flag+2] == 0) {
                temp.push_back(0);
                temp.push_back(0);
                temp.push_back(0);
                results.push_back(temp);
            }
        }

        flag = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                flag = i;
                break;
            }
        }
        if (flag == 0)
            return results;

        for (int i = 0; i < flag; i++) {
            for (int j = flag; j < nums.size(); j++) {
                if (nums[i] + nums[j] > 0) {
                    for (int k = 0; k < flag && k != i; k++) {
                        if (nums[i] + nums[j] + nums[k] == 0) {
                            vector<int> result;
                            if (nums[i] <= nums[k]) {
                                result.push_back(nums[i]);
                                result.push_back(nums[k]);
                                result.push_back(nums[j]);
                            } else {
                                result.push_back(nums[k]);
                                result.push_back(nums[i]);
                                result.push_back(nums[j]);
                            }
                            if (find(results.begin(), results.end(), result) == results.end())
                                results.push_back(result);
                        }
                    }
                } else if (nums[i] + nums[j] < 0) {
                    for (int k = flag; k < nums.size() && k != j; k++) {
                        if (nums[i] + nums[j] + nums[k] == 0) {
                            vector<int> result;
                            if (nums[j] <= nums[k]) {
                                result.push_back(nums[i]);
                                result.push_back(nums[j]);
                                result.push_back(nums[k]);
                            } else {
                                result.push_back(nums[i]);
                                result.push_back(nums[k]);
                                result.push_back(nums[j]);
                            }
                            if (find(results.begin(), results.end(), result) == results.end())
                                results.push_back(result);
                        }
                    }
                }
            }
        }
        sort(results.begin(), results.end());
        return results;
    }
};
