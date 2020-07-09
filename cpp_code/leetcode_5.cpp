# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    	if (s.length() < 1) 
    		return s;
    	
    	int flag = 0;
    	for (int i = 0; i < s.length(); i++) {
    		if (s[i] != s[0]) {
    			flag = 1;
    			break;
			}
		}
		if (flag == 0) 
			return s;

        string max = "";
        for (int i = 0; i < s.length(); i++) {
            int left_len = i;
            int right_len = s.length() - 1 - i;
            int min_len = left_len < right_len ? left_len : right_len;
            string temp = s.substr(i, 1);
            // string temp(s, i, 1);
            
            for (int j = 0; j < min_len; j++) {
                if (s[i - 1 - j] == s[i + 1 + j]) {
                    temp = s[i - 1 - j] + temp + s[i + 1 + j];
                } else {
                    break;
                }
            }

            if (temp.length() > max.length()) {
                max = temp;
            }
        }
        for (int i = 0; i < s.length() - 1; i++) {
        	int left_len = i;
        	int right_len = s.length() - 2 - i;
        	int min_len = left_len < right_len ? left_len : right_len;
        	string temp = s.substr(i, 2);
        	if (temp[0] != temp[1])
        		continue;
        	
        	for (int j = 0; j < min_len; j++) {
        		if (s[i - 1 - j] == s[i + 2 + j]) {
        			temp = s[i - 1 - j] + temp + s[i + 2 + j];
				} else {
					break;
				}
			}
			if (temp.length() > max.length()) {
				max = temp;
			}
		}
        return max;
    }
};

int main() {
	Solution solution;
	string s = "babad"; 
//	string s = "cbbd";
	string max = solution.longestPalindrome(s);
	cout << max << endl;
	return 0;
} 
