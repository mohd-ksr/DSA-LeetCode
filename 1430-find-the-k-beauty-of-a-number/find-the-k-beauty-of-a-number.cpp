class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int l=0, ans=0;
        string str = to_string(num);
        while(l<=(str.size()-k)){
            int div = stoi(str.substr(l,k));
            if(div!=0 && num%div==0)ans++;
            l++;
        }
        return ans;
    }
};
