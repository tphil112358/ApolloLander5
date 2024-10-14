/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

/************************************
* Normalize
* Recieves some amount of radians as a double.
* Truncates the radian value and expresses it in its simplest form. (0 < x < 2pi)
* Returns the normalized radians.
************************************/
double Angle::normalize(double rad) const
{
   rad = fmod(rad, M_PI * 2); // Sets rad as the remainder of radians / 2pi, which can be positive or negative.
   if (rad < 0)
      rad = rad + M_PI * 2; // Makes negative radians positive while preserving their position on the unit circle.
   return rad;
}