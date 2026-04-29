/**
* @file MergeFruits.cpp
* @author shrrain-cs
* @brief 贪心 - 哈夫曼树问题
* @version 1.0
* @date 2027-04-29
*
* 例题来源：洛谷 P1090 [NOIP 2004 提高组] 合并果子
* 题目链接：https://www.luogu.com.cn/problem/P1090
*
* 算法思路：
* 1. 贪心策略 : 每次都选择最小的两堆合并，就可以使体力消耗最低
* 2. 用小顶堆优先数列记录堆的重量，每次合并最小两堆，记录体力消耗并将其重新存入优先队列中
**/

#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;

#define int long long

signed main() {
	int n ,num ;
	cin >> n;
	priority_queue <int,vector<int>,greater<int>> pq;	// 优先队列（小顶堆），方便每次合并后得到最小的一堆
	// 将每个果子的堆数存入优先队列
	for (int i = 0 ; i < n ; i++) {
		cin >> num;
		pq.push(num);
	}
	int total = 0;	// 记录最后消耗的体力
	// 总共需要合并n-1次，每次取出最小的两堆
	for (int i = 1 ; i < n ; i++) {
		// 取出最小的两堆
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		// 合并他们并记录体力消耗
		total += a + b ;
		// 将新的堆重新存入优先队列
		pq.push(a + b);
	}
	cout << total;	// 输出消耗的体力
	return 0;
}
