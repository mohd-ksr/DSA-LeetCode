class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto ast:asteroids){
            bool servived = true;
            while(servived && ast<0 && !st.empty() && st.top()>0){
                if(st.top() < -ast){
                    st.pop();
                }
                else if(st.top()==-ast){
                    st.pop();
                    servived=false;
                }
                else{
                    servived=false;
                }
                if(!servived)break;
            }
            if(servived)st.push(ast);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};