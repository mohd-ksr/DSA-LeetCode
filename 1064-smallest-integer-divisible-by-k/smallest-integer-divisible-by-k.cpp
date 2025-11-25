class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1)return 1;
        if(k%2==0 || k%5==0)return -1;
        int n=1;
        int ans = 1;
        unordered_set<int>s;
        while(true){
            ans++;
            n = (n*10+1)%k;
            if(n%k==0)return ans;
            if(s.find(n%k)==s.end())s.insert(n%k);
            else return -1;
        }
        return -1;
    }
};
// Time Complexity O(K)