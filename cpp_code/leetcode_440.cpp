class Solution {
public:
    int findKthNumber(int n, int k) {
        priority_queue< pair<string,int>, vector<pair<string,int>>, greater<pair<string,int>> > q;
        for (int i = 1; i <= n; i++) q.push(make_pair(to_string(i), i));
        while (k > 1) {
            q.pop(); k = k - 1;
        }
        return q.top().second;
    }
};
