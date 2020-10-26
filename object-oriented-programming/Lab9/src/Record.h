/*
 * Record.h
 *
 *  Created on: Mar 27, 2019
 *      Author: student
 */

#ifndef RECORD_H_
#define RECORD_H_

class Record {
public:
	/**
	 * Constructor
	 * string is in the format index,department,item_code,quantity,cost
	 * index is ignored
	 * throws exception if string not in appropriate format or if quantity or cost are not valid numbers
	 */
	Record(std::string s);

	/**
	 * Deconstructor
	 */
	virtual ~Record();

	/*
	 * returns cost
	 */
	double getCost() const;
	/*
	 * returns department
	 */
	const std::string& getDepartment() const;
	/*
	 * returns item code
	 */
	const std::string& getItemCode() const;
	/*
	 * returns quantity
	 */
	int getQuantity() const;

	/**
	 * Overloaded == operator
	 */
	friend bool operator ==(const Record& lhs, const Record& rhs);

	/**
	 * Overloaded < operator
	 */
	friend bool operator <(const Record& lhs, const Record& rhs);

	/**
	 * Overloaded << operator
	 * outputs comma separated list of values
	 */
	friend std::ostream& operator <<(std::ostream&, const Record&);

private:
	std::string department;
	std::string item_code;
	int quantity;
	double cost;
};

#endif /* RECORD_H_ */
