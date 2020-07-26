class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> results;
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 == 0 || len2 == 0)
            return results;

        // Ð¡¶¥¶Ñ
        priority_queue<
            pair< int, pair<int, int> >,
            vector< pair<int, pair<int, int>> >,
            greater< pair< int, pair<int, int> > >
        > smallheap;

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int sum = nums1[i] + nums2[j];
                pair<int, int> item = make_pair(nums1[i], nums2[j]);
                smallheap.push( make_pair(sum, item) );
            }
        }

        if (k > smallheap.size())
            k = smallheap.size();

        for (int i = 0; i < k; i++) {
            pair<int, int> item = smallheap.top().second;
            vector<int> result({item.first, item.second});
            results.push_back(result);
            smallheap.pop();
        }
        return results;
    }
};
