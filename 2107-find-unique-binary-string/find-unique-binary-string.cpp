class Solution {
private:
    string toBinary(int num, int n){
        string ans = "";
        while(num){
            ans.push_back('0' + (num&1));
            num>>=1;
        }
        while(ans.size()<n){
            ans.push_back('0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums[0].size();
        int i=0;
        for(; i<nums.size(); i++){
            string x = toBinary(i, n);
            cout<<x<<endl;
            if(x!=nums[i])return x;
        }
        return toBinary(i, n);
    }
};