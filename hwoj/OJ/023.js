/**
 * 金字塔/微商收入
 * 下级每赚 100 就要上交 15
 * 输入的每行有三个数
 * 代理商代号  上级代理商代号 代理商转的钱
 * 输入
 * 1 0 223
 * 2 0 323
 * 3 2 1203
 * 输出
 * 0 105
 * 
 * 首先按照上级代理商代号排序（由大到小）N->0
 * 维持一个数组，下标代表级数，遍历输入的结构体，按照规则计入即可
 */