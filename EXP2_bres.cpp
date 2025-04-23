#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

int sign(int x) {
    if (x < 0)
        return -1;
    if (x > 0)
        return 1;
    return 0;
}

void lineBres(int xa, int ya, int xb, int yb) {
    int sx, sy, t, length, flag;
    int x = xa;
    int y = ya;
    int dx = abs(xa - xb), dy = abs(ya - yb);

    sx = sign(xb - xa);
    sy = sign(yb - ya);

    if (dy > dx) {
        t = dx;
        dx = dy;
        dy = t;
        length = dy;
        flag = 1;
    } else {
        length = dx;
        flag = 0;
    }

    int p = (2 * dy) - dx;
    int twoDx = 2 * dx, twoDy = 2 * dy;

    putpixel(x, y, 15); // Draw the starting pixel
    delay(50);

    for (int i = 0; i < length; i++) {
        while (p > 0) {
            if (flag == 1)
                x = x + sx; // Move in x direction
            else
                y = y + sy; // Move in y direction
            p = p - twoDx; // Update decision parameter
        }

        if (flag == 1)
            y = y + sy; // Move in y direction
        else {
            x = x + sx; // Move in x direction
            p = p + twoDy; // Update decision parameter
        }

        putpixel(x, y, 15); // Draw the pixel
        delay(50);
    }
}

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c://turboc3//bgi"); // Initialize graphics mode

    int xa, ya, xb, yb;
    cout << "Enter the starting point of x: ";
    cin >> xa;
    cout << "Enter the starting point of y: ";
    cin >> ya;
    cout << "Enter the ending point of x: ";
    cin >> xb;
    cout << "Enter the ending point of y: ";
    cin >> yb;

    cleardevice(); // Clear the screen
    lineBres(xa, ya, xb, yb); // Draw the line using Bresenham's algorithm

    getch(); // Wait for a key press
    closegraph(); // Close the graphics mode
}