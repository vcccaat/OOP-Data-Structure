#include <cstring>      /* File: conversion-constructor-default-arg.cpp */
class Word
{
    int frequency; char* str;
  public:
    Word(const char* s, int k = 1)   // Still conversion constructor!
    {
    	frequency = k;
        str = new char [strlen(s)+1]; strcpy(str, s);
    }
};

int main()
{
    // same as Word("action"), {} is for char 
    Word *p = new Word {"action"};   // Explicit conversion
    // need delete p to delete Word
    Word movie("Titanic");           // Explicit conversion
    Word director = "James Cameron"; // Implicit conversion
}


    // char *p = "ab";
    // char pp{'a'};
    // cout<<p<<endl;   ab
    // cout<<p[1]<<endl;   b
    // cout<<&p<<endl;   address
    // cout<<pp<<endl;   a