var reverse = function(x) {
    let result = 0;
    let value = Math.abs(x);
    let MIN_VALUE = - Math.pow(2,31);
    let MAX_VALUE = Math.pow(2,31) - 1;
    while (value !== 0) {
        let pop = value % 10;
        // 溢出判断
        if (result > MAX_VALUE / 10 || (result === MAX_VALUE / 10) && pop > 7) return 0;
        if (result < MIN_VALUE / 10 || (result === MIN_VALUE && pop < -8)) return 0;
        result = result * 10 + pop;
        value = Math.floor(value / 10);
    }
    return (x >= 0 ? result : - result);
};
/*
**author:leviding
**https://leetcode-cn.com/problems/reverse-integer/solution/7-zheng-shu-fan-zhuan-javascript-de-liang-chong-ji/
*/