/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const mapp = new Map();

    for(let i=0; i<nums.length; i++){
        let num = nums[i];
        if(mapp.has(target-num)){
            return [mapp.get(target-num), i];
        }
        mapp.set(num,i);
    }
};