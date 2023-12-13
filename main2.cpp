#include <iostream>
#include <graphics.h>
using namespace std;

struct Point {
    int x, y;
    char code[4];
};

void drawWindow() {
    setcolor(RED);
    rectangle(150, 100, 450, 350);
}

void drawLine(Point p1, Point p2, int color) {
    setcolor(color);
    line(p1.x, p1.y, p2.x, p2.y);
}

void setCode(Point &p) {
    p.code[0] = (p.y < 100) ? '1' : '0';
    p.code[1] = (p.y > 350) ? '1' : '0';
    p.code[2] = (p.x > 450) ? '1' : '0';
    p.code[3] = (p.x < 150) ? '1' : '0';
}

int visibility(Point p1, Point p2) {
    for (int i = 0; i < 4; ++i)
        if (p1.code[i] != '0' || p2.code[i] != '0')
            return 2;

    for (int i = 0; i < 4; ++i)
        if (p1.code[i] == '1' && p2.code[i] == '1')
            return 1;

    return 0;
}

Point resetEndPoint(Point p1, Point p2) {
    Point temp;
    float m = static_cast<float>(p2.y - p1.y) / (p2.x - p1.x);

    if (p1.code[3] == '1') {
        temp.x = 150;
        temp.y = p1.y + m * (150 - p1.x);
    } else if (p1.code[2] == '1') {
        temp.x = 450;
        temp.y = p1.y + m * (450 - p1.x);
    } else if (p1.code[0] == '1') {
        temp.y = 100;
        temp.x = p1.x + (100 - p1.y) / m;
    } else if (p1.code[1] == '1') {
        temp.y = 350;
        temp.x = p1.x + (350 - p1.y) / m;
    }

    setCode(temp);
    return temp;
}

void checkLine(Point p1, Point p2) {
    setCode(p1);
    setCode(p2);

    int v = visibility(p1, p2);
    if (v == 0) {
        cleardevice(); 
        drawWindow();
        drawLine(p1, p2, 15);
    } else if (v == 2) {
        cleardevice();
        drawWindow();
        p1 = resetEndPoint(p1, p2);
        p2 = resetEndPoint(p2, p1);
        checkLine(p1, p2);
    } else {
        cleardevice();
        drawWindow();
    }
    delay(2000);
}

int main() {
    initwindow(800, 800);
    Point p1, p2;

    cout << "\n\t\tENTER END-POINT 1 (x,y): ";
    cin >> p1.x >> p1.y;
    cout << "\n\t\tENTER END-POINT 2 (x,y): ";
    cin >> p2.x >> p2.y;

    drawWindow();
    drawLine(p1, p2, 15);
    checkLine(p1, p2);

    getch();
    closegraph();
    return 0;
}

