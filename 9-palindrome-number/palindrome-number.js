/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x<0)return false;
    let str = x.toString();
    let s = 0, e = str.length - 1;
    while(s<e){
        if(str[s]!=str[e])return false;
        s++;
        e--;
    }
    return true;
};