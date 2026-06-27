/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    unordered_map<int, int>imp;
    unordered_map<int, vector<int>>adj;
    int dfs(int node){
        if(adj[node].empty())return imp[node];
        int childsImp = 0;
        for(auto it:adj[node]){
            childsImp+=dfs(it);
        } 
        return imp[node]+childsImp;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(auto emp:employees){
            this->imp[emp->id]=emp->importance;
            this->adj[emp->id]=emp->subordinates;
        }
        return dfs(id);
        // int ans=0;
        // queue<int>q;
        // q.push(id);
        // while(!q.empty()){
        //     int node = q.front();q.pop();
        //     ans+=imp[node];
        //     for(auto it:adj[node]){
        //         q.push(it);
        //     }
        // }
        // return ans;
    }
};