#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 12 == 0) {
        cout << (n / 12) * 15000;
    }
    else if (n % 9 == 0) {
        cout << (n / 9) * 12000;
    }
    else if (n % 6 == 0) {
        cout << (n / 6) * 9000;
    }
    else if (n % 3 == 0) {
        cout << (n / 3) * 5000;
    }
    else {
        cout << "Error";
    }

    return 0;
}
