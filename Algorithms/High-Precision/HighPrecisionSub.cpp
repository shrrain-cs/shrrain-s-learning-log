/**
 * @file HighPrecisionSub.cpp
 * @author shrrain-cs
 * @brief 高精度减法 —— 用数组模拟大整数竖式减法
 * @version 1.0
 * @date 2027-04-27
 *
 * 例题来源：洛谷 P2142 高精度减法
 * 题目链接：https://www.luogu.com.cn/problem/P2142
 *
 * 算法思路：
 * 1. 反转字符串，使低位对齐数组下标 0
 * 2. 比较大小，确定正负，保证大数减小数
 * 3. 逐位相减，不够减则向高位借 1
 * 4. 去除前面无意义的零，找到最高非零位（若全为零则最终输出 0）
 * 5. 负数先输出负号
**/

#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;

// 比较两个高精度数的大小：s1 < s2 返回 true
bool cmp(string s1, string s2) {
    // 位数不同时，长度大的值更大
    if (s1.size() != s2.size()) return s1.size() < s2.size();
    // 位数相同时，直接按字典序比较
    return s1 < s2;
}

signed main() {
    string s1, s2;
    char op = '+';  // 记录结果的正负号

    // 根据题目数据范围（10^10086），开足够大的数组
    const int MAXX = 12000;
    vector<int> n1(MAXX, 0), n2(MAXX, 0), n3(MAXX, 0);

    cin >> s1 >> s2;

    // 若 s1 < s2，交换两数并标记结果为负，确保大数减小数
    if (cmp(s1, s2)) {
        op = '-';
        swap(s1, s2);
    }

    // 反转字符串，使个位对齐数组下标 0，方便从低位开始计算
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    // 将字符转换为数字存入数组
    for (int i = 0; i < s1.size(); i++) n1[i] = s1[i] - '0';
    for (int i = 0; i < s2.size(); i++) n2[i] = s2[i] - '0';

    int len = max(s1.size(), s2.size());

    // 竖式减法核心：逐位相减，不够减则向高位借 1
    for (int i = 0; i < len; i++) {
        if (n1[i] < n2[i]) {
            n1[i] += 10;      // 向高位借 1，当前位加 10
            n1[i + 1] -= 1;   // 高位减 1
        }
        n3[i] = n1[i] - n2[i];
    }

    // 去除前导零：从高位向低位找到第一个非零位
    // 若结果全为零（如 2-2），pos 保持 0，输出 "0"
    int pos = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (n3[i]) {
            pos = i;
            break;
        }
    }

    // 输出结果
    if (op == '-') cout << "-";
    for (int i = pos; i >= 0; i--) {
        cout << n3[i];
    }

    return 0;
}
