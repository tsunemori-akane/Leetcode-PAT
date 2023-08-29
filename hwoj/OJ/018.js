/**
 * 扑克牌由小到大 顺序 3，4，5，6，7，8，9，10，J，Q，K，A，2
 * 玩家出的扑克牌阵型：单张，对子，顺子，飞机， 炸弹
 * 顺子出牌规则：由至少5张由小到大连续递增的扑克牌组成，且不包含2 （JQKA2、34568不是顺子）
 * 给定一个13张牌的牌组，由上述13种不同的牌组合而成， 输出满足规则的所有顺子
 * 例子： 2 9 J 2 3 4 K A 7 9 A 5 6
 * 输出 3 4 5 6 7
 * 
 */

const { cursorTo } = require("readline");

const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

let iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void async function() {
  const valid  = ["3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"]
  const cards = (await readline()).split(" ")
  cards.sort((a, b) => valid.indexOf(a) - valid.indexOf(b))
  const _cards = new Set(cards)
  // 双指针
}()