/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let ans = [];
    arr.forEach((num, ind)=>{
        if(fn(num, ind)){
            ans.push(num);
        }
    });
    return ans;
};