// 1091 N-自守数 （15 分）
// 如果某个数 K 的平方乘以 N 以后，结果的末尾几位数等于 K，那么就称这个数为“N-自守数”。例如 3×92
// ​2
// ​​ =25392，而 25392 的末尾两位正好是 92，所以 92 是一个 3-自守数。

// 本题就请你编写程序判断一个给定的数字是否关于某个 N 是 N-自守数。

// 输入格式：
// 输入在第一行中给出正整数 M（≤20），随后一行给出 M 个待检测的、不超过 1000 的正整数。

// 输出格式：
// 对每个需要检测的数字，如果它是 N-自守数就在一行中输出最小的 N 和 NK
// ​2
// ​​  的值，以一个空格隔开；否则输出 No。注意题目保证 N<10。

// 输入样例：
// 3
// 92 5 233
// 输出样例：
// 3 25392
// 1 25
// No

//这道题就输入数字计算然后将数字和结果都转化成string
//然后判断是否满足条件即可

#include <iostream>
#include <string>

using namespace std;

bool judge(int, int);

int main(void) {
    int m;
    int num;
    cin >> m;
    for (int i = 0; i < m; i++) {
        bool flag = false;
        cin >> num; 
        if (num == 0) {
            cout << "0 0\n"; 
            continue;
        }
        for (int j = 1; j < 10; j++) {
            if (judge(j, num)) {
                cout << j << " " << j * num * num << endl;
                flag = true;
                break;
            }
        }
        if (!flag) cout << "No\n";
    }
}

bool judge(int i, int num) {
    string numstr = to_string(num);
    string resultstr = to_string(i * num * num);
    for (int i = numstr.size() - 1, j = resultstr.size() - 1; i >= 0 && j >= 0; i--, j--) {
        if (resultstr[j] != numstr[i])  return false;      
    }
    return true;
}