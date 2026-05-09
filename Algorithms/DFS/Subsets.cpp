/**
* @file Subsets.cpp
 * @author shrrain-cs
 * @brief 深度优先搜索 —— 子集型（组合）
 * @version 2.0
 * @date 2026-05-09
 *
 * 例题来源：洛谷 P1157 组合的输出
 * 题目链接：https://www.luogu.com.cn/problem/P1157
 *
 * 算法思路：
 * 1. 从 1~n 中选 r 个数，每个数只能选一次，不考虑顺序。
 * 2. 用 DFS 枚举所有可能的选择，每次在当前位置放入一个数。
 * 3. 使用 start 参数保证只从小到大选，避免重复组合（如 {1,2} 和 {2,1}）。
 * 4. 回溯时恢复现场：弹出已选的数。
 */

#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;

void dfs(vector<int>& path, int start, int n, int r) {
    // 递归出口：已选满 r 个数，输出并返回
    if (path.size() == r) {
        for (int i = 0; i < r; i++) {
            cout << setw(3) << path[i];  // 每个数占 3 个字符宽度，右对齐
        }
        cout << "\n";
        return;
    }

    // 从 start 开始枚举，避免组合重复
    for (int i = start; i <= n; i++) {
        path.push_back(i);              // 加入当前路径
        dfs(path, i + 1, n, r);          // 递归下一层，起始数字 +1
        path.pop_back();                // 回溯：恢复现场，以便尝试其他选择
    }
}

signed main() {
    int n, r;
    cin >> n >> r;
    vector<int> path;             // 存储当前组合
    dfs(path, 1, n, r);           // 从数字 1 开始搜索
    return 0;
}
