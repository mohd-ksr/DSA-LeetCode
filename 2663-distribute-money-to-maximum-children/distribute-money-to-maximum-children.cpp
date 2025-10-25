class Solution {
public:
    int distMoney(int money, int children) {
        if(children*8 == money)return children;
        if(children*8 < money)return children-1;
        if(money<children)return -1;

        vector<int>c(children, 1);
        bool isLast = false;
        int remainingMoney = money - children;
        for(int i=0; i<children; i++){
            if(remainingMoney>=7){
                c[i]+=7;
                remainingMoney-=7;
            }
            else{
                c[i]+=remainingMoney;
                if(i==children-1)isLast = true;
                break;
            }
        }
        int ans=0;
        bool isHavingFour = false;
        for(auto ch:c){
            if(ch==8)ans++;
            if(ch==4)isHavingFour=true;
        }
        if(isHavingFour && isLast)ans--;
        return ans;
    }
};