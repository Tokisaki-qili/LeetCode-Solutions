/**
 * LeetCode 题目：数根 (Digital Root)
 * 难度：⭐ 简单
 * 
 * 题目描述：
 * 给定一个非负整数，不断将各位数字相加，直到结果为一位数。
 * 例如：38 → 3+8=11 → 1+1=2，所以 38 的数根是 2。
 * 
 * 思路：
 * 方法1：模拟法 - 不断求和直到一位数（当前实现）
 * 方法2：数学法 - 数根 = (num - 1) % 9 + 1
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s && s != "0") {
        // 不断求和，直到得到一位数
        while (s.size() > 1) {
            int sum = 0;
            for (char c : s) {
                sum += c - '0';
            }
            // 将 sum 转为字符串，继续下一轮
            s = to_string(sum);
        }
        cout << s << "\n";
    }
    return 0;
}
