#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

int main(void) {
    std::string s;
    std::cin >> s;
    if (s.length() < 3) {
        std::cout << 0 << std::endl;
        return 0;
    }
    int begin = s.find_first_of('P');
    int end = s.find_last_of('T');
    s = s.substr(begin, end-begin+1);
    
    int ans = 0;

    int tCount = 0;
    for (auto i : s) {
        if (i == 'T') {
            ++tCount;
        }
    }
    int pCount = 0;
    for (auto i : s) {
        if (i == 'P') {
            ++pCount;
        }
        else if (i == 'T') {
            --tCount;
        }
        else {
            ans += (pCount * tCount);
            ans %= MOD;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}