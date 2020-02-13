#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void bh(int x0, int y0, int x1, int y1)
{
 	int	dx=abs(x1-x0);
	int dy=abs(y1-y0);
	int x,y,xEnd,yEnd;
	
 	float m=(float)(y1-y0)/(x1-x0);

 	if(m<=1&&m>=(-1)){
 	if(x0>x1){
		x=x1;
		y=y1;
		xEnd=x0;
	}
	else{
		x=x0;
		y=y0;
		xEnd=x1;
	}	putpixel(x,y,GREEN);
 		int p=2*dy-dx;
 		while(x<xEnd){
 			x++;
 			if(p<0)
 				p+=2*dy;
 			else{
 			if(m<0)	y--;
 			else y++;
 				p+=(2*dy-2*dx);
 			}
 			putpixel(x,y,GREEN);
 		}
 	}
 	else{
 	if(y0<y1){
		x=x1;
		y=y1;
		yEnd=y0;
	}
	else{
		x=x0;
		y=y0;
		yEnd=y1;
	}	putpixel(x,y,GREEN);
 		int p=2*dx-dy;
 		while(y>yEnd){
 			y--;
 			if(p<0)
 				p+=2*dx;
 			else{
 				if(m>0)x--;
 				else x++;
 				p+=(2*dx-2*dy);
 			}
 			putpixel(x,y,GREEN);
 		}
 	}
}
void dda(int x1,int y1,int x2,int y2)
{
int dx,dy,m,s;
float xi,yi,x,y;
dx = x2 - x1;
dy = y2 - y1;

if (abs(dx) > abs(dy))
s = abs(dx);
else
s = abs(dy);

xi = dx / (float) s;
yi = dy / (float) s;

x = x1;
y = y1;

putpixel(x1, y1, RED);

for (m = 0; m < s; m++)
{
x += xi;
y += yi;
putpixel(x, y, RED);
}

}
int main(){
    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;
    printf("1 : dda\n");
    printf("2 : brasenham\n");
    printf("3 : exit\n");


    int xa=20,xb=70,ya=100,yb=30,xc=120,yc=100;
    // printf("enter x-coordinates : \n");
    // scanf("%d %d %d",&xa,&xb,&xc);
    // printf("enter y-coordinates : \n");
    // scanf("%d %d %d",&ya,&yb,&yc);
    int n;
    printf("Enter number for algo : ");
    scanf("%d",&n);
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
    switch(n){
        case 1:
            printf("this is dda");  
            dda(xa,ya,xb,yb);
            dda(xb,yb,xc,yc);
            dda(xc,yc,xa,ya);
            break;
        case 2:
            printf("this is brasenham");  
            bh(xa,ya,xb,yb);
            bh(xb,yb,xc,yc);
            bh(xc,yc,xa,ya);
            break;
        default :
            break;
    }

    getch();
    return 0;
}