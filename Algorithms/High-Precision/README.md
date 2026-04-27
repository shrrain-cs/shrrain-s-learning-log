# 高精度算法 | High Precision Arithmetic

有时候，我们会遇到一些连 unsigned long long都无法存储的大数，就要用一个数组来存储，有时候还会涉及他们之间的运算，这时就需要用到高精度算法

---

## 算法实现

| 运算 | 文件 | 核心思想 | 例题来源 | 状态 |
| :--- | :--- | :--- | :--- | :--- |
| 加法 | `HighPrecisionAdd.cpp` | 逐位相加，处理进位 | 洛谷 P1601 | ✅ |
| 减法 | `HighPrecisionSub.cpp` | 比较大小，借位相减 | 洛谷 P2142 | ✅ |
| 乘法 | `HighPrecisionMul.cpp` | 逐位相乘，错位相加 | 洛谷 P1303 | ✅ |
| 除法 | 待补充 | — | — | 📝 暂缓 |

---

## 核心思想

字符串存储高精度数 → 反转后存入数组 → 模拟竖式运算 → 找到第一个非零位 → 倒序输出

---

## 学习心得

- **加法**：逐位相加，进位即可，不要忘记进位可能导致多出一位
- **减法**：注意要先判断正负，不够减需要借位
- **乘法**：关键在于**内层循环处理高精度乘一位数，外层循环处理错位相加**的思想，不要忘记进位
- 其他容易出错的地方：忘记去前导零、数组越界、进位逻辑写反

---

## 参考资料

- 洛谷题单 【算法1-1】模拟与高精度 https://www.luogu.com.cn/training/106#information
- B站视频(高精度加法) https://www.bilibili.com/video/BV1Ne411v78Z/
- B站视频(高精度减法) https://www.bilibili.com/video/BV1kb4y1A7Wf/
- B站视频(高精度乘法) https://www.bilibili.com/video/BV166SgYFEea/
