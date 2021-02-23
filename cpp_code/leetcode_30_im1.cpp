class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.length() == 0 || words.size() == 0) return vector<int>({});
        
        unordered_map<string, int> hash;
        for (auto word:words) hash[word]++;

        vector<int> ans;
        int len = s.length();
        int size = words.size();
        // 所有单词的长度相同
        int modlen = words[0].length();

        string temp = "";
        unordered_map<string,int> buff;
        for (int i = 0; i < len; i++) {
            if (len-i+1 < modlen*size) break;
            temp = s.substr(i, modlen);

            int idx = i;
            int count = 0;
            buff = hash;
            while (buff[temp] > 0) {
                buff[temp]--;
                count++;
                idx += modlen;
                temp = s.substr(idx, modlen);
            }
            if (count == size) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
