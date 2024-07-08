

/*Write a C++ program to implement bouncing ball using sine wave form. Apply the concept
of polymorphism.*/

#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{

int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,NULL);

int y,x,angle;
angle=0;

setcolor(BLUE);
for (x=0;x<getmaxx();x+=3){
y=50*sin(angle*3.141/180);
y = getmaxy()/2 - y;
circle(x,y,30);
floodfill(x,y,YELLOW);
delay(30);
angle+=5;
cleardevice();
}


delay(6000);
closegraph();

return 0;
}
