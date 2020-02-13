#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void plotPoint(int xcentre, int ycentre, int x, int y)
{
    putpixel(xcentre + x, ycentre + y, GREEN);
    putpixel(xcentre + x, ycentre - y, GREEN);
    putpixel(xcentre - x, ycentre + y, GREEN);
    putpixel(xcentre - x, ycentre - y, GREEN);
}

void elipse(int xcentre, int ycentre, int rx, int ry)
{
    int p, px, py, x, y;
    int rx2, ry2;
    int tworx, twory;

    ry2 = ry * ry;
    rx2 = rx * rx;
    twory = 2 * ry2;
    tworx = 2 * rx2;

    x = 0;
    y = ry;
    plotPoint(xcentre, ycentre, x, y);

    p = abs(ry2 - rx2 * ry + (0.25 * rx2));
    px = 0;
    py = tworx * y;
    
    while (px<py)
    {
        x++;
        px += twory;
        if(p>=0){
            y--;
            py-=tworx;
        }
        if(p<0){
            p+=ry2 + px;
        }else
        {
            p+= ry2 + px -py;
        }
        plotPoint(xcentre,ycentre,x,y);
        
    }

    p = abs(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y-1) * (y-1) - rx2*ry2);

    while(y>0){
        y--;
        py-= tworx;
        if(p<=0){
            x++;
            px+=twory;
        }
        if(p>0){
            p+= p + rx2 - py;
        }
        else
        {
            p+= rx2 -py + px;
        }
        plotPoint(xcentre,ycentre,x,y);
        
    }
    
}

int main()
{
    int gdriver = DETECT, gmode, error, x0, y0, x1, y1;

    int xcentre =100,ycentre=100,rx=30,ry=20;

    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
    elipse(xcentre,ycentre,rx,ry);
    getch();
    return 0;
}