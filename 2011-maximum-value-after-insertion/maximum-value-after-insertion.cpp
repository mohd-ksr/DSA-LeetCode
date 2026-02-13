class Solution {
private:
    string makeSmallest(string n, int x){
        int ind = -1;
        for(int i=0; i<n.size(); i++){
            if((n[i]-'0')>x){
                ind = i;
                break;
            }
        }
        if(ind==-1){
            return n+to_string(x);
        }
        n.insert(ind, to_string(x));
        return n;
    }
    string makeBiggest(string n, int x){
        int ind = -1;
        for(int i=0; i<n.size(); i++){
            if((n[i]-'0')<x){
                ind = i;
                break;
            }
        }
        if(ind==-1){
            return n+to_string(x);
        }
        n.insert(ind, to_string(x));
        return n;
    }
public:
    string maxValue(string n, int x) {
        bool isNeg = false;
        if(n[0]=='-'){
            n=n.substr(1);
            isNeg=true;
        }
        if(isNeg){
            n = makeSmallest(n, x);
            n = "-"+n;
        }
        else{
            n = makeBiggest(n, x);
        }

        return n;
    }
};