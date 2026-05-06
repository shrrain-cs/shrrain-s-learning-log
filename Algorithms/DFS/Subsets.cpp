/**
* @file Subsets.cpp
 * @author shrrain-cs
 * @brief 深度优先搜索 —— 子集型（组合）
 * @version 1.0
 * @date 2026-05-06
 *
 * 例题来源：洛谷 P1157 组合的输出
 * 题目链接：https://www.luogu.com.cn/problem/P1157
 *
 * 算法思路：
 * 1. 从 1~n 中选 r 个数，每个数只能选一次，不考虑顺序。
 * 2. 用 DFS 枚举所有可能的选择，每次在当前位置放入一个未用过的数。
 * 3. 使用 start 参数保证只从小到大选，避免重复组合（如 {1,2} 和 {2,1}）。
 * 4. 回溯时恢复现场：弹出已选的数，标记为未使用。
 */
#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;
void dfs(vector<int>& path, vector<bool>& used, int start, int n, int r) {
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
        if (!used[i]) {               // 当前数字未被使用
            used[i] = true;           // 标记为已使用
            path.push_back(i);        // 加入当前路径
            dfs(path, used, i + 1, n, r);  // 递归下一层，起始数字 +1
            // 回溯：恢复现场，以便尝试其他选择
            used[i] = false;
            path.pop_back();
        }
    }
}
signed main() {
    int n, r;
    cin >> n >> r;
    vector<int> path;             // 存储当前组合
    vector<bool> used(n + 1);     // 标记每个数字是否已使用，下标 1~n
    dfs(path, used, 1, n, r);     // 从数字 1 开始搜索
    return 0;
}
