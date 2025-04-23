#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

#define ROUND(a) ((int)(a + 0.5))

void symDDA(int xa, int ya, int xb, int yb) {
    int dx = xb - xa, dy = yb - ya;
    float length;

    float xinc, yinc, x = xa, y = ya;

    if (abs(dx) > abs(dy))
        length = abs(dx);
    else
        length = abs(dy);

    float n = log10(length) / log10(2); // Calculate the number of increments
    xinc = dx / (pow(2, n)); // Calculate x increment
    yinc = dy / (pow(2, n)); // Calculate y increment

    putpixel(ROUND(x), ROUND(y), 15); // Draw the starting pixel
    delay(50);

    for (int i = 0; i < length; i++) {
        x = x + xinc; // Increment x
        y = y + yinc; // Increment y
        putpixel(ROUND(x), ROUND(y), 15); // Draw the pixel
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
    symDDA(xa, ya, xb, yb); // Draw the line using Symmetrical DDA algorithm

    getch(); // Wait for a key press
    closegraph(); // Close the graphics mode
}