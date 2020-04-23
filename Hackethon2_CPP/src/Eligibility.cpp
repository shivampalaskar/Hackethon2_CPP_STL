/*
 * Eligibility.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: shiva
 */

#include "Eligibility.h"
#include <vector>

Eligibility::Eligibility() {
	// TODO Auto-generated constructor stub

}

Eligibility::Eligibility(string course_name, string degree,
		double min_percentage) {
	this->course_name = course_name;
	this->degree = degree;
	this->min_percentage = min_percentage;
}

Eligibility::Eligibility(vector<Eligibility> &elgb_vtr,string name){
	for(unsigned int i=0;i<elgb_vtr.size();i++){
		if(elgb_vtr[i].getCourseName() == name){
			this->course_name = name;
			this->degree = elgb_vtr[i].getDegree();
			this->min_percentage = elgb_vtr[i].getMinPercentage();
			break;
		}
	}
}

string& Eligibility::getCourseName() {
	return course_name;
}

void Eligibility::setCourseName(string& courseName) {
	course_name = courseName;
}

string& Eligibility::getDegree() {
	return degree;
}

void Eligibility::setDegree(string& degree) {
	this->degree = degree;
}

double Eligibility::getMinPercentage() {
	return min_percentage;
}

void Eligibility::setMinPercentage(double minPercentage) {
	min_percentage = minPercentage;
}

Eligibility::~Eligibility() {
	// TODO Auto-generated destructor stub
}

