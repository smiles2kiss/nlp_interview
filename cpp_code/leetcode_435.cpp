class Solution {
public:
    // 大根堆
    struct cmp_big{
        bool operator()(const pair<int, int> &a, const pair<int, int> &b){
            if (a.first < b.first) return true;
            else if (a.first == b.first && a.second < b.second) return true;
            return false;
        }
    };

    // 小根堆
    struct cmp_small{
        bool operator()(const pair<int, int> &a, const pair<int, int> &b){
            if (a.first > b.first) return true;
            else if (a.first == b.first && a.second > b.second) return true;
            return false;
        }
    };

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp_small> small_heap;
        for (auto val:intervals) small_heap.push(make_pair(val[0], val[1]));
        while (!small_heap.empty()) {
            pair<int,int> item = small_heap.top();
            small_heap.pop();
            cout << "first: " << item.first << " " << "second: " << item.second << endl;
        }
        return 0;
    }
};
