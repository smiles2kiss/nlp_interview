class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it;
        for(it=nums.begin();it!=nums.end();)
        {
            if(*it == val)
                it=nums.erase(it);    //删除元素，返回值指向已删除元素的下一个位置    
            else
                it++;    //指向下一个位置
        }
        return nums.size();
    }
};
