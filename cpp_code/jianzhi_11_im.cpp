class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len = numbers.size();
        int start = 0;
        int end = len - 1;
        while(start < end) {
            int mid = (start + end) / 2;
            if (numbers[start] > numbers[mid])
                end = mid;
            else if (numbers[mid] > numbers[end])
                start = mid + 1;
            else {
                end = end - 1;
            }
        }
        return numbers[start];
    }
};
