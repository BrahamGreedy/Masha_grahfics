#include "task.h"
#include "controls.h"
using namespace std;

Figure_3d::Figure_3d(){
   ifstream in("figure.txt");
   string line;
   string sym;
   
   if(in.is_open())
   {
      while (getline(in, line))
      {
         in >> sym;
         if (sym == "v")
         {
            double x, y, z;
            int id;
            in >> id >> x >> y >> z;
            points.push_back(Point(id, x * 10, y * 10, z * 10));
         }
         if (sym == "f")
         {
            vector<int> ids;
            for (int i = 0; i < 5; i++)
            {
               int id;
               in >> id; 
               ids.push_back(id);
            }
            figure.push_back(Face(ids));
         }
      }
   }
   in.close();
   move_to(WIDTH/2, HEIGHT/2, WIDTH/2);
}

void Figure_3d::move_to(int x, int y, int z)
{
   for (int i = 0; i < points.size(); i++)
   {
      points[i].x += x - center[0];
      points[i].y += y - center[1];
      points[i].z += z - center[2];
   }
   center[0] = x;
   center[1] = y;
   center[2] = z;
}

void Figure_3d::draw(int mode, int offset_x, int offset_y)
{
   for (int i = 0; i < surfaces.size(); i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (mode == 1)
            line(points[surfaces[i].ids[j]].x - offset_x, points[surfaces[i].ids[j]].y - offset_y, points[surfaces[i].ids[j + 1]].x - offset_x, points[surfaces[i].ids[j + 1]].y - offset_y);
         if (mode == 2)
             line(points[surfaces[i].ids[j]].z - offset_x, points[surfaces[i].ids[j]].y - offset_y, points[surfaces[i].ids[j + 1]].z - offset_x, points[surfaces[i].ids[j + 1]].y - offset_y);
         if (mode == 3)
            line(points[surfaces[i].ids[j]].x - offset_x, points[surfaces[i].ids[j]].z - offset_y, points[surfaces[i].ids[j + 1]].x - offset_x, points[surfaces[i].ids[j + 1]].z - offset_y);
      }
   }
}

void Figure_3d::resize(double scale)
{
   vector<double> t_center = center;
   move_to(0, 0, 0);
   for (int i = 0; i < points.size(); i++)
   {
      points[i].x = points[i].x + scale * points[i].x;
      points[i].y = points[i].y + scale * points[i].y;
      points[i].z = points[i].z + scale * points[i].z;
   }
   move_to(t_center[0], t_center[1], t_center[2]);
}

void Figure_3d::rotate(int mode, double angle)
{
   vector<double> t_center = center;
   move_to(0, 0, 0);
   double new_x, new_y, new_z;
   for (int i = 0; i < points.size(); i++)
   {
      if (mode == 3)
      {
         new_x = points[i].x * cos(angle) - points[i].y * sin(angle);
         new_y = points[i].x * sin(angle) + points[i].y * cos(angle);
         new_z = points[i].z;
      }
      if (mode == 1)
      {
         new_y = points[i].y * cos(angle) + points[i].z * sin(angle);
         new_z = -points[i].y * sin(angle) + points[i].z * cos(angle);
         new_x = points[i].x;
      }
      if (mode == 2)
      {
         new_x = points[i].x * cos(angle) + points[i].z * sin(angle);
         new_z = -points[i].x * sin(angle) + points[i].z * cos(angle);
         new_y = points[i].y;
      }
      points[i].x = new_x;
      points[i].y = new_y;
      points[i].z = new_z;
   }

   move_to(t_center[0], t_center[1], t_center[2]);
}

void Figure::move(int mode)
{
   int m_x = mousex();
   int m_y = mousey();
   
   if (mousebuttons() == 1)
   {
      if (mode == 1)
         move_to(m_x - delta_center[0], center[1], m_y - delta_center[2]);
      if (mode == 2)
         move_to(m_x - delta_center[0], m_y - delta_center[1], center[2]);
      return;
   }
   
   delta_center[0] = m_x - center[0];
   delta_center[1] = m_y - center[1];
   delta_center[2] = m_y - center[2];
}