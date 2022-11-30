// bar.h
// Program 3: Animated Bar Graph
// Course: CS 251, Fall 2022. Thursday 12pm lab
// System: Windows 10 PC using VS Code

//Author: Alexander Bernatowicz
//
// The Animated Bar Graph Project reads an inputed file and print data from that file, updating on each frame.
// For example on the cities.txt file the animation will print the most populous citites in the world for
// every year from 1500-2018. Printing the most populous in order largest printing first. The bar.h file sets
// and stores input for an individual bar.

#include <iostream>
#include <string>
#include "myrandom.h" // used in graders, do not remove
using namespace std;
//
// Bar
//
class Bar {
 private:
    string name, category;
    int value;

 public:

    // default constructor:
    Bar() {
        name = "";
        value = 0;
        category = "";
    }

    //
    // a second constructor:
    //
    // Parameter passed in constructor Bar object.
    //
    Bar(string name, int value, string category) {
        this->name = name;
        this->value = value;
        this->category = category;
        
    }

    // destructor:
    virtual ~Bar() {
        
        // destructor not needed here
        
    }

    // getName:
	string getName() {
        return name;
	}

    // getValue:
	int getValue() {
        return value;
	}

    // getCategory:
	string getCategory() {
        return category;
	}

	// operators
    // TO DO:  Write these operators.  This allows you to compare two Bar
    // objects.  Comparison should be based on the Bar's value.  For example:
	bool operator<(const Bar &other) const {
        return this->value < other.value;
	}

	bool operator<=(const Bar &other) const {
        return this->value <= other.value;
	}

	bool operator>(const Bar &other) const {
        return this->value > other.value;
	}

	bool operator>=(const Bar &other) const {
        return this->value >= other.value;
	}
};

