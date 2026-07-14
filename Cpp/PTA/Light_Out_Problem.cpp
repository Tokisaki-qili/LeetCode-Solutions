/**
 * PTA 7-6 熄灯问题 (2811:熄灯问题)
 * 分数：10
 * 
 * 思路：
 * 枚举第一行的所有按法（2^6 = 64种）
 * 第一行确定后，后面每行的按法就确定了：
 *   - 第i行按不按，取决于第i-1行的灯是否亮着
 *   - 如果第i-1行第j列灯亮，就必须按第i行第j列来熄灭它
 * 最后检查最后一行是否全部熄灭
 */

#include <bits/stdc++.h>
using namespace std;

// 原始灯状态
int light[7][8];
// 按按钮的方案
int press[7][8];

/**
 * 判断当前第一行的按法是否能熄灭所有灯
 */
bool check() {
    // 根据第一行的按法，确定后面每行的按法
    for (int i = 2; i <= 5; i++) {
        for (int j = 1; j <= 6; j++) {
            // 如果(i-1, j)位置的灯是亮的，就必须按(i, j)来熄灭它
            // 灯的状态 = 初始状态 + 自身被按 + 上下左右被按
            press[i][j] = (light[i-1][j] + press[i-1][j] + press[i-1][j-1] 
                          + press[i-1][j+1] + press[i-2][j]) % 2;
        }
    }
    
    // 检查最后一行是否全部熄灭
    for (int j = 1; j <= 6; j++) {
        int s = (light[5][j] + press[5][j] + press[5][j-1] 
                + press[5][j+1] + press[4][j]) % 2;
        if (s == 1) return false;
    }
    return true;
}

/**
 * 枚举第一行的所有按法
 * 用二进制表示：0~63 对应第一行6个按钮的按法
 */
void solve() {
    // 枚举第一行的64种按法
    for (int n = 0; n < 64; n++) {
        // 将n的二进制位分解到press[1][1]~press[1][6]
        int temp = n;
        for (int j = 1; j <= 6; j++) {
            press[1][j] = temp % 2;
            temp /= 2;
        }
        
        if (check()) return;  // 找到解
    }
}

int main() {
    // 读入初始灯状态
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 6; j++) {
            cin >> light[i][j];
        }
    }
    
    // 求解
    solve();
    
    // 输出结果
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 6; j++) {
            cout << press[i][j];
            if (j < 6) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
