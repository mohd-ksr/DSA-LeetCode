class Solution {
private:
    bool isValid(string a, string b){
        int count = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i]!=b[i])count++;
            if(count>2)return false;
        }
        return true;
    }

public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(auto q:queries){
            for(auto dic_word:dictionary){
                if(isValid(q, dic_word)){
                    cout<<dic_word<<" ";
                    ans.push_back(q);
                    break;
                }
            }
        }

        return ans;
    }
};