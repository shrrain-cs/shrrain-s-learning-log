/**
* @file EightQueens.cpp
 * @author shrrain-cs
 * @brief 回溯型DFS-八皇后
 * @version 1.0
 * @date 2026-05-09
 *
 * 例题来源：洛谷 P1219 [USACO1.5] 八皇后 Checker Challenge
 * 题目链接：https://www.luogu.com.cn/problem/P1219
 *
 * 算法思路：
 * 1. 用path记录每一行放置皇后的列数，如果path的大小等于n则记录当前路径并返回
 * 2. 如果当前放置位置满足与之前放置的每个皇后的位置都合法，进行回溯试探
 * 3. 将当前状态放入path数组中进行递归搜索，之后回溯状态
 * 4.输出前三个结果与方案数
 */

#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;
#define int long long

// 检查当前位置是否合法
bool check(int col,int row ,vector<int>& path) {
	// 检查每行放置的皇后是否与目标位置相对非法
	for (int r = 1 ; r < row ; r++) {
		int c = path[r-1];	// 第r行皇后的列数
		if (c == col) return false;	//检测在同一列
		if (row - r == abs(col - c)) return false;	//检测在对角线上，即行数差与列数差的绝对值相等
	}
	return true;	// 若上述均合法，则可以放置
}

// 回溯枚举皇后的放置方案
void dfs(int n,vector<int>& path,vector<vector<int>>& res) {
	// 如果每行都放满皇后，记录结果并返回
	if (path.size() == n) {
		res.push_back(path);
		return;
	}
	int idx = path.size() + 1;	// 当前放置皇后的行数 = 已放置的数量 + 1
	// 回溯试探，在第idx行，第i列放置皇后
	for (int i = 1 ; i <= n ; i++) {
		if (check(i,idx,path)) {
			path.push_back(i);	// 将列数存储
			dfs(n,path,res);	//递归调用，向下搜索分支
			path.pop_back(); // 回溯，清除刚刚放置的列数
		}
	}
}

signed main() {
	int n;
	cin >> n;
	vector<int> path;	// 记录已经放到棋盘上的皇后的列数
	vector<vector<int>> res;	// 记录最终结果
	dfs(n,path,res);
	// 输出前三种方案
	for (int i = 0 ; i < 3; i++) {
		for (int j = 0 ; j < n ; j++) {
			cout << res[i][j] <<" ";
		}
		cout <<"\n";
	}
	// 输出方案数
	cout << res.size();
	return 0;
}
