class Solution {
private:
    bool notContains0(int n){
        while(n){
            if(n%10==0)return false;
            n/=10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<=n; i++){
            int f = i, s = n-i;
            if(notContains0(f) && notContains0(s)) return {f,s};
        }
        return {}; //dummy  
    }
};
// Time complexity O(nlog10(n))