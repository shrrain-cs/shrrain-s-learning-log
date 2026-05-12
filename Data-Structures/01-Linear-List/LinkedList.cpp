/**
 * @file LinkedList.cpp
 * @author shrrain-cs
 * @brief 单链表 —— 带头结点的单向链表实现
 * @version 1.0
 * @date 2026-05-12
 */

#include <bits/stdc++.h>
using namespace std;

// 链表节点结构体
struct Node {
    int data;    // 数据域
    Node* next;  // 指针域
};

// 带头结点的单链表
struct LinkedList {
    Node* head;  // 头结点（不存储数据）
    int len;     // 链表长度

    // 初始化链表
    void init() {
        head = new Node;
        head->next = nullptr;
        len = 0;
    }

    // 头插法：在头部插入元素 x
    void push_front(int x) {
        Node* node = new Node;
        node->data = x;
        node->next = head->next;
        head->next = node;
        len++;
    }

    // 尾插法：在尾部插入元素 x
    void push_back(int x) {
        Node* node = new Node;
        node->data = x;
        node->next = nullptr;
        Node* p = head;
        while (p->next != nullptr) p = p->next;
        p->next = node;
        len++;
    }

    // 在位置 pos 插入元素 x（pos 从 0 开始）
    void insert(int pos, int x) {
        Node* node = new Node;
        node->data = x;
        Node* p = head;
        while (pos--) p = p->next;
        node->next = p->next;
        p->next = node;
        len++;
    }

    // 删除位置 pos 的元素
    void erase(int pos) {
        Node* p = head;
        while (pos--) p = p->next;
        Node* t = p->next;
        p->next = p->next->next;
        delete t;
        len--;
    }

    // 反转链表
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head->next;
        while (curr != nullptr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = prev;
    }

    // 按值查找：返回第一次出现的下标，未找到返回 -1
    int find(int x) {
        int idx = 0;
        Node* p = head->next;
        while (p != nullptr) {
            if (p->data == x) return idx;
            p = p->next;
            idx++;
        }
        return -1;
    }

    // 打印链表
    void print() {
        Node* p = head->next;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "\n";
    }

    // 释放所有节点内存
    void destroy() {
        Node* p = head;
        while (p != nullptr) {
            Node* t = p->next;
            delete p;
            p = t;
        }
        head = nullptr;
        len = 0;
    }
};

int main() {
    LinkedList list;
    list.init();

    // 尾插 10, 20, 30
    list.push_back(10);  // [10]
    list.push_back(20);  // [10, 20]
    list.push_back(30);  // [10, 20, 30]

    // 头插 99
    list.push_front(99); // [99, 10, 20, 30]
    // 打印：99 10 20 30
    list.print();

    // 删除下标 1 的元素（值为 10）
    list.erase(1);       // [99, 20, 30]
    // 打印：99 20 30
    list.print();

    // 反转链表
    list.reverse();      // [30, 20, 99]
    // 打印：30 20 99
    list.print();

    // 查找元素 20，应返回下标 1
    int idx = list.find(20);
    cout << "find(20) = " << idx << "\n";   // 理论输出：1

    // 查找不存在的元素 100，应返回 -1
    idx = list.find(100);
    cout << "find(100) = " << idx << "\n";  // 理论输出：-1

    // 销毁链表
    list.destroy();
    cout << "len after destroy = " << list.len << "\n"; // 理论输出：0
    // 经测试，实际输出与理论输出相同

    return 0;
}
