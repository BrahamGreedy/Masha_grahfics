#include "task.h"
#include "control.h"

int main(){
   initwindow(WIDTH, HEIGHT);
   Polyhedron figure = Polyhedron();
   set_bg("bg.jpg");
   create_control(X_ROTATE, 0, 0);
   create_control(Y_ROTATE, 0, 75);
   create_control(Z_ROTATE, 0, 150);
   create_control(MOVE_UP, 0, 225);
   create_control(MOVE_RIGHT, 0, 300);
   create_control(MOVE_LEFT, 0, 375);
   create_control(MOVE_DOWN, 0, 450);
   create_control(EXIT, 0, 645);
   create_control(SAVE, 0, 730);
   figure.draw(0);
   while(1){
      while(mousebuttons() != 1);
      switch(select_control()){
         case X_ROTATE:
            figure.rotate(0);
            set_bg("bg.jpg");
            figure.draw(0);
            break;
         case Y_ROTATE:
            figure.rotate(1);
            set_bg("bg.jpg");
            figure.draw(0);
            break;
         case Z_ROTATE:
            figure.rotate(2);
            set_bg("bg.jpg");
            figure.draw(0);
            break;
         case MOVE_UP:
            figure.move(1, 1);
            set_bg("bg.jpg");
            figure.draw(0);
            break;
         case MOVE_RIGHT:
            figure.move(0, 1);
            set_bg("bg.jpg");
            figure.draw(0);
            break;
         case MOVE_LEFT:
            figure.move(0, -1);
            set_bg("bg.jpg");
            figure.draw(0);
            break;
         case MOVE_DOWN:
            figure.move(1, -1);
            set_bg("bg.jpg");
            figure.draw(0);
            break;
         case SAVE:
            save();
            break;
         case EXIT:
            return 0;
      }
   }
}