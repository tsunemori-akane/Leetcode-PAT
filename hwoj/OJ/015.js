/**
 * 一排座位由数组表示，此数组由0和1组成，0表示空位，1表示有人坐
 * 要求1的左右必须保证有一个空位，问这排座位还能座几个人
 * The seating arrangement is represented by an array where 0 indicates an empty seat
 * and 1 indicates a filled seat. It is required that there must be at least one empty seat 
 * on the left and right side of a filled seat. The question is, how many more people canbe seated in this row of seats
 * 例如输入 0 1 0 0 0 1 0 0 输出2
 */
const readLine = require("readline");
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", function (line) {
  const arr = line.split(" ").map(e => Number(e));
  let count = 0;
  for(let i =0; i < arr.length; i++) {
    if(arr[i] === 0) {
      if((i === 0 || arr[i - 1]) && (i === arr.length-1 || arr[i + 1] === 0)) {
        count ++ ;
        i++;
      }
    }
  }
  console.log(count);
  rl.close();
})