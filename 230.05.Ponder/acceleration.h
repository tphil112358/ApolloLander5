/***********************************************************************
 * Header File:
 *    ACCELERATION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once
#include "acceleration.h"

class TestAcceleration;
class TestVelocity;
class TestPosition;
class TestLander;
class Angle;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestLander;

public:
   // Constructors
   Acceleration() : ddx(0.0), ddy(0.0) {}
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) {}

   // Getters
   double getDDX() const
   {
      return ddx;
   }

   double getDDY() const
   {
      return ddy;
   }

   // Setters
   void setDDX(double ddx)
   {
      this->ddx = ddx;
   }

   void setDDY(double ddy)
   {
      this->ddy = ddy;
   }

   void set(const Angle& a, double magnitude);

   // Add functions
   void addDDX(double ddx)
   {
      this->ddx += ddx;
   }

   void addDDY(double ddy)
   {
      this->ddy += ddy;
   }

   void add(const Acceleration& rhs);

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};


