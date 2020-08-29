class Solution {
public:
    int nthUglyNumber(int n) {
        // ά��һ����СΪ3��С����
        priority_queue<long, vector<long>, greater<long>> small_heap;
        // ��¼��������Ԫ��
        unordered_set<long> hash_set; 
        small_heap.push(1);
        hash_set.insert(1);

        long result = 1;
        for (int i = 1; i < n; i++) {
            if (hash_set.find(result * 2) == hash_set.end()) {
                small_heap.push(result * 2);
                hash_set.insert(result * 2);
            }
            if (hash_set.find(result * 3) == hash_set.end()) {
                small_heap.push(result * 3);
                hash_set.insert(result * 3);
            }
            if (hash_set.find(result * 5) == hash_set.end()) {
                small_heap.push(result * 5);
                hash_set.insert(result * 5);
            }
            result = small_heap.top();
            small_heap.pop();
        }
        return small_heap.top();
    }
};
