class Solution {
private:
    unordered_set<string>st;
    bool isPossible(vector<string>ingredients){
        for(auto ing:ingredients){
            if(!st.count(ing))return false;
        }
        return true;
    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n = recipes.size();
        vector<int>made(n,0);
        for(auto sup:supplies){
            this->st.insert(sup);
        }
        while(true){
            bool isChange = false;
            for(int i=0; i<n; i++){
                if(made[i]==1)continue;
                if(isPossible(ingredients[i])){
                    made[i]=1;
                    this->st.insert(recipes[i]);
                    isChange=true;
                }
            }
            if(!isChange)break;
        }
        vector<string>ans;
        for(int i=0; i<n; i++){
            if(made[i]==1){
                ans.push_back(recipes[i]);
            }
        }
        return ans;
    }
};