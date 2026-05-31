class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for(auto ast:asteroids){
            if(ast>m)return false;
            m+=ast;
        }
        return true;
    }
};