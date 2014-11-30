//
//  main.cpp
//  Soundex
//
//  Created by Justin Oroz on 10/15/14.
//  Copyright (c) 2014 jmoroz. All rights reserved.
//

#include "main.h"

Soundex::Soundex(const string &surname){
    name = surname;
    char val = '\0'; //stores the value of a character
    
    //convertName += toupper(name[0]); // Saves first letter
    for (int i = 0; i < name.length(); i++) { //Skips first letter
        if ((val = charVal(name[i]))) { //simultaneously filters vowels (+h,w) and saves the value of the char
            convertName += val;
        }
    }
    soundex = formatSoundex();
    
    
}

char Soundex::charVal(const char& in) { //Returns the value for the corresponding input
    
    switch (tolower(in)) { //checks the lowercase of the input
        case 'b':
        case 'f':
        case 'p':
        case 'v':
            return '1';
            break;
            
        case 'c':
        case 'g':
        case 'j':
        case 'k':
        case 'q':
        case 's':
        case 'x':
        case 'z':
            return '2';
            break;
            
        case 'd':
        case 't':
            return '3';
            break;
            
        case 'l':
            return '4';
            break;
            
        case 'm':
        case 'n':
            return '5';
            break;
            
        case 'r':
            return '6';
            break;
            
        case 'w':
        case 'h':
            return '-';
            break;
            
        default:
            return '_';
            break;
    }
}

string Soundex::formatSoundex () {
    string formatted, test;
    int i = 0, k; // i scans string, k moves forward to find duplicates ahead of i
    
    while (i < convertName.length()) {
        k=i;
        while ((convertName[k] == convertName[k+1]) || ((convertName[k] == convertName[k+2]) && (convertName[k+1] == '-'))){
            // Two same numbers are next to eachother OR same numbers are seperated by a 'w' or 'h' (see charVal)
            
            if (convertName[k+1] == '-') {
                k++; //skips an extra space if w or h
            }
            k++;
        }
        
        formatted.append(convertName.substr(i,1)); //adds number to end result
        i=k+1; //moves reader past last instance of duplicate number
    }
    
    formatted[0] = toupper(name[0]); //Repaces first number with the correct letter
    
    for (int r = (int) formatted.length(); r > 0; r--) {
        if (formatted[r-1] == '-' || formatted[r-1] =='_') {
            formatted.erase(r-1,1);
        }
    }
    
    while (formatted.length() < 4) {
        formatted.append("0");
    }
    
    formatted = formatted.substr(0,4);
    return formatted;
}

int main(int argc, const char * argv[]) {
    string surname;
    char ans = '\0';
    bool again;
    

    do {
        cout << "Enter a surname\n";
        cin >> surname;
        Soundex code(surname);
        
        cout << "Soundex: " << code.output() << endl;
        
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        
        // end Soundex code, just setting up repeat now
        cout << "\nCheck another name? (y/n)\n";
        cin >> ans;
        
        switch (ans) {
            case 'y':
            case 'Y':
                again = true;
                break;
            case 'n':
            case 'N':
                again = false;
                cout << "Exiting...\n";
                break;
            default:
                cout << "ERROR: Unknown characacter. Exiting...\n";
                again = false;
                break;
        }
        cout << endl;
    } while (again);

    return 0;
}


