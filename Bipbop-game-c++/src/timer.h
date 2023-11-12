class Timer : public Fl_Box {
	int secs=0;
    void draw() {
    	//starting time
        static int start = time(NULL);
        //time passed
        int tick = time(NULL) - start;
        //convert time into string with a time format
        char secs[80];
        sprintf(secs, "%02d:%02d", tick/60, tick%60);
        this->secs = tick;
        // set color
        fl_color(FL_BLACK);
        // place the timer on given coordinates
        fl_draw(secs,14,440);
    }
    static void Timer_CB(void *userdata) {
        Timer *o = (Timer*)userdata;
        o->redraw();
        Fl::repeat_timeout(0.25, Timer_CB, userdata);
    }
public:
    Timer(int X,int Y,int W,int H,const char*L=0) : Fl_Box(X,Y,W,H,L) {
        Fl::add_timeout(0.25, Timer_CB, (void*)this);

    }
    //get the time passed
    int getTimePassed() {
    	return secs;
    }
};

