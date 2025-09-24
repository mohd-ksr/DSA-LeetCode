class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0,e=height.size()-1;
        int ans=0;
        while(s<=e){
            int temp=min(height[s],height[e])*(e-s);
            ans=max(ans,temp);
            if(height[s]<height[e]){
                s++;
            }
            else{
                e--;
            }
        }
        return ans;
    }
};
// Time Complexity O(n)
// Space Complexity O(1)