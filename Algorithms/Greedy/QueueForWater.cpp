/**
* @file QueueForWater.cpp
 * @author shrrain-cs
 * @brief 贪心算法 —— 排序不等式 / 排队接水问题
 * @version 1.0
 * @date 2026-04-28
 *
 * 例题来源：洛谷 P1223 排队接水
 * 题目链接：https://www.luogu.com.cn/problem/P1223
 *
 * 算法思路：
 * 1. 贪心策略：接水时间短的人先接，这样后面的人等待时间最短
 * 2. 第i个人的等待时间 = 前面所有人的接水时间之和
 *    让耗时短的人先接，可以最小化这个累加和
 * 3. 若接水时间相同，编号小的优先
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

// 记录每个人的编号与接水时间
struct man {
    int idx;
    int t;
};

bool cmp(man a, man b) {
    if (a.t != b.t) return a.t < b.t; // 按接水时间升序
    return a.idx < b.idx;             // 时间相同，编号小的在前
}

signed main() {
    int n;
    double total = 0; // 记录总共的等待时间
    cin >> n;
    vector<man> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].t;
        v[i].idx = i;
    }
    sort(v.begin() + 1, v.end(), cmp); // 只排序 v[1] 到 v[n]
    vector<int> sum(n + 1); // 前缀和，记录前i个人的接水时间总和
    sum[1] = v[1].t;
    for (int i = 2; i <= n; i++) {
        sum[i] = sum[i - 1] + v[i].t; // 前i个人接水时间的和 = 他本身的接水时间 + 前i-1个人接水时间的和
    }
    // 按顺序输出编号，并计算total
    for (int i = 1; i <= n; i++) {
        total += sum[i]; // 累加计算所有人的接水时间总和
        cout << v[i].idx;
        if (i != n) cout << " ";
    }
    cout << "\n";
    cout << fixed << setprecision(2) << (total - sum[n]) / n; // 所有人的等待时间 = 所有人的接水时间总和 - 第n个人的接水时间
    return 0;
}
