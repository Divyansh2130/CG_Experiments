#include <graphics.h>
#include <conio.h>
#include <dos.h>

void drawSymmetricPoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void midpointCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;
    while (x <= y) {
        drawSymmetricPoints(xc, yc, x, y);
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * x - 2 * y + 1;
        }
    }
}

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");  // Make sure this path matches your Turbo C++ setup

    setbkcolor(GREEN);
    cleardevice();

    int xc = 260, yc = 240, r = 100;
    midpointCircle(xc, yc, r);

    outtextxy(150, 380, "Circle Using Mid-Point Algorithm");

    delay(3000);  // Wait 3 seconds
    getch();
    closegraph();
}
