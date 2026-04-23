class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int>st;
        int num = 0;
        int sum = 0;
        while(st.size()!=n){
            num++;
            if(st.count(k-num))continue;
            sum+=num;
            st.insert(num);
        }
        return sum;
    }
};