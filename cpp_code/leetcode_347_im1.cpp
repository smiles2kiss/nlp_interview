class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map; // first: Ԫ��, second: Ԫ�ظ���
        for (int num: nums) map[num]++;
        // ��С��, first: Ԫ��, second: Ԫ�ظ���
        // ����
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > q;
        for (auto iter: map) {
            if (q.size() == k) {// ������
                if (iter.second > q.top().first) { // ������
                    q.pop();
                    q.push(make_pair(iter.second, iter.first));
                }
            } else {
                q.push(make_pair(iter.second, iter.first));
            }
        }
        // ����Ľ��Ϊ����
        vector<int> result;
        while(q.size()) { //�����ȶ�����k����ƵԪ�ش���vector
            result.push_back(q.top().second);
            q.pop();
        }
        return vector<int>(result.rbegin(), result.rend());
    }
};
