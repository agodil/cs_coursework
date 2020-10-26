//============================================================================
// Name        : main.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Record.h"
using namespace std;

/*
 * returns true if element exists in vector
 */
template <typename T>
bool element_in_vector(const T& elem, const vector<T> vector) {
	// loop to search each element in vector
	for(int i = 0; i < vector.size(); i++) {
		if(elem == vector[i]) {
			return true; // element is in vector
		}
	}
	return false;
}

/*
 * read lines from ifstream into record vector
 * ignore duplicates
 */
vector<Record> build_record_vector_from_ifstream(ifstream& ifs) {
	vector<Record> vector;
	string line;
	// loop to read each line
	while(getline(ifs, line)) {		// read line
		Record r(line);				// store data in object
		if(!element_in_vector(r, vector)) {
			vector.push_back(r);	// store in vector if not duplicate
		}
	}
	return vector;
}

/*
 * write records, with indexes
 */
void output_records_to_ofstream(vector<Record>& records, ofstream& ofs) {
	for(unsigned int i = 0; i < records.size(); i++) {
		ofs << i + 1 << ',' << records[i] << endl; // write line to file
	}
}

int main() {
	// variables
	vector<Record> records;
	string filename;

	// prompt user for file name
	cout << "Enter the name of the file with the file path:" << endl;
	// read filename
	cin >> filename;

	// open file
	ifstream ifs{filename.c_str()};
	if(!ifs) {
		cerr << "can't open file " << filename << endl;
		return 1;
	}

	/*
	 * read and store records
	 */
	try {
		// store lines from file
		records = build_record_vector_from_ifstream(ifs);
		ifs.close();
	} catch(invalid_argument& e) {
		// record constructor has received a bad line
		ifs.close();
		cerr << "Bad data";
		return 2;
	}

	// sort data
	sort(records.begin(), records.end());

	/*
	 * split file name
	 */
	int separator = filename.find_last_of("\\/");
	string path = filename.substr(0, separator);
	string file = filename.substr(separator + 1, filename.length());
	if (path.compare(file) == 0) {
		path = "";
	} else {
		path += filename[separator]; // add slash to end of path
	}

	// build new file name
	string newfilename = path + "new_" + file;

	// open file
	ofstream ofs{newfilename};
	if(!ofs) {
		cerr << "cannot output to " << newfilename << endl;
		return 3;
	}

	/*
	 * write records to file
	 */
	output_records_to_ofstream(records, ofs);
	ofs.close();
	cout << "Records rewritten to " << newfilename << endl;


	/*
	 * output report
	 */
	cout << '\n'	// output header
		<< left << setw(16) << "Department"
		<< setw(14) << "Item Code"
		<< setw(5) << "Quantity"
		<< right << setw(10) << "Cost  "
		<< setw(13) << "Total  " << '\n';
	cout << "________________________________________________________________\n\n";
	/*
	 * iterate over vector to format output for each record
	 */
	for (unsigned int i = 0; i < records.size(); i++) {
		// output a record
		cout << left << setw(16) << records[i].getDepartment() 	//width 16 column, align left
			<< setw(16) << records[i].getItemCode()				//width 16 column, align left
			<< setw(5) << records[i].getQuantity()				//width 5 column, align left
			<< right << setw(10) << fixed << setprecision(2) << records[i].getCost() //width 10 column, align right, fixed point format, precision 2
			<< setw(13) << (records[i].getQuantity() * records[i].getCost()) //total calculated as quantity times cost; width 13 column, align right, fixed point format, precision 2
			<< '\n';
	}

	return 0;
}
