class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string key = "";
        while(num1 && num2 && num3){
            key = to_string(min({num1%10, num2%10, num3%10})) + key;
            num1/=10;
            num2/=10;
            num3/=10;
        }
        return stoi(key);
    }
};