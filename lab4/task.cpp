#include <task.h>
#include <math.h>
#include <string>
#include <graphics.h>
#include <control.h>
#include <cstdlib>
#define M_PI 3.1415926535

using namespace std;

bool is_created = false;

void circ(int x0, int y0, int r){
   int color = COLOR_MAX;
   int x=0, y=r, p=3-2*r;
   while(x<=y){
      putpixel(x0 + x, y0 + y,color);
      putpixel(x0 + x, y0 - y,color);
      putpixel(x0 - x, y0 + y,color);
      putpixel(x0 - x, y0 - y,color);
      putpixel(x0 + y, y0 + x,color);
      putpixel(x0 + y, y0 - x,color);
      putpixel(x0 - y, y0 + x,color);
      putpixel(x0 - y, y0 - x,color);
      if(p>0){
         p+=4*(x-y)+10;
         y--;
      }
      else{
         p+=4*x+6;
      }
      x++;
   }
}

void rand_fill(int x0, int y0){
   int x,y;
   double df=M_PI/6, da=df/2;

   int color[7];
   int R1[3]= {30,180,280};
   int R2[4]= {30,110,160,250};
   for (int i=0; i<7; i++){
      color[i]=rand()%WHITE;
   }
   for (int i=0; i<3; i++){
      setfillstyle(SOLID_FILL,color[i]);
      for (int j=0; j<12; j++){
         x=x0+R1[i]*cos(j*df);
         y=y0+R1[i]*sin(j*df);
         floodfill(x,y,COLOR_MAX);
      }
   }
   for (int i=0; i<4; i++){
      setfillstyle(SOLID_FILL,color[3+i]);
      for (int j=0; j<12; j++){
         x=x0+R2[i]*cos(j*df+da);
         y=y0+R2[i]*sin(j*df+da);
         floodfill(x,y,COLOR_MAX);
      }
   }
}

void circles(int x0, int y0, int r){
   for(int i = 0; i<12; i++){
      circ(x0+r*cos((M_PI/6)*i), y0+r*sin((M_PI/6)*i),  r);
   }
}

void create_rounds(){
   circles(WIDTH/2, 350,150);
   is_created = true;
}

void fill(){
   if(is_created){
      while(mousebuttons()!=0);
      rand_fill(400,350);
   }
}

void save(){
   int width, height;
   IMAGE *output;

   width  = getmaxx() + 1;
   height = getmaxy() + 1;
   output = createimage(width, height);

   getimage(0, 0, width - 1, height - 1, output);
   saveBMP("output.jpg", output);
   freeimage(output);
}