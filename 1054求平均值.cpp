// 1054 求平均值 （20 分）
// 本题的基本要求非常简单：给定 N 个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是 [−1000,1000] 区间内的实数，并且最多精确到小数点后 2 位。当你计算平均值的时候，不能把那些非法的数据算在内。

// 输入格式：
// 输入第一行给出正整数 N（≤100）。随后一行给出 N 个实数，数字间以一个空格分隔。

// 输出格式：
// 对每个非法输入，在一行中输出 ERROR: X is not a legal number，其中 X 是输入。最后在一行中输出结果：The average of K numbers is Y，其中 K 是合法输入的个数，Y 是它们的平均值，精确到小数点后 2 位。如果平均值无法计算，则用 Undefined 替换 Y。如果 K 为 1，则输出 The average of 1 number is Y。

// 输入样例 1：
// 7
// 5 -3.2 aaa 9999 2.3.4 7.123 2.35
// 输出样例 1：
// ERROR: aaa is not a legal number
// ERROR: 9999 is not a legal number
// ERROR: 2.3.4 is not a legal number
// ERROR: 7.123 is not a legal number
// The average of 3 numbers is 1.38
// 输入样例 2：
// 2
// aaa -9999
// 输出样例 2：
// ERROR: aaa is not a legal number
// ERROR: -9999 is not a legal number
// The average of 0 numbers is Undefined

//比较简单的一道题，判断输入的字符是否合法即可
//需要注意合法数字为1个和大于1个时的输出其中一个是单数number，多个合法数字时是复数numbers

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

//判断一个数字形式的字符是否合法
bool islegal(string str); 

int main(void) {
    int numcount, legalnumcount = 0;
    double num, sum = 0;
    string numstr;
    cin >> numcount;
    for (int i = 0; i < numcount; i++) {
        cin >> numstr;
        if (islegal(numstr)) {
            legalnumcount++;
            sum += atof(numstr.c_str());
            continue;
        }
        cout << "ERROR: " << numstr <<" is not a legal number" << endl;
    }   
    if (legalnumcount == 0) {
        cout << "The average of 0 numbers is Undefined" << endl;
    }
    else if (legalnumcount == 1) {
        printf("The average of %d number is %.2f", legalnumcount, sum / legalnumcount);
    }
    else {
        printf("The average of %d numbers is %.2f", legalnumcount, sum / legalnumcount);   
    }
    return 0;
}

bool islegal(string str) {
    if (str[0] == '.') return false;
    int length = str.length();
    int pointnum = 0;
    for (int i = 0; i < length; i++) {
        if (!((str[i] <= '9' && str[i] >= '0') || str[i] == '-' || str[i] == '.')) return false;
        if (i != 0 && str[i] == '-') return false;
        if (str[i] == '.') {
            if (length - i - 1 > 2) return false;
            pointnum++;
            if (pointnum > 1) return false;
        }
    }
    float num = atof(str.c_str());
    if (!(num >= -1000 && num <= 1000)) return false;
    return true;
}