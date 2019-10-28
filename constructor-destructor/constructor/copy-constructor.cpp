#include <iostream>     /* File: copy-constructor.cpp */
#include <cstring> 
using namespace std;

class Word
{
  private:
    int frequency; char* str;
    void set(int f, const char* s)
        { frequency = f; str = new char [strlen(s)+1]; strcpy(str,s); }  //doesn't include \0 as strlen
  public:
    Word(const char* s, int k = 1)
        { set(k, s); cout << "conversion\n"; }
    Word(const Word& w) 
        { set(w.frequency, w.str); cout << "copy\n"; }
};

int main() 
{
    Word movie("Titanic");       // which constructor?  explicit conv
    Word song(movie);            // which constructor?  explicit copy
    Word ship = movie;           // which constructor?  implicit copy
    Word actress {"Kate"};       // which constructor?  explicit conv
}

