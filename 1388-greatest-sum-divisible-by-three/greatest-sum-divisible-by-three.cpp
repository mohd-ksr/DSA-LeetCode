class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> modGroup[3];

        for (int num : nums) 
            modGroup[num % 3].push_back(num);

        sort(modGroup[1].begin(), modGroup[1].end(), greater<int>());
        sort(modGroup[2].begin(), modGroup[2].end(), greater<int>());

        int maxSum = 0;
        int size1 = modGroup[1].size(), size2 = modGroup[2].size();

        for (int count1 = size1 - 2; count1 <= size1; ++count1) {
            if (count1 >= 0) {
                for (int count2 = size2 - 2; count2 <= size2; ++count2) {
                    if (count2 >= 0 && (count1 - count2) % 3 == 0) {
                        maxSum = max(
                            maxSum,
                            accumulate(modGroup[1].begin(), modGroup[1].begin() + count1, 0) +
                            accumulate(modGroup[2].begin(), modGroup[2].begin() + count2, 0)
                        );
                    }
                }
            }
        }

        return maxSum + accumulate(modGroup[0].begin(), modGroup[0].end(), 0);
    }
};
// Time Complexity O(nlogn)
// Time complexity O(n)