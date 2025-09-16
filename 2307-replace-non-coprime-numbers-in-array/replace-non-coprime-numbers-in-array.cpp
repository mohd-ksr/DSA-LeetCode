class Solution {
private:
    int gcd(int a, int b) {
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        for(int a:nums){
            while(!st.empty() && gcd(a,st.top())>1){
                int b = st.top();
                st.pop();
                int g = gcd(a,b);
                a = (a/g)*b;
            }
            st.push(a);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// Time complexity O(n)