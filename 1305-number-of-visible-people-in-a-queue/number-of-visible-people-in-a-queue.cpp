class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            int count = 0;
            while(!st.empty() && st.top()<=heights[i]){
                count++;
                st.pop();
            }
            if(!st.empty())count++;
            ans[i] = count;
            st.push(heights[i]);
        }
        return ans;
    }
};