class Solution {
    public int binaryGap(int n) {
        StringBuilder s = new StringBuilder();
        while(n > 0){
            s.append((char)('0' + (n & 1)));
            n >>= 1;
        }
        int prev = -1;
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '1'){
                if(prev != -1){
                    ans = Math.max(ans, i - prev);
                }
                prev = i;
            }
        }
        return ans;
    }
}