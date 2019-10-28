class Clock             /* File: postoffice8.h */
{
  private:
    int HHMM;           // hour, minute
  public:
    Clock(int hhmm) : HHMM(hhmm)
        { cout << "Clock Constructor at "<< HHMM << endl; }
    ~Clock() { cout << "Clock Destructor at " << HHMM << endl; }
};

class Postoffice
{
  private:
    Clock clock;   //with MIL, don't need to initilize the data member again
  public:
    Postoffice() : clock(800) { cout << "Postoffice Constructor\n"; }
    ~Postoffice() { cout << "Postoffice Destructor\n"; }
};
