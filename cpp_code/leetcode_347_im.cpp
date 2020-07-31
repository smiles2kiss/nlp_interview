class Solution {
public:
    struct cmp {
        // С����
        bool operator() (const pair<int, int> &op1, const pair<int, int> &op2) {
            return op1.first > op2.first;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash_map; // first: Ԫ��, second: Ԫ�ظ���
        for (int num: nums) {
            if (hash_map.find(num) == hash_map.end())
                hash_map[num] = 1;
            else 
                hash_map[num] = hash_map[num] + 1;
        }

        // С����: ���ڵ�Ϊ��Сֵ
        // ��һ��Ԫ��Ϊ
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > q;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto iter: hash_map) {
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
