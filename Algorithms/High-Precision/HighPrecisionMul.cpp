/**
 * @file HighPrecisionMul.cpp
 * @author shrrain-cs
 * @brief 高精度乘法 —— 用数组模拟大整数竖式乘法
 * @version 1.0
 * @date 2027-04-27
 *
 * 例题来源：洛谷 P1303 A*B Problem
 * 题目链接：https://www.luogu.com.cn/problem/P1303
 *
 * 算法思路：
 * 1.将两个数字字符串反转，使低位对齐数组下标 0
 * 2. 将高精度数a与b逐位相乘，再错位相加并进位
 * 3. 找到最高非零位（若全为零则最终输出 0），按顺序输出
**/

#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;
signed main() {
    string s1,s2;
    // 根据题目数据范围（10^2000），开足够大的数组
    const int MAXX = 5000;
    vector<int> n1(MAXX),n2(MAXX),n3(MAXX,0);

    cin >> s1 >> s2;
    // 反转字符串，使个位对齐数组下标 0，方便从低位开始计算
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    // 将字符转换为数字存入数组
    for (int i = 0; i < s1.size(); i++) n1[i] = s1[i] - '0';
    for (int i = 0; i < s2.size(); i++) n2[i] = s2[i] - '0';

    int len = s1.size() + s2.size();
    // 竖式乘法核心：错位相乘再相加，并处理进位
    for (int i = 0 ; i < s2.size(); i ++) {
        for (int j = 0 ; j < s1.size() ; j++) {
            n3[j+i] = n3[j+i] + n1[j] * n2[i];  // 内层循环处理高精度乘一位数，外层循环处理错位相加
            if (n3[j+i] >= 10) {
                n3[j+i+1] += n3[j+i] / 10; // 进位到下一位
                n3[j+i] %= 10;  // 当前位只保留个位
            }
        }
    }
    // 去除前导零：从高位向低位找到第一个非零位
    // 若结果为零，idx 保持 0，输出 "0"
    int idx = 0;
    for (int i = len-1 ; i >= 0 ; i--) {
        if (n3[i]) {
            idx = i;
            break;
        }
    }
    // 输出结果
    for (int i = idx ; i >= 0 ; i--) {
        cout << n3[i];
    }
}
