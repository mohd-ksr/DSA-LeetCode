/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    nums1.sort((a,b)=>a-b);
    nums2.sort((a,b)=>a-b);
    let k = 0, i=0, j=0;
    let ans = [];
    
    while(i<nums1.length && j<nums2.length){
        while((i+1<nums1.length )&& nums1[i]===nums1[i+1])i++;
        while((j+1<nums2.length) && nums2[j]===nums2[j+1])j++;
        if(nums1[i]==nums2[j]){
            ans[k]= nums1[i];
            k++;
            i++;
            j++;
        }
        else if(nums1[i]>nums2[j])j++;
        else i++;
    }
    return ans;
};