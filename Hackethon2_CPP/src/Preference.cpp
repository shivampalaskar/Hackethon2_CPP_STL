/*
 * Preference.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#include "Preference.h"

Preference::Preference() {
	// TODO Auto-generated constructor stub

}

Preference::Preference(int student_form_no,int preference_no,string course_name,string center_id){
	this->student_form_no = student_form_no;
	this->course_name = course_name;
	this->preference_no = preference_no;
	this->center_id = center_id;
}

Preference::Preference(vector<Preference> &pre_vtr,int formNo){
	for(unsigned int i=0;i<pre_vtr.size();i++){
		if(pre_vtr[i].getStudentFormNo() == formNo){
			this->center_id = pre_vtr[i].getCenterId();
			this->course_name = pre_vtr[i].getCourseName();
			this->preference_no = pre_vtr[i].getPreferenceNo();
			this->student_form_no = pre_vtr[i].getStudentFormNo();
		}
	}
}

const string& Preference::getCenterId() const {
	return center_id;
}

void Preference::setCenterId(const string& centerId) {
	center_id = centerId;
}

const string& Preference::getCourseName() const {
	return course_name;
}

void Preference::setCourseName(const string& courseName) {
	course_name = courseName;
}

int Preference::getPreferenceNo() const {
	return preference_no;
}

void Preference::setPreferenceNo(int preferenceNo) {
	preference_no = preferenceNo;
}

int Preference::getStudentFormNo() const {
	return student_form_no;
}

void Preference::setStudentFormNo(int studentFormNo) {
	student_form_no = studentFormNo;
}

Preference::~Preference() {
	// TODO Auto-generated destructor stub
}

