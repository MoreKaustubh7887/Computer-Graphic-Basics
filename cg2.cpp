
/*Write C++ program to implement Cohen Southerland line clipping algorithm.*/

#include<iostream>
#include<graphics.h>
using namespace std;

class lineclip
{
public:
int TOP=8,BOTTOM=4,LEFT=1,RIGHT=2;
int yh,yl,xh,xl;
float m;
int x1,x2,y1,y2,x,y;
int temp;
public:
int getcode(int x, int y);
int process();
};


int lineclip::getcode(int x, int y)
{
int code=0;
if(y>yh){
code |= TOP;}
if(y < yl){
code|=BOTTOM;}
if(x< xl){
code |= LEFT;}
if(x > xh){
code |= RIGHT;}
return code;
}


int lineclip::process()
{
int Code1, Code2;

cout<<"\n ENTER THE BL AND UR COORDINATE OF RECTANGLE:";
cin>>xl>>yl>>xh>>yh;

setcolor(YELLOW);
rectangle(xl,yl,xh,yh);

cout<<"\n enter the line coordinate:";
cout<<"\n starting coordinate:";
cin>>x1>>y1;
cout<<"\n ending coordinate:";
cin>>x2>>y2;

setcolor(BLUE);
line(x1,y1,x2,y2);
delay(10000);

Code1 = getcode(x1,y1);
Code2 = getcode(x2,y2);

int flag = 0;
while(1)
{
m=(float)(y2 - y1)/(x2 - x1);
if(Code1 == 0 && Code2 == 0)
{
flag = 1;
break ;
}
else if((Code1 & Code2) != 0)
{
break;
}
else
{
if(Code1 == 0)
temp = Code2;
else
temp = Code1;
if (temp & TOP)
{
x = x1 + (yh - y1)/m;
y=yh;
}
else if (temp & BOTTOM)
{
x = x1 + (yl - y1)/m;
y=yl;
}
else if (temp & LEFT)
{
y= y1 + m*(xl - x1);
x=xl;
}
else if(temp & RIGHT)
{
y= y1 +m*(xh - x1);
x=xh;
}


if(temp == Code1)
{
x1 = x;
y1 = y;
Code1=getcode(x1,y1);
}
else
{
x2 = x;
y2 = y;
Code2 = getcode(x2,y2);
}
}
}

cleardevice();
rectangle(xl,yl,xh,yh);
setcolor(YELLOW);

if(flag == 1)
line(x1,y1,x2,y2);
delay(100000);
getch();

closegraph();

}

int main()
{
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,NULL);

lineclip l;
l.process();

delay(60000);
closegraph();

return 0;
}
