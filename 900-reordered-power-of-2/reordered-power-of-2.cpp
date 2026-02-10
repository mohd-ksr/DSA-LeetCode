class Solution {
public:
    bool reorderedPowerOf2(int n) {
    //    string s = to_string(n);
    //    sort(s.begin(), s.end());
    //    do{
    //     if(s[0]=='0')continue;
    //     int k = stoi(s);
    //     if(((k)&(k-1))==0)return true;
    //    }while(next_permutation(s.begin(), s.end()));

    //    return false;

        unordered_set<string>st;
        int curr = 1;
        while(curr<=1e9+7){
            string s = to_string(curr);
            sort(s.begin(), s.end());
            st.insert(s);
            curr<<=1;
        }
        string s = to_string(n);
        sort(s.begin(), s.end());
        return st.count(s);
    }
};