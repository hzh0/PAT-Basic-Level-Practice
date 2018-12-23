// 1033 旧键盘打字 （20 分）
// 旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

// 输入格式：
// 输入在 2 行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过 10^5
// ​​个字符的串。可用的字符包括字母 [a-z, A-Z]、数字 0-9、以及下划线 _（代表空格）、,、.、-、+（代表上档键）。题目保证第 2 行输入的文字串非空。

// 注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

// 输出格式：
// 在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

// 输入样例：
// 7+IE.
// 7_This_is_a_test.
// 输出样例：
// _hs_s_a_tst


//这道题需要注意一个坑就是如果键盘没坏，那么输入的第一行为空，而用cin的话，
//一开始为空是录入不进去的，遇到第一个非空字符才进行存储，所以用了getline来进行输入

#include <iostream>
#include <string>

using namespace std;

string processstr(char c, string str);

int main(void) {
    string badkey;
    string str;
    getline(cin, badkey);
    getline(cin, str);
    int size = badkey.length();
    for (int i = 0; i < size; i++) {
        str = processstr(badkey[i], str);
    }
    cout << str << endl;
    return 0;
}

string processstr(char c, string str) {
    string rtnstr = "";
    int size = str.length();
    if (c == '+') {
        for (int i = 0; i < size; i++) {
            if (!(str[i] >= 'A' && str[i] <= 'Z')) {
                rtnstr += str[i];
            }
        }
    }
    else if (c >= 'A' && c <= 'Z') {
        for (int i = 0; i < size; i++) {
            if (!(str[i] - c == 0 || str[i] == (c - 'A') + 'a')) {
                rtnstr += str[i];
            }
        }    
    }
    else {
        for (int i = 0; i < size; i++) {
            if (str[i] != c) {
                rtnstr += str[i];
            }
        }
    }
    return rtnstr;
}