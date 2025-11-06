class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>>adjList(c+1);
        for(auto &p:connections){
            adjList[p[0]].push_back(p[1]);
            adjList[p[1]].push_back(p[0]);
        }

        vector<int>comp(c+1, -1);
        int comp_id = 0;
        for(int i=1; i<=c; i++){
            if(comp[i]==-1){
                queue<int>q;
                q.push(i);
                comp[i] = comp_id;
                while(!q.empty()){
                    int u = q.front(); q.pop();
                    for(int v: adjList[u]){
                        if(comp[v]==-1){
                            comp[v]=comp_id;
                            q.push(v);
                        }
                    }
                }
                comp_id++;
            }
        }

        vector<set<int>>online(comp_id);
        for(int i=1; i<=c; i++){
            online[comp[i]].insert(i);
        }

        vector<int> ans;

        for(auto &q: queries){
            int type = q[0], x = q[1];
            int cid = comp[x];

            if(type==1){
                if(online[cid].count(x)){
                    ans.push_back(x);
                }
                else if(!online[cid].empty()){
                    ans.push_back(*online[cid].begin());
                }
                else ans.push_back(-1);
            }
            else{
                online[cid].erase(x);
            }
        }
        return ans;

    }
};
// Time Complexity O(c+len(queries))