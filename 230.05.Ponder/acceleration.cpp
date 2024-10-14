/***********************************************************************
 * Source File:
 *    ACCELERATION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about changing speed
 ************************************************************************/

#include "acceleration.h"
#include "angle.h"

#include <cmath>

 /*********************************************
  * ACCELERATION : ADD
  *  a += a
  *********************************************/
void Acceleration::add(const Acceleration& acceleration)
{
   this->ddx += acceleration.getDDX();
   this->ddy += acceleration.getDDY();
}


/*********************************************
 * ACCELERATION : SET
 *  set from angle and direction by using
 * cos and sin to isolate the x and y factors of these vectors
 *********************************************/
void Acceleration::set(const Angle& angle, double magnitude)
{
   this->ddx = magnitude * sin(angle.getRadians());  // x-component
   this->ddy = magnitude * cos(angle.getRadians());  // y-component
}
