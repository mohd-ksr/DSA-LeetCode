class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mapp;
        for(int num:nums){
            int r = ((num%value)+value)%value;
            mapp[r]++;
        }

        int mex=0;
        while(1){
            int r = mex%value;
            if(mapp[r]>0){
                mapp[r]--;
                mex++;
            }
            else return mex;
        }
        return 0; //dummy
    }
};