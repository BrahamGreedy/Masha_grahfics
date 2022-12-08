#ifndef CONTROL_H
#define CONTROL_H
#define COLOR_MAX BLACK
#define WIDTH 800
#define HEIGHT 800

enum control_values { NONE = -1, EXIT, SAVE,
                      CREATE_ROUNDS, FILL, 
                      N_CONTROLS };

struct Control
{
   int left;
   int top;
   int right;
   int bottom;
};

void create_control(int, int, int, const char*);
void create_background(const char *file_name);
int select_control();

#endif