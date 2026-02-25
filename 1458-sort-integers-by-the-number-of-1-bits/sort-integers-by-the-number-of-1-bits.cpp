class Solution {
private:
    int countBits(int n){
        int c=0;
        while(n!=0){
            n&=(n-1);
            c++;
        }
        return c;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int &a:arr){
            pq.push({countBits(a), a});
        }
        int i=0;
        while(!pq.empty()){
            arr[i++]=pq.top().second;
            pq.pop();
        }

        return arr;
    }
};