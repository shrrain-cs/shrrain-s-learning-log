/**
 * @file FillColor.cpp
 * @author shrrain-cs
 * @brief BFS——填涂颜色（圈外染色法）
 * @version 1.0
 * @date 2026-05-15
 *
 * 例题来源：洛谷 P1162 填涂颜色
 * 题目链接：https://www.luogu.com.cn/problem/P1162
 *
 * 算法思路：
 * 1. 反向思维：不直接找圈内，而是从矩阵边界的0开始BFS染色。
 * 2. 把所有与边界相连的0都标记为已访问，表示“圈外可到达的区域”。
 * 3. BFS结束后，遍历矩阵。若原值为0且未被标记，说明它在闭合圈内，输出2。否则输出原值。
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

// 方向数组：右、左、下、上
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));          // 原始矩阵
    vector<vector<int>> visited(n, vector<int>(n, 0)); // 访问标记：1表示圈外可达
    queue<pair<int, int>> q;                           // BFS队列
    // 输入原始矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    // 将所有边界上的0入队，作为BFS起点（圈外染色）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 || i == n - 1 || j == 0 || j == n - 1) && v[i][j] == 0) {
                visited[i][j] = 1;   // 标记为圈外可达
                q.push({i, j});      // 入队
            }
        }
    }
    // BFS扩展：将与边界相连的所有0都标记
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 向四个方向扩展
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 在矩阵范围内，且未访问过，且是0（非墙），则标记并入队
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && v[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    // 输出结果：未被标记的0在闭合圈内，输出2；其余输出原值
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0 && !visited[i][j])
                cout << 2 << " ";
            else
                cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
