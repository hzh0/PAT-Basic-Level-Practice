#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int number;
    string id;
    int x, y;
    int max = 0, min = 30000;    
    string winner, loser;
    cin >> number;
    for (int i = 0; i < number; i++) {
        cin >> id >> x >> y;
        int distance = x * x + y * y;
        if (distance < min) {
            min = distance;
            winner = id;
        }
        if (distance > max) {
            max = distance;
            loser = id;
        }
    }
    cout << winner << " " << loser << endl;
}