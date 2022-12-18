#include <task.h>
#include <math.h>
#include <string>
#include <graphics.h>
#include <control.h>
#define M_PI acos(0.0)*2.0

using namespace std;

void create_line(int x1, int y1)
{
   int x0 = getx(), y0 = gety();
   int sx, sy, dx, dy, p;
   
   sx = x0 > x1 ? -1 : 1;
   sy = y0 > y1 ? -1 : 1;
   dx = abs(x1 - x0);
   dy = abs(y1 - y0);

   if (dx >= dy)
   {
      p = 2 * dy - dx;
      for (int i = x0; i != x1; i += sx)
      {
         putpixel(i, y0, getcolor());
         y0 = p > 0 ? y0 + sy : y0;
         p = p > 0 ? p + 2 * (dy - dx) : p + 2 * dy;
      }
   }
   else
   {
      p = 2 * dx - dy;
      for (int i= y0; i != y1; i += sy)
      {
         putpixel(x0, i, getcolor());
         x0 = p > 0 ? x0 + sx : x0;
         p = p > 0 ? p + 2 * (dx - dy) : p + 2 * dx;
      }
   }
    putpixel(x1, y1, getcolor());
}

void draw_star(int x0, int y0, int R, int n)
{
   setcolor(RED);
    double r = (R * cos(2 * M_PI / n)) / cos(M_PI / n);
    double da = M_PI / n;
    
    for (int k = 0; k < 2 * n + 1; k++)
    {
        int l = k % 2 == 0 ? R : r;
        double x = (x0 + l * cos(k * da));
        double y = (y0 + l * sin(k * da));
        if (k == 0) moveto(x, y);
        create_line(x, y);
        moveto(x, y);
    }
   delay(10);
   floodfill(x0, y0, getcolor());
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