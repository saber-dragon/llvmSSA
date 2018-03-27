#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    int x = 0, y = 1, z, w;
    int a = 0, b, c = 0, d;

    std::cin >> w;

    d = x + y;

    if (w == 10) {
        a = x + y;
        c = x + y;
        z = 10;
    } else {
        ++ x;
        ++ y;
        z = y * x;
    }

    b = x + y;

    if (z == 10 || z >= 100)
        std::cout << "a = "
                  << a
                  << ", b = "
                  << b
                  << ", c = "
                  << c
                  << ", d = "
                  << d
                  << std::endl;


    return 0;
}