// Program 3: Animated Bar Graph
// Course: CS 251, Fall 2022. Thursday 12pm lab
// System: Windows 10 PC using VS Code

//Author: Alexander Bernatowicz
//
// The Animated Bar Graph Project reads an inputed file and print data from that file, updating on each frame.
// For example on the cities.txt file the animation will print the most populous citites in the world for
// every year from 1500-2018. Printing the most populous in order largest printing first. This file are all the
// tests that I used while writing the program.
#include <iostream>
#include "barchartanimate.h"
using namespace std;

//////////////////////// bar.h tests 
bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool testBarGetName(){
	Bar b("Chicago", 9234324, "US");
	if(b.getName() != "Chicago"){
		cout << "testBarGetName failed" << endl;
		return false;
	}
	cout << "testBarGetName passed!" << endl;
	return true;
}

bool testBarGetValue(){
	Bar b("Chicago", 9234324, "US");
	if(b.getValue() != 9234324){
		cout << "testBarGetValue failed" << endl;
		return false;
	}
	cout << "testBarGetValue passed!" << endl;
	return true;
}

bool testBarGetCategory(){
	Bar b("Chicago", 9234324, "US");
	if(b.getCategory() != "US"){
		cout << "testBarGetCategory failed";
		return false;
	}
	cout << "testBarGetCategory passed!" << endl;
	return true;
}

bool testBarLessThanOperator(){
	Bar b1("a", 1, "cat");
	Bar b2("b", 2, "cat");
	
	if(b1 < b2){
		cout << "testLessThanOperator passed!" << endl;
		return true;
	}
	else{
		cout << "testLessThanOperator failed" << endl;
		return false;
	}
}

bool testBarLessThanOperator2(){
	Bar b1("a", 1, "cat");
	Bar b2("b", 3, "cat");
	
	if(b1 < b2){
		cout << "testLessThanOperator2 passed!" << endl;
		return true;
	}
	else{
		cout << "testLessThanOperator2 failed" << endl;
		return false;
	}
}

bool testBarLessThanEqualToOperator(){
	Bar b1("a", 1, "cat");
	Bar b2("b", 2, "cat");
	
	if(b1 <= b2){
		cout << "testLessThanEqualToOperator passed!" << endl;
		return true;
	}
	else{
		cout << "testLessThanEqualToOperator failed" << endl;
		return false;
	}
}
bool testBarLessThanEqualToOperator2(){
	Bar b1("a", 1, "cat");
	Bar b2("b", 1, "cat");
	
	if(b1 <= b2){
		cout << "testLessThanEqualToOperator2 passed!" << endl;
		return true;
	}
	else{
		cout << "testLessThanEqualToOperator2 failed" << endl;
		return false;
	}
}

bool testBarGreaterThanOperator(){
	Bar b1("a", 1, "cat");
	Bar b2("b", 2, "cat");
	
	if(b2 > b1){
		cout << "testGreaterThanOperator passed!" << endl;
		return true;
	}
	else{
		cout << "testGreaterThanOperator failed" << endl;
		return false;
	}
}
bool testBarGreaterThanOperator2(){
	Bar b1("a", 1, "cat");
	Bar b2("b", 3, "cat");
	
	if(b2 > b1){
		cout << "testGreaterThanOperator2 passed!" << endl;
		return true;
	}
	else{
		cout << "testGreaterThanOperator2 failed" << endl;
		return false;
	}
}

bool testBarGreaterThanEqualToOperator(){
	Bar b1("a", 1, "cat");
	Bar b2("b", 2, "cat");
	
	if(b2 >= b1){
		cout << "testGreaterThanEqualToOperator passed!" << endl;
		return true;
	}
	else{
		cout << "testGreaterThanEqualToOperator failed" << endl;
		return false;
	}
}

bool testBarGreaterThanEqualToOperator2(){
	Bar b1("a", 2, "cat");
	Bar b2("b", 2, "cat");
	
	if(b2 >= b1){
		cout << "testGreaterThanEqualToOperator2 passed!" << endl;
		return true;
	}
	else{
		cout << "testGreaterThanEqualToOperator2 failed" << endl;
		return false;
	}
}
//////////////////////// bar.h tests end

//////////////////////// barchart.h tests
bool testBarChartDefaultConstructor() {
	BarChart bc;
	if(bc.getFrame() != ""){
		cout << "Barchart getFrame() failed!";
		return false;
	}
	else if (bc.getSize() != 0){
		cout << "Barchart getSize() failed!";
		return false;
	}
    cout << "testBarChartDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarChartParamConstructor(){
	BarChart bc(3);
	if(bc.getFrame() != ""){
		cout << "Barchart getFrame() failed!";
		return false;
	}
	else if(bc.getSize() != 0){
		cout << "Barchart getSize() failed!";
		return false;
	}
	cout << "testBarChartParamConstructor: all passed!" << endl;
    return true;
}

bool testBarChartCopyConstructor(){
	BarChart bc(10);
	BarChart bcCopy(bc);
	if(bcCopy.getFrame() != bc.getFrame())
	{
		cout << "Barchart getFrame() failed!";
		return false;
	}
	else if(bcCopy.getSize() != bc.getSize()){
		cout << "Barchart getSize() failed!";
		return false;
	}
	cout << "testBarChartParamConstructor: all passed!" << endl;
    return true;
}

bool testBarChartGetFrame(){
	BarChart bc;
	if(bc.getFrame() != ""){
		cout << "Barchart getFrame() failed!";
		return false;
	}
	cout << "testBarChartGetFrame passed!" << endl;
	return true;
}

bool testBarChartSetFrame(){

	BarChart bc;
	bc.setFrame("1950");
	if(bc.getFrame() != "1950"){
		cout << "Barchart setFrame() failed!";
		return false;
	}
	cout << "testBarChartSetFrame passed!" << endl;
	return true;
}

bool testBarChartGetSize(){
	BarChart bc;
	if(bc.getSize() != 0){
		cout << "Barchart getSize() failed!";
		return false;
	}
	cout << "testBarChartGetSize passed!" << endl;
	return true;
}

bool testBarChartAddBar(){

	BarChart bc(3);
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	if(bc.getSize() == 0){
		cout << "Barchart getSize() failed!";
		return false;
	}
	cout << "testBarChartAddBar passed!" << endl;
	return true;
}

bool testBarChartAddBarPastCapacity(){

	BarChart bc(3);
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	bc.addBar("San Francisco", 1200, "US");

	if(bc.getSize() != 3){
		cout << "Barchart getSize() failed!";
		return false;
	}
	cout << "testBarChartAddBarPastCapacity passed!" << endl;
	return true;
}

bool testBarChartGraphAndDump(){
	BarChart bc(3);
	bc.setFrame("1950");
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	string red("\033[1;36m");
	string blue("\033[1;33m");
	map<string, string> colorMap;
	colorMap["US"] = red;
	colorMap["France"] = blue;
	bc.graph(cout, colorMap, 3);
}

bool testBarChartGraphAndDump2(){
	cout << endl;
	BarChart bc(3);
	bc.setFrame("2018");
	bc.addBar("Beijing", 22674, "China");
	bc.addBar("Cairo", 19850, "Egypt");
	string red("\033[1;36m");
	string blue("\033[1;33m");
	map<string, string> colorMap;
	colorMap["China"] = red;
	colorMap["Egypt"] = blue;
	bc.graph(cout, colorMap, 2);
}


//////////////////////// barchart.h tests end


void testGraph() {
	// BarChart bc(10);
	// bc.addBar("Chicago", 1020,"US");
	// bc.addBar("Paris", 1200,"France");
	// bc.addBar("NYC", 1300,"US");

	// string red("\033[1;36m");
	// string blue("\033[1;33m");
	// map<string, string> colorMap;
	// colorMap["US"] = red;
	// colorMap["France"] = blue;
	// bc.graph(cout, colorMap, 4);
}

int main() {
	//////////////////////// bar.h tests function calls

	testBarDefaultConstructor();
	testBarParamConstructor();
	testBarGetName();
	testBarGetValue();
	testBarGetCategory();
	testBarLessThanOperator();
	testBarLessThanOperator2();
	testBarLessThanEqualToOperator();
	testBarLessThanEqualToOperator2();
	testBarGreaterThanOperator();
	testBarGreaterThanOperator2();
	testBarGreaterThanEqualToOperator();
	testBarGreaterThanEqualToOperator2();
	
	//////////////////////// bar.h tests function calls end

	cout << endl;

	//////////////////////// barchart.h tests function calls

	testBarChartDefaultConstructor();
	testBarChartParamConstructor();
	testBarChartCopyConstructor();
	testBarChartGetFrame();
	testBarChartSetFrame();
	testBarChartGetSize();
	testBarChartAddBar();
	testBarChartAddBarPastCapacity();
	testBarChartGraphAndDump();
	testBarChartGraphAndDump2();
	
	//////////////////////// barchart.h tests function calls end

	cout << endl;

	//////////////////////// barchartanimate.h test function calls

	testGraph();
	
	//////////////////////// barchartanimate.h test function calls end

    return 0;
}