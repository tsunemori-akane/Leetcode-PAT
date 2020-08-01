var lengthOfLongestSubstring = function(s) {
    var start = 0;
    var max = 0;
    var visitedChar = {};

    for (var pos=0; pos < s.length; pos++) {
        var nextchar = s[pos];
        if (nextchar in visitedChar && visitedChar[nextchar] >= start) {
            start = visitedChar[nextchar] + 1;
            visitedChar[nextchar] = pos;
        } else {
            visitedChar[nextchar] = pos;
            max = Math.max(max, pos + 1 - start);
        }
    }
    return max;
};

console.log(lengthOfLongestSubstring('wgddxff'))