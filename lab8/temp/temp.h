#pragma once




using namespace std;

struct Point{
   int id;
   double x, y, z;
   Point(int id, double x, double y, double z): id(id), x(x), y(y), z(z) {}
};

struct Surface{
   vector<int> ids; // Идентификаторы точек из которых состоит грань
   Surface(vector<int> ids): ids(ids) {}
};

class Figure_3d{
   vector<Point> points;
   vector<Surface> surfaces;
   int center[3] = {0};
   int d_center[3] = {0};
public:
   Figure_3d();
   void draw(int, int, int);
   void move_to(int, int, int);
   void move();
   void rotate(_abracadabra_cast(int);