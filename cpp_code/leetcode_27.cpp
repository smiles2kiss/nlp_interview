class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it;
        for(it=nums.begin();it!=nums.end();)
        {
            if(*it == val)
                it=nums.erase(it);    //ɾ��Ԫ�أ�����ֵָ����ɾ��Ԫ�ص���һ��λ��    
            else
                it++;    //ָ����һ��λ��
        }
        return nums.size();
    }
};
