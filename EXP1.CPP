#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main()
{
    clrscr();
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    setbkcolor(20);
    setcolor(RED);
    circle(100,100,50);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(100, 100, RED);
    outtextxy(75,98,"CIRCLE");
    int maxX = getmaxx();
    int maxY = getmaxy();
    int rectWidth = 190;
    int rectHeight = 80;
    int x1=maxX-rectWidth;
    int y1 = maxY - rectHeight;
    int x2 = maxX;
    int y2 = maxY;
    setcolor(BLUE);
    rectangle(x1,y1,x2,y2);
    outtextxy(270,100,"RECTANGLE");
    setcolor(YELLOW);
    line(455,85,555,85);
    outtextxy(490,95,"LINE");
    setcolor(BLUE);
    arc(80, 350, 10, 80, 100);
    setcolor(RED);
    ellipse(380,300,0,360,40,80);
    outtextxy(355,300,"ELLIPSE");
    getch();
}