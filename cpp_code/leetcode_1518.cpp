class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles;
        // 保证每次用瓶子换最多的酒
        while (numBottles >= numExchange) {
            int change = numBottles / numExchange;
            count = count + change;
            numBottles = numBottles - change * numExchange;
            numBottles = numBottles + change;
        }
        return count;
    }
};
