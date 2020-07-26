class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 先排序，再逐个插入
        // 先按照身高从大到小排序
        // 再按照人数从小到大排序
        sort(people.begin(), people.end(),
            [](const vector<int> &a, const vector<int> &b) {
                if (a[0] > b[0]) return true;
                if (a[0] == b[0] && a[1] < b[1]) return true;
                return false; 
            });
        
        vector<vector<int>> result;
        for (auto item: people) {
            result.insert(result.begin() + item[1], item);
        }
        return result;
    }
};
