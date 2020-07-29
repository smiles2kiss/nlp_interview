class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles;
        // ��֤ÿ����ƿ�ӻ����ľ�
        while (numBottles >= numExchange) {
            int change = numBottles / numExchange;
            count = count + change;
            numBottles = numBottles - change * numExchange;
            numBottles = numBottles + change;
        }
        return count;
    }
};
