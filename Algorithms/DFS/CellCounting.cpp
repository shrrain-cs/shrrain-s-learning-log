/**
 * @file CellCounting.cpp
 * @author shrrain-cs
 * @brief 连通块计数DFS
 * @version 1.0
 * @date 2026-05-17
 *
 * 例题来源：洛谷 P1451 求细胞数量
 * 题目链接：https://www.luogu.com.cn/problem/P1451
 *
 * 算法思路：
 * 1. 遍历矩阵，遇到未被访问过的非零数字（'1'~'9'）时，细胞计数+1。
 * 2. 从该位置启动DFS，向四个方向搜索，把所有属于同一细胞的数字标记为已访问。
 * 3. 搜索时遇到'0'或越界或已访问则停止，不需要回溯——染色后不再撤销。
 * 4. 最终输出计数即为细胞总数。
 */

#include <bits/stdc++.h>    // 竞赛万能头文件
using namespace std;
#define int long long

int n,m;
vector<vector<char>> v(n+1,vector<char>(m+1));  // 给定的矩阵序列
vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));  // 记录访问过的位置，即合法但已经被记为细胞的位置
// 方向数组
vector<int> dx = {0,1,0,-1};
vector<int> dy = {1,0,-1,0};
// 深搜实现同一个细胞区域的标记（不需要回溯！）
void dfs(int x,int y) {
    if (v[x][y] == '0') return; // 搜索到某点不是细胞数字，说明后面都不属于同一个细胞，返回
    vis[x][y] = true;   // 标记搜索的细胞数字
    // 按四个方向搜索
    for (int i = 0 ; i < 4 ; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;   // 防止越界
        if (vis[nx][ny]) continue;  // 去除访问过的情况
        dfs(nx,ny); // 递归调用，继续往下搜索
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    // 设置数组大小
    v.resize(n+1, vector<char>(m+1));
    vis.resize(n+1, vector<bool>(m+1, false));
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> v[i][j];
        }
    }
    int cnt = 0;    // 记录细胞数量
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (vis[i][j] || v[i][j] == '0') continue;  // 不是细胞数字或已经被统计的情况直接跳过
            cnt ++; //一个新的细胞
            dfs(i,j);   // 标记该细胞的所有位置
        }
    }
    cout << cnt;
    return 0;
}
