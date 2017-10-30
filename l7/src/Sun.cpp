#include "Sun.hpp"

Sun::Sun(float rad, int res, float r, float g, float b)
{
   float ang = (M_PI * 2) / res;

   _vec.push_back(0.0);
   _vec.push_back(0.0);
   _vec.push_back(0.0);

   _col.push_back(0.0);
   _col.push_back(0.0);
   _col.push_back(0.0);
  

   //std::cout << "new Sun OBj\n";
   for (int i = 0; i < res; i++)
   {
      _vec.push_back(rad * cos (ang * i)); //x
      _vec.push_back(rad * sin (ang * i)); //y
      _vec.push_back(1.0);  //z or whatevs
      _col.push_back(r); //r
      _col.push_back(g); //g
      _col.push_back(b); //b
      

      _vec.push_back((rad / 2) * cos (ang * i + (ang / 2))); //x
      _vec.push_back((rad / 2) * sin (ang * i + (ang / 2))); //y
      _vec.push_back(0.0);  //z or whatevs
      _col.push_back(r); //r
      _col.push_back(g); //g
      _col.push_back(b); //b
      


   }
   for ( int i = 1; i < res * 2; i++) 
   {
      _ind.push_back(0);
      _ind.push_back(i);
      _ind.push_back(i + 1);

      _ind.push_back(0);
      _ind.push_back(i + 1);
      _ind.push_back(i + 2);
   } 
   _ind.push_back(0);
   _ind.push_back(res * 2);
   _ind.push_back(1);

  // _ind.push_back(0);
  // _ind.push_back(res * 2 - 1);
  // _ind.push_back(res * 2);

 //  _ind.push_back(0);
 //  _ind.push_back(res * 2);
 //  _ind.push_back(1);
}
