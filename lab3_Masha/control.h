#ifndef CONTROL_H
#define CONTROL_H
#define WIDTH 700
#define HEIGHT 500

enum control_values { NONE = -1, EXIT, SAVE, INCREASE_R, DECREASE_R, INCREASE_N, DECREASE_N, CANVAS, N_CONTROLS};

struct Control
{
   int x0;
   int y0;
   int x1;
   int y1;
};


void create_control_mini(int,int,int);
void create_control_maxi(int,int,int);
void canvas(int);
void create_background(const char*);
int select_control();

#endif