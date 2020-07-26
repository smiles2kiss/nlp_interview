class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // ���������������
        // �Ȱ�����ߴӴ�С����
        // �ٰ���������С��������
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
