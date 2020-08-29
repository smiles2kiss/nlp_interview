class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> helper;
        helper.insert(0);

        long long sum = 0;
        int count = 0;
        for (auto num: nums) {
            sum += num;
            count += distance(helper.lower_bound(sum - upper), helper.upper_bound(sum - lower));
            helper.insert(sum);
        }

        for (auto num : helper) cout << num << "\t";
        return count;
    }
};
