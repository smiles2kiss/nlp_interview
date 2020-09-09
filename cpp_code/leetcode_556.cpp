class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> nums;
        while (n / 10) {
            nums.push_back(n % 10);
            n = n / 10;
        }
        nums.push_back(n);
        reverse(nums.begin(), nums.end());
        
        int len = nums.size();
        stack<pair<int, int>> stk; // 单调栈，上面元素最大
        for (int i = len-1; i >= 0; i--) {
            int num = nums[i];
            if (!stk.empty() && stk.top().first > num) {
                // 交换两个元素
                int idx = -1;
                while (!stk.empty() && stk.top().first > num) {
                    idx = stk.top().second;
                    stk.pop();
                }

                int temp = nums[i];
                nums[i] = nums[idx];
                nums[idx] = temp;
                sort(nums.begin() + i + 1, nums.end());
                long long res = 0;
                for (auto num:nums) res = res * 10 + num;
                return res > INT_MAX ? -1 : res;
            }
            stk.push(make_pair(num,i));
        }
        return -1;
    }
};
