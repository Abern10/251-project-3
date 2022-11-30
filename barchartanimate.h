// barchartanimate.h
// Program 3: Animated Bar Graph
// Course: CS 251, Fall 2022. Thursday 12pm lab
// System: Windows 10 PC using VS Code

//Author: Alexander Bernatowicz
//
// The Animated Bar Graph Project reads an inputed file and print data from that file, updating on each frame.
// For example on the cities.txt file the animation will print the most populous citites in the world for
// every year from 1500-2018. Printing the most populous in order largest printing first. The barchart.h file
// prints output all bars on a certain frame.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;
    int colorIndex;

    void ifSizeIsLessThanCapacity(ifstream &file){
        string line, year, name, country, category;
        int value, groupOfRecords;

        getline(file, line); // skips empty line
            if(file.eof()){
                return;
            }
            
            getline(file, line); // gets group of records
            groupOfRecords = stoi(line);

             // stores the line above each frame
            BarChart bc(groupOfRecords); // holds an individual barchart for each group of records

            for(int i = 0; i < groupOfRecords; i++){
                getline(file, line); // gets a line in data
                readingEachLine(line, year, name, country, category, value, bc);
            }

            this->barcharts[size] = bc;
            this->size++;
    }
    // function to parse each line in the file
    void readingEachLine(string line, string &year, string &name, string &country, string &category, int &value, BarChart &bc){
        stringstream ss(line);
        string temp;
        getline(ss, year, ',');
        getline(ss, name, ',');
        getline(ss, country, ',');
        getline(ss, temp, ',');
        getline(ss, category, ',');

        value = stoi(temp);
        // creates bar with passed parameters
        bc.addBar(name, value, category);
        bc.setFrame(year);

        if(colorMap.count(category) == 0){
            if(colorIndex == 7){
                colorIndex = 0;
            }
            colorMap[category] = COLORS[colorIndex];
            colorIndex++;
        }
    }
    // function to double capacity
    void addSize(){
        int doubledCapacity = capacity * 2;
        BarChart* newBC = new BarChart[doubledCapacity];

        for(int i = 0; i < this->size; ++i){
            newBC[i] = barcharts[i];
        }
        delete[] barcharts;
        barcharts = newBC;
        capacity = doubledCapacity;
    }

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        barcharts = new BarChart[4];
        size = 0;
        capacity = 4;
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
        colorIndex = 0;
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        delete[] barcharts;
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
        // checks to see if barCharts has run out of space, doubles if it has
        if(this->size == this->capacity){
            addSize();
        }
        // if size of barCharts is less then capacity
        ifSizeIsLessThanCapacity(file);
        
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
        int stop ;
        if(endIter == -1){
            endIter = this->size;
        }
        else{
            stop = endIter;
        }
        // prints all bars through each frame iteration and clears console of previous frame
        for(int i = 0; i < stop; i++){
            top = barcharts[i].getSize();
            usleep(3 * microsecond);
            output << CLEARCONSOLE;
            output << BLACK << title << endl;
            output << BLACK << source << endl;
            barcharts[i].graph(output, colorMap, top);
            output << BLACK << xlabel << endl;
            output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
        }
	}

    void animate(ostream &output, int top, int endIter, int frameRate){
		unsigned int microsecond = frameRate;
        int stop ;
        if(endIter == -1){
            endIter = this->size;
        }
        else{
            stop = endIter;
        }
        // prints all bars through each frame iteration and clears console of previous frame
        for(int i = 0; i < stop; i++){
            top = barcharts[i].getSize();
            usleep(3 * microsecond);
            output << CLEARCONSOLE;
            output << BLACK << title << endl;
            output << BLACK << source << endl;
            barcharts[i].graph(output, colorMap, top);
            output << BLACK << xlabel << endl;
            output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
        }
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        return size;
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
        if(i < 0 || i > this->size){
            __throw_out_of_range("BarChartAnimate: i out of bounds");
        }
        else{
            return barcharts[i];
        }
    }
};
