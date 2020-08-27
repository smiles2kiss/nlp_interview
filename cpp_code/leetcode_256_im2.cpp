class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int len = costs.size();
        int pre_R = 0, cur_R = 0;
        int pre_B = 0, cur_B = 0;
        int pre_G = 0, cur_G = 0;
        for (int i = 0; i < len; i++) {
            cur_R = min(pre_B, pre_G) + costs[i][0];
            cur_B = min(pre_R, pre_G) + costs[i][1];
            cur_G = min(pre_R, pre_B) + costs[i][2];
            pre_R = cur_R;
            pre_B = cur_B;
            pre_G = cur_G;
        }
        return min(min(cur_R, cur_B), cur_G);
    }
};
