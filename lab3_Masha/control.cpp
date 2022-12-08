#include <graphics.h>
#include <control.h>

Control controls[N_CONTROLS];

void create_control_mini(int n,int x0,int y0)
{
   controls[n].x0=x0;
   controls[n].y0=y0;
   controls[n].x1=x0+75;
   controls[n].y1=y0+75;
}

void create_control_maxi(int n,int x0,int y0)
{
   controls[n].x0=x0;
   controls[n].y0=y0;
   controls[n].x1=x0+140;
   controls[n].y1=y0+75;
}

void canvas(int n)
{
   controls[n].x0=1;
   controls[n].y0=1;
   controls[n].x1=699;
   controls[n].y1=330;
}

void create_background(const char* image_name)
{
   IMAGE *image=loadBMP(image_name);
   putimage(0,0,image,COPY_PUT);
   freeimage(image);
}

int select_control()
{
   int x, y;
   
   x = mousex();
   y = mousey();
   
   for (int i = 0; i < N_CONTROLS; i++)
   {
      if (x > controls[i].x0 && x < controls[i].x1 &&
          y > controls[i].y0  && y < controls[i].y1)
      {
         return i;
      }
   }
   
   return NONE;
}