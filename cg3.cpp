
/*a) Write C++ program to draw the following pattern. Use DDA line and Bresenham‘s circle
drawing algorithm. Apply the concept of encapsulation.
OR
b) Write C++ program to draw the following pattern. Use DDA line and Bresenham‘s circle
drawing algorithm. Apply the concept of encapsulation.
*/
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void DDA_line(int x1,int y1,int x2,int y2,int icolour)
{
	int i;
	float dx,dy,steps,Xinc,Yinc,X,Y;
	dx=(x2-x1);
	dy=(y2-y1);
	if (fabs(dx)>fabs(dy))
	{
		steps=fabs(dx);
	}
	else
	{
		steps=fabs(dy);
	}
	Xinc=dx/steps;
	Yinc=dy/steps;
	
	X=x1;
	Y=y1;
	for(i=0;i<steps;i++)
	{
		putpixel (floor(X),floor(Y),icolour);
		X=X+Xinc;
		Y=Y+Yinc;
	}
}

class bricircle
{
	int xi,yi,sig1,sig2 ,del;
	int limit, r;
	int x,y,z;
	void circle(int x,int y,int z);
	void mh();
	void mb();
	void mv();
};
void bricircle::circle(int x,int y,int z)
{
	limit=0;
	xi=0;
	yi=r;
	del=2*(1-r);
	while (yi>=limit)
	{
		putpixel(x+xi,y+yi,RED);
		putpixel(x+xi,y-yi,RED);
		putpixel(x-xi,y-yi,RED);
		putpixel(x-xi,y+yi,RED);
	}
	if(del<0)
	{
		sig1=((2*del)+(2*yi)-1);
		if (sig1<=0)
		{
			mh();
		}
		else
		{
			mb();
		}
	}
	else if (del>0)
	{
		sig2+((2*del)-(2*xi)-1);
		if (sig2<=0)
		{
			mb();
		}
		else
		{
			mv();
		}
	}
	else if(del==0)
	{
		mb();
	}
}
void bricircle::mh()
{
	x=xi+1;
	del=del+2*xi+1;
}
void bricircle::mv()
{
	yi=yi+1;
	del=del-2*y+1;
}
void bricircle::mb()
{
	xi=xi+1;
	yi=yi-1;
	del=del+2*xi-2*yi+2;
}
void program_A()
{
	DDA_line(60,140,60,260,YELLOW);
	delay(200);
	DDA_line(60,260,340,260,BLUE);
	delay(200);
	DDA_line(340,260,340,140,YELLOW);
	delay(200);
	DDA_line(340,140,60,140,BLUE);
	delay(200);
	
	DDA_line(200,140,60,200,RED);
	delay(200);
	DDA_line(60,200,200,260,GREEN);
	delay(200);
	DDA_line(200,260,340,200,RED);
	delay(200);
	DDA_line(340,200,200,140,GREEN);
	delay(200);
	
	bricircle is;
	setcolor(MAGENTA);
	circle(200,200,55);
	delay(5000);
}
void program_B()
{
	bricircle is;
	setcolor(BLUE);
	circle(200,200,140);
	delay(200);
	
	DDA_line(200,60,320,270,RED);
	delay(200);
	DDA_line(200,60,80,270,GREEN);
	delay(200);
	DDA_line(320,270,80,270,WHITE);
	delay(200);
	
	setcolor(CYAN);
	circle(200,200,70);
	delay(5000);
}


int main()
{
	void DDA_line(int x1,int y1,int x2,int y2,int icolour);
	int Choice;
	int gd,gm;
	gd=DETECT;
	
	cout<<"program A:1"<<endl;
	cout<<"program B:2"<<endl;
	cout<<"exit:3"<<endl;
	
	
	cout<<"enter your choice:"<<endl;
	cin>>Choice;
	initgraph(&gd,&gm,NULL);
	
	switch(Choice)
	{
	case 1:
		program_A();
		break;
	case 2:
		program_B();
		break;
	
	case 3:
		cout<<"exit the program";
		exit(0);
		break;
	default:
		cout<<"wrong choice";
		
		exit(0);
		break;
	}
	closegraph();
	
	return 0;
}
