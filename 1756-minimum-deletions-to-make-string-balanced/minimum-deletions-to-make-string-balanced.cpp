class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int>A(n,0), B(n, 0);
        int a=0, b=0;
        for(int i=0; i<n; i++){
            B[i]=b;
            A[n-i-1]=a;
            if(s[i]=='b')b++;
            if(s[n-i-1]=='a')a++;

        }

        int ans = n;
        for(int i=0; i<n; i++){
            ans = min(ans, A[i]+B[i]);
        }

        return ans;
    }
};