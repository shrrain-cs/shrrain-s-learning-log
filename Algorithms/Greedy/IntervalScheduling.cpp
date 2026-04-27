/**
 * @file IntervalScheduling.cpp
 * @author shrrain-cs
 * @brief 贪心-线段覆盖/区间调度问题
 * @version 1.0
 * @date 2027-04-27
 *
 * 例题来源：洛谷 P1803 凌乱的yyy / 线段覆盖
 * 题目链接：https://www.luogu.com.cn/problem/P1803
 *
 * 算法思路：
 * 1.我们选择一个比赛，根据他的开始时间和持续时间，都无法得出选择该比赛是否最优的结论，但如果按照结束时间来选择，就能省出更多的时间，从而参与更多的比赛，这就是局部最优解
 * 2.将数据存入结构体，按照结束时间排序
 * 3.维护比赛的结束日期last，以此判断是否可以参加某比赛，并计数输出
**/

#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;
// 结构体存储比赛的开始与结束时间
struct competition {
    int begin;
    int end;
};
//比较结束时间，以便后续排序
bool cmp(competition c1 ,competition c2) {
    return c1.end < c2.end;
}
signed main() {
    int n;
    cin >>n ;
    vector<competition> c(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> c[i].begin >> c[i].end;
    }
    // 按结束时间排序
    sort(c.begin(),c.end(),cmp);
    int last = 0;   // 维护比赛结束后的日期
    int ans = 0;    // 记录参与比赛的最大数量
    //每次求局部最优解
    for (int i = 0 ; i < n ; i++) {
        if (last <= c[i].begin) {     // 判断能否参加当前这场比赛
            ans ++; // 若能，则记录
            last = c[i].end;    //维护比赛结束日期
        }
    }
    cout << ans;
}
