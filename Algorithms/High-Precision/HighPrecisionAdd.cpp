/**
 * @file HighPrecisionAdd.cpp
 * @author shrrain-cs
 * @brief 高精度加法 —— 用数组模拟大整数竖式加法
 * @version 1.0
 * @date 2027-04-27
 * 
 * 算法思路：
 * 1. 将两个数字字符串反转，使低位对齐数组下标 0（类比小学学的竖式乘法）
 * 2. 逐位相加，处理进位：当前位 = (a[i] + b[i] + 进位) % 10
 * 3. 若最高位有进位，需额外输出
 */

#include<bits/stdc++.h> //竞赛用万能头文件
using namespace std;
#define int long long

signed main() {
    string s1, s2;
    // 使用 vector 而非数组，方便动态控制大小；开 1000 位处理常规大数足够
    vector<int> n1(1000), n2(1000), n3(1000, 0);  // n3 存放结果，初始全为 0
    
    cin >> s1 >> s2;
    
    // 反转字符串，让低位在前，方便 i=0 开始逐位相加
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    // 将字符转为数字存入数组
    for (int i = 0; i < s1.size(); i++) {
        n1[i] = s1[i] - '0';
    }
    for (int i = 0; i < s2.size(); i++) {
        n2[i] = s2[i] - '0';
    }
    
    int len = max(s1.size(), s2.size());
    
    // 竖式加法核心：逐位相加，处理进位
    for (int i = 0; i < len; i++) {
        n3[i] += n1[i] + n2[i];       // 累加当前位
        n3[i + 1] += n3[i] / 10;      // 进位传到下一位
        n3[i] %= 10;                  // 当前位只保留个位
    }
    
    // 输出结果：若最高位有进位，先输出它
    if (n3[len]) cout << n3[len];
    for (int i = len - 1; i >= 0; i--) {
        cout << n3[i];
    }
    
    return 0;
}
