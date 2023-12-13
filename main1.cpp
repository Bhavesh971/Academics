#include <iostream>
#include <graphics.h>
using namespace std;

class Polygon {
protected:
    int numVertices;//Number of Vertices
    int x[20];//array to store x co-ordinates
    int y[20];//array to store y co-ordinates

public:
    Polygon() {
        numVertices = 0;//set Verices to zero
    }

    void setVertices() {//Function to take Vertices as input
        cout << "Enter the number of vertices of the polygon: ";//taking input number of vertices
        cin >> numVertices;//storing input number of vertices

        cout << "Enter the vertices (x, y) of the polygon:\n";
        for (int i = 0; i < numVertices; i++) {
            cout << "x" << i << ": ";
            cin >> x[i];
            cout << "y" << i << ": ";
            cin >> y[i];
        }
    }

    virtual void draw() {
        initwindow(800, 600);
        for (int i = 0; i < numVertices - 1; i++) {
            line(x[i], y[i], x[i + 1], y[i + 1]);
        }
        line(x[numVertices - 1], y[numVertices - 1], x[0], y[0]);
    }

    virtual void fill(int fill_color) = 0; // Pure virtual function for filling
};
class ConcavePolygon : public Polygon {
public:
    void fill(int fill_color) override {
        int x_int[800]; // Assuming maximum 800 intersection points
        int yy, i, j;
        
        // Code to set up the window and draw the polygon
        draw();

        for (yy = 0; yy < 600; yy++) {
            j = 0;
            for (i = 0; i < numVertices; i++) {
                int next = (i + 1) % numVertices;
                if ((y[i] < yy && y[next] >= yy) || (y[next] < yy && y[i] >= yy)) {
                    x_int[j++] = x[i] + (yy - y[i]) * (x[next] - x[i]) / (y[next] - y[i]);
                }
            }

            for (i = 0; i < j - 1; i += 2) {
                line(x_int[i], yy, x_int[i + 1], yy);
                delay(10);
            }
        }
        delay(3000);
        getch();
        closegraph();
    }
};
int main() {
	
    ConcavePolygon cp;
    cp.setVertices();
    
    cp.fill(RED); // Change YELLOW to any desired fill color
    return 0;
}

