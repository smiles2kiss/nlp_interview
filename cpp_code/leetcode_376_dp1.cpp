class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        // 以i结尾的上升摆动序列和下降摆动序列的长度
        // 即在第i个位置元素是上升的还是下降的
        vector<int> up;
        vector<int> down;
        for (int i = 0; i < nums.size(); i++) {
            up.push_back(1);
            down.push_back(1);
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    // 当前节点作为波峰，找到上一个波谷
                    up[i] = max(up[i], down[j] + 1);
                } 
                else if (nums[i] < nums[j]) {
                    // 当前节点作为波谷，找到上一个波峰
                    down[i] = max(down[i], up[j] + 1);
                }
            }
        }
        return max(down[nums.size() - 1], up[nums.size() - 1]);
    }
};
