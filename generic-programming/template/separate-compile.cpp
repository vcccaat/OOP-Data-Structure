/* File: max.h */
template <typename T> inline const T&
    my_max(const T& a, const T& b);

/* File: max.cpp */
template <class T> inline const T&
    my_max(const T& a, const T& b) { return (a < b) ? b : a; }
