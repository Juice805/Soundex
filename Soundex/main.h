//
//  main.h
//  Soundex
//
//  Created by Justin Oroz on 10/15/14.
//  Copyright (c) 2014 jmoroz. All rights reserved.
//

#ifndef Soundex_main_h
#define Soundex_main_h


#endif

#include <iostream>
#include <string>
using namespace std;

class Soundex {
public:
    Soundex(const string&);
    
    string output(){
        return soundex;
    }
    
    string surname(){
        return name;
    }
private:
    string name, convertName, soundex;// original name, converted name (Pre-shortened, all numbers), final Soundex code
    char charVal(const char&); // return the value of the char
    string formatSoundex (); //formats the converted name to the 4 character standard

};