class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); i++) {
            int add = gas[i];
            int dif = cost[i];
            if (add >= dif) {
                int reserved = 0;
                int flag = 0;
                for (int j = 0; j <= gas.size(); j++) {
                    int start = (j + i) % gas.size();
                    reserved = reserved + gas[start];
                    if (reserved < cost[start]) {
                        flag = 1;
                        break;
                    } else {
                        reserved = reserved - cost[start];
                    }
                }
                if (flag == 0)
                    return i;
            }
        }
        return -1;
    }
};
