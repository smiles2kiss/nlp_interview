class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int index = 0, count = 0, result = 0;
        while (index < len){
            while (index < len && s[index] != ' ') {
                count = count + 1;
                result = count;
                index++;
            }
            count = 0;
            index++;
        }
        return result;
    }
};
