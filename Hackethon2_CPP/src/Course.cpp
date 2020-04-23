/*
 * Course.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: shiva
 */
#include <iostream>
#include <iomanip>
#include "Course.h"
#include <vector>

using namespace std;

Course::Course() {
	// TODO Auto-generated constructor stub

}

Course::Course(int id,string name,string fees,string ccat_section,vector<Eligibility> elgb_vtr){
	this->id = id;
	this->name = name;
	this->fees = fees;
	this->ccat_section = ccat_section;

	for (unsigned int i = 0; i < elgb_vtr.size(); i++) {
		Eligibility temp_elgb_obj;
		if(this->name == elgb_vtr[i].getCourseName()){
			temp_elgb_obj.setCourseName(name);
			temp_elgb_obj.setDegree(elgb_vtr[i].getDegree());
			temp_elgb_obj.setMinPercentage(elgb_vtr[i].getMinPercentage());
			this->eligibilities.push_back(temp_elgb_obj);
		}
	}
}

void Course::listCoursesAndEligibility(vector<Course> &crs_vtr) {
	for (unsigned int i = 0; i < crs_vtr.size(); i++) {
		cout << "Course : " << crs_vtr[i].getName() << endl;
		cout << setw(20) << left << "Degree";
		cout << setw(20) << left << "Min Percentage" << endl;
		for (unsigned int j = 0; j < crs_vtr[i].getEligibilities().size();
				j++) {
			cout << setw(20) << left
					<< crs_vtr[i].getEligibilities()[j].getDegree();
			cout << setw(20) << left
					<< crs_vtr[i].getEligibilities()[j].getMinPercentage()
					<< endl;
		}
		cout << endl;
	}
}
const string& Course::getCcatSection() const {
	return ccat_section;
}

void Course::setCcatSection(const string& ccatSection) {
	ccat_section = ccatSection;
}

const string& Course::getFees() const {
	return fees;
}

void Course::setFees(const string& fees) {
	this->fees = fees;
}

int Course::getId() const {
	return id;
}

void Course::setId(int id) {
	this->id = id;
}

const string& Course::getName() const {
	return name;
}

void Course::setName(const string& name) {
	this->name = name;
}

Course::~Course() {
	// TODO Auto-generated destructor stub
}

vector<Eligibility>& Course::getEligibilities() {
	return eligibilities;
}

void Course::setEligibilities(vector<Eligibility>& eligibilities) {
	this->eligibilities = eligibilities;
}
