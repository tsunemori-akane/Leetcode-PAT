/**
 * leetcode 20 判断有效括号 并且算出最大嵌套深度
 * 例如：([]{()})
 * 输出 3
 * )]
 * 输出 0
 * 利用栈，符号匹配则出栈，栈中的最大括号数量即为最大嵌套深度
 */

const readLine = require("readline");
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const arr = [];

rl.on("line", function (line) {

})