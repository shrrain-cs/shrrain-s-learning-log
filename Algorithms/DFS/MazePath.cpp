/**
* @file MazePath.cpp
 * @author shrrain-cs
 * @brief 回溯型DFS —— 二维网格路径搜索
 * @version 1.0
 * @date 2026-05-14
 *
 * 例题来源：洛谷 P1605 迷宫
 * 题目链接：https://www.luogu.com.cn/problem/P1605
 *
 * 算法思路：
 * 1.使用方向数组按顺序在二维网格上搜索。
 * 2.进入每个格子时立刻标记为已访问，防止走回头路。
 * 3.到达终点时存储当前路径；探索时存入要探索点的坐标，探索完四个方向后回溯，恢复访问状态，弹出之前存入的坐标。
 * 4.DFS结束判断是否有符合要求的路径，按要求输出。
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

int m,n,sx,sy,ex,ey;	// 定义，长，宽，起点，终点
// 按题意“左上右下”的顺序定义方向数组
vector<int> dx= {0,-1,0,1};
vector<int> dy= {-1,0,1,0};
vector<vector<pair<int,int>>> res;	// 最终结果
// 深搜，传入搜索点的坐标，障碍，已经访问过的点的位置，以及当前经过的路径
void dfs(vector<vector<int>>& v,vector<vector<bool>>& vis,vector<pair<int,int>>& path,int x,int y) {
	// 如果到达终点，把路径存入结果并返回
	if (x == ex && y == ey) {
		res.push_back(path);
		return;
	}
	// 标记当前点已经访问过，向下搜索
	vis[x][y] = true;
	// 按顺序分别搜索四个方向
	for (int i = 0 ; i  < 4 ; i++) {
		// 下一个节点的坐标
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || nx > m || ny <=0 || ny > n ) continue;	// 排除出界情况
		if (!v[nx][ny] || vis[nx][ny]) continue;	// 不能访问障碍和走过的地方
		path.emplace_back(nx,ny);	// 将下一个节点的坐标存入路径
		dfs(v,vis,path,nx,ny);
		path.pop_back();	// 回溯，取消当前状态
	}
	vis[x][y] = false;	// 回溯探索状态
}
signed main() {
    cin >> m >> n;
	vector<vector<int>> v(m+1,vector<int>(n+1));	// 障碍数组
	vector<vector<bool>> vis(m+1,vector<bool>(n+1,false));	// 记录访问过的位置
	vector<pair<int,int>> path;	// 记录当前的路径（不包括起点）
	// 存入障碍物坐标
	for (int i = 1 ; i  <= m ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> v[i][j];
		}
	}
	cin >> sx >> sy >> ex >> ey;
	dfs(v,vis,path,sx,sy);
	if (res.empty())
		cout <<-1;	// 如果没有实现路径，输出-1
	else {
		// 否则输出路径坐标
		for (int i = 0 ; i < res.size(); i++) {
			cout <<"("<<sx<<","<<sy <<")";	// 先输入起点坐标
			for (int j = 0 ; j < res[i].size(); j++) {
				cout<<"->"<<"("<<res[i][j].first<<","<<res[i][j].second <<")";
			}
			cout <<"\n";
		}
	}
	return 0;
}
