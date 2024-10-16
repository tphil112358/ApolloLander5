/**********************************************************************
 * LAB 06
 * Lunar Lander simulation. This is the Game class and main()
 **********************************************************************/

#include "position.h"    // everything should have a point
#include "angle.h"       // angle of the lander
#include "uiInteract.h"  // for INTERFACE
#include "uiDraw.h"      // for RANDOM and DRAW*
#include "ground.h"      // for GROUND
#include "test.h"        // for the unit tests
#include "star.h"
#include <cmath>         // for SQRT
#include <cassert>       // for ASSERT
#include <array>
#include <iostream>
#include <random>
#include "position.h"    // everything should have a point
#include "angle.h"       // angle of the lander
#include "uiInteract.h"  // for INTERFACE
#include "uiDraw.h"      // for RANDOM and DRAW*
#include "ground.h"      // for GROUND
#include "test.h"        // for the unit tests
#include <cmath>         // for SQRT
#include <cassert>       // for ASSERT
#include <array>
#include <iostream>
#include <random>
using namespace std;


/*************************************************************************
 * SIMULATOR
 * Everything pertaining to the simulator.
 *************************************************************************/
class Simulator
{
public:
   // set up the simulator
   Simulator(const Position& posUpperRight) : ground(posUpperRight) {}

   // display stuff on the screen
   void display();

   Angle a;
   Ground ground;
};

/**********************************************************
 * DISPLAY
 * Draw on the screen
 **********************************************************/
void Simulator::display()
{
   ogstream gout;

   // draw the stars
   Star stars(400.0, 400.0);
   stars.draw(gout);

   // draw the ground
   ground.draw(gout);

   // draw the lander
   Position posLander(100, 300);
   gout.drawLander(posLander, a.getRadians());
}


/*************************************
 * CALLBACK
 * Handle one frame of the simulator
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator* pSimulator = (Simulator*)p;

   // draw the game
   pSimulator->display();

   // handle input
   if (pUI->isRight())
      pSimulator->a.add(-0.1);   // Change the angle of the lander to rotate right
   if (pUI->isLeft())
      pSimulator->a.add(0.1);   // Chnage the angle of the lander to rotate left
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my LM type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ LPSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Run the unit tests
   testRunner();

   // Initialize OpenGL
   Position posUpperRight(400, 400);
   Interface ui("Lunar Lander", posUpperRight);

   // Initialize the game class
   Simulator simulator(posUpperRight);

   // set everything into action
   ui.run(callBack, (void*)&simulator);

   return 0;
}