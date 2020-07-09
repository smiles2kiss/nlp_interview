# include <iostream>
# include <string>

using namespace std;

bool is_Palindrome(string s){
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
    	if(s[i] != s[j])
            break;
        i++;
        j--;
	}
    if(i >= j)
        return true;
    else
        return false;
}


class Solution {
public:
    string longestPalindrome(string s) {    	
    	if (s.size() < 2)
    		return s;
    	int n = s.size();
    	
    	// dp代表[i, j]之间的字符串是否是回文字符串 
    	// 这里要满足条件 j > i; 
		int dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }

    	int left = 0;
    	int len = 1;
    	
    	for (int j = 0; j < n; j++) {
    		dp[j][j] = 1;
    		for (int i = 0; i < j; i++) {
    			if (s[i] == s[j]) {
    				if (j - i < 2) {
    					dp[i][j] = 1;
					} else { // j - i >= 2
						if (dp[i + 1][j - 1] == 1) {
							dp[i][j] = 1;
						} else {
							dp[i][j] = 0;
						}
					}
				} else {
					dp[i][j] = 0;
				}
				
				if (dp[i][j] == 1 && len < j - i + 1) {
					len = j - i + 1;
					left = i;
				}
			}
		}
		string max = s.substr(left, len);
		return max; 
    }
};


int main() {
	Solution solution;
//	string s = "cbbd";
	string s = "babad";
	string max = solution.longestPalindrome(s);
	cout << max << endl;
	return 0;
} 
