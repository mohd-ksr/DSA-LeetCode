class Solution {
public:
    int countAsterisks(string s) {
        int dandiCount = 0;
        int ans = 0;
        for(auto &ch:s){
            if(ch=='|')dandiCount++;
            if(dandiCount==2)dandiCount=0;
            if(dandiCount==0 && ch=='*')ans++;
        }
        return ans;
    }
};