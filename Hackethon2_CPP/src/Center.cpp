/*
 * Center.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#include <iostream>
#include <iomanip>
#include "Center.h"
#include <map>
using namespace std;

Center::Center() {
	this->address ="";
	this->center_id = "";
	this->center_name = "";
	this->coordinator = "";
	this->password = "";
}

Center::Center(string center_id,string center_name,string address,string coordinator,string password,vector<Capacity> &cap_vtr,vector<Course> &crs_vtr){
	this->address = address;
	this->center_id = center_id;
	this->center_name = center_name;
	this->coordinator = coordinator;
	this->password = password;
	for(unsigned int i=0;i<cap_vtr.size();i++){
		if(center_id == cap_vtr[i].getCenterId()){
			this->crs_max_cap.insert(pair<string,int> (cap_vtr[i].getCourseName(),cap_vtr[i].getMaxCapacity()));
			this->crs_fill_seats.insert(pair<string,int> (cap_vtr[i].getCourseName(),cap_vtr[i].getFilledCapacity()));
		}
	}
}

void Center::get_Center(vector<Center> &cntr_vtr,string username){
	vector<Center>::iterator it = cntr_vtr.begin();
	while(it != cntr_vtr.end()){
		if(username == it->getCenterId()){
			this->address = it->address;
			this->center_id = it->center_id;
			this->center_name = it->center_name;
			this->coordinator = it->coordinator;
			this->password = it->password;
			this->crs_fill_seats = it->crs_fill_seats;
			this->crs_max_cap = it->crs_max_cap;
		}
		++it;
	}
}

void Center::LoginIn(vector<Center> &cntr_vtr) {
	string username;
	string password;
	cout << "User Name(Center Id) : ";
	cin >> username;
	cout << "Password(Password) : ";
	cin >> password;
	bool isLogIn = 0;
	for (unsigned int i = 0; i < cntr_vtr.size(); i++) {
		if (username == cntr_vtr[i].getCenterId()
				&& password == cntr_vtr[i].getPassword()) {
			isLogIn = 1;
		}
	}
	if (isLogIn) {
		this->get_Center(cntr_vtr,username);
		cout << "You are Successfully logged In" << endl;
	} else {
		cerr << "Invalid User" << endl;
	}
}

void Center::listCoursesOfCenter(){
	map<string,int>::iterator it = this->crs_max_cap.begin();
	cout<<"Courses "<<endl;
	int srNo=1;
	while(it != this->crs_max_cap.end()){
		cout<<srNo++<<". "<<it->first<<endl;
		++it;
	}
}
void Center::listCentersAndCapacities(vector<Center> &cntr_vtr, vector<Capacity> &cap_vtr) {
	cout << "=========================================================="<< endl;
	cout << setw(10) << left << "Center Id";
	cout << setw(20) << left << "Center Name";
	cout << setw(20) << left << "Center Address";
	cout << setw(20) << left << "Coordinator" << endl;
	cout << "=========================================================="
			<< endl;

	for (unsigned int i = 0; i < cntr_vtr.size(); i++) {
		cout << setw(10) << left << cntr_vtr[i].getCenterId();
		cout << setw(20) << left << cntr_vtr[i].getCenterName();
		cout << setw(20) << left << cntr_vtr[i].getAddress();
		cout << setw(20) << left << cntr_vtr[i].getCoordinator();
		cout << endl;
		cout << setw(10) << left << "Course";
		cout << setw(15) << left << "Max Capacity";
		cout << setw(15) << left << "Filled Seats" << endl;
		cout << "-------------------------------------" << endl;

		for (unsigned int j = 0; j < cap_vtr.size(); j++) {
			if (cntr_vtr[i].getCenterId() == cap_vtr[j].getCenterId()) {
				cout << setw(10) << cap_vtr[j].getCourseName();
				cout << setw(15) << cap_vtr[j].getMaxCapacity();
				cout << setw(15) << cap_vtr[j].getFilledCapacity() << endl;
			}
		}
		cout << "_____________________________________" << endl;
	}
}

void Center::listCentersAndCapacitiesUsingMap(vector<Center> &cntr_vtr) {
	cout << "=========================================================="
			<< endl;
	cout << setw(10) << left << "Center Id";
	cout << setw(20) << left << "Center Name";
	cout << setw(20) << left << "Center Address";
	cout << setw(20) << left << "Coordinator" << endl;
	cout << "=========================================================="
			<< endl;

	for (unsigned int i = 0; i < cntr_vtr.size(); i++) {
		cout << setw(10) << left << cntr_vtr[i].getCenterId();
		cout << setw(20) << left << cntr_vtr[i].getCenterName();
		cout << setw(20) << left << cntr_vtr[i].getAddress();
		cout << setw(20) << left << cntr_vtr[i].getCoordinator();
		cout << endl;
		cout << setw(10) << left << "Course";
		cout << setw(15) << left << "Max Capacity";
		cout << setw(15) << left << "Filled Seats" << endl;
		cout << "-------------------------------------" << endl;

		map<string, int>::iterator max_cap_it;
		map<string, int>::iterator fill_seats_it;

		for (max_cap_it = cntr_vtr[i].getCrsMaxCap().begin(), fill_seats_it =
				cntr_vtr[i].getCrsFillSeats().begin();
				max_cap_it != cntr_vtr[i].getCrsMaxCap().end();
				++max_cap_it, ++fill_seats_it) {
			cout << setw(10) << left << max_cap_it->first;
			cout << setw(15) << left << max_cap_it->second;
			cout << setw(15) << left << fill_seats_it->second << endl;
		}
	}
	cout << "_____________________________________" << endl;
}

vector<eligiblePreferences> Center::listPreferencesAsPerEligilibity(Student curr_std_obj,
		vector<Course> &crs_vtr, vector<Center> &cntr_vtr,
		vector<Preference> &pre_vtr) {
	vector<Course>::iterator crs_it;
	vector<Center>::iterator cntr_it;
	map<string, int>::iterator cntr_crs_it;
	vector<Eligibility>::iterator crs_elgb_it;
	vector<Preference>::iterator pre_it;
	vector<eligiblePreferences> elgb_pref_vtr;
	eligiblePreferences temp_elgb_obj;
	int sr_no = 1;
	cout << setw(10) << left << "Sr. No";
	cout << setw(15) << left << "Center ID";
	cout << setw(15) << left << "Course" << endl;

	for (cntr_it = cntr_vtr.begin(); cntr_it != cntr_vtr.end(); ++cntr_it) {
		for (crs_it = crs_vtr.begin(); crs_it != crs_vtr.end(); ++crs_it) {
			for (cntr_crs_it = cntr_it->getCrsMaxCap().begin();
					cntr_crs_it != cntr_it->getCrsMaxCap().end();
					++cntr_crs_it) {
				for (crs_elgb_it = crs_it->getEligibilities().begin();
						crs_elgb_it != crs_it->getEligibilities().end();
						++crs_elgb_it) {
					if ((cntr_crs_it->first == crs_it->getName())
							&& crs_elgb_it->getDegree()
									== curr_std_obj.getDegree()
							&& (crs_elgb_it->getMinPercentage()
									<= curr_std_obj.getDegreeMarks())) {

						bool flag = 0;
						for (pre_it = pre_vtr.begin(); pre_it != pre_vtr.end();
								++pre_it) {
							if ((pre_it->getStudentFormNo()
									== curr_std_obj.getFormNo()
									&& (pre_it->getCenterId()
											== cntr_it->getCenterId())
									&& (pre_it->getCourseName()
											== crs_it->getName()))) {
								flag = 1;
								break;
							}
						}
						if (flag == 0) {
							temp_elgb_obj.sr_no = sr_no;
							temp_elgb_obj.center_id = cntr_it->getCenterId();
							temp_elgb_obj.course = crs_it->getName();
							elgb_pref_vtr.push_back(temp_elgb_obj);
							cout << setw(10) << left << sr_no++;
							cout << setw(15) << left << cntr_it->getCenterId();
							cout << setw(15) << left << crs_it->getName()
									<< endl;
						}
					}
				}
			}
		}
	}
	return elgb_pref_vtr;
}

void Center::listStudentsAllocatedToCenter(vector<Student> &std_vtr){
	vector<Student>::iterator it = std_vtr.begin();
	cout << setw(10) << left << "Form No";
	cout << setw(15) << left << "Student Name";
	cout << setw(10) << left << "Rank-A";
	cout << setw(10) << left << "Rank-B";
	cout << setw(10) << left << "Rank-C";
	cout << setw(15) << left << "Degree";
	cout << setw(10) << left << "Degree Marks";
	cout << setw(15) << left << "Course";
	cout << setw(10) << left << "Payment";
	cout << setw(10) << left << "Reported";
	cout << setw(15) << left << "PRN"<<endl;

	while( it != std_vtr.end()){
		if(this->center_id == it->getCenterId()){
			it->displayStudentDetails();
		}
		++it;
	}
}

void Center::updateReportedStatus(vector<Student> &std_vtr){
	vector<Student>::iterator it = std_vtr.begin();
	while (it != std_vtr.end()) {
		if (this->center_id == it->getCenterId() && it->getPayment() != 0) {
			it->setReported(1);
		}
		++it;
	}
}

void Center::listAdmittedStudents(vector<Student> &std_vtr) {
	vector<Student>::iterator it = std_vtr.begin();
	cout << setw(15) << left << "Form No";
	cout << setw(15) << left << "Student Name";
	cout << setw(15) << left << "Course";
	cout << setw(15) << left << "PRN"<<endl;

	while (it != std_vtr.end()) {
		if (this->center_id == it->getCenterId() && (it->getPrn() != "NA")) {
			it->displayStudentDetails();
		}
		++it;
	}
}

const string& Center::getAddress() const {
	return address;
}

void Center::setAddress(const string& address) {
	this->address = address;
}

const string& Center::getCenterId() const {
	return center_id;
}

void Center::setCenterId(const string& centerId) {
	center_id = centerId;
}

const string& Center::getCenterName() const {
	return center_name;
}

void Center::setCenterName(const string& centerName) {
	center_name = centerName;
}

const string& Center::getCoordinator() const {
	return coordinator;
}

void Center::setCoordinator(const string& coordinator) {
	this->coordinator = coordinator;
}

const string& Center::getPassword() const {
	return password;
}

void Center::setPassword(const string& password) {
	this->password = password;
}

Center::~Center() {
	// TODO Auto-generated destructor stub
}

map<string, int>& Center::getCrsFillSeats() {
return crs_fill_seats;
}

void Center::setCrsFillSeats(map<string, int>& crsFillSeats) {
crs_fill_seats = crsFillSeats;
}

map<string, int>& Center::getCrsMaxCap() {
	return crs_max_cap;
}

void Center::setCrsMaxCap(map<string, int>& crsMaxCap) {
crs_max_cap = crsMaxCap;
}
