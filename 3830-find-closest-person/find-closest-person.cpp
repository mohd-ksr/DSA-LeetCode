class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(x-z)<abs(y-z)?1:abs(x-z)==abs(y-z)?0:2;
    }
};
// Time Complexity O(1)
// Space Complexity O(1)