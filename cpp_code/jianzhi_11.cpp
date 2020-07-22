class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len = numbers.size();
        vector<int> q;
        q.push_back(numbers[0]);
        for (int i = 1; i < len; i++) {
            if (numbers[i] < q.front())
                return numbers[i];
        }
        return q.front();
    }
};
