/**
* @file Difference.cpp
 * @author shrrain-cs
 * @brief 一维差分
 * @version 1.0
 * @date 2026-05-04
 *
 * 例题来源：洛谷 P2367 语文成绩
 * 题目链接：https://www.luogu.com.cn/problem/P2367
 *
 * 算法思路：
 * 1. 构建差分数组diff其中diff[i] = v[i] - v[i-1]（diff[1] = v[1]）。
 * 2. 对于每次区间修改[l,r] 加上 s，只需 diff[l] += s，diff[r+1] -= s。
 * 3. 所有修改完成后，对差分数组求前缀和，还原出最终的成绩数组ans。
 * 4. 遍历ans找到最小值输出。
 * 5. 区间修改O(1)最终还原O(n)，适用于大量区间修改后查询的场景。
 */

#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;
#define int long long

signed main() {
	int n, p;
	cin >> n >> p;
	vector<int> v(n + 2, 0), diff(n + 2, 0), ans(n + 2, 0);  // 原数组、差分数组、答案数组，多开一位防止 r+1 越界
	// 输入初始成绩，下标1-n
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	// 构建差分数组：diff[i] = v[i] - v[i-1]
	diff[1] = v[1];  // 第一个位置的差分值 = 第一个原数值
	for (int i = 2; i <= n; i++) {
		diff[i] = v[i] - v[i - 1];  // 差分数组的第i项 = 原数组第i项 - 原数组第i-1项
	}
	int l, r, s;
	while (p--) {
		cin >> l >> r >> s;
		// 差分核心操作：区间[l,r]加 s，只需修改两个端点
		diff[l] += s;      // 左端点加s表示从l开始所有元素加s
		diff[r + 1] -= s;  // 右端点后一个位置减s表示从r+1开始恢复原值
	}
	// 对差分数组求前缀和，还原最终的分数
	for (int i = 1; i <= n; i++) {
		ans[i] = ans[i - 1] + diff[i];  // 前i个差分值的和 = 第i个学生的最终成绩
	}
	// 找到最低分
	int minn = 100;  // 初始化分数的最大值
	for (int i = 1; i <= n; i++) {
		minn = min(minn, ans[i]);
	}
	cout << minn;
	return 0;
}
