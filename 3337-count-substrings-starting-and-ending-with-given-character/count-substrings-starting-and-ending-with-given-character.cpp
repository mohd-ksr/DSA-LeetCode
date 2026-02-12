class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;
        for(auto &ch:s)if(ch==c)count++;
        if(count%2==0){
            return ((count/2)*(count+1));
        }
        else{
            return (count*((count+1)/2));
        }
    }
};