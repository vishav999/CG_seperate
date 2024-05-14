#include <iostream>
#include <cmath>
#include <graphics.h>

//Plotting Graph in DDA
using namespace std;
int main(){
	int x1,x2,y1,y2;
	cout<<"ENTER X & Y CO-ORDINATE FOR P"<<endl;
	cin>>x1>>y1;
	cout<<"ENTER X & Y CO-ORDINATE FOR Q"<<endl;
	cin>>x2>>y2;
	cout<<"P->("<<x1<<","<<y1<<")"<<endl;
	double dx=x2-x1;
	double dy=y2-y1;
	double step=dx>dy?dx:dy;
	int* arrx= new int(step);
	int* arry= new int(step);
	arrx[0]=x1;
	arry[0]=y1;
	double xinc=dx/step;
	double yinc=dy/step;
	double x=x1;
	double y=y1;
	for(int i=0;i<step;i++)
	{
		x=x+xinc;
		arrx[i+1]=round(x);
		y=y+yinc;
		arry[i+1]=round(y);
		cout<<"P"<<i+1<<"->("<<round(x)<<","<<round(y)<<")"<<endl;
	}
//	int size = sizeof(arrx)/sizeof(arrx[0]);
	int gd= DETECT,gm;
	initgraph(&gd, &gm, NULL);
	for(int i=0;i<step;++i){
		putpixel(arrx[i], arry[i], YELLOW);
		//line(arrx[i],arry[i],arrx[i+1],arry[i+1]);
	}
	delay(12000);
	getch();
	closegraph();
	for(int i=0;i<step;i++)
	{
		cout<<arrx[i]<<endl;	
	}
	for(int i=0;i<step;i++)
	{
		cout<<arry[i]<<	endl;
	}
	
	return 0;
}
