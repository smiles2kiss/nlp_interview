class Solution {
public:
    unordered_map<int, int> memo;
    int dp(int K, int N) {
        if (memo.find(N * 100 + K) != memo.end()) 
            return memo[N * 100 + K];
        
        if (K == 0) return 0;
        if (K == 1) return N; // ˳����� ��Ҫ�ƶ��Ĵ���

        int result;
        int left = 1;
        int right = N;
        while (left < right) {
            int mid = (left + right) / 2;
            int t1 = dp(K-1, mid-1); // �����ڵ�mid��ˤ����
            int t2 = dp(K, N-mid);   // �����ڵ�mid��ûˤ��
            if (t1 < t2) left = mid;
            else if (t1 > t2) right = mid;
            else {
                left = mid;
                right = mid;
            }

            result = 1 + min(
                max(dp(K-1, left-1),  dp(K, N-left)),  // ���ĳ��Կ��� 
                max(dp(K-1, right-1), dp(K, N-right))
            );
            memo[N*100 + K] = result;
        }
        return memo[N * 100 + K];
    }
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
};
