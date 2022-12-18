#ifndef CONTROL_H
#define CONTROL_H

#define WIDTH 900
#define HEIGHT 800

enum control_values { NONE = -1, SAVE,
                      X_ROTATE, Y_ROTATE, Z_ROTATE,
                      MOVE_UP, MOVE_RIGHT, MOVE_LEFT, MOVE_DOWN, EXIT, N_CONTROLS};

struct Control
{
   int left;
   int top;
   int right;
   int bottom;
};

void create_control(int, int, int);
int select_control();
void set_bg(const char*);
void save();

#endif