/*
 * Student.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Course.h"
#include <algorithm>
using namespace std;

#include "Student.h"

Student::Student() {
	this->center_id = "NA";
	this->course_name = "NA";
	this->degree = "";
	this->degree_marks = 0.0;
	this->form_no = 0;
	this->name = "";
	this->payment = 0.0;
	this->prn = "NA";
	this->rank_a = -1;
	this->rank_b = -1;
	this->rank_c = -1;
	this->reported = 0;
	this->allocated_preference = 0;
}

Student::Student(int formNo, string name, int rank_a, int rank_b, int rank_c,
		string degree, double degree_marks, int allocated_preference,
		string allocated_course_name, string allocated_center_id,
		double payment, int reportedToCenter, string prn,vector<Preference> &pre_vtr) {

	this->allocated_preference = allocated_preference;
	this->center_id = allocated_center_id;
	this->course_name = allocated_course_name;
	this->degree = degree;
	this->degree_marks = degree_marks;
	this->form_no = formNo;
	this->name = name;
	this->payment = payment;
	this->prn = prn;
	this->rank_a = rank_a;
	this->rank_b = rank_b;
	this->rank_c = rank_c;
	this->reported = reportedToCenter;

	for (unsigned int i = 0; i < pre_vtr.size(); i++) {
		Preference temp_pre_obj;
		if (pre_vtr[i].getStudentFormNo() == formNo) {
			temp_pre_obj.setCenterId(pre_vtr[i].getCenterId());
			temp_pre_obj.setCourseName(pre_vtr[i].getCourseName());
			temp_pre_obj.setPreferenceNo(pre_vtr[i].getPreferenceNo());
			temp_pre_obj.setStudentFormNo(pre_vtr[i].getStudentFormNo());
			this->preferences.push_back(temp_pre_obj);
		}
	}
}

Student::Student(vector<Student> &std_vtr,vector<Preference> &pre_vtr, int formNo){
	for (unsigned int i = 0; i < std_vtr.size(); i++) {
		if (std_vtr[i].getFormNo() == formNo) {
			this->allocated_preference = std_vtr[i].allocated_preference;
			this->center_id = std_vtr[i].center_id;
			this->course_name = std_vtr[i].course_name;
			this->degree = std_vtr[i].degree;
			this->degree_marks = std_vtr[i].degree_marks;
			this->form_no = std_vtr[i].form_no;
			this->name = std_vtr[i].name;
			this->payment = std_vtr[i].payment;
			this->prn = std_vtr[i].prn;
			this->rank_a = std_vtr[i].rank_a;
			this->rank_b = std_vtr[i].rank_b;
			this->rank_c = std_vtr[i].rank_c;
			this->reported = std_vtr[i].reported;
		}
	}
	for (unsigned int i = 0; i < pre_vtr.size(); i++) {
		Preference temp_pre_obj;
		if (pre_vtr[i].getStudentFormNo() == formNo) {
			temp_pre_obj.setCenterId(pre_vtr[i].getCenterId());
			temp_pre_obj.setCourseName(pre_vtr[i].getCourseName());
			temp_pre_obj.setPreferenceNo(pre_vtr[i].getPreferenceNo());
			temp_pre_obj.setStudentFormNo(pre_vtr[i].getStudentFormNo());
			this->preferences.push_back(temp_pre_obj);
		}
	}
}

int Student::getStudent(vector<Student> &std_vtr, vector<Preference> &pre_vtr,
		int formNo) {
	int std_vtr_index;
	for (unsigned int i = 0; i < std_vtr.size(); i++) {
		if (std_vtr[i].getFormNo() == formNo) {
			this->allocated_preference = std_vtr[i].allocated_preference;
			this->center_id = std_vtr[i].center_id;
			this->course_name = std_vtr[i].course_name;
			this->degree = std_vtr[i].degree;
			this->degree_marks = std_vtr[i].degree_marks;
			this->form_no = std_vtr[i].form_no;
			this->name = std_vtr[i].name;
			this->payment = std_vtr[i].payment;
			this->prn = std_vtr[i].prn;
			this->rank_a = std_vtr[i].rank_a;
			this->rank_b = std_vtr[i].rank_b;
			this->rank_c = std_vtr[i].rank_c;
			this->reported = std_vtr[i].reported;
			std_vtr_index = i;
			break;
		}
	}
	for (unsigned int i = 0; i < pre_vtr.size(); i++) {
		Preference temp_pre_obj;
		if (pre_vtr[i].getStudentFormNo() == formNo) {
			temp_pre_obj.setCenterId(pre_vtr[i].getCenterId());
			temp_pre_obj.setCourseName(pre_vtr[i].getCourseName());
			temp_pre_obj.setPreferenceNo(pre_vtr[i].getPreferenceNo());
			temp_pre_obj.setStudentFormNo(pre_vtr[i].getStudentFormNo());
			this->preferences.push_back(temp_pre_obj);
		}
	}
	return std_vtr_index;
}

void Student::setStudent(vector<Student> &std_vtr) {
	vector<Student>::iterator std_it;
	vector<Preference>::iterator std_pre_it;
	for (std_it = std_vtr.begin(); std_it != std_vtr.end(); ++std_it) {
		if (this->getFormNo() == std_it->getFormNo()) {
			std_it->setPreferences(this->getPreferences());
			/*std_it->setAllocatedPreference(this->getAllocatedPreference());
			std_it->setCenterId(this->getCenterId());
			std_it->setCourseName(this->getCourseName());
			std_it->setDegree(this->getDegree());
			std_it->setDegreeMarks(this->getDegreeMarks());
			std_it->setFormNo(this->getFormNo());
			std_it->setName(this->getName());
			std_it->setPayment(this->getPayment());
			std_it->setPrn(this->getPrn());
			std_it->setRankA(this->getRankA());
			std_it->setRankB(this->getRankB());
			std_it->setRankC(this->getRankC());
			std_it->setReported(this->getReported());*/
			break;
		}
	}
}

void Student::displayAllocatedCenterAndCourse() {
	cout << setw(10) << left << "Pref No";
	cout << setw(15) << left << "Center Id";
	cout << setw(15) << left << "Course" << endl;
	cout << setw(10) << left
			<< this->getPreferences()[this->getAllocatedPreference()-1].getPreferenceNo();
	cout << setw(10) << left
			<< this->getPreferences()[this->getAllocatedPreference()-1].getCenterId();
	cout << setw(15) << left
			<< this->getPreferences()[this->getAllocatedPreference()-1].getCourseName()
			<< endl;
}

bool Student::updatePaymentDetails(vector<Course> &crs_vtr) {
	int amount, first_insta, course_fee, sec_insta;
	vector<Course>::iterator crs_it;
	for (crs_it = crs_vtr.begin(); crs_it != crs_vtr.end(); ++crs_it) {
		if (this->getCourseName() == crs_it->getName()) {
			course_fee = stoi(crs_it->getFees());
			break;
		}
	}
	if (this->getAllocatedPreference() == 0) {
		cout << "You Haven't allocated to Any Center Yet " << endl;
		return 0;
	} else if (this->getPayment() == course_fee) {
		cout << "Already Paid the Full Fees : " << course_fee << ". Thank You !"
				<< endl;
		return 0;
	}

	first_insta = 11800;
	cout << "Fees Paid : " << this->getPayment() << endl;
	if (this->getPayment() == 0) {
		cout << "Please Pay " << first_insta << endl;
		cout << "Enter Amount : ";
		cin >> amount;
		while (amount != 11800) {
			cout << "Please Pay Exact Amount Only" << endl;
			cout << "Enter Amount : ";
			cin >> amount;
		}
		this->setPayment(first_insta);
		return 1;
	} /*else if (this->getPayment() == 11800
			&& this->getAllocatedPreference() != 0) {
		cout
				<< "You have Already Paid First Installment.\n Please wait for 2nd Round Result \n Thank You !"
				<< endl;
	}*/ else if (this->getPayment() == 11800) {
		sec_insta = course_fee - first_insta;
		cout << "Please Pay " << sec_insta << endl;
		cout << "Enter Amount : ";
		cin >> amount;
		while (amount != sec_insta) {
			cout << "Please Pay Exact Amount Only" << endl;
			cout << "Enter Amount : ";
			cin >> amount;
		}
		this->setPayment(course_fee);
		return 1;
	}
	return 0;
}

bool sortByFormNo1(Student s1,Student s2) {
	return (s1.getFormNo() < s2.getFormNo());
}

void Student::registerNewStudent(vector<Student> &std_vtr,vector<string> &dgre_vtr){
	string name,degree;
	unsigned int degree_choice,sr_no=1;
	double percentage;
	cout<<"Enter Student Details "<<endl;
	cout<<"Name : ";
	cin>>name;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout<<"Choose your Degree : "<<endl;
	cout<<setw(10)<<left<<"Sr.No";
	cout<<setw(20)<<left<<"Degree"<<endl;
	vector<string>::iterator dgre_it;
	for(dgre_it = (dgre_vtr.begin()+4); dgre_it != dgre_vtr.end();++dgre_it){
		cout<<setw(10)<<left<<sr_no++;
		cout<<setw(20)<<left<<*dgre_it<<endl;
	}
	while(1){
		cout<<"Enter Sr. No : ";
		cin>>degree_choice;
		if(degree_choice < 0 || degree_choice > (dgre_vtr.size()-4)){
			cerr<<"Invalid Choice"<<endl;
			cin.clear();
		}else{
			break;
		}
	}

	sr_no=1;
	for (dgre_it = (dgre_vtr.begin()+4); dgre_it != dgre_vtr.end(); ++dgre_it) {
		if(degree_choice == sr_no++){
			degree = *dgre_it;
			break;
		}
	}
	while (1) {
		cout << "Percentage : ";
		cin >> percentage;
		if(percentage <= 0 || percentage > 100){
			cout<<"Invalid Percentage"<<endl;
			cin.clear();
		}else{
			break;
		}
	}

	sort(std_vtr.begin(),std_vtr.end(),sortByFormNo1);
	vector<Student>::iterator std_it = --std_vtr.end();
	int form_no = std_it->getFormNo() + 1;
	this->setFormNo(form_no);
	this->setName(name);
	this->setDegree(degree);
	this->setDegreeMarks(percentage);
	std_vtr.push_back(*this);
}

int Student::LoginIn(vector<Student> &std_vtr,vector<Preference> &pre_vtr) {
	int username;
	string password;
	int std_vtr_index = -1;
	cout << "User Name(Form Number) : ";
	cin >> username;
	cout << "Password(Student Name) : ";
	cin >> password;
	bool isLogIn = 0;
	for (unsigned int i = 0; i < std_vtr.size(); i++) {
		if (username == std_vtr[i].getFormNo()
				&& password == std_vtr[i].getName()) {
			isLogIn = 1;
		}
	}
	if (isLogIn) {
		std_vtr_index = this->getStudent(std_vtr, pre_vtr, username);
		cout << "You are Successfully logged In" << endl;
	} else {
		cerr << "Invalid User" << endl;
	}
	return std_vtr_index;
}

bool Student::validateStudent(int username,string password,vector<Student> &std_vtr){
	return 0;
}

bool Student::validateStudentByFormNo(int form_no,vector<Student> &std_vtr){
	vector<Student>::iterator std_it;
	for (std_it = std_vtr.begin(); std_it != std_vtr.end(); ++std_it) {
		if(std_it->getFormNo() == form_no){
			return 1;
		}
	}
	return 0;
}

const string& Student::getCenterId() const {
	return center_id;
}

void Student::setCenterId(const string& centerId) {
	center_id = centerId;
}

const string& Student::getCourseName() const {
	return course_name;
}

void Student::setCourseName(const string& courseName) {
	course_name = courseName;
}

const string& Student::getDegree() const {
	return degree;
}

void Student::setDegree(const string& degree) {
	this->degree = degree;
}

double Student::getDegreeMarks() const {
	return degree_marks;
}

void Student::setDegreeMarks(double degreeMarks) {
	degree_marks = degreeMarks;
}

const string& Student::getName() const {
	return name;
}

void Student::setName(const string& name) {
	this->name = name;
}

int Student::getPayment() const {
	return payment;
}

void Student::setPayment(int payment) {
	this->payment = payment;
}

const string& Student::getPrn() const {
	return prn;
}

void Student::setPrn(const string& prn) {
	this->prn = prn;
}

int Student::getRankA() const {
	return rank_a;
}

void Student::setRankA(int rankA) {
	rank_a = rankA;
}

int Student::getRankB() const {
	return rank_b;
}

void Student::setRankB(int rankB) {
	rank_b = rankB;
}

int Student::getRankC() const {
	return rank_c;
}

void Student::setRankC(int rankC) {
	rank_c = rankC;
}

int Student::getReported() const {
	return reported;
}

int Student::getFormNo() const {
	return form_no;
}

vector<Preference>& Student::getPreferences() {
	return preferences;
}

void Student::setPreferences(vector<Preference>& preferences) {
	this->preferences = preferences;
}

void Student::setFormNo(int formNo) {
	form_no = formNo;
}

void Student::setReported(int reported) {
	this->reported = reported;
}

Student::~Student() {
	// TODO Auto-generated destructor stub
}

void Student::displayStudentDetails(){
	cout << setw(10) << left << this->getFormNo();
	cout << setw(15) << left << this->getName();
	cout << setw(10) << left << this->getRankA();
	cout << setw(10) << left << this->getRankB();
	cout << setw(10) << left << this->getRankC();
	cout << setw(15) << left << this->getDegree();
	cout << setw(10) << left << this->getDegreeMarks();
	cout << setw(15) << left << this->getCourseName();
	cout << setw(10) << left << this->getPayment();
	cout << setw(10) << left << this->getReported();
	cout << setw(15) << left << this->getPrn() << endl;

	/*cout<<"Preferences : "<<endl;
	for(unsigned int i=0;i<this->getPreferences().size();i++){
		cout<<setw(5)<<left<<this->getPreferences()[i].getPreferenceNo();
		cout<<setw(15)<<left<<this->getPreferences()[i].getCenterId();
		cout<<setw(15)<<left<<this->getPreferences()[i].getCourseName();
		cout<<endl;
	}*/
}

void Student::listCoursesAsPerEligibility(vector<Course> &crs_vtr) {
	vector<Course> elgb_crs_vtr;
	cout << setw(10) << left << "Course Id";
	cout << setw(10) << left << "Course";
	cout << setw(10) << left << "Fees";
	cout << setw(10) << left << "C-CAT Sec";
	cout << endl;
	for (unsigned int i = 0; i < crs_vtr.size(); i++) {
		for (unsigned int j = 0; j < crs_vtr[i].getEligibilities().size();
				j++) {
			if (crs_vtr[i].getCcatSection() == "A"
					&& this->getRankA() == -1) {
				break;
			} else if (crs_vtr[i].getCcatSection() == "B"
					&& this->getRankB() == -1) {
				break;
			} else if (crs_vtr[i].getCcatSection() == "C"
					&& this->getRankA() == -1) {
				break;
			}
			if ((this->getDegree()
					== crs_vtr[i].getEligibilities()[j].getDegree())
					&& (this->getDegreeMarks()
							>= crs_vtr[i].getEligibilities()[j].getMinPercentage())) {
				elgb_crs_vtr.push_back(crs_vtr[i]);
				cout << setw(5) << left << crs_vtr[i].getId();
				cout << setw(10) << left << crs_vtr[i].getName();
				cout << setw(10) << left << crs_vtr[i].getFees();
				cout << setw(5) << left << crs_vtr[i].getCcatSection();
				cout << endl;
			}
		}
	}
}

void Student::listStudents(vector<Student> &std_vtr){
	for (unsigned int i = 0; i < std_vtr.size(); i++) {
		cout <<setw(5)<<left<<std_vtr[i].getFormNo();
		cout <<setw(20)<<left<< std_vtr[i].getName();
		cout <<setw(5)<<left<< std_vtr[i].getRankA();
		cout <<setw(5)<<left<< std_vtr[i].getRankB();
		cout <<setw(5)<<left<< std_vtr[i].getRankC();
		cout <<setw(20)<<left<< std_vtr[i].getDegree();
		cout <<setw(10)<<left<< std_vtr[i].getDegreeMarks();
		cout <<setw(10)<<left<<std_vtr[i].getAllocatedPreference();
		cout <<setw(10)<<left<< std_vtr[i].getCourseName();
		cout <<setw(5)<<left<< std_vtr[i].getCenterId();
		cout <<setw(10)<<left<< std_vtr[i].getPayment();
		cout <<setw(5)<<left<< std_vtr[i].getReported();
		cout <<setw(15)<<left<< std_vtr[i].getPrn()<<endl;
	}
}

void Student::listStudentsWithPreferences(vector<Student> &std_vtr,vector<Preference> &pre_vtr) {
	for (unsigned int i = 0; i < std_vtr.size(); i++) {
		cout << setw(5) << left << std_vtr[i].getFormNo();
		cout << setw(20) << left << std_vtr[i].getName();
		cout << setw(5) << left << std_vtr[i].getRankA();
		cout << setw(5) << left << std_vtr[i].getRankB();
		cout << setw(5) << left << std_vtr[i].getRankC();
		cout << setw(20) << left << std_vtr[i].getDegree();
		cout << setw(10) << left << std_vtr[i].getDegreeMarks();
		//cout<<"Allocated Preferences : "<<std_obj.getPreferences();
		cout << setw(10) << left << std_vtr[i].getCourseName();
		cout << setw(5) << left << std_vtr[i].getCenterId();
		cout << setw(10) << left << std_vtr[i].getPayment();
		cout << setw(5) << left << std_vtr[i].getReported();
		cout << setw(15) << left << std_vtr[i].getPrn() << endl;

		for (unsigned int j = 0; j < pre_vtr.size(); j++) {
			if (std_vtr[i].getFormNo() == pre_vtr[j].getStudentFormNo()) {
				cout << setw(5) << left << pre_vtr[j].getPreferenceNo();
				cout << setw(10) << left << pre_vtr[j].getCenterId();
				cout << setw(10) << left << pre_vtr[j].getCourseName() << endl;
			}
		}
		cout << endl;
	}
}

void Student::listFilledPreferences(vector<Preference> &pre_vtr) {
	cout << setw(10) << left << "Pref No";
	cout << setw(15) << left << "Center Id";
	cout << setw(15) << left << "Course Name"<< endl;
	/*for (unsigned int j = 0; j < pre_vtr.size(); j++) {
		if (this->getFormNo() == pre_vtr[j].getStudentFormNo()) {
			cout << setw(10) << left << pre_vtr[j].getPreferenceNo();
			cout << setw(15) << left << pre_vtr[j].getCenterId();
			cout << setw(15) << left << pre_vtr[j].getCourseName() << endl;
		}
	}*/

	vector<Preference>::iterator std_pref_it = this->getPreferences().begin();
	while(std_pref_it != this->getPreferences().end()){
		cout << setw(10) << left << std_pref_it->getPreferenceNo();
		cout << setw(10) << left << std_pref_it->getCenterId();
		cout << setw(10) << left << std_pref_it->getCourseName()<<endl;
		++std_pref_it;
	}

}

void Student::clearAlreadyFilledPreferences(vector<Preference> &pre_vtr) {
	vector<Preference>::iterator pre_it = pre_vtr.begin();

	//To Clear Preferences Vector
	while (pre_it != pre_vtr.end()) {
		if (this->getFormNo() == pre_it->getStudentFormNo()) {
			pre_it = pre_vtr.erase(pre_it);
		} else {
			++pre_it;
		}
	}

	//To Erase Student_Preferences Vector
	this->getPreferences().clear();
}

void Student::givePreferences(vector<Course> &crs_vtr,
		vector<Preference> &pre_vtr,
		vector<eligiblePreferences> &elgb_pref_vtr) {

	vector<eligiblePreferences>::iterator elgb_pref_it;
	unsigned int pref_no = this->getPreferences().size()+1;
	unsigned int sr_no;

	cout << "Enter Sr.No of Preference from above list"<<endl;
	while (1) {
		cout << "Preference Number : " << pref_no << endl;
		cout << "Sr No : ";
		cin >> sr_no;

		if (sr_no > elgb_pref_vtr.size() || sr_no < 0) {
			cerr <<"\n Invalid Sr_No " << endl;
		}else{
			break;
		}
	}

	//To update Preferences vector
	Preference temp_pre_obj;
	for (elgb_pref_it = elgb_pref_vtr.begin();
			elgb_pref_it != elgb_pref_vtr.end(); ++elgb_pref_it) {
		if (elgb_pref_it->sr_no == sr_no) {
			temp_pre_obj.setPreferenceNo(pref_no);
			temp_pre_obj.setStudentFormNo(this->getFormNo());
			temp_pre_obj.setCenterId(elgb_pref_it->center_id);
			temp_pre_obj.setCourseName(elgb_pref_it->course);
			break;
		}
	}
	pre_vtr.push_back(temp_pre_obj);

	//To update Student_Preference Vector
	this->getPreferences().push_back(temp_pre_obj);

}

void Student::listAllocatedStudents(vector<Student> &std_vtr){
	vector<Student>::iterator it = std_vtr.begin();
	cout << setw(15) << left <<"Form Number";
	cout << setw(15) << left << "Student Name";
	cout << setw(15) << left <<"Pref. No";
	cout << setw(15) << left <<"Center ID";
	cout << setw(15) << left <<"Course Name"<<endl;
	while(it != std_vtr.end()){
		if ((it->getAllocatedPreference() != 0)) {
			cout << setw(15) << left << it->getFormNo();
			cout << setw(15) << left << it->getName();
			cout << setw(15) << left << it->getAllocatedPreference();
			cout << setw(15) << left << it->getCenterId();
			cout << setw(15) << left << it->getCourseName() << endl;
		}
		it++;
	}
}

void Student::listPaidStudents(vector<Student> &std_vtr) {
	vector<Student>::iterator it = std_vtr.begin();
	cout << setw(15) << left << "Form Number";
	cout << setw(15) << left << "Student Name";
	cout << setw(15) << left << "Paid Amount"<<endl;
	while (it != std_vtr.end()) {
		if(it->getPayment() !=0 && it->getPayment()!=-1 ){
		cout << setw(15) << left << it->getFormNo();
		cout << setw(15) << left << it->getName();
		cout << setw(15) << left << it->getPayment()<<endl;
		}
		it++;
	}
}

void Student::listReportedtoCenterStudents(vector<Student> &std_vtr) {
	vector<Student>::iterator it = std_vtr.begin();
	cout << setw(15) << left << "Form Number";
	cout << setw(15) << left << "Student Name";
	cout << setw(15) << left << "Reported Center" << endl;
	while(it != std_vtr.end()){
		if(it->getReported() == 1){
		cout << setw(15) << left << it->getFormNo();
		cout << setw(15) << left << it->getName();
		cout << setw(15) << left << it->getCenterId() << endl;
		}
		++it;
	}
}

void Student::generatePRNNumber(vector<Student> &std_vtr,vector<Course> &crs_vtr) {
	vector<Student>::iterator it = std_vtr.begin();
	vector<Course>::iterator crs_it;
	int course_fees, num_prn = 0;
	while (it != std_vtr.end()) {
		if (it->getReported() == 1) {
			for (crs_it = crs_vtr.begin(); crs_it != crs_vtr.end(); ++crs_it) {
				if (it->getCourseName() == crs_it->getName()) {
					course_fees = stoi(crs_it->getFees());
					break;
				}
			}
			if (it->getPayment() == course_fees) {
				string prn = it->getCenterId();
				prn.append("_");
				prn.append(it->getCourseName());
				prn.append("_");
				prn.append(to_string(it->getFormNo()));
				it->setPrn(prn);
				num_prn++;
			}
		}
		it++;
	}
	if(num_prn){
		cout<<"PRN Generated Successfully for "<<num_prn<<" students"<<endl;
	}else{
		cout<<"No Student is Eligible to Generate PRN"<<endl;
	}
}

void Student::listAdmitedStudents(vector<Student> &std_vtr) {
	vector<Student>::iterator it = std_vtr.begin();
	cout << setw(15) << left << "Form Number";
	cout << setw(15) << left << "Student Name";
	cout << setw(15) << left << "Center";
	cout << setw(15) << left << "Course";
	cout << setw(15) << left << "PRN Number"<<endl;
	while (it != std_vtr.end()) {
		cout << setw(15) << left << it->getFormNo();
		cout << setw(15) << left << it->getName();
		cout << setw(15) << left << it->getCenterId();
		cout << setw(15) << left << it->getCourseName();
		cout << setw(15) << left << it->getPrn()<<endl;
		it++;
	}
}

int Student::getAllocatedPreference(){
	return this->allocated_preference;
}

void Student::setAllocatedPreference(int allocatedPreference) {
	this->allocated_preference = allocatedPreference;
}
