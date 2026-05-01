/**
* @file FindFirst.cpp
 * @author shrrain-cs
 * @brief 二分查找 —— 查找指定值第一次出现的位置
 * @version 1.0
 * @date 2026-05-01
 *
 * 例题来源：洛谷 P2249 【深基13.例1】查找
 * 题目链接：https://www.luogu.com.cn/problem/P2249
 *
 * 算法思路：
 * 1. 数组已按单调不减顺序排列，要求查找指定值第一次出现的位置。
 * 2. 使用二分查找的“最左边界”模板。
 * 3. 当找到目标值时，不直接返回，而是继续向左搜索，收缩右边界。
 * 4. 最终 result 记录的就是第一次出现的位置（从 1 开始编号）。
 */

#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);	// 加快IO速度
	int n, m;
	cin >> n >> m;
	vector<int> a(n);       // 存储有序数组
	vector<int> q(m);       // 存储待查询的数字
	// 输入有序数组
	for (int i = 0; i < n; i++) cin >> a[i];
	// 输入查询列表
	for (int i = 0; i < m; i++) cin >> q[i];
	// 对每个查询进行二分查找
	for (int i = 0; i < m; i++) {
		int l = 0, r = n - 1;   // 搜索区间 [l, r]
		int result = -1;        // 记录答案，-1 表示未找到
		while (l <= r) {
			int mid = l + (r - l) / 2;  // 防溢出写法
			if (a[mid] == q[i]) {
				result = mid + 1;   // 记录当前位置（从1开始编号）
				r = mid - 1;        // 继续向左搜索，寻找更早出现的位置
			} else if (a[mid] > q[i]) {
				r = mid - 1;        // 目标在左侧，收缩右边界
			} else {
				l = mid + 1;        // 目标在右侧，收缩左边界
			}
		}
		cout << result << " ";
	}
	return 0;
}
