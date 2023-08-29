/**
 * 最小传输时延
 * 有 M * N 的节点矩阵， 每个节点可以向8个方向（上下左右、四个斜角）转发数据包
 * 每个节点转发会消耗固定时延, 每有连续两个相同时延可减少一个时延
 * 例如
 * 输入 第一行 m n
 * 4 4
 * 2 2 2 2
 * 2 2 2 2
 * 2 2 2 2
 * 2 2 2 2
 * 输出 5
 * 斜线连续4个2=8再减去3
 */

const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
})

const iter = rl[Symbol.asyncIterator]()
const readline = async () => (await iter.next()).value

void async function () {
  let matrix = [];
  let [m, n] = (await readline()).split(' ').map(e => parseInt(e));
  console.log(m, n)
  while(m > 0) {
    const line = await readline()
    matrix.push(line.split(' ').map(e => parseInt(e)))
    m--
  }
  console.log(matrix)
  console.log(bfs(matrix))
  rl.close()
}()

/**
 * 构造一个数组a记录a[0][0] 
 * 初始化第一列该列信号仅能从上面传来
 */
function bfs(m) {
  
}