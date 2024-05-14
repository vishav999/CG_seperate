#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

int main()
{
	int a, b, xc, yc;
	cout<<"Enter a: ";
	cin>>a;
	cout<<"Enter b: ";
	cin>>b;
	cout<<"Enter center of circle: \n";
	cin>>xc>>yc;
	
	int x=0;
	int y=b;
	int col = RED;
	
	int gd= DETECT,gm;
	initgraph(&gd, &gm, NULL);
	
	double d1 = pow(b, 2) - ((pow(a, 2))*b) + (0.25*(pow(a, 2)));
	
	while((2*(pow(b, 2))*x)>(2*(pow(a, 2))*y))
	{
		putpixel(x + xc, y + yc, col);
		putpixel(-x + xc, y + yc, col);
		putpixel(-x + xc, -y + yc, col);
		putpixel(x + xc, -y + yc, col);
		
		if(d1<0)
		{
			x=x+1;
			y=y;
			d1 = d1 + (pow(b, 2))*(2*x+3);
			putpixel(x + xc, y + yc, col);
		}
		else
		{
			x=x+1;
			y=y-1;
			d1 = d1 + (pow(b, 2)*(2*x+3))+(pow(a, 2)*(-2*y+2));
			putpixel(x + xc, y + yc, col);
		}
	}
	
	double d2 = pow(b, 2)*pow((x+0.5), 2) + pow(a, 2)*pow((y-1), 2) - pow(a, 2)*pow(b, 2);
	while(y>0)
	{
		putpixel(x + xc, y + yc, col);
		putpixel(-x + xc, y + yc, col);
		putpixel(-x + xc, -y + yc, col);
		putpixel(x + xc, -y + yc, col);
		
		if(d2<0)
		{
			x=x+1;
			y=y-1;
			d2 = d2 + pow(b, 2)*(2*x+2) + pow(a, 2)*(-2*y+3);
			putpixel(x + xc, y + yc, col);
		}
		else
		{
			y = y-1;
			x = x;
			d2 = d2 + pow(a, 2)*(-2*y+3);
			putpixel(x + xc, y + yc, col);
		}
	}
	delay(12000);
	closegraph();
	return 0;	
}
