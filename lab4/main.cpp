#include <iostream>
#include <graphics.h>
#include "control.h"
#include "task.h"

using namespace std;


int main()
{
   initwindow(WIDTH, HEIGHT, "Chocolate&rounds");
   setfillstyle(SOLID_FILL, COLOR(247, 243, 227));
   floodfill(1,1,COLOR(247, 243, 227));
   setbkcolor(COLOR(247, 243, 227));
   setcolor(COLOR(111, 26, 7));
   
   create_backgroung("bg.jpg");
   create_control(CREATE_ROUNDS, 0, HEIGHT-100,"create.jpg");
   create_control(FILL, 200, HEIGHT-100,"paint.jpg");
   create_control(SAVE, 400, HEIGHT-100,"save.jpg");
   create_control(EXIT, 600, HEIGHT-100,"exit.jpg");
   
   while(true){
      while(mousebuttons() != 1);
      switch(select_control()){
         case NONE:
            break;
         case CREATE_ROUNDS:
            create_rounds();
            break;
         case FILL:
            fill();
            break;
         case SAVE:
            save();
            break;
         case EXIT:
            return 0;
      }
   }
}