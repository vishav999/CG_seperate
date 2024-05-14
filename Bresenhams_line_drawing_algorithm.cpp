#include <iostream>
#include <cmath>
#include <graphics.h>
using namespace std;
int main(){
	int x1,x2,y1,y2;
	cout<<"ENTER X & Y CO-ORDINATE FOR P"<<endl;
	cin>>x1>>y1;
	cout<<"ENTER X & Y CO-ORDINATE FOR Q"<<endl;
	cin>>x2>>y2;
	double dx=x2-x1;
	double dy=y2-y1;
	double m= dy/dx;
	double step=dx>dy?dx:dy;
	double step1= step;
	int* arrx= new int(step);
	int* arry= new int(step);
	arrx[0]=x1;
	arry[0]=y1;
    double p= 2*dy-dx;
    int t=1;
    while(m<1 && step!=0)
    {
    	if(p<0)
    	{
    		arrx[t]=arrx[t-1]+1;
    		arry[t]=arry[t-1];
    		t++;
    		p=p+2*dy;
		}
		else
		{
			arrx[t]=arrx[t-1]+1;
    		arry[t]=arry[t-1]+1;
    		t++;
    		p=p+2*dy-2*dx;
		}
		step--;
	}
	
	while(m>=1 && step!=0)
    {
    	if(p<0)
    	{
    		arrx[t]=arrx[t-1];
    		arry[t]=arry[t-1]+1;
    		t++;
    		p=p+2*dx;
		}
		else
		{
			arrx[t]=arrx[t-1]+1;
    		arry[t]=arry[t-1]+1;
    		t++;
    		p=p+2*dx-2*dy;			
		}
	    step--;
	}
	
	for(int i=0;i<=step1;i++)
	{
		cout<<i+1<<"->("<<arrx[i]<<","<<arry[i]<<")"<<endl;	
	}
	
	int gd= DETECT,gm;
	initgraph(&gd,&gm,NULL);
	for(int i=0;i<step1;++i){
		putpixel(arrx[i], arry[i], BLUE);
	}
	delay(12000);
	getch();
	closegraph();

	
	return 0;
}
