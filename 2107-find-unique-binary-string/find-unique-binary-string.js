var findDifferentBinaryString = function(nums) {
    nums.sort();
    const n = nums[0].length;
    for (let i = 0; i <= nums.length; i++) {
        const x = i.toString(2).padStart(n, '0');
        if (i === nums.length || x !== nums[i]) return x;
    }
};