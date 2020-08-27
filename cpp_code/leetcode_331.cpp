class Solution {
public:
    string char2string(char ch) {
        string str = "-";
        str[0] = ch;
        return str;
    }
    bool isValidSerialization(string preorder) {
        vector<string> nums;
        int pre_is_dot = 1;
        for (char ch: preorder) {
            if (ch == ',') 
                pre_is_dot = 1;
            else {
                if (pre_is_dot == 1) 
                    nums.push_back(char2string(ch));
                else
                    nums[nums.size()-1] += char2string(ch);
                pre_is_dot = 0;
            }
        }
        
        int slots = 1; 
        for (auto ch : nums) {
            slots = slots - 1;
            if (slots < 0) return false;
            if (ch != "#") slots = slots + 2;
        }
        return slots == 0;
    }
};
