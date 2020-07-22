class Solution {
public:
    // 广度优先搜索
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0)
            return true;
        
        int len = arr.size();
        vector<bool> used(len, false);
        queue<int> q;
        q.push(start);
        used[start] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            int pos1 = u + arr[u];
            int pos2 = u - arr[u];
            if (pos1 < len && !used[pos1]) {
                if (arr[pos1] == 0)
                    return true;
                q.push(pos1);
                used[pos1] = true;
            }
            if (pos2 >= 0 && !used[pos2]) {
                if (arr[pos2] == 0)
                    return true;
                q.push(pos2);
                used[pos2] = true;
            }
        }
        return false;
    }
};
