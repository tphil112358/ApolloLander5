/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159 

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestLander;

/************************************
 * ANGLE
 ************************************/
class Angle
{
public:
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestLander;

   // Constructors
   Angle() : radians(0.0) {}                        // Default Constructor
   Angle(const Angle& rhs) : radians(rhs.radians) {}                // Copy Constructor
   Angle(double degrees) : radians(convertToRadians(degrees)) {}  // Non-default Constructor

   // Getters
   double getDegrees() const
   {
      return radians * (180 / M_PI);
   }

   double getRadians() const
   {
      return radians;
   }

   // Setters
   void setDegrees(double degrees)
   {
      this->radians = normalize(degrees * (M_PI / 180));
   }

   void setRadians(double radians)
   {
      this->radians = normalize(radians);
   }

   void setUp()
   {
      this->radians = 0.0;
   }

   void setDown()
   {
      this->radians = M_PI;
   }

   void setRight()
   {
      this->radians = M_PI / 2;
   }

   void setLeft()
   {
      this->radians = M_PI + M_PI / 2;
   }

   /************************************
   * Reverse
   * Adjusts the angle by reversing its direction.
   * Subtracts π radians (180 degrees) from the current angle
   * and normalizes the result to ensure the angle is in the range (0, 2π).
   ************************************/
   void reverse()
   {
      this->radians = normalize(radians - M_PI);
   }

   /************************************
   * Add
   * Adds a given delta (in radians) to the current angle.
   * After adding the delta, the result is normalized.
   * Returns a reference to the updated Angle object.
   ************************************/
   Angle& add(double delta)
   {
      radians += delta;
      radians = normalize(radians);
      return *this;
   };

private:
   double radians;

   double normalize(double rad) const;

   /************************************
   * Degrees to Radians
   * Recieves some amount of degrees as a double.
   * Multiplies it by pi / 180 to get radians and normalizes it.
   * Returns the normalized radians.
   ************************************/
   double convertToRadians(double degrees) const
   {
      double rad;
      rad = degrees * (M_PI / 180);
      rad = normalize(rad);
      return rad;
   }

   /************************************
   * Radians to Degrees
   * Recieves some amount of radians as a double.
   * Normalizes the radians and multiplies them by 180 / pi to get degrees.
   * Returns the normalized degrees.
   ************************************/
   double convertToDegrees(double rad) const
   {
      double degrees;
      degrees = normalize(rad);
      return degrees * (180 / M_PI);
   }
};