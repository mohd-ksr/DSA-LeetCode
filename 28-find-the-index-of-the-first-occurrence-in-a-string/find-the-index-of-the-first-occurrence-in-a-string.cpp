class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle)!=string::npos){
            return haystack.find(needle);
        }
        else return-1;
    }
};
// Time Complexity O((n - m + 1) * m) ≈ O(n * m)
// Space Complexity O(1)