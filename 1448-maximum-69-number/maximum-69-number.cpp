class Solution {
public:
    int maximum69Number (int num) {
        string temp=to_string(num);
        for(char &n:temp){
            if(n=='6'){
                n='9';
                break;
            }
        }
        return stoi(temp);
    }
};
// Time Coplexity O(n)
// Space Coplexity O(n)