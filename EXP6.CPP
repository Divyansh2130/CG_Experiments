#include <graphics.h>
#include <conio.h>
#include <iostream.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the line (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    int m = getmaxx();
    int n = getmaxy();
    setcolor(6);
    line(x1, y1, x2, y2);
    outtextxy(x1, y2 + 10, "Original Object");

    setcolor(4);
    line(m / 2, 0, m / 2, n); // Y-axis
    line(0, n / 2, m, n / 2); // X-axis

    // Reflection along X-axis
    setcolor(3);
    int reflectedY1 = (n / 2) + ((n / 2) - y1);
    int reflectedY2 = (n / 2) + ((n / 2) - y2);
    line(x1, reflectedY1, x2, reflectedY2);
    outtextxy(x1, reflectedY1 + 10, "Reflection along X-axis");

    // Reflection along Y-axis
    setcolor(9);
    int reflectedX1 = (m / 2) + ((m / 2) - x1);
    int reflectedX2 = (m / 2) + ((m / 2) - x2);
    line(reflectedX1, y1, reflectedX2, y2);
    outtextxy(reflectedX2 - 40, y2 + 10, "Reflection along Y-axis");

    getch();
    closegraph();
    return 0;
}