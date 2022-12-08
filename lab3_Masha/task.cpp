#include <task.h>
#include <math.h>
#include <string>
#include <graphics.h>
#include <control.h>
#define M_PI 3.1415926535

using namespace std;

void create_line(int x1, int y1)
{
   int x0=getx();
   int y0=gety();
   int rx=abs(x0-x1);
   int ry=abs(y0-y1);
   int sx=1,sy=1;
   if(x0>x1) sx=-1;
   if(y0>y1) sy=-1;
   int p;
   if(rx>=ry)
   {
      p=2*ry-rx;
      for(x0;x0!=x1;x0=x0+sx)
      {
         putpixel(x0,y0,getcolor());
         if(p>0)
         {
            y0=y0+sy;
            p=p+2*(ry-rx);
         }
         else
            p=p+2*ry;
      }
   }
   else
   {
      p=2*rx-ry;
      for(y0;y0!=y1;y0=y0+sy)
      {
         putpixel(x0,y0,getcolor());
         if(p>0)
         {
            x0=x0+sx;
            p=p+2*(rx-ry);
         }
         else
            p=p+2*sx;
      }
   }
   putpixel(x1, y1, getcolor());
}

void draw_star(int x0, int y0, int R, int n)
{
   setcolor(YELLOW);
   double r=0, h=0, x=0,y=0;
   int k=0;
   r=(R * cos(2 * M_PI / n)) / cos(M_PI / n);
   h=M_PI / n;
   for(int i=0; i<2*n+1;i++)
   {
      if(i%2==0)
         k=R;
      else 
         k=r;
      x=x0+k*cos(i*h);
      y=y0+k*cos(i*h);
      if(i==0)
         moveto(x,y);
      create_line(x,y);
      moveto(x,y);
   }
   floodfill(x0,y0,getcolor());
}

void show_number(int n, int choose)
{
   setfillstyle(SOLID_FILL, BLACK);
   if(choose==0)
   {
      bar(20, 440, 74, 480);
      setcolor(WHITE);
      outtextxy(24, 444, to_string(n).c_str());
   }
   else
   {
      bar(634, 440, 700, 500);
      setcolor(WHITE);
      outtextxy(636, 444, to_string(n).c_str());
   }
}

void save()
{
   IMAGE *screen;
   screen=createimage(WIDTH+1, HEIGHT+1);
   getimage(0,0,WIDTH,HEIGHT,screen);
   saveBMP("screen.bmp", screen);
}