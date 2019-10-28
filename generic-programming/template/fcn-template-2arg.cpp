#include <iostream>     /* File: fcn-template-2arg.cpp */
using namespace std;
    
template <typename T1, typename T2> inline const T1&
    my_max(const T1& a, const T2& b) { return (a < b) ? b : a; }

int main()
{
    cout << my_max(4, 5.5) << endl; // T1 is int, T2 is double
    cout << my_max(5.5, 4) << endl; // T1 is double, T2 is int
}
