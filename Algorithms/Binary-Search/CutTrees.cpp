/**
* @file	CutTrees.cpp
 * @author shrrain-cs
 * @brief 二分答案 -在答案区间二分验证
 * @version 1.0
 * @date 2026-05-02
 *
 * 例题来源：洛谷 P1873 [COCI 2011/2012 #5] EKO / 砍树
 * 题目链接：https://www.luogu.com.cn/problem/P1873
 *
 * 算法思路：
 * 1. 二分答案：在答案可能的区间里二分查找最优的砍树高度
 * 2. 设当前高度为 mid，计算在这个高度下能获得的木材总量 h
 * 3. 若 h >= m，说明高度还能更高（木材足够），向右搜索
 * 4. 若 h < m，说明高度太高了（木材不够），向左搜索
 * 5. 二分结束后，r 指向最后一个可行的高度，即为答案
 */

#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;
#define int long long

signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> height(n);  // 每棵树的高度
	int maxH = 0;           // 最高的树高，作为二分上界
	// 读入树高，同时记录最大值作为二分上界
	for (int i = 0; i < n; i++) {
		cin >> height[i];
		maxH = max(maxH, height[i]);
	}
	int l = 0, r = maxH;    // 二分区间：砍树高度从 0 到最高树高
	// 二分查找最优的砍树高度
	while (l <= r) {
		int mid = l + (r - l) / 2;  // 当前猜测的砍树高度
		int h = 0;                  // 当前高度下获得的木材总量
		for (int i = 0; i < n; i++) {
			h += max((int)0, height[i] - mid);
			// 若树高大于当前砍树高度，则获得 height[i] - mid 的木材
		}
		// 判断当前高度是否可行
		if (h >= m) l = mid + 1;    // 木材够，尝试更高
		else r = mid - 1;           // 木材不够，必须降低
	}
	cout << r;  // 由于最后l = r时，符合条件且l+1，故输出r
	return 0;
}
