class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int len = postorder.size();
        if (len == 0) return true;
        // ����ջ��������
        stack<int> stk;
        int root = INT_MAX;
        for (int i=len-1; i >= 0; i--) {
            if (postorder[i] > root) return false; // ���ڵ����ĸ��ڵ�
            while (!stk.empty() && stk.top() > postorder[i]) {
                root = stk.top(); stk.pop();
            }
            stk.push(postorder[i]);
        }
        return true;
    }
};
