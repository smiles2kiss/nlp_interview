class Solution {
public:
    struct Mycmp {
        bool operator () (pair<char, int> &a, pair<char, int> &b)
        {
            return a.second < b.second;
        }
    };

    string reorganizeString(string S) {
        // ��ϣ���¼ÿ����ĸ���ֵĴ���
        // ���ȶ��жԹ�ϣ���еĽ������������(�󶥶�)
        priority_queue<pair<char, int>, vector<pair<char,int>>, Mycmp> bigheap;
        // priority_queue<pair<char, int>, vector<pair<char,int>>, less<pair<char, int>>> heap; 
        // priority_queue<pair<char, int>, vector<pair<char,int>>, greater<pair<char, int>>> heap; 
        unordered_map<char, int> hash_table;

        for (auto ch: S) 
            hash_table[ch]++;
        for (auto pair: hash_table)
            bigheap.push(pair);
        
        string result;
        while (bigheap.size() >= 2) {
            pair<char, int> pair1 = bigheap.top();
            bigheap.pop();
            pair<char, int> pair2 = bigheap.top();
            bigheap.pop();
            
            result = result + pair1.first;
            result = result + pair2.first;

            pair1.second--;
            pair2.second--;

            if (pair1.second > 0)
                bigheap.push(pair1);
            if (pair2.second > 0)
                bigheap.push(pair2);
        }

        if (bigheap.size() == 1) {
            if (bigheap.top().second > 1)
                return "";
            else if (bigheap.top().second == 1) 
                result = result + bigheap.top().first;
        }
        return result;
    }
};
