#include <graphics.h>
#include <iostream.h>
#include<conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c://turboc3//bgi");
    
    // Get screen dimensions
    int screenWidth = getmaxx();
    int screenHeight = getmaxy();
    
    // Define clipping window dynamically
    int xmin = screenWidth / 4;
    int xmax = 3 * screenWidth / 4;
    int ymin = screenHeight / 4;
    int ymax = 3 * screenHeight / 4;
    
    // Draw the clipping window
    line(xmin, 0, xmin, screenHeight);
    line(xmax, 0, xmax, screenHeight);
    line(0, ymax, screenWidth, ymax);
    line(0, ymin, screenWidth, ymin);
    
    cout << "Enter the endpoints of the line: ";
    int x[2], y[2], num[2];
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    
    line(x[0], y[0], x[1], y[1]);
    
    for (int i = 0; i < 2; i++) {
        int bit1 = 0, bit2 = 0, bit3 = 0, bit4 = 0;
        
        if (y[i] < ymin) bit1 = 1;
        if (y[i] > ymax) bit2 = 1;
        if (x[i] > xmax) bit3 = 1;
        if (x[i] < xmin) bit4 = 1;
        
        cout << "For " << i << "th endpoint, region code is: "
             << bit1 << bit2 << bit3 << bit4 << endl;
        
        num[i] = bit4 * 1 + bit3 * 2 + bit2 * 4 + bit1 * 8;
    }
    
    if (!(num[0] | num[1]))
        cout << "Line is completely inside the window." << endl;
    else if (!(num[0] & num[1]))
        cout << "Line is partially inside the window and needs clipping." << endl;
    else
	cout << "Line is completely outside the window." << endl;
    getch();
    closegraph();
	return 0;
}