/**
* @file	Maze.cpp
 * @author shrrain-cs
 * @brief 回溯型DFS——二维网格路径计数
 * @version 1.0
 * @date 2026-05-13
 *
 * 例题来源：洛谷 P1605 迷宫
 * 题目链接：https://www.luogu.com.cn/problem/P1605
 *
 * 算法思路：
 * 1.使用方向数组在二维网格上搜索。
 * 2.进入每个格子时立刻标记为已访问，防止走回头路。
 * 3.到达终点时计数；探索完四个方向后回溯，恢复访问状态。
 * 4.DFS结束后统计从起点到终点的路径总数。
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,t;	// 长，宽，障碍数
int sx,sy,ex,ey;	// 起点与终点的坐标
int cnt = 0;	// 方案数
// 方向数组
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
// 深搜，传入搜索点的坐标，障碍和已经访问过的点的位置
void dfs(int x,int y,vector<vector<int>>& v,vector<vector<bool>>& vis) {
	// 如果到达终点，记录方案数并返回
	if (x == ex && y == ey) {
		cnt ++;
		return;
	}
	// 标记当前点已经访问过，向下搜索
	vis[x][y] = true;
	// 分别搜索四个位置
	for (int i = 0 ; i < 4 ;i++) {
		// 下一个节点的坐标
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m) continue;	// 排除出界情况
		if (v[nx][ny]) continue;	// 不能访问障碍
		if (vis[nx][ny]) continue;	//不能访问走过的地方
		dfs(nx,ny,v,vis);	// 递归探索
	}
	vis[x][y] = false;	// 回溯探索状态
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> m >> t;
	vector<vector<int>> v(n+1,vector<int>(m+1,0));	// 障碍数组
	vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));	// 记录访问过的位置
	cin >> sx >> sy >> ex >> ey;
	int x,y;
	// 标记障碍物
	while (t--) {
		cin >> x >> y;
		v[x][y] = 1;
	}
	dfs(sx,sy,v,vis);
	cout << cnt;
	return 0;
}
