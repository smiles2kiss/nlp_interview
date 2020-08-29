class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long long, vector<long long>, greater<long long>> small_heap;
        unordered_set<long long> hash_set;
        small_heap.push(1);
        hash_set.insert(1);
        long long result = 1;
        int k = primes.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int temp = result * primes[j];
                if (hash_set.find(temp) == hash_set.end()) {
                    small_heap.push(temp);
                    hash_set.insert(temp);
                }
            }
            small_heap.pop();
            result = small_heap.top();
        }
        return small_heap.top();
    }
};
