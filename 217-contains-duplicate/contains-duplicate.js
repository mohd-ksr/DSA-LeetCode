/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let arr=[];
    for(let num of nums){
        if(arr[num])return true;
        else arr[num]=true;
    }
    return false;
};