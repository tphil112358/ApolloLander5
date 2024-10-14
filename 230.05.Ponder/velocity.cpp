/***********************************************************************
 * Source File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#include "velocity.h"
#include "acceleration.h"
#include "angle.h"

#include <math.h>  // for sqrt()

 /*********************************************
  * VELOCITY : ADD WEEK 1
  *  v = v_0(dx and dy) + a t
  *********************************************/
void Velocity::add(const Acceleration& acceleration, double time)
{
   this->dx = dx + (acceleration.getDDX() * time);
   this->dy = dy + (acceleration.getDDY() * time);
}


/*********************************************
 * VELOCITY : GET SPEED
 *  find the magnitude of velocity
 *********************************************/
double Velocity::getSpeed() const
{
   return sqrt(dx * dx + dy * dy);
}

/*********************************************
 * VELOCITY : SET
 *  set from angle and direction WEEK1
 *********************************************/
void Velocity::set(const Angle& angle, double magnitude)
{
   this->dx = magnitude * sin(angle.getRadians());
   this->dy = magnitude * cos(angle.getRadians());

}