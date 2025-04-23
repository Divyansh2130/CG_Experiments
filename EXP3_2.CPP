#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>
#include <dos.h>

#define round(a) ((int)(a + 0.5))

void drawCircleUsingAngles(int xc, int yc, int r) {
    float x, y;
    for (int i = 0; i <= 360; i++) { // Full circle
	double ang = double(i) * (3.142 / 180); // Convert degrees to radians
	x = r * cos(ang);
	y = r * sin(ang);

	// Draw the eight symmetric points
	putpixel(xc + round(x), yc + round(y), WHITE);
	putpixel(xc - round(x), yc + round(y), WHITE);
	putpixel(xc + round(x), yc - round(y), WHITE);
	putpixel(xc - round(x), yc - round(y), WHITE);
	putpixel(xc + round(y), yc + round(x), WHITE);
	putpixel(xc - round(y), yc + round(x), WHITE);
	putpixel(xc + round(y), yc - round(x), WHITE);
	putpixel(xc - round(y), yc - round(x), WHITE);

	delay(10); // Short delay for visualization
    }
}

void drawCircleUsingEquation(int xc, int yc, int r) {
    float x = 0, y = r;

    for (x = 0; x <= y; x++) {
	double temp = (r * r) - (x * x);
	y = sqrt(temp);

	// Draw the eight symmetric points
	putpixel(xc + round(x), yc + round(y), WHITE);
	putpixel(xc - round(x), yc + round(y), WHITE);
	putpixel(xc + round(x), yc - round(y), WHITE);
	putpixel(xc - round(x), yc - round(y), WHITE);
	putpixel(xc + round(y), yc + round(x), WHITE);
	putpixel(xc - round(y), yc + round(x), WHITE);
	putpixel(xc + round(y), yc - round(x), WHITE);
	putpixel(xc - round(y), yc - round(x), WHITE);

	delay(10); // Short delay for visualization
    }
}

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // User input for circle center and radius
    int xc, yc, r;
 // cout << "Enter the center coordinates (xc, yc): ";
 // cin >> xc >> yc;
    cout << "Enter the radius (r): ";
    cin >> r;

    // Draw circle using both methods
    drawCircleUsingAngles(150,150,r);
    drawCircleUsingEquation(350,150,r);

    getch();
    closegraph();
}