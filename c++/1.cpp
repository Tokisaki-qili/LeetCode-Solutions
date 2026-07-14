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
