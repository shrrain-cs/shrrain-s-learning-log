/**
* @file PartialKnapsack.cpp
 * @author shrrain-cs
 * @brief 贪心算法 —— 部分背包问题
 * @version 1.0
 * @date 2026-04-28
 *
 * 例题来源：洛谷 P2240 【深基12.例1】部分背包问题
 * 题目链接：https://www.luogu.com.cn/problem/P2240
 *
 * 算法思路：
 * 1. 贪心策略：要使金币价值最高，就应该优先拿单位质量价值高的金币堆
 * 2. 按照单位质量金币价值排序，随后按照从大到小拿取金币，直至剩余容量小于金币堆的质量
 * 3. 每次拿取金币时记录当前背包中金币的价值
 */

#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;
#define int long long

// 记录每堆金币的质量和总价值
struct coin {
	double m;  // 开double方便计算单位质量的价值
	double v;
};

// 按单位质量金币价值排序（交叉相乘，避免浮点精度）
bool cmp(coin c1, coin c2) {
	return c1.v * c2.m > c2.v * c1.m;
}

signed main() {
	int n, t;
	double ans = 0;  // 记录最终金币价值
	cin >> n >> t;
	vector<coin> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].m >> v[i].v;
	}
	sort(v.begin(), v.end(), cmp);  // 按贪心策略排序
	// 从大到小拿取金币，直至剩余容量小于金币堆的质量
	for (int i = 0; i < n; i++) {
		if (t <= v[i].m) {
			ans += v[i].v / v[i].m * t;  // 还能取走的金币价值 = 单位质量的金币价值 * 背包剩余空间
			break;
		}
		// 能装下则全部取走
		ans += v[i].v;
		t -= v[i].m;
	}
	cout << fixed << setprecision(2) << ans;  // 输出结果
	return 0;
}
