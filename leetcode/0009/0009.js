var isPalindrome = function(x) {
    if (x < 0) return false
    if (x < 10) return true
    let n = 10 ** Math.floor(Math.log10(x))   
    while (x > 1) {
        if (x%10 != Math.floor(x/n)) return false
        x=Math.floor((x%n)/10)
        n /= 100
    }
    return true
};

console.log((isPalindrome(1234321)))