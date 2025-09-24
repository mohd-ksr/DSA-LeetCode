class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)return "0";
        string ans;
        if((numerator < 0)^(denominator < 0))ans+="-";
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);
        ans+=to_string(n/d);
        long long r = n%d;
        if(r==0)return ans;
        ans+=".";
        unordered_map<long long, int> mapp;
        while(r!=0){
            if(mapp.find(r)!=mapp.end()){
                ans.insert(mapp[r],"(");
                ans+=")";
                break;
            }
            mapp[r]=ans.size();
            r*=10;
            ans+=to_string(r/d);
            r%=d;
        }
        return ans;
    }
};
// Time Complexity O(n)
// Space Complexity O(n)