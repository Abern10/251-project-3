// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// TO DO: Nothing for the standard application, just compile and run! However,
// before submitting you need to add your creative component.
//
// Adam Koehler
// U. of Illinois, Chicago
// Fall 2022
//
// Original iteration of program developed by:
// Shanon Reckinger
// U. of Illinois, Chicago 

// Milestone 5 Creative Component 
// The Creative component that I have implemented allows the user to change the frame speed of the program allowing to either run the program faster or slower.
// To run the create component please comment out line 53.
// Then uncomment lines 55-57.

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;


int main() {
	int frameSpeed = 50000;
	string filename;
	cout << "Enter filename: ";
	cin >> filename;
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);

	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}

	// Comment out the line below
	bca.animate(cout, 12, -1);
	// Uncomment the lines below 55-57
	// cout << "Enter a frame speed to run the program: ";
	// cin >> frameSpeed;
	// bca.animate(cout, 12, -1, frameSpeed);

    return 0;
}
