#include <string>

class Brick: public Fl_Box {
	private:
		int x;
		int y;
		int integrity = 10;

	public:
		Brick(int x, int y);
		int getX();
		int getY();
		int getIntegrity();
		void setIntegrity();
		void show_integrity();
};

Brick::Brick(int x, int y) : Fl_Box(x,y,40,40) {
	//set coordinates
	this->x = x;
	this->y = y;
}

char* intToStr(int data) {
	// convert the integer integrity into string
    string strData = std::to_string(data);
    char* temp = new char[strData.length() + 1];
    strcpy(temp, strData.c_str());
    return temp;
}

void Brick::show_integrity(){
	// show each brick's integrity on them as a label
	this->label(intToStr(this->getIntegrity()));
	this->draw_label(this->getX(), this->getY(), 40, 40, FL_ALIGN_CENTER );

}

//Getters
int Brick::getX() {
	return this->x;
}

int Brick::getY() {
	return this->y;
}

int Brick::getIntegrity() {
	return this->integrity;
}

// Decreases the integrity number by one
void Brick::setIntegrity() {
	this->integrity--;
}

// Class to store and draw each of the bricks
class Bricks {
	private:
	int col;
	int row;

	public:
	Bricks(int row,int col);
	void draw();
	vector<Brick*> body;
};

Bricks::Bricks(int row,int col) {
	this->row = row;
	this->col = col;
}

//Draw the bricks according to the row and column number
void Bricks::draw() {
	int i, j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			Brick *br = new Brick(20 + (50*j), 30 + (50*i));
			br->show_integrity();
		    //shape and color
			br->box(FL_FLAT_BOX);
		    br->color(FL_CYAN);
			this->body.push_back(br);
			br->show();
		}
	}
}


