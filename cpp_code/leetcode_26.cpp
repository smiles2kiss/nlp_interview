class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();

        vector<int>::iterator it;
        int pre = nums[0] - 1;
        for(it=nums.begin();it!=nums.end();)
        {
            if(*it == pre)
                it=nums.erase(it);    //ɾ��Ԫ�أ�����ֵָ����ɾ��Ԫ�ص���һ��λ��    
            else {
                pre = *it;
                it++;    //ָ����һ��λ��
            }
        }
        return nums.size();
    }
};
