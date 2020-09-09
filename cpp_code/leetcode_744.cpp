class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (auto ch:letters) {
            if (ch - 'a'> target - 'a') return ch;
        }
        return letters[0];
    }
};
