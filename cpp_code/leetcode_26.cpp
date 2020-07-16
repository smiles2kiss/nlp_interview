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
                it=nums.erase(it);    //删除元素，返回值指向已删除元素的下一个位置    
            else {
                pre = *it;
                it++;    //指向下一个位置
            }
        }
        return nums.size();
    }
};
