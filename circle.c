#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>


int main(){
    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;

    // printf("enter x-coordinates : \n");
    // scanf("%d %d %d",&xa,&xb,&xc);
    // printf("enter y-coordinates : \n");
    // scanf("%d %d %d",&ya,&yb,&yc);
    int n;
    printf("Enter number for algo : ");
    scanf("%d",&n);
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");


    getch();
    return 0;
}