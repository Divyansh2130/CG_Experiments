#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <iostream>
using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Define window boundaries
int x_min = 100, y_min = 100;
int x_max = 300, y_max = 300;

// Compute region code
int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < x_min)
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;
    if (y < y_min)
        code |= BOTTOM;
    else if (y > y_max)
        code |= TOP;

    return code;
}

// Cohen-Sutherland Line Clipping
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both points inside
            accept = 1;
            break;
        } else if (code1 & code2) {
            // Both points share an outside region
            break;
        } else {
            // Line needs clipping
            int code_out;
            int x, y;

            // At least one endpoint is outside
            code_out = code1 ? code1 : code2;

            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Replace the outside point
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    } else {
        outtextxy(100, 80, "Line rejected (outside window)");
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw clipping window
    rectangle(x_min, y_min, x_max, y_max);

    // --- Example A: Line intersecting at one point ---
    setcolor(RED);
    line(50, 150, 150, 150); // Outside -> Inside
    delay(1000);
    cohenSutherlandClip(50, 150, 150, 150);

    // --- Example B: Line intersecting at two points ---
    setcolor(RED);
    line(50, 50, 350, 350); // Crosses window
    delay(1000);
    cohenSutherlandClip(50, 50, 350, 350);

    getch();
    closegraph();
    return 0;
}
