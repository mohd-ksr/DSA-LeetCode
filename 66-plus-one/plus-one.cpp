class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for(int i=0; i<digits.size(); i++){
            int num = digits[i];
            digits[i] = (num + carry)%10;
            carry = (num+carry)/10;
            if(carry==0)break;
        }
        if(carry==1)digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};