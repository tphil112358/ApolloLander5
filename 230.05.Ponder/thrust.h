/***********************************************************************
 * Header File:
 *    Thrust : Represents activation of thrusters
 * Author:
 *    Br. Helfrich
 * Summary:
 *    down, clockwise, and counterclockwise
 ************************************************************************/

#pragma once

#include "uiInteract.h"  // for Interface

class TestLander;
class TestThrust;

 /*****************************************************
  * THRUST
  * Represents activation of thrusters
  *****************************************************/
class Thrust
{
   friend TestLander;
   friend TestThrust;
   
public:
   // Thrust is initially turned off
   Thrust() : mainEngine(false), clockwise(false), counterClockwise(false) {}
   
   // Get rotation in radians per second
   double rotation() const
   {
      double radians = 0.0; 
      if (isClock()) 
      {
         radians += 0.1;
      }
      if (isCounter()) 
      {
         radians += -0.1;
      }
      return radians;
      
   }

   // get main engine thrust in  m / s ^ 2
   double mainEngineThrust() const
   {
      double thrust = 45000.0 / 15103.0;
      return thrust;
   }

   // reflect what is firing
   bool isMain()    const { return mainEngine; }
   bool isClock()   const { return clockwise; }
   bool isCounter() const { return counterClockwise; }

   // set the thrusters
   void set(const Interface * pUI)
   {
      if (pUI->isRight() > 0)              // If the user is pressing right, turn on counterClockwise.
      {
         counterClockwise = true;
      }
      else                                 // If the user is not pressing right, turn off counterClockwise.
      {
         counterClockwise = false;
      }
      if (pUI->isLeft() != 0)              // If the user is pressing left, turn on clockwise.
      {
         clockwise = true;
      }
      else                                 // If the user is not pressing left, turn off clockwise.
      {
         clockwise = false;
      }
      if (pUI->isDown() != 0)              // If the user is pressing down, turn on mainEngine.
      {
         mainEngine = true;
      }
      else                                 // If the user is not pressing down, turn off mainEngine.
      {
         mainEngine = false;
      }
   }

private:
   bool mainEngine;
   bool clockwise;
   bool counterClockwise;
};
