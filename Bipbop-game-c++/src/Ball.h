#include <time.h>
extern int dir;
extern int win;
extern int lives;
extern int time_limit;
#include "Paddle.h"
#include <cmath>
#include "timer.h"


class Ball: public Fl_Box {
	private:
		int x;
		int y;
		Paddle* paddle;
		Bricks* bricks;
		Timer* timer;
		static void Play(void *userdata);
		double angle;
		int dir; // 1- TopRight, 2- TopLeft, 3- BottomLeft, 4-BottomRight

	public:
		Ball(int x, int y, Paddle* p, Bricks* b, Timer* t);
		int getX();
		int getY();
		void move(int newX, int newY);
		void changeDirection();
		void ballHitPaddle(Paddle *p);
		void ballHitBrick(Bricks *b);

};

Ball::Ball(int x, int y, Paddle* p, Bricks* b, Timer* t) : Fl_Box(x,y,20,20) {
	//set coordinates
	this->x = x;
	this->y = y;

	srand (time(NULL));
	this->angle = 22.5;
	this->dir = rand()%4+1; //random direction at the beginning
	this->paddle = p;
	this->bricks = b;
	this->timer = t;
	//shape and color
	this->box(FL_OFLAT_BOX);
	this->color(FL_GREEN);
	Fl::add_timeout(0.01, Play, (void*)this);
	this->show();
}

void Ball::Play(void *userdata) {
    Ball *ball = (Ball*)userdata;
    ball->ballHitPaddle(ball->paddle);
    ball->ballHitBrick(ball->bricks);
    ball->changeDirection();
    Fl::repeat_timeout(0.01, Play, userdata);
    if (win==1) {  // if player broke all the bricks before the time limit
    	Fl::remove_timeout(Play, userdata);
    }
    if (lives==0) { // if player has spent all three of their lives
    	Fl::remove_timeout(Play, userdata);
    }
    if (ball->timer->getTimePassed() >= time_limit) { // if the time limit has been reached
    	Fl::remove_timeout(Play, userdata);
    }
}

void Ball::ballHitBrick(Bricks* b) {
	//Check if ball touched any of the bricks
	for (int i=0; i< b->body.size(); i++) {
		Brick *cur_brick = b->body[i];
		if (x >= cur_brick->getX() - 20 && x <= cur_brick->getX()+40) {
			if (y == cur_brick->getY()+40){ // if ball hits the brick from below
				if (dir==1) {
					dir=4;
				}
				else if (dir==2) {
					dir=3;
				}
				cur_brick->setIntegrity();
				cur_brick->show_integrity();
			}
			else if (y == cur_brick->getY()-20){ // if ball hits the brick from above
				if (dir==3) {
					dir=2;
				}
				else if (dir==4) {
					dir=1;
				}
				cur_brick->setIntegrity();
				cur_brick->show_integrity();
			}
			else if (y < cur_brick->getY()+40 && y> cur_brick->getY()-20) { // if ball hits the brick from the sides
				if (dir==1) {
					dir=2;
				}
				else if (dir==2) {
					dir=1;
				}
				else if (dir==3) {
					dir=4;
				}
				else if (dir==4) {
					dir=3;
				}
				cur_brick->setIntegrity();
				cur_brick->show_integrity();
			}
		}

		// if brick's integrity is zero, hide it and remove from the vector
		if (cur_brick->getIntegrity() == 0) {
			cur_brick->hide();
			b->body.erase( b->body.begin() + i );
		}
		// if there are no more bricks, the player wins
		if (b->body.size() == 0) {
		    	win = 1;
		    }
	}
}

void Ball::changeDirection() {
	// Ball's movement when it does not hit the paddle or the bricks
	// If it moves to the window boundaries, it bounces back

	if( dir == 1) { // TOP RIGHT
		this->move(x+int(2/tan(angle)),y-2);
		if( x >= 640-20 ){
			dir = 2;
	    }
	    else if( y <= 0 ){
	    	dir = 4;
	    }
	}
	else if( dir == 2) { // TOP LEFT
		this->move(x-int(2/tan(angle)), y-2);
		if( y <= 0 ){
			dir = 3;
		}
		else if( x <= 0  ){
			dir = 1;
		}
	}
	else if( dir == 3) { // BOTTOM LEFT
		this->move(x-int(2/tan(angle)), y+2);

		if( y >= 460 ){
			lives--;
			this->move(200,200);
		}
		else if( x <= 0  ){
			dir = 4;
		}
	}
	else if( dir == 4) { // BOTTOM RIGHT
		this->move(x+int(2/tan(angle)), y+2);
		if( x >= 640-20  ){
			dir = 3;
		}
		else if( y >= 460 ){
			lives--;
			this->move(200,200);
		}
	}
}

void Ball::ballHitPaddle(Paddle *p){
	// if the ball is touching the paddle
	// hitting the ball with the corners of the paddle is also taken into account
	if( y + 20 == p->getY()) {
		if( (x >= p->getX()-10) && (x <= p->getX()+120+10)) {
			if ( dir == 3 ) {
				dir = 2;
	        }
	        if ( dir == 4 ) {
	        	dir = 1;
	        }
	        // if the ball touches the edges of the paddle, the angle becomes 22.5
			if ((x >= p->getX()-10) && (x <= p->getX()+24)) {
				angle = 22.5;
	        }
			if ((x >= p->getX()+120-24) && (x <= p->getX()+130)) {
				angle = 22.5;
			}
		}
	}
}


void Ball::move(int newX, int newY){
    // hide the block
    this->hide();
    // set the new coordinates
    this->x = newX;
    this->y = newY;
    // reposition the block
    this->position(newX, newY);
    // show the block
    this->show();
}



// Getters
int Ball::getX(){
    return this->x;
}
int Ball::getY(){
    return this->y;
}
