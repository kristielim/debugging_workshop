#include <iostream>
using namespace std;

void printLine(int width, bool fill) {
    for (int i = 0; i < width; i++) {
        if (i != 0 && i != width && !fill) {
            cout << " ";
        } else {
            cout << "*";
        }
    }
    cout << endl;
}

void printRectangle(int height, int width) {
    for (int i = 0; i < height; i++) {
        bool fill = false;
        if (i == 0 || i == height - 1) {
            fill = true;
        }
        printLine(width, fill);
    }
}

int main() {
    printRectangle(5, 8);
    return 0;
}
