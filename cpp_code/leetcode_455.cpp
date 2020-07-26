class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // ���ɳߴ�
        sort(g.begin(), g.end());
        // С��θ��
        sort(s.begin(), s.end());
        
        int len1 = g.size();
        int len2 = s.size();
        int i = 0; 
        int j = 0;
        int count = 0;
        while (i < len1 && j < len2) {
            if (g[i] <= s[j]) {
                i++;
                j++;
                count++;
            } else {
                j++;
            }
        }
        return count;
    }
};
