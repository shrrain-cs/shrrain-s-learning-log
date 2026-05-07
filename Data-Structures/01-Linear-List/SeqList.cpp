/**
* @file SeqList.cpp
 * @author shrrain-cs
 * @brief 顺序表 —— 用结构体封装静态数组实现
 * @version 1.0
 * @date 2026-05-07
 */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000

struct SeqList {
	int data[MAXN];   // 存储元素的数组
	int len;          // 当前长度

	// 初始化顺序表为空
	void init() {
		len = 0;
	}

	// 尾插:在表末尾插入元素x
	void push_back(int x) {
		data[len] = x;
		len++;
	}

	// 在位置 pos 插入元素 x（pos 从 0 开始）
	void insert(int pos, int x) {
		for (int i = len ; i > pos ; i--) {
			data [i] = data [i - 1];
		}
		data[pos] = x;
		len++;
	}

	// 删除位置 pos 的元素
	void erase(int pos) {
		for (int i = pos ; i < len - 1 ; i++) {
			data[i] = data[i+1];
		}
		len--;
	};

	// 按值查找：返回第一个值为 x 的元素下标，未找到返回 -1
	int find(int x) {
		for (int i = 0 ; i < len ; i++) {
			if (data[i] == x) {
				return i;
			}
		}
		return -1;
	}

	// 按下标访问：返回位置 pos 的元素
	int get(int pos) {
		return data[pos];
	}

	// 修改位置 pos 的值为 x
	void set(int pos, int x) {
		data[pos] = x;
	}

	// 打印所有元素（调试用）
	void print() {
		for (int i = 0 ; i < len ; i++) {
			cout << data[i];
			if (i != len - 1) cout <<" ";
		}
		cout << "\n";
	}
};

int main() {
	SeqList list;
	list.init();
	// 尾插 10, 20, 30
	list.push_back(10);  // [10]
	list.push_back(20);  // [10, 20]
	list.push_back(30);  // [10, 20, 30]
	// 打印：10 20 30
	list.print();
	// 在位置 1 插入 99
	list.insert(1, 99);  // [10, 99, 20, 30]
	// 打印：10 99 20 30
	list.print();
	// 删除位置 2 的元素（值为 20）
	list.erase(2);       // [10, 99, 30]
	// 打印：10 99 30
	list.print();
	// 查找元素 99，应返回下标 1
	int idx = list.find(99);
	cout << "find(99) = " << idx << "\n";  // 理论输出：1
	// 查找不存在的元素 666，应返回 -1
	idx = list.find(666);
	cout << "find(666) = " << idx << "\n";  // 理论输出：-1
	// 按下标访问：get(0) 应为 10
	cout << "get(0) = " << list.get(0) << "\n";  // 理论输出：10
	// 修改位置 2 的值为 88
	list.set(2, 88);     // [10, 99, 88]
	// 打印：10 99 88
	list.print();
	return 0;
	// 经测试，实际输出与理论输出相同
}
