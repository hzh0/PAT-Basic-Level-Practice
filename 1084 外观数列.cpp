#include <iostream>
#include <string>

using namespace std;

string process(string str) {	
    int length = str.length();
    if (length == 1) {
        return str + "1";
    }
    else {
    	str += "A";
        string prostr = "";
        int count = 1;
        for (int i = 0; i < length; i++) {
            if (str[i] == str[i+1]) {
                count++;
            }
            else {
                prostr += str[i];
				prostr += (count + '0');
                count = 1;
            }
        }
        return prostr;
    }
}

int main(void) {
    int num, times;
    cin >> num >> times;
    string str = "";
    str +=  (num + '0');
    for (int i = 0; i < times-1; i++) {
        str = process(str);
    }
    cout << str;
} 