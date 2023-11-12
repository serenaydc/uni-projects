//============================================================================
// Name        : Project.cpp
// Author      : Serenay
//============================================================================

using namespace std;
// Vector header
#include <vector>
//FLTK headers
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Timer.H>
#include <FL/Fl_Text_Display.H>
// Brick Header
#include "Brick.h"
// Ball Header
#include "Ball.h"


int lives = 3; // 3 lives at the beginning
int win = 0;
int time_limit = 300; // 5 minutes

int main() {

    // Create a window
    Fl_Window window(100,100, 640, 480, "Bip-bop");

    // Create timer
    Timer *tim = new Timer(10, window.w()-60, 50, 50);

    // Create bricks
    Bricks *brcks = new Bricks(3,12);
    brcks->draw();

    // Create the paddle
    Paddle *paddle = new Paddle(240, 460);

    // Create the ball
    Ball ball(300,240,paddle,brcks,tim);

    window.show();

    return Fl::run();

}


