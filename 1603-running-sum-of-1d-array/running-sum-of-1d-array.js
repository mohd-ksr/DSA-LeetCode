/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    let sum=0;
    let ans = nums.map((num)=>{
        sum+=num;
        return sum;
    });
    return ans;
};