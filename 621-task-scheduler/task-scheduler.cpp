class Solution {
private:
    int max(int a, int b){
        return a>b?a:b;
    }
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>t(26,0);
        for(char ch:tasks){
            t[ch-'A']++;
        }
        sort(t.begin(), t.end());
        int countMax = 1;
        for(int i=24; i>=0; i--){
            if(t[i]==t[i+1])countMax++;
            else break;
        }
        return max(tasks.size(), (t[25]-1)*(n+1)+countMax);
    }
};