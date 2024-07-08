
/*Write C++ program to draw a concave polygon and fill it with desired color using scan fill
algorithm. Apply the concept of inheritance.*/

#include<graphics.h> 
#include<iostream>
using namespace std;

int main()
{

	int n,x[10],y[10],k=0,ymin=1000000,ymax=0,Y,dx,dy,xi[100],gm,gd, temp;
	float slope[100];
	cout<<"Enter the number of vertices:";
	cin>>n;
	cout<<"enter the coordinates of vertices X or Y:"<<"\n";
	for (int i=0;i<n;i++)
	{
	cin>>x[i]>>y[i];
	if(y[i]>ymax)
	ymax=y[i];
	if(y[i]<ymin)
	ymin=y[i];
	}
	
	detectgraph (&gd,&gm);
	initgraph(&gd,&gm,NULL);
	x[n]=x[0];y[n]=y[0];
	
	for(int i=0;i<n; i++)
	{
	line(x[i],y[i],x[i+1],y[i+1]);
	}
	for(int i=0;i<n;i++)
	{
	dx=x[i+1]-x[i];
	dy=y[i+1]-y[i];
	
	if(dy==0)
	slope[i]=1.0;
	if(dx==0)
	slope[i]=0.0;
	if(dx!=0 && dy!=0)
	slope [i]=(float)dx/dy;
	}
	for (int j=0; j<=ymax; j++)
	{
	int k=0;
	for(int i=0;i<n;i++)
	{
	if(((y[i]<=j) && y[i+1]>j) || ((y[i]>j) && (y[i+1]<=j)))
	{
	xi[k] = (int)(x[i] + slope[i]*(j - y[i]));
	k++;
	}
	}
	
	for(int m=0;m<k-1;m++)
	{
	for (int i=0;i<k-1; i++)
	{
	if(xi[i]>xi[i+1])
	{
	temp=xi[i];
	xi [i] = xi[i + 1] ;
	xi[i+1]=temp;
	}
	}
	setcolor (2);
	
	for(int i=0; i<k; i+=2)
	{
	line (xi[i],j,xi[i+1]+1, j); 
	delay(30);
	}
	}
	}
	getch();
	return 0;
}

