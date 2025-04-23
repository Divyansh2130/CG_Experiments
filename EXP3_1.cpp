#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

#define round(a) ((int)(a + 0.5))  // Fixed the rounding macro

void putcircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, 1);
    putpixel(xc - x, yc + y, 2);
    putpixel(xc + x, yc - y, 3);
    putpixel(xc - x, yc - y, 4);
    putpixel(xc + y, yc + x, 5);
    putpixel(xc - y, yc + x, 6);
    putpixel(xc + y, yc - x, 7);
    putpixel(xc - y, yc - x, 8);
}

void circlemid(int xc, int yc, float r) {
    float x = 0, y = r;
    int p = 1 - r;

    while (x < y) {
        x++;
        if (p < 0) {
            p = p + (2 * x) + 1;
        } else {
            y--;
            p = p + (2 * (x - y) + 1);
        }

        putcircle(xc, yc, round(x), round(y));
        delay(10);  // Keep Turbo C++ delay
    }
}
void main() {
    clrscr();

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xc, yc, r;
    cout << "Enter radius: ";
    cin >> r;

    // Top-left corner
    xc = r; // x-coordinate for top-left corner
    yc = r; // y-coordinate for top-left corner
    circlemid(xc, yc, r);
    delay(1000); // Delay to see the circle

    // Top-right corner
    xc = getmaxx() - r; // x-coordinate for top-right corner
    yc = r; // y-coordinate for top-right corner
    circlemid(xc, yc, r);
    delay(1000); // Delay to see the circle

    // Bottom-left corner
    xc = r; // x-coordinate for bottom-left corner
    yc = getmaxy() - r; // y-coordinate for bottom-left corner
    circlemid(xc, yc, r);
    delay(1000); // Delay to see the circle

    // Bottom-right corner
    xc = getmaxx() - r; // x-coordinate for bottom-right corner
    yc = getmaxy() - r; // y-coordinate for bottom-right corner
    circlemid(xc, yc, r);
    delay(1000); // Delay to see the circle

    getch();
    closegraph();
}