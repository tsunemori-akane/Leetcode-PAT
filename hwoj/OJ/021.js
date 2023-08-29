/**
 * 有若干个文件，大小都是整数MB, 都不超过500MB，不能分割分卷
 * 使用光盘备份。每张光盘容量固定500MB, 求使用光盘最少的文件分布方式
 * 输入 100 500 300 200 400
 * 输出 3
 */

const rl = require("readline").createInterface({
  input : process.stdin,
  output : process.stdout
})

let iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void  async function() {
  const files = (await readline()).split(" ").map(e => Number(e));
  console.log(files);
  files.sort((a, b) => b -a);
  let occupied = []
  for(let i = 0; i < files.length; i++) {
    let needNew = true

    for(let j = 0; j < occupied.length; j ++) {
      if(500 - occupied[j] >= files[i]) {
        occupied[j] = occupied[j] + files[i];
        needNew = false
        break;
      }
    }

    if(needNew) {
      occupied.push(files[i])
    }
  }
  console.log(occupied)
  rl.close()
}()