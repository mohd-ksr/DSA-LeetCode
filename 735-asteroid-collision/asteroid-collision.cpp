class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                st.push(nums[i]);
            }
            else{
                bool ok = true;
                while(!st.empty()){
                    if(abs(nums[i])==st.top()){
                        st.pop();
                        ok=false;
                        break;
                    }
                    if(st.top()>0 && abs(nums[i])>st.top()){
                        st.pop();
                    }
                    else{
                        break;
                    }
                }
                if(ok && (st.empty() || st.top()<0))st.push(nums[i]);
            }
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