学习笔记

动态规划，名字比较玄乎。英语是dynamic programming。programming在此不是编程的意思，是推理的意思。
动态规划中是分治的升级版本。以分治算法为基础，找到递推规律。一般而言递推会从底向上寻找换句话说就是从底向上逐步递推出子问题的解，然后再根据子问题的解推出更大一点子问题的解，直到更大的子问题就是问题本身。

从小的子问题的解推出稍大子问题的解-->分治思想
一般递推公式会从底向上递推-->动态规划
递推过程要保存下来

因为结果是随着上一个递推出来的结果得出，所以体现了动态性。

另外使用自顶向下+分治+递归+cache也能做到相同的效果。但是没有动态规划自底向上来的巧妙。