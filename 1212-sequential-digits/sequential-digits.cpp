class Solution {
private:
    vector<int>ans;
    int low,high;
    void backtrack(long long n){
        if(n>high)return;
        if(n>10 && n>=low && n<=high){
            ans.push_back(n);
        }
        if(n%10 == 9)return;
        int d = n%10;
        backtrack(n*10 + (d+1));
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        this->low = low;
        this->high = high;
        for(long long i=1; i<9; i++){
            backtrack(i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};