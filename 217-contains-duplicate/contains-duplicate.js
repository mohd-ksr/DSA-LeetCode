/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let mapp = new Map();
    for(let num of nums){
        if(mapp.has(num)){
            mapp.set(num, mapp.get(num)+1);
        }
        else{
            mapp.set(num, 1);
        }
    }

    for(const [key, val] of mapp){
        if(val>1)return true;
    }
    return false;
};