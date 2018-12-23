//这道题最坑的一点就是输出的加密数据的位数是由A和B中较长的那一的确定的
//例如：A长度为10，B长度为1，则加密数据为10位
//     A长度为1，B长度为10，则加密数据还是10位
//所以我比较无法理解，你要加密数据B，为什么加密出来的数据长度还跟A有关，不是应该与B的长度唯一相关吗
//这一点卡了很久

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string A, B;
    string result = "";
    cin >> A >> B;
    int length = B.length();
    int alength = A.length();
    if (length > alength) {
        for (int i = 0; i < length - alength; i++) {
            A = "0" + A;
        }
    }
    else {
        for (int i = 0; i < alength - length; i++) {
            B = "0" + B;
        }
    }
    length = B.length();
    alength = A.length();
    int index = 1;
    for (int i = length - 1, j = alength - 1; i >= 0 && j >= 0; i--, j--) {
        if (index % 2 == 1) {
            int num = ((A[j] - '0') + (B[i] - '0')) % 13;
            if (num == 10) {
                result = "J" + result;
            }
            else if (num == 11) {
                result = "Q" + result;
            }
            else if (num == 12) {
                result = "K" + result;
            }
            else {
                result = (char)(num + '0') + result;
            } 
        }
        else {
            int num = (B[i] - '0') - (A[j] - '0');
            if (num < 0) {
                num += 10;
            }
            result = (char)(num + '0') + result;
        }
        index++;
    }
    cout << result << endl;
    return 0;
}