class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int l_count = 0;
        int r_count = 0;
        for(auto ch:moves){
            if(ch=='L')l_count++;
            if(ch=='R')r_count++;
        }
        int count__ = n-l_count-r_count;
        if(l_count>=r_count){
            l_count+=count__;
        }else{
            r_count+=count__;
        }
        return abs(l_count-r_count);
    }
};