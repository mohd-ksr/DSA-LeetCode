/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    let ans = 0;
    for(let num of nums){
        ans+=((num.toString().length)%2===0);
    }
    return ans;
};