/*
 * Record.cpp
 *
 *  Created on: Mar 27, 2019
 *      Author: student
 */

#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "Record.h"

using namespace std;

/*
 * constructor
 */
Record::Record(string s) {

	// strings to store numbers
	string index_string;
	string quantity_string;
	string cost_string;

	// variable to detect index
	int index = 0;

	// create string stream from record string
	istringstream stream(s);

	try {
		// extract index, not used
		getline(stream, index_string, ',');
		// extract department
		getline(stream, department, ',');
		// extract item code
		getline(stream, item_code, ',');
		// extract quantity
		getline(stream, quantity_string, ',');
		// extract cost
		getline(stream, cost_string, ',');

		// validate stream
		if(!stream.eof() || stream.fail() || s.empty()) {
			throw exception();
		}

		// create streams to read number variables
		istringstream indstream(index_string);
		istringstream qstream(quantity_string);
		istringstream cstream(cost_string);

		/*
		 * read number variables from streams, index not stored into member variable
		 */
		indstream >> index;
		qstream >> quantity;
		cstream >> cost;

		// validate streams, check for failed readings
		if (!indstream.eof() || !qstream.eof() || !cstream.eof()
			|| indstream.fail() || qstream.fail() || cstream.fail()) {
			// invalid number detected (index, quantity, cost)
			throw exception();
		}

	} catch (exception& e) {
		department = "";
		item_code = "";
		quantity = 0;
		cost = 0;
		throw invalid_argument("Bad record string");
	}
}

/*
 * deconstructor
 */
Record::~Record() {
	// do nothing
}

double Record::getCost() const {
	return cost;
}

const std::string& Record::getDepartment() const {
	return department;
}

const std::string& Record::getItemCode() const {
	return item_code;
}

int Record::getQuantity() const {
	return quantity;
}

/*
 * == operator
 */
bool operator ==(const Record& lhs, const Record& rhs) {
	// check for equal contents
	return lhs.department == rhs.department
			&& lhs.item_code == rhs.item_code
			&& lhs.quantity == rhs.quantity
			&& lhs.cost == rhs.cost;
}

/*
 * < operator
 */
bool operator <(const Record& lhs, const Record& rhs) {
	return lhs.department < rhs.department || (lhs.department == rhs.department && lhs.item_code < rhs.item_code);
}

/*
 * << operator
 */
std::ostream& operator <<(std::ostream& os, const Record& r) {
	// output each value, comma separated
	return os << r.department << ',' << r.item_code << ','
			<< r.quantity << ',' << r.cost;
}
