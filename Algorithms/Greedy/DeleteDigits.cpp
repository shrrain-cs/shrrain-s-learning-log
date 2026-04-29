/**
* @file DeleteDigits.cpp
 * @author shrrain-cs
 * @brief 贪心 - 删数问题
 * @version 1.0
 * @date 2027-04-29
 *
 * 例题来源：洛谷 P1106 删数问题
 * 题目链接：https://www.luogu.com.cn/problem/P1106
 *
 * 算法思路：
 * 1. 贪心策略：为使数尽可能小，应不断从前至后删除第一个比后一位大的数，可使数整体减小
 * 2. 要删除n次，则将找第一个符合要求的数操作循环n次，每次记录要删除的数的下标
 * 3. 找到非零的最高位，以便去除前导零，最后按顺序输出即可
**/

#include <bits/stdc++.h>  // 竞赛用万能头文件
using namespace std;

#define int long long

signed main() {
	int n;
	string s;
	cin >> s >> n;
	vector<int> v;	// 用字符串模拟高精度数
	int len = s.size();
	// 将高精度数存入数组
	for(int i = 0 ; i < len ; i++) {
		v.push_back(s[i] - '0');
	}
	// 为使数尽可能小，应不断从前至后删除第一个比后一位大的数，可使数整体减小
	for (int i = 0 ; i < n ; i++) {
		int idx = len - 1 - i;	// 标记每次数组的末位下标
		for (int j = 0 ; j < idx ; j++) {
			// 从前往后找到第一个比后一位大的数
			if (v[j] > v[j + 1]) {
				idx = j ;	// 找到该数，记录其下标
				break;
			}
		}
		// 删除这个数（如未找到则删除末位）
		v.erase(v.begin() + idx ,v.begin() + idx + 1);
	}
	int pos = v.size() - 1;	// 初始化为末尾，防止答案所有位均为0
	// 找到非零的最高位，以便去除前导零
	for (int i = 0 ; i < v.size() ; i++) {
		if (v[i]) {
			pos = i;
			break;
		}
	}
	// 输出结果
	for (int i = pos ; i < v.size() ; i++) {
		cout << v[i];
	}
	return 0;
}
