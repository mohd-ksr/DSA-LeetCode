/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let cand = nums[0];
    let c = 1;
    for(let i=1; i<nums.length; i++){
        if(nums[i]===cand)c++;
        else c--;

        if(c<0){
            cand = nums[i];
            c=1;
        }
    }
    return cand;
};