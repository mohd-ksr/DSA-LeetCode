class Solution {
private:
    int convertToInt(int s, int e, string &str){
        int ans = 0;
        for(int i = s; i <= e; i++){
            ans <<= 1;
            if(str[i] == '1'){
                ans |= 1;
            }
        }
        return ans;
    }

public:
    bool hasAllCodes(string s, int k) {
        if(k > s.size()) return false;

        vector<bool> nums(1 << k, false);

        for(int i = 0; i + k <= s.size(); i++){
            int x = convertToInt(i, i + k - 1, s);
            nums[x] = true;
        }

        for(bool b:nums)if(!b) return false;

        return true;
    }
};