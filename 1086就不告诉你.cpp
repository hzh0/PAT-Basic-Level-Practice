// 1086 就不告诉你 （15 分）
// 做作业的时候，邻座的小盆友问你：“五乘以七等于多少？”你应该不失礼貌地围笑着告诉他：“五十三。”本题就要求你，对任何一对给定的正整数，倒着输出它们的乘积。

// 输入格式：
// 输入在第一行给出两个不超过 1000 的正整数 A 和 B，其间以空格分隔。

// 输出格式：
// 在一行中倒着输出 A 和 B 的乘积。

// 输入样例：
// 5 7
// 输出样例：
// 53

//很简单的一道题，输入两数，得出乘积，然后将结果转换成string
//将得到的string翻转，将翻转的结果变成数字输出即可

//我刚开始直接将翻转的字符串输出了，但可能存在例如4*5=20，反转后变为02输出
//所以把“02”变成int直接输出2就行了

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    string s= to_string(a * b);
    reverse(s.begin(), s.end());
    cout << atoi(s.c_str()) << endl;
    return 0;
}