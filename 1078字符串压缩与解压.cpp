// 1078 字符串压缩与解压 （20 分）
// 文本压缩有很多种方法，这里我们只考虑最简单的一种：把由相同字符组成的一个连续的片段用这个字符和片段中含有这个字符的个数来表示。例如 ccccc 就用 5c 来表示。如果字符没有重复，就原样输出。例如 aba 压缩后仍然是 aba。

// 解压方法就是反过来，把形如 5c 这样的表示恢复为 ccccc。

// 本题需要你根据压缩或解压的要求，对给定字符串进行处理。这里我们简单地假设原始字符串是完全由英文字母和空格组成的非空字符串。

// 输入格式：
// 输入第一行给出一个字符，如果是 C 就表示下面的字符串需要被压缩；如果是 D 就表示下面的字符串需要被解压。第二行给出需要被压缩或解压的不超过 1000 个字符的字符串，以回车结尾。题目保证字符重复个数在整型范围内，且输出文件不超过 1MB。

// 输出格式：
// 根据要求压缩或解压字符串，并在一行中输出结果。

// 输入样例 1：
// C
// TTTTThhiiiis isssss a   tesssst CAaaa as
// 输出样例 1：
// 5T2h4is i5s a3 te4st CA3a as
// 输入样例 2：
// D
// 5T2h4is i5s a3 te4st CA3a as10Z
// 输出样例 2：
// TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ

//这道题我是将压缩和解压写了两个函数
//压缩函数：
//因为比较的时候我是用后一个字符与当前字符比较，
//所以如果到了最后一个字符，那么访问它的下一个字符会出错
//所以我将str的长度+1，那么我就可以访问所有的字符以及它的下一个字符，刚开始我是在str的最后加了一个空格，后来测试点3答案错误
//所以我猜测压缩的字符最后会以空格结尾，当时思考如何解决这个问题，保证最后一个字符不会对整个答案有影响
//后来我的方法是str += (str[str.length()-1] + 1);这样就保证了新加的字符一定不会与最后一个字符相同，最后答案正确
//接着说思路，初始num = 1，如果当前字符的下一个字符与当前字符相同，那么num++，
//如果不相同，如果num = 1，说明当前字符没有重复，那就输出当前字符，如果num > 1，就输出num然后再输出当前字符，并将num重置为1，继续循环判断

//解压函数：
//刚开始用一个string num来保存数字
//遍历整个字符串，如果是数字，那么就用num+=str[i],如果是字母，就将num转化成int类型，输出这么多遍字母，并将num重置为空
//需要注意若是两个连着的都是字母，那么我们需要对num进行长度判断，如果num长度为0，就只输出一边当前字母

#include <iostream>
#include <string>

using namespace std;

void compression(string);
void decompression(string);

int main(void) {
    char flag;
    string text;
    cin >> flag;
    getchar();
    getline(cin, text);
    if (flag == 'C') {
        compression(text);
    }
    else {
        decompression(text);
    }
    return 0;
}

void compression(string str) {
    string result = "";
    str += (str[str.length()-1] + 1);
    int length = str.length();
    int num = 1;
    for (int i = 0; i < length - 1; i++) {
        if (str[i+1] == str[i]) {
            num++;
        }   
        else {
            if (num != 1) {
                result = result + to_string(num) + str[i];
            }
            else {
                result = result + str[i];   
            }
            num = 1;
        }
    }
    cout << result;
}

void decompression(string str) {
    string num = "";
    int length = str.length();
    for (int i = 0; i < length; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num += str[i];
        }
        else {
            if (num.length() > 0) {
                for (int j = 0; j < atoi(num.c_str()); j++) {
                    cout << str[i];
                }
            }
            else {
                cout << str[i];
            }
            num = "";
        }
    }
}