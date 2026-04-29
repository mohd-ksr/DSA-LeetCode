class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        long long ans=0;
        for(int i=0; i<=n; i++){
            int curr = (i==n?0:heights[i]);
            while(!st.empty() && heights[st.top()]>=curr){
                long long h = heights[st.top()];
                st.pop();

                int r = i;
                int l = st.empty()?-1:st.top();

                long long w = r-l-1;

                ans = max(ans, h*w);
            }
            st.push(i);
        }
        return ans;
    }
};