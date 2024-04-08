#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    const string s[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

    int a, b;
    cin >> a;
    cin >> b;

    for (int i = a; i <= b; i++) {
        if (i >= 1 && i <= 9) {
            std::cout << s[i] << endl;

        }
        else if (i % 2 == 0) {
            std::cout << "even" << endl;
        }

        else {
            std::cout << "odd" << endl;
        }

    }

    return 0;
}
