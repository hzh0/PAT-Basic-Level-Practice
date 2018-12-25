// 1094 谷歌的招聘 （20 分）

// 本题要求你编程解决一个更通用的问题：从任一给定的长度为 L 的数字中，找出最早出现的 K 位连续数字所组成的素数。

// 输入格式：
// 输入在第一行给出 2 个正整数，分别是 L（不超过 1000 的正整数，为数字长度）和 K（小于 10 的正整数）。接下来一行给出一个长度为 L 的正整数 N。

// 输出格式：
// 在一行中输出 N 中最早出现的 K 位连续数字所组成的素数。如果这样的素数不存在，则输出 404。注意，原始数字中的前导零也计算在位数之内。例如在 200236 中找 4 位素数，0023 算是解；但第一位 2 不能被当成 0002 输出，因为在原始数字中不存在这个 2 的前导零。

// 输入样例 1：
// 20 5
// 23654987725541023819
// 输出样例 1：
// 49877
// 输入样例 2：
// 10 3
// 2468024680
// 输出样例 2：
// 404

//遍历数字，将每个满足长度的数字判断一下是否为素数
//需要注意遍历时的条件，例如6位数字取4位连续数字组成的素数
//如200236，则只需要判断2002, 0023, 0236三个，即循环时开头数字从下标num[0]到nun[6-4]即可

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isprime(long long num);

int main(void) {
    int totallength, resultlength;
    string num, resultnum;
    cin >> totallength >> resultlength >> num;
    for (int i = 0; i <= totallength - resultlength; i++) {
        resultnum = "";
        for (int j = 0; j < resultlength; j++) {
            resultnum += num[i+j];
        }
        long long midnum = atoi(resultnum.c_str());
        if (isprime(midnum)) {
            cout << resultnum << endl;
            return 0;
        } 
    }
    cout << "404" << endl;
    return 0;
}

bool isprime(long long num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}