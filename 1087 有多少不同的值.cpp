#include <iostream>
#include <set>

using namespace std;

int main(void) {
    int num;
    cin >> num;
    set<int> s;
    for (int i = 1 ; i <= num; i++) {
        s.insert(i/2 + i/3 + i/5);
    }
    cout << s.size();
    return 0;
}