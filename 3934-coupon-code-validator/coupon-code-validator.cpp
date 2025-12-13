class Solution {
private:
    bool isCodeValid(string str){
        if(str.empty())return false;
        for(char &ch:str){
            if((ch>= 'a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') || (ch=='_'))continue;
            else return false;
        }
        return true;
    }
    bool isValidBusinessLine(string str){
        if(str=="electronics" || str=="grocery" || str=="pharmacy" || str=="restaurant")return true;
        return false;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string,vector<string>>mapp;
        int n = code.size();
        for(int i=0; i<n; i++){
            if(!isCodeValid(code[i]))continue;
            if(!isValidBusinessLine(businessLine[i]))continue;
            if(!isActive[i])continue;
            mapp[businessLine[i]].push_back(code[i]);
        }
        for(auto &it:mapp){
            sort(it.second.begin(), it.second.end());
        }
        vector<string>ans;
        for(auto v:mapp["electronics"])ans.push_back(v);
        for(auto v:mapp["grocery"])ans.push_back(v);
        for(auto v:mapp["pharmacy"])ans.push_back(v);
        for(auto v:mapp["restaurant"])ans.push_back(v);
        return ans;
    }
};