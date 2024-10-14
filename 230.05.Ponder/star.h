/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Br. Helfrich
 * Summary:
 *    A single star that twinkles
 ************************************************************************/

#pragma once
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for RANDOM and DRAWSTAR
#include <array>
#include <map>
#include <random>

 /*****************************************************
  * STAR
  * A star that twinkles
  *****************************************************/
class Star
{
public:
   Star(double width, double height) : width(width), height(height)
   {
      initialize(width, height);
   }

   void draw(ogstream& gout)
   {
      for (auto& star : stars)
      {
         star.second += 1; // Increment phase
         gout.drawStar(star.first, star.second); // Draw star at position with phase
      }
   }

   void reset()
   {
      std::uniform_int_distribution<> killAStar(0, stars.size() - 1); // Random star index
      std::mt19937 gen(rd()); // Random number generator

      auto it = std::next(stars.begin(), killAStar(gen)); // Get a random star
      std::uniform_real_distribution<> xDis(0.0, width); // Random x-coordinates
      std::uniform_real_distribution<> yDis(0.0, height); // Random y-coordinates

      // Reset star position and phase
      it->first = Position(xDis(gen), yDis(gen));
      it->second = 0; // Reset phase to 0
   }

private:
   std::map<Position, unsigned char> stars;
   std::random_device rd;

   double width;
   double height;

   void initialize(double width, double height)
   {
      std::mt19937 gen(rd()); // Random number generator
      std::uniform_real_distribution<> xDis(0.0, width); // Random x-coordinates
      std::uniform_real_distribution<> yDis(0.0, height); // Random y-coordinates
      std::uniform_int_distribution<> pDis(0, 225);      // Random phases

      for (int i = 0; i < 50; ++i) // Generate 50 stars
      {
         Position pos(xDis(gen), yDis(gen));
         unsigned char phase = static_cast<unsigned char>(pDis(gen));
         stars[pos] = phase;
      }
   }
};