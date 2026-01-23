class Solution {
private:   
    vector<string>ans;
    vector<string>parts;
    void bt(string &s, int ind){
        if(parts.size()==4){
            if(ind==s.size()){
                ans.push_back(parts[0]+"."+parts[1]+"."+parts[2]+"."+parts[3]);
            }
             return;
        }

        int rp = 4 - parts.size();
        int rc = s.size()-ind;

        if(rc<rp || rc>rp*3) return ;

        for(int len = 1; len<=3 && ind+len<=s.size(); len++){
            string part = s.substr(ind, len);

            if(part.size()>1 && part[0]=='0')break;

            int temp = stoi(part);
            if(temp>255)break;

            parts.push_back(part);
            bt(s, ind+len);
            parts.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        bt(s, 0);
        return ans;
    }
};

// Time Complexity O(max(81));
