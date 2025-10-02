class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrunk = numBottles;  
        int empty = numBottles;

        while (empty >= numExchange) {
            empty -= numExchange;
            numExchange++;  
            empty += 1;
            totalDrunk += 1;
        }
        return totalDrunk;
    }
};
// Time Complexity O(n)