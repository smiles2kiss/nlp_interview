class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len1 = nums.size();
        if (len1 == 0) return vector<int>();

        stack<pair<int,int>> stk;
        vector<int> res(len1, -1);
        stk.push(make_pair(nums[0], 0));
        for (int i = 1; i < 2*len1; i++) {
            while (!stk.empty() && stk.top().first < nums[i%len1]) {
                int idx = stk.top().second;
                if (idx < len1) res[idx] = nums[i%len1];
                stk.pop();
            }
            stk.push(make_pair(nums[i%len1], i));
        }
        return res;
    }
};
