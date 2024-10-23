/***********************************************************************
 * Source File:
 *    LANDER
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the information about the lunar lander
 ************************************************************************/

#include "lander.h"
#include "acceleration.h"
#include <iostream> // TEMP

#include <math.h>  // for cos() and sin()

 /***************************************************************
  * RESET
  * Reset the lander and its position to start the game over
  ***************************************************************/
void Lander::reset(const Position& posUpperRight)
{
   angle.setDegrees(0.0);
   status = PLAYING;
   fuel = 5000.0;
   velocity.setDX(random(-10, -4));
   velocity.setDY(random(-2, 2));
   pos.setX(99);
   pos.setY(random(posUpperRight.getY() * .75, posUpperRight.getY() * .90));

}

/***************************************************************
 * DRAW
 * Draw the lander on the screen
 ***************************************************************/
void Lander::draw(const Thrust& thrust, ogstream& gout, double elevation) const
{
   gout.setPosition(Position(20, 380));
   gout << "Fuel: " << fuel << "lbs\n";
   gout.precision(3);
   if (isFlying())
      gout << "Altitude: " << elevation << " m\n";
   else
      gout << "Altitude: 0 m\n";
   gout << "Speed: " << velocity.getSpeed() << " m/s\n";

   gout.drawLander(pos, angle.getRadians());     // Draw the Lander.

   if (fuel > 0 && isFlying())
   {
      gout.drawLanderFlames(pos, angle.getRadians(), thrust.isMain(), thrust.isCounter(), thrust.isClock());  // Draw the flames.
   }

   if (isLanded())
   {
      gout.setPosition(Position(130, 300));
      gout << "The Eagle Has Landed\n";
   }
}

/***************************************************************
 * INPUT
 * Accept input from the Neil Armstrong
 ***************************************************************/
Acceleration Lander::input(const Thrust& thrust, double gravity)
{
   Acceleration a;
   if (fuel > 10)
   {
      if (thrust.isClock() == true)  // change the angle if the clockwise thruster is on.
      {
         angle.add(thrust.rotation());
         fuel -= 1;
      }
      if (thrust.isCounter() == true)  // change the angle if the counter-clockwise thruster is on.
      {
         angle.add(thrust.rotation());
         fuel -= 1;
      }
      if (thrust.isMain() == true && fuel >= 10)  // if the main thrust is on, adjust the position.
      {
         a.setDDX(thrust.mainEngineThrust() * -(sin(angle.getRadians())));
         a.addDDY(thrust.mainEngineThrust() * cos(angle.getRadians()));
         fuel -= 10;
      }
   }
   else
      fuel = 0;

   if (isFlying()) // Don't apply gravity once the lander is on the surface
      a.addDDY(gravity);

   return a;
}

/******************************************************************
 * COAST
 * What happens when we coast?
 *******************************************************************/
void Lander::coast(Acceleration& acceleration, double time)
{
   if (isFlying())
   {
      pos.add(acceleration, velocity, time);         // update the position.
      velocity.addDX(acceleration.getDDX() * time);  // update the velocity.
      velocity.addDY(acceleration.getDDY() * time);
   }
}