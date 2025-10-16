class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int level=1;
        int r=red;
        int b=blue;
        while(true){
            if(level&1){
                if(r<level)break;
                r-=level;
            }
            else{
                if(b<level)break;
                b-=level;
            }
            level++;
        }
        int ansRed=level-1;
        level=1;
        while(true){
            if(level&1){
                if(blue<level)break;
                blue-=level;
            }
            else{
                if(red<level)break;
                red-=level;
            }
            level++;         
        }
        int ansBlue = level-1;
        return max(ansRed,ansBlue);
    }
};