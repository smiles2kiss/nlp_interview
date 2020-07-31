class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int, int> hash_table;
        for (int i = 0; i < mat.size(); i++) {
            // ��ĳһ����Ѱ��
            unordered_set<int> _set(mat[i].begin(), mat[i].end());
            for (auto num: _set) hash_table[num]++;
        }
        
        // С���ѣ����ڵ�Ԫ����С
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto item: hash_table) {
            int num = item.first;
            int count = item.second;
            if (count == mat.size()) q.push(num);
        }
        if (!q.empty()) return q.top();
        else return -1;
    }
};
