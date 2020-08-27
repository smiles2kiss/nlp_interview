class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        const int div = 1000000007;
        int ans = 0;
        int sum = 0;  // 前缀和
        int odd = 0, even = 1; // 奇数odd，偶数even
        for (int i = 0; i < n; i++) {
            sum = sum + arr[i];
            ans = (ans + (sum % 2 == 0 ? odd : even)) % div;
            if (sum % 2 == 0) even++;
            else odd++;
        }
        return ans;
    }
};
