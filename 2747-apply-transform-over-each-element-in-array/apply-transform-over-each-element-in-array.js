/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let ans = [];
    arr.forEach((val, ind)=>{
        ans[ind]=fn(val,ind);
    })
    return ans;
};