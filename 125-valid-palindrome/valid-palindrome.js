/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(str) {
    let s = 0, e = str.length-1;
    while(s<e){
        if(!(str[s]>='a' && str[s]<='z') && !(str[s]>='A' && str[s]<='Z') && !(str[s]>='0' && str[s]<='9')){
            s++;
            continue;
        }
        if(!(str[e]>='a' && str[e]<='z') && !(str[e]>='A' && str[e]<='Z') && !(str[e]>='0' && str[e]<='9')){
            e--;
            continue;
        }
        if(str[s].toLowerCase()!=str[e].toLowerCase())return false;
        s++;
        e--;
    }
    return true;
};