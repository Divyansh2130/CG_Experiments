#include <graphics.h>
#include <conio.h>
#include <dos.h>

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Provide the correct BGI path
    clrscr();

    // Window and viewport boundaries
    int wxmin = 10, wxmax = 150, wymin = 10, wymax = 250;
    int vxmin = 200, vxmax = 600, vymin = 10, vymax = 250;

    int wx1 = 30, wy1 = 50, wx2 = 100, wy2 = 180;

    // Draw window and viewport rectangles
    rectangle(wxmin, wymin, wxmax, wymax);
    rectangle(vxmin, vymin, vxmax, vymax);

    // Scaling factors
    float sx = (float)(vxmax - vxmin) / (wxmax - wxmin);
    float sy = (float)(vymax - vymin) / (wymax - wymin);

    // Draw original line in window
    line(wx1, wy1, wx2, wy2);

    // Transform coordinates to viewport
    int vx1 = (int)(sx * (wx1 - wxmin) + vxmin);
    int vy1 = (int)(sy * (wy1 - wymin) + vymin);
    int vx2 = (int)(sx * (wx2 - wxmin) + vxmin);
    int vy2 = (int)(sy * (wy2 - wymin) + vymin);

    // Draw transformed line in viewport
    line(vx1, vy1, vx2, vy2);

    // Labels
    outtextxy(60, 260, "Window");
    outtextxy(360, 260, "Viewport");

    getch();
    closegraph();
}
