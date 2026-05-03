/**
* @file PrefixSum.cpp
 * @author shrrain-cs
 * @brief 一维前缀和
 * @version 1.0
 * @date 2026-05-03
 *
 * 例题来源：洛谷 P8218 【深进1.例1】求区间和
 * 题目链接：https://www.luogu.com.cn/problem/P8218
 *
 * 算法思路：
 * 1. 构建前缀和数组 sum，其中 sum[i] 表示前 i 个数的和。
 * 2. 对于任意区间 [l, r]，区间和 = sum[r] - sum[l-1]。
 * 3. 预处理 O(n)，每次查询 O(1)，适用于大量区间查询的场景。
 */

#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;
#define int long long

signed main (){
    int n,m;
	cin >> n;
	vector <int> v(n+1),sum(n+1);	// 定义记录数组和前缀和数组，由于下标范围是1到n，故开到n+1
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}
	sum[0] = 0;	// 初始化sum[0]为0，方便计算区间和
	sum[1] = v[1];	// 前1个数的和 = 第1个数
	for (int i = 2; i <=n ;i++) {
		sum[i] = sum[i - 1] + v[i];	// 前n个数的和(n >= 2) = 前n-1个数的和 + 第n个数
	}
	cin >> m;
	int l,r;	// 定义左右区间
	while (m--) {
		cin >> l >> r;
		cout << sum[r] - sum[l-1] << "\n";	// 第l个数到第r个数的和 = 前r个数 - 前l-1个数
	}
	return 0;
}
