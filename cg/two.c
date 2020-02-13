#include<stdio.h>
#include<graphics.h>
#include<math.h>
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
int main(){
	int gd = DETECT, gm;
//	char ip = '0';
	int x[3]={20,100,120};
	int y[3]={100,120,100};
	int i;
//	int faltu;
//	printf("Press\n a) for dda\nb) for bresenham\nc) for exit\n");	
//
//	printf("Enter Choice\n");
//	scanf("%c",&ip);	
//	while(ip!='c'){
//	printf("Enter 3 x-points\n");
//	for(i=0;i<3;i++){
//		scanf("%d",x+i);	
//	}
//	printf("Enter 3 y-points\n");
//	for(i=0;i<3;i++){
//		scanf("%d",y+i);	
//	}	
//	if(ip=='a'){
		initgraph(&gd,&gm,"");	
		for(i=0;i<3;i++){
			dda(x[i],y[i],x[(i+1)%3],y[(i+1)%3]);		
		}
//		getch();
//		closegraph();
//	}
//	else if(ip=='b'){
//		initgraph(&gd,&gm,"");
		for(i=0;i<3;i++){
			bh(x[i],y[i],x[(i+1)%3],y[(i+1)%3]);		
		}
		delay(5000);

		closegraph();	
//	}
//	else if(ip=='c'){
//		break;
//	}
//	else{
//		printf("Enter valid Character\n");	
//	}
//	scanf("%d",&faltu);
//	printf("Enter Choice\n");
//	scanf("%c",&ip);
//}
}
