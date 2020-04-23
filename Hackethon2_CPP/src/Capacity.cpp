/*
 * Capacity.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: shiva
 */

#include "Capacity.h"

Capacity::Capacity() {
	// TODO Auto-generated constructor stub

}

Capacity::Capacity(string center_id,string course_name,int max_capacity,int filled_capacity){
	this->center_id = center_id;
	this->course_name = course_name;
	this->filled_capacity = filled_capacity;
	this->max_capacity = max_capacity;
}
const string& Capacity::getCenterId() const {
	return center_id;
}

void Capacity::setCenterId(const string& centerId) {
	center_id = centerId;
}

const string& Capacity::getCourseName() const {
	return course_name;
}

void Capacity::setCourseName(const string& courseName) {
	course_name = courseName;
}

int Capacity::getFilledCapacity() const {
	return filled_capacity;
}

void Capacity::setFilledCapacity(int filledCapacity) {
	filled_capacity = filledCapacity;
}

int Capacity::getMaxCapacity() const {
	return max_capacity;
}

void Capacity::setMaxCapacity(int maxCapacity) {
	max_capacity = maxCapacity;
}

Capacity::~Capacity() {
	// TODO Auto-generated destructor stub
}

