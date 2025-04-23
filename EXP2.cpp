#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

#define round(a) ((int)(a + 0.5))

void dda_line(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int length = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xinc = dx / (float)length;
    float yinc = dy / (float)length;

    float x = x1, y = y1;

    putpixel(round(x), round(y), 15);

    for (int k = 1; k <= length; k++)
    {
        x += xinc;
        y += yinc;
        putpixel(round(x), round(y), 15);
        delay(100);
    }
}

void main()
{
    clrscr();

    int x1, y1, x2, y2;
    int gd = DETECT, gm;

    cout << "Enter the x-coordinate of the starting point: ";
    cin >> x1;
    cout << "Enter the y-coordinate of the starting point: ";
    cin >> y1;
    cout << "Enter the x-coordinate of the ending point: ";
    cin >> x2;
    cout << "Enter the y-coordinate of the ending point: ";
    cin >> y2;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    dda_line(x1, y1, x2, y2);

    getch();
    closegraph();
}