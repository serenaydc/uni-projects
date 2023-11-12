class Paddle: public Fl_Box {
	private:
		int x;
		int y;
	public:
		Paddle(int x, int y);
		int getX();
		int getY();
		void move(int newX, int newY);
		int handle(int event);

};

Paddle::Paddle(int x=240, int y=460) : Fl_Box(x,y,120,20) {
	//set the coordinates
	this->x = x;
	this->y = y;
	//shape and color
	this->box(FL_FLAT_BOX);
	this->color(FL_MAGENTA);

	this->show();
}

// Getters
int Paddle::getX(){
    return this->x;
}
int Paddle::getY(){
    return this->y;
}

// Move
void Paddle::move(int newX, int newY){
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

// FLTK handler for keys
int Paddle::handle(int event) {
    switch(event){
    case FL_KEYDOWN:
    	// If left key pressed, move left 20 units
        if(Fl::event_key() == FL_Left){
        	if (x-20 >= 0) {
            	this->move(x-20, y);
        	}
            return 1;
        }
        // If right key pressed, move left 20 units
        else if(Fl::event_key() == FL_Right){
        	if (x+20 <= 520) {
        		this->move(x+20, y);
        	}
            return 1;
        }
        return Fl_Widget::handle(event);
    }

}

