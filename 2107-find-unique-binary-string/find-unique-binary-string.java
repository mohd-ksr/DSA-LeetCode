class Solution {
    private String toBinary(int num, int n) {
        String ans = Integer.toBinaryString(num);
        while (ans.length() < n) ans = "0" + ans;
        return ans;
    }
    public String findDifferentBinaryString(String[] nums) {
        Arrays.sort(nums);
        int n = nums[0].length();
        int i = 0;
        for (; i < nums.length; i++) {
            String x = toBinary(i, n);
            if (!x.equals(nums[i])) return x;
        }
        return toBinary(i, n);
    }
}