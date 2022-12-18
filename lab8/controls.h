#pragma once

#include <graphics.h>
#define HEIGHT 600
#define WIDTH 800

enum Controls {X_MOVE, Y_MOVE, Z_MOVE, X_ROTATE, Y_ROTATE, Z_ROTATE, SAVE, EXIT, N_BUTTONS};

struct coord{
   int x1, y1;
   int x2, y2;
};

void create_bg(const char*);
void create_button(int, int, int, const char*);
void save();
int select_control();

