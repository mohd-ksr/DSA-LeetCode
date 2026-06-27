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
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(auto emp:employees){
            this->imp[emp->id]=emp->importance;
            this->adj[emp->id]=emp->subordinates;
        }
        int ans=0;
        queue<int>q;
        q.push(id);
        while(!q.empty()){
            int node = q.front();q.pop();
            ans+=imp[node];
            for(auto it:adj[node]){
                q.push(it);
            }
        }
        return ans;
    }
};