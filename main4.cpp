//Practical no.4
//Basic 2-D Transformations
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

class Transformation {
public:
    void drawTriangle(int co[2][3]) {
        line(co[0][0], co[1][0], co[0][1], co[1][1]);
        line(co[0][1], co[1][1], co[0][2], co[1][2]);
        line(co[0][2], co[1][2], co[0][0], co[1][0]);
    }

    void translate(int tx, int ty, int co[2][3]) {
        int i, j;
        for (i = 0; i < 3; i++) {
            co[0][i] += tx;
            co[1][i] += ty;
        }
    }

    void scale(float sx, float sy, int co[2][3]) {
        int i, j;
        for (i = 0; i < 3; i++) {
            co[0][i] *= sx;
            co[1][i] *= sy;
        }
    }

    void rotate(float theta, int co[2][3]) {
    // Finding the center of the triangle
    int cx = (co[0][0] + co[0][1] + co[0][2]) / 3;
    int cy = (co[1][0] + co[1][1] + co[1][2]) / 3;

    theta = theta * (3.14 / 180); // Convert angle to radians

    for (int i = 0; i < 3; i++) {
        int x = co[0][i] - cx;
        int y = co[1][i] - cy;

        co[0][i] = round((x * cos(theta)) - (y * sin(theta))) + cx;
        co[1][i] = round((x * sin(theta)) + (y * cos(theta))) + cy;
    }
}

};

int main() {
    initwindow(800, 800);
    int c;
    int tx, ty;
    float sx, sy;
    float theta;

    int co[2][3] = {{300, 250, 350}, {200, 300, 300}};

    Transformation t;

    t.drawTriangle(co);

    cout << "Enter your choice" << endl;
    cout << "1. Translation" << endl;
    cout << "2. Scaling" << endl;
    cout << "3. Rotation" << endl;
    cin >> c;

    switch (c) {
    case 1:
        cout << "Enter Translation Factor" << endl;
        cin >> tx >> ty;
        t.translate(tx, ty, co);
        break;
    case 2:
        cout << "Enter Scaling Factor" << endl;
        cin >> sx >> sy;
        t.scale(sx, sy, co);
        break;
    case 3:
        cout << "Enter Rotation Angle" << endl;
        cin >> theta;
        t.rotate(theta, co);
        break;
    default:
        cout << ("You have entered a wrong choice");
    }

    t.drawTriangle(co);

    getch();
    return 0;
}

