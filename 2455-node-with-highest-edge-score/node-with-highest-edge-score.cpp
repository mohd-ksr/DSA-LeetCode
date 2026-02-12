class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int, long long>mapp;
        for(int i=0; i<edges.size(); i++){
            mapp[edges[i]]+=i;
        }
        long long maxi = LLONG_MIN;
        int ind=-1;
        for(auto &it:mapp){
            if(it.second>maxi){maxi=it.second; ind=it.first;}
        }
        return ind;
    }
};