#include "controls.h"

coord buttons[N_BUTTONS];

void create_bg(const char* file){
   IMAGE *image = loadBMP(file);
   putimage(0, 0, image, COPY_PUT);
   freeimage(image);
}

void create_button(int n, int x, int y, const char* file){
   IMAGE *image = loadBMP(file);
   buttons[n].x1 = 1;
   buttons[n].y1 = 1;
   buttons[n].x2 = 1;
   buttons[n].y2 = 1;
   putimage(x, y, image, COPY_PUT);
   freeimage(image);
}

void save(){
   IMAGE *output = createimage(WIDTH+1, HEIGHT+1);
   getimage(0, 0, WIDTH, HEIGHT, output);
   saveBMP("output.jpg", output);
   freeimage(output);
}

int select_control()
{
   int x, y;
   
   x = mousex();
   y = mousey();
   
   for (int i = 0; i < N_BUTTONS; i++)
   {
      if (x > buttons[i].x1 && x < buttons[i].x2 &&
          y > buttons[i].y1  && y < buttons[i].y2)
      {
         return i;
      }
   }
   
   return -1;
}