class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string>ver1,ver2;
        string part;
        stringstream ss1(version1);
        while (getline(ss1, part, '.')) {
            ver1.push_back(part);
        }
        stringstream ss2(version2);
        while (getline(ss2, part, '.')) {
            ver2.push_back(part);
        }
        int n = ver1.size(), m = ver2.size();
        for(int i=0; i<n || i<m; i++){
            if(i>=n){
                if(stoi(ver2[i])>0)return -1;
            }
            else if(i>=m){
                if(stoi(ver1[i])>0)return 1;
            }
            else if(stoi(ver2[i])>stoi(ver1[i]))return -1;
            else if(stoi(ver2[i])<stoi(ver1[i]))return 1;
        }
        return 0;
    }
};
// Time complexity O(max(n,m))
// Time complexity O(n+m)