class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> result;

        for(int spell: spells){
            long long minPotion = (success+spell -1)/ spell;

            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            int count = potions.end()- it;
            result.push_back(count);
            }
        return result;
    }
};