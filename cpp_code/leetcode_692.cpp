class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // unordered_set<string> hash_table;
        unordered_map<string, int> hash_table;
        // �����: ���ϵ�Ԫ��ֵ���
        // less: �����(��Ԫ�����)
        // greater: С����(��Ԫ����С))
        // С���ѷ��㽻��
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>> 
        > bigheap;

        for (auto word: words) {
            // hash_table[word]++;
            hash_table[word]++;
        }
        
        for (auto item: hash_table) {
            pair<int, string> cur = make_pair(item.second, item.first);
            if (bigheap.size() < k) {
                bigheap.push(cur);
            } else if (bigheap.size() == k) {
                if (item.second > bigheap.top().first) {
                    bigheap.pop();
                    bigheap.push(cur);
                }
            }
        }

        vector<string> result;
        while (!bigheap.empty()) {
            result.push_back(bigheap.top().second);
            bigheap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
