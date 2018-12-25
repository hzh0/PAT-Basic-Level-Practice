// 1093 字符串A+B （20 分）
// 给定两个字符串 A 和 B，本题要求你输出 A+B，即两个字符串的并集。要求先输出 A，再输出 B，但重复的字符必须被剔除。

// 输入格式：
// 输入在两行中分别给出 A 和 B，均为长度不超过 10
// ​6
// ​​ 的、由可见 ASCII 字符 (即码值为32~126)和空格组成的、由回车标识结束的非空字符串。

// 输出格式：
// 在一行中输出题面要求的 A 和 B 的和。

// 输入样例：
// This is a sample test
// to show you_How it works
// 输出样例：
// This ampletowyu_Hrk

//用一个数组保存所有ASCII字符的状态，初始值为0，表示为没有被输出过
//若输出过了，就将其置为1
//对A+B的每一个字符进行判断，就可以保证A先输出完并且没有重复的字符


#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string A, B;
    int arr[128] = {0};
    getline(cin, A);
    getline(cin, B);
    string C = A + B;
    for (int i = 0; i < C.length(); i++) {
        if (arr[C[i]] == 0) {
            cout << C[i];
            arr[C[i]]++;
        }
    }
    return 0;
}