#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{
	int r, xc, yc;
	cout<<"Enter radius of circle: ";
	cin>>r;
	cout<<"Enter center of circle: ";
	cin>>xc>>yc;
	
	int p=1-r;
	int x=0;
	int y=r;
	
	int col = RED;
	
	int gd= DETECT,gm;
	initgraph(&gd, &gm, NULL);
	
	do
	{
		putpixel(xc+x, yc+y, col);
		putpixel(xc+x, yc-y, col);
		putpixel(xc-x, yc-y, col);
		putpixel(xc+y, yc+x, col);
		putpixel(xc+y, yc-x, col);
		putpixel(xc-x, yc+y, col);
		putpixel(xc-y, yc+x, col);
		putpixel(xc-y, yc-x, col);
		
		if(p<0)
		{
			x=x+1;
			p=p+2*x+1;
			putpixel((x+xc), (y+yc), col);
		}
		else
		{
			x=x+1;
			y=y-1;
			p=p+2*x-2*y+1;
			putpixel((x+xc), (y+yc), col);
		}
	}
	while(x<=y);
	
	delay(12000);
	getch();
	closegraph();
	
	return 0;
}

