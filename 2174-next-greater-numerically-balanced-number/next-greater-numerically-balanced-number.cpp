class Solution {
private:
    bool fun(int n){
        vector<int>mapp(10,0);
        while(n){
            mapp[n%10]++;
            n/=10;
        }

        for(int i=0; i<10; i++){
            if(mapp[i]!=0 && mapp[i]!=i)return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
       for(int i=n+1; i<=1224444; i++){
            if(fun(i)){
                return i;
            }
       }
       return 100; 
    }
};