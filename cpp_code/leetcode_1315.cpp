class Solution {
public:
    // 添加孙子节点与祖父节点之间的对应关系
    unordered_map<TreeNode*, TreeNode*> grandparents;
    // 前两层节点的祖父节点都为NULL
    void dfs(TreeNode* root, TreeNode* pre, TreeNode* gra_pre) {
        if (root) {
            if (!gra_pre) {
                grandparents[root] = NULL;
                if (!pre) {
                    gra_pre = NULL;
                    pre = root;
                } else {
                    gra_pre = pre;
                    pre = root;
                }
            } else {
                grandparents[root] = gra_pre;
                gra_pre = pre;
                pre = root;
            }
            dfs(root->left, pre, gra_pre);
            dfs(root->right, pre, gra_pre);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, NULL, NULL);
        int sum = 0;
        for (auto item = grandparents.begin(); item != grandparents.end(); item++) {
            if (item->second && item->second->val % 2 == 0) 
                sum = sum + item->first->val;
        }
        return sum;
    }
};
