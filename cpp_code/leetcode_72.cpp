#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 == 0)
            return len2;
        if (len2 == 0)
            return len1;

        int distance[len1 + 1][len2 + 1];
        distance[0][0] = 0;
        for (int i = 1; i <= len1; i++) {
            distance[i][0] = i;
        }
        for (int j = 1; j <= len2; j++) {
            distance[0][j] = j;
        }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    distance[i][j] = distance[i - 1][j - 1];
                } else {
                    int min = i > j ? i : j;
                    if (distance[i - 1][j - 1] + 1 < min) { // Ìæ»»
                        min = distance[i - 1][j - 1] + 1;
                    }
                    if (distance[i - 1][j] + 1 < min) { // ²åÈë
                        min = distance[i - 1][j] + 1;
                    }
                    if (distance[i][j - 1] + 1 < min) { // É¾³ý
                        min = distance[i][j - 1] + 1;
                    }
                    distance[i][j] = min;
                }
            }
        }
        return distance[len1][len2];
    }
};

int main() {
	Solution solution;
	string word1 = "horse";
	string word2 = "ros";
	int len = solution.minDistance(word1, word2);
	cout << len << endl;
	return 0;
} 
