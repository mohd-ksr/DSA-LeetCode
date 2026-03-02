class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>trailngZeros(n);
        for(int i=0; i<n; i++){
            int count  = 0;
            for(int j=n-1; j>=0; j--){
                if(grid[i][j]==0)count++;
                else break;
            }
            trailngZeros[i]=count;
        }

        int count  = 0;
        for(int i=0; i<n; i++){
            int need = n-i-1;
            int j=i;
            while(j<n && trailngZeros[j]<need){
                j++;
            }
            if(j==n)return -1;

            while(j>i){
                swap(trailngZeros[j], trailngZeros[j-1]);
                j--;
                count++;
            }
        }
        return count;
    }
};