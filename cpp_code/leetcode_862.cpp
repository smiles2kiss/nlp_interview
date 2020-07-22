class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
    	int len = A.size();
    	int min_len = len + 1;
    	// dp[i]表示以字符i-1结尾的最大值 
    	vector<int> dp(len + 1, 0);
    	
    	for (int i = 0; i < len; i++) {
    		if (dp[i] + A[i] > 0)
    			dp[i+1] = dp[i] + A[i];
    		if (dp[i + 1] >= K) {
    			int sum = A[i];
    			int cur = 1;
    			while (sum < K) {
    				sum = sum + A[i-cur];
    				cur = cur + 1;
				}
				if (cur < min_len)
					min_len = cur;
			}
		}
		return min_len == len + 1 ? -1 : min_len;
	}
};

