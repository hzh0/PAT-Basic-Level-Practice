#include <iostream>
#include <vector>

int main(void) {
    int num1, num2;
    bool flag = false;
    while(std::cin >> num1 >> num2) {
        if (num2 != 0) {
            if (flag) {
                std::cout << " ";
            }
            std::cout << num1* num2 << " " << num2 - 1;
            flag = true;
        }   
    }
    if (!flag) {
        std::cout << "0 0" << std::endl;
    }
    return 0;
}