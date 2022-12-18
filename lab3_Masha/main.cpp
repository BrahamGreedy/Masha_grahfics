#include <iostream>
#include <graphics.h>
#include <control.h>
#include <task.h>

using namespace std;

int main()
{
   initwindow(WIDTH,HEIGHT,"Stars");
   create_background("bg.jpg");
   
   create_control_mini(INCREASE_R,1,341);
   create_control_mini(DECREASE_R,80,420);
   create_control_mini(INCREASE_N,624,341);
   create_control_mini(DECREASE_N,548,418);
   
   create_control_maxi(EXIT,385,421);
   create_control_maxi(SAVE,184,423);
   
   canvas(CANVAS);
   
   int R=20, N=5;
   
   while(1)
   {
      while(mousebuttons()!=1);
      switch(select_control())
      {
         case CANVAS:
            draw_star(mousex(),mousey(),R,N);
            break;
         case INCREASE_R:
            R=R+5;
            show_number(R,0);
            delay(100);
            break;
         case DECREASE_R:
            if(R>5)
               R=R-5;
            show_number(R,0);
            delay(100);
            break;
         case INCREASE_N:
            N++;
            show_number(N,1);
            delay(100);
            break;
         case DECREASE_N:
            if(N>3)
               N--;
            show_number(N,1);
            delay(100);
            break;
         case SAVE:
            save();
            break;
         case EXIT:
            return 0;
         
      }
   }
}