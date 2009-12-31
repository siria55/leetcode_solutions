### Solution1 DP

当 k 大于等于总天数的一半时，退化为贪心问题. 和 Best_Time_to_Buy_and_Sell_Stock_II 一样

当 k 小于总天数一半时，和 Best_Time_to_Buy_and_Sell_Stock_III 一样

建立两个数组： buy, sell

buy[j] 表示在第 j 次买入时的最大收益
sell[j] 表示在第 j 次卖出是的最大收益

