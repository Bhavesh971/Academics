//Practical 3
//Write a C++ program to draw the following pattern. Use DDA line and Bresenham‘s 
//circle drawing algorithm. Apply the concept of encapsulation.


#include <iostream>
#include <graphics.h>
using namespace std;

class Draw {
private:
    int x1, y1, x2, y2;
    int xmid, ymid;

public:
    void getInput() {
        cout << "Enter x1: ";
        cin >> x1;
        cout << "Enter y1: ";
        cin >> y1;
        cout << "Enter x2: ";
        cin >> x2;
        cout << "Enter y2: ";
        cin >> y2;
    }

    void drawLine(int x1, int x2, int y1, int y2) {
        float dx = (x2 - x1);
        float dy = (y2 - y1);
        float steps = abs(dx) >= abs(dy) ? abs(dx) : abs(dy);
        dx /= steps;
        dy /= steps;

        float x = x1, y = y1;
        for (int i = 1; i <= steps; ++i) {
            x += dx;
            y += dy;
            putpixel(x, y, WHITE);
        }
    }

    void drawCircle(int xc, int yc, int r) {
        int x = 0, y = r;
        int d = 3 - 2 * r;
        do {
            putpixel(xc + x, yc + y, WHITE);
            putpixel(xc - x, yc - y, WHITE);
            putpixel(xc + x, yc - y, WHITE);
            putpixel(xc - x, yc + y, WHITE);
            putpixel(xc + y, yc - x, WHITE);
            putpixel(xc - y, yc - x, WHITE);
            putpixel(xc + y, yc + x, WHITE);
            putpixel(xc - y, yc + x, WHITE);

            if (d < 0) {
                y = y;
                d = d + 4 * x + 6;
            } else {
                d = d + 4 * (x - y) + 10;
                y--;
            }
            x++;
        } while (x <= y);
    }

    void drawPattern() {
        initwindow(900, 900);
        getInput();
        drawLine(x1, x2, y1, y1);
        drawLine(x2, x2, y1, y2);
        drawLine(x2, x1, y2, y2);
        drawLine(x1, x1, y2, y1);

        xmid = abs((x1 + x2)) / 2;
        ymid = abs((y1 + y2)) / 2;

        drawLine(xmid, x2, y1, ymid);
        drawLine(x2, xmid, ymid, y2);
        drawLine(xmid, x1, y2, ymid);
        drawLine(x1, xmid, ymid, y1);

        cout << "Enter the circle radius: ";
        int radius;
        cin >> radius;
        drawCircle(xmid, ymid, radius);

        getch();
        closegraph();
    }
};

int main() {
    Draw d;
    d.drawPattern();
    return 0;
}

