/**
 * @param {string} n
 * @return {number}
 */
var minPartitions = function(n) {
    let arr = n.split('');
    let maxi = arr.reduce((prev, curr)=>{
        return prev>curr?prev:curr;
    })
    return maxi - '0';
};