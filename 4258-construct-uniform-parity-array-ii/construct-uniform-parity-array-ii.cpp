class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd=true, even=true;
        int smallestOdd = INT_MAX;
        for(auto num:nums1){
            if(num%2==1 && num<smallestOdd){
                smallestOdd=num;
            }
        }
        //construct with odd
        for(auto num:nums1){
            if(num%2==1 || num-smallestOdd>=1)continue;
            odd=false;
            break;
        }
        //construct with even 
        for(auto num:nums1){
            if(num%2==0 || num-smallestOdd>=1)continue;
            even=false;
            break;
        }
        return odd||even;
    }
};