class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        // 把数组按照奇数和偶数数组分成两块
        int len = A.size();
        int i = 0;
        int j = len - 1;
        int temp;
        while (i < j) {
            while (i < j && A[i] % 2 == 0) i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            while (i < j && A[j] % 2 == 1) j--;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        return A;
    }
};
