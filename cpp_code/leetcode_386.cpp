class Solution {
public:
    vector<int> lexicalOrder(int n) {
        priority_queue< pair<string,int>, vector<pair<string,int>>, greater<pair<string,int>> > q;
        for (int i = 1; i <= n; i++) 
            q.push(make_pair(to_string(i), i));
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
