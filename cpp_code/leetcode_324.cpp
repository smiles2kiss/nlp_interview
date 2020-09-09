class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int size = nums.size();
        int mid = (size + 1) / 2 - 1;
        int end = size - 1;
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {nums[i] = temp[mid]; mid--;}
            else {nums[i] = temp[end]; end--;}
        }
    }
};
