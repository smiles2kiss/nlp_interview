class Solution {
public:
    int distance(vector<int> point) {
        return pow(point[0], 2) + pow(point[1], 2);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // ´ó¶¥¶Ñ
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> heap;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        int len = points.size();
        vector<int> distances(len, 0);
        for (int i = 0; i < len; i++) {
            distances[i] = distance(points[i]);
            cout << distances[i] << endl;
        }

        for (int i = 0; i < len; i++) {
            if (heap.size() == K) {
                if (heap.top().first <= distances[i]) {
                    continue;
                } else {
                    heap.pop();
                    heap.push(make_pair(distances[i], i));
                }
            } else {
                heap.push(make_pair(distances[i], i));
            }
        }
        vector<vector<int>> results;
        while (!heap.empty()) {
            int idx = heap.top().second;
            results.push_back(points[idx]);
            heap.pop();
        }
        return results;
    }
};
