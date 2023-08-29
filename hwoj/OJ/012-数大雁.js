//
// Created by cal on 2023/6/12.
//
/* 数大雁
 * leetcode 1419
 * 大雁发出完整的叫声“quack”, 多个大雁同时叫，字符串可能混合多个"quack"
 * 5个字母 按照顺序完整存在才能计数为一只大雁，求出叫声（最少）由几只大雁发出
 * 没有找到返回-1
 * 例子1: quackquack 输出1
 * 例子2: quacqkuac 输出1
 */
const readLine = require("readline");
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout,
});
rl.on("line", function (line) {
  
  const str = line;
  const cnt = [0, 0, 0, 0, 0];
  let first = 0;
  let last = 0;
  for (const e of str) {
    const idx = "quack".indexOf(e);
    if (idx > -1) {
      ++cnt[idx];
    }
    if (idx === 0) {
      ++first;
    } else if (cnt[idx] > cnt[idx - 1]) {
      cnt[idx] -= 1;
    } else if (idx === 4) {
      ++last;
    }
  }
  console.log(cnt);
  console.log(Math.min(cnt[0], cnt[4]))
  rl.close();
});

