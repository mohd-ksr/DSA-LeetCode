class Solution {
private:
    int CD(int n){
        int count = 0;
        int sum = 0;
        for(int i = 1; i*i<=n; i++){
            if(n%i == 0){
                if(i*i!=n){
                    count+=2;
                    sum+=i+(n/i);
                }
                else{
                    count++;
                    sum+=i;
                }
            }
        }
        return (count==4?sum:-1);
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto n:nums){
            int v = CD(n);
            if(v!=-1)sum+=v;
        }
        return sum;
    }
};