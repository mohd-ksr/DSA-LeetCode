class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i=0,j=n-1;
        while(i<n && directions[i]=='L')i++;
        while(j>=0 && directions[j]=='R')j--;
        int ans=0;
        for(int p=i; p<=j; p++){
            if(directions[p]!='S')ans++;
        }
        return ans;
    }
};
// Time complexity O(n)