/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (numRows == 1) return s
    let arr = new Array(numRows).fill("")
    let k = 2*numRows-2
    for (let i=0; i<s.length; i++) {
        if(i%k <= numRows-1 ) arr[i%k] += s[i]
        if(i%k > numRows-1) arr[(2*numRows-2)-i%k] += s[i] 
    }
    res = "".concat(...arr)
    return res
};
const s = "abcdefg", numRows = 3
console.log(convert(s, numRows))

/*
对于n行的, s中的第i个字符：

对余数进行判断

i%(2n-2) == 0 ----> row0

i%(2n-2) == 1 & 2n-2-1 ----> row1

i%(2n-2) == 2 & 2n-2-2 ----> row2

...

i%(2n-2) == n-1 ----> row(n-1)

==>

对 k = i%(2n-2)进行判断

k<=n-1时候，s[i]就属于第k行
k>n-1时候，s[i]就属于2n-2-k行
最后将rows拼接起来就行了
*/ 