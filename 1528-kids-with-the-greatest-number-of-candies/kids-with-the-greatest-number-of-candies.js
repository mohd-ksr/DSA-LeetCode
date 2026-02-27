/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    let maxi = candies.reduce((prev, curr)=>{
        return prev > curr ? prev : curr;
    })

    let ans = candies.map((num)=>{
        return (num+extraCandies)>=maxi;
    })

    return ans;
};