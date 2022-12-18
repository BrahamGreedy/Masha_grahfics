#pragma once

#include <vector>
#include <graphics.h>
#include <string>
#include <fstream>
#include "controls.h"
using namespace std;

struct Point{
   int id;
   double x, y, z;
   Point(int id, double x, double y, double z): id(id), x(x), y(y), z(z) {}
};

struct Surface{
   vector<int> ids;
   Surface(vector<int> ids): ids(ids) {}
};

class Figure_3d{
   vector<Point> points;
   vector<Surface> surfaces;
   vector<double> center = {0, 0, 0};
   vector<int> delta_center = {0, 0, 0};
public:
   Figure_3d();
   void draw(int, int, int);
   void move_to(int, int, int);
   void move(int);
   void rotate(int, double);
   void resize(double);
};