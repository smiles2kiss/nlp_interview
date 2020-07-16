class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size(); first++) {
            if (first > 0 && nums[first] == nums[first-1])
                continue;
            
            int third = nums.size() - 1;
            int target = -nums[first];
            for (int second = first + 1; second < nums.size(); second++) {
                if (second > first + 1 && nums[second] == nums[second-1])
                    continue;
                
                while(second < third && nums[second] + nums[third] > target)
                    third--;
                
                if (second == third)
                    break;
                
                if (nums[second] + nums[third] == target){
                    results.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return results;
    }
};
