/*
 * AdmissionSystem.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: shiva
 */

#include <iomanip>
#include <algorithm>
#include <map>
#include "AdmissionSystem.h"
#include <sstream>
#include <fstream>

AdmissionSystem::AdmissionSystem() {
	load_eligibilities_csv(this->elgb_vtr);
	load_courses_csv(this->crs_vtr, this->elgb_vtr);
	load_preference_csv(this->pre_vtr);
	load_student_csv(this->std_vtr,this->pre_vtr);
	load_capacity_csv(this->cap_vtr);
	load_center_csv(this->cntr_vtr,this->cap_vtr,this->crs_vtr);
	adminLogIn = 0;
	studentLogIn = 0;
	coordinatorLogIn = 0;
}

void AdmissionSystem::load_student_csv(vector<Student> &std_vtr,vector<Preference> &pre_vtr){
	string line;
	ifstream fin;
	//fin.open("04_students_1st_install_paid.csv");
	fin.open("students.csv");
	if (!fin) {
		cout << "Can't open students.csv file";
		return;
	}
	int std_count=0;
	while(getline(fin,line)){
		stringstream str(line);
		string token[13];
		for(int i=0;i<13;i++){
			getline(str,token[i],',');
		}
		//int formNo,string name,int rank_a,int rank_b,int rank_c,string degree,double percentage,int allocated_preference,string allocated_course_name,string allocated_center_id ,double payment,int reportedToCenter,string prn
		Student temp_std(stoi(token[0]),token[1],stoi(token[2]),stoi(token[3]),stoi(token[4]),token[5],stod(token[6]),stoi(token[7]),token[8],token[9],stod(token[10]),stoi(token[11]),token[12],pre_vtr);
		std_vtr.push_back(temp_std);
		std_count++;
	}
	cout<<"Student Count : "<<std_count<<endl;
}

void AdmissionSystem::load_preference_csv(vector<Preference> &pre_vtr){
	string line;
	ifstream fin;
	fin.open("01_preferences.csv");
	//fin.open("preferences.csv");
	if(!fin){
		cout<<"Can't open preferences.csv file";
		return;
	}
	int pre_count=0;
	while(getline(fin,line)){
		stringstream str(line);
		string token[4];
		for(int i=0;i<4;i++){
			getline(str,token[i],',');
		}
		Preference temp_pre_obj(stoi(token[0]),stoi(token[1]),token[2],token[3]);
		pre_vtr.push_back(temp_pre_obj);
		pre_count++;
	}
	cout<<"Preference Count : "<<pre_count<<endl;
}

void AdmissionSystem::load_eligibilities_csv(vector<Eligibility> &elgb_vtr){
	string line;
	ifstream fin;
	fin.open("eligibilities.csv");
	if (!fin) {
		cout << "Can't Open Eligibilities.csv file";
		return;
	}
	while(getline(fin,line)){
		stringstream str(line);
		string token[3];
		for(int i=0;i<3;i++){
			getline(str,token[i],',');
		}
		Eligibility temp_elgb_obj(token[0],token[1],stod(token[2]));
		elgb_vtr.push_back(temp_elgb_obj);
	}
}

void AdmissionSystem::load_courses_csv(vector<Course> &crs_vtr,vector<Eligibility> &elgb_vtr1){
	string line;
	ifstream fin;
	fin.open("courses.csv");
	if (!fin) {
		cout << "Can't Open courses.csv file";
		return;
	}
	while(getline(fin,line)){
		stringstream str(line);
		string token[4];
		for(int i=0;i<4;i++){
			getline(str,token[i],',');
		}
		Course temp_crs_obj1(stoi(token[0]),token[1],token[2],token[3],elgb_vtr1);
		crs_vtr.push_back(temp_crs_obj1);
	}
}

void AdmissionSystem::load_center_csv(vector<Center> &cntr_vtr,vector<Capacity> &cap_vtr,vector<Course> &crs_vtr){
	string line;
	ifstream fin;
	fin.open("centers.csv");
	if (!fin) {
		cout << "Can't Open courses.csv file";
		return;
	}
	while(getline(fin,line)){
		stringstream str(line);
		string token[5];
		for(int i=0;i<5;i++){
			getline(str,token[i],',');
		}
		Center temp_cntr_obj(token[0],token[1],token[2],token[3],token[4],cap_vtr,crs_vtr);
		cntr_vtr.push_back(temp_cntr_obj);
	}
}

void AdmissionSystem::load_capacity_csv(vector<Capacity> &cap_vtr){
	string line;
	ifstream fin;
	fin.open("capacities.csv");
	if (!fin) {
		cout << "Can't Open courses.csv file";
		return;
	}
	while(getline(fin,line)){
		stringstream str(line);
		string token[4];
		for(int i=0;i<4;i++){
			getline(str,token[i],',');
		}
		Capacity temp_cap_obj(token[0],token[1],stoi(token[2]),stoi(token[3]));
		cap_vtr.push_back(temp_cap_obj);
	}
}

void AdmissionSystem::save_eligibilities_csv(vector<Eligibility> &elgb_vtr) {
	ofstream fp;
	fp.open("Result\\eligibilities.csv");
	if(!fp){
		cout<<"Can't open eligibilitie.csv file";
		return;
	}
	vector<Eligibility>::iterator elgb_it;
	for(elgb_it = elgb_vtr.begin();elgb_it != elgb_vtr.end();++elgb_it){
		fp<<elgb_it->getCourseName()<<","<<elgb_it->getDegree()<<","<<elgb_it->getMinPercentage()<<endl;
	}
	fp.close();
}

void AdmissionSystem::save_courses_csv(vector<Course> &crs_vtr) {
	ofstream fp;
	fp.open("Result\\courses.csv");
	if (!fp) {
		cout << "Can't open courses.csv file";
		return;
	}
	vector<Course>::iterator crs_it;
	for (crs_it = crs_vtr.begin(); crs_it != crs_vtr.end(); ++crs_it) {
		fp << crs_it->getId()<<","<<crs_it->getName()<<","<<crs_it->getFees()<<","<<crs_it->getCcatSection()<<endl;
	}
	fp.close();
}

void AdmissionSystem::save_preference_csv(vector<Preference> &pre_vtr) {
	ofstream fp;
	fp.open("Result\\preferences.csv");
	if (!fp) {
		cout << "Can't open preferences.csv file";
		return;
	}
	vector<Preference>::iterator pref_it;
	for (pref_it = pre_vtr.begin(); pref_it != pre_vtr.end(); ++pref_it) {
		fp << pref_it->getStudentFormNo()<<","<<pref_it->getPreferenceNo()<<","<<pref_it->getCourseName()<<","<<pref_it->getCenterId()<<endl;
	}
	fp.close();
}

void AdmissionSystem::save_student_csv(vector<Student> &std_vtr) {
	ofstream fp;
		fp.open("Result\\students.csv");
		if (!fp) {
			cout << "Can't open students.csv file";
			return;
		}
		vector<Student>::iterator std_it;
	for (std_it = std_vtr.begin(); std_it != std_vtr.end(); ++std_it) {
		fp << std_it->getFormNo() << "," << std_it->getName() << ","
				<< std_it->getRankA() << "," << std_it->getRankB() << ","
				<< std_it->getRankC() << "," << std_it->getDegree() << ","
				<< std_it->getDegreeMarks() << ","
				<< std_it->getAllocatedPreference() << ","
				<< std_it->getCourseName() << "," << std_it->getCenterId()
				<< "," << std_it->getPayment() << "," << std_it->getReported()
				<< "," << std_it->getPrn() << endl;
	}
		fp.close();
}

void AdmissionSystem::save_capacity_csv(vector<Capacity> &cap_vtr) {
	ofstream fp;
	fp.open("Result\\capacites.csv");
	if (!fp) {
		cout << "Can't open capacites.csv file";
		return;
	}
	vector<Capacity>::iterator cap_it;
	for (cap_it = cap_vtr.begin(); cap_it != cap_vtr.end(); ++cap_it) {
		fp << cap_it->getCenterId() << "," << cap_it->getCourseName() << ","
				<< cap_it->getMaxCapacity() << ","
				<< cap_it->getFilledCapacity() << endl;
	}
	fp.close();
}

void AdmissionSystem::save_center_csv(vector<Center> &cntr_vtr) {
	ofstream fp;
	fp.open("Result\\centers.csv");
	if (!fp) {
		cout << "Can't open centers.csv file";
		return;
	}
	vector<Center>::iterator cntr_it;
	for (cntr_it = cntr_vtr.begin(); cntr_it != cntr_vtr.end(); ++cntr_it) {
		fp << cntr_it->getCenterId() << "," << cntr_it->getCenterName() << ","
				<< cntr_it->getAddress() << "," << cntr_it->getCoordinator()
				<< "," << cntr_it->getPassword() << endl;
	}
	fp.close();
}


void displayStudentDetailsById(vector<Student> &std_vtr,int std_formNo){
	for(unsigned int i=0;i<std_vtr.size();i++){
		if(std_formNo == std_vtr[i].getFormNo()){
			std_vtr[i].displayStudentDetails();
		}
	}
}

bool sortByRankA(Student s1,Student s2) {
	return (s1.getRankA() < s2.getRankA());
}

bool sortByFormNo(Student s1,Student s2) {
	return (s1.getFormNo() < s2.getFormNo());
}


bool sortByRankB(Student s1,Student s2) {
	return (s1.getRankB() < s2.getRankB());
}

bool sortByRankC(Student s1,Student s2) {
	return (s1.getRankC() < s2.getRankC());
}

struct Allocation{
	int formNo,prefNo,rank;
	string name,course_name,center_id;
};

bool sortByPref(Allocation a1,Allocation a2){
	return ((a1.prefNo < a2.prefNo) || ((a1.prefNo == a2.prefNo) && (a1.rank < a2.rank)) || ((a1.prefNo == a2.prefNo) && (a1.rank == a2.rank)));
}

void print_alc_vtr(vector<Allocation> &alc_vtr, vector<Student> &std_vtr,
		vector<Capacity> &cap_vtr, vector<Center> &cntr_vtr) {
	vector<Allocation>::iterator alc_it;
	vector<Student>::iterator std_it;
	vector<Preference>::iterator std_pref_it;
	vector<Capacity>::iterator cap_it;
	vector<Center>::iterator cntr_it;
	map<string, int>::iterator cntr_crs_it;

	cout << setw(10) << left << "Pref No";
	cout << setw(10) << left << "Form No";
	cout << setw(15) << left << " Student Name";
	cout << setw(10) << left << "Rank " << endl;
	for (alc_it = alc_vtr.begin(); alc_it != alc_vtr.end(); ++alc_it) {
		cout << setw(10) << left << alc_it->prefNo;
		cout << setw(10) << left << alc_it->formNo;
		cout << setw(15) << left << alc_it->name;
		cout << setw(10) << left << alc_it->rank << endl;

		for (cap_it = cap_vtr.begin(); cap_it != cap_vtr.end(); ++cap_it) {
			if ((cap_it->getCenterId() == alc_it->center_id)
					&& (cap_it->getCourseName() == alc_it->course_name)
					&& (cap_it->getFilledCapacity() < cap_it->getMaxCapacity())) {

				for (std_it = std_vtr.begin(); std_it != std_vtr.end();
						++std_it) {
					if ((alc_it->formNo == std_it->getFormNo())
							&& (std_it->getAllocatedPreference() == 0)) {

						// Update Student Vector
						std_it->setAllocatedPreference(alc_it->prefNo);
						std_it->setCenterId(alc_it->center_id);
						std_it->setCourseName(alc_it->course_name);

						// Update Capacity Vector
						int temp_fill = cap_it->getFilledCapacity();
						++temp_fill;
						cap_it->setFilledCapacity(temp_fill);
					}
				}

			}
		}
	}
}

void AdmissionSystem::allocateCentersRound2() {
	vector<Student>::iterator std_it;

	//Mark payment = -1 who doesn't paid fees after round 1
	for (std_it = std_vtr.begin(); std_it != std_vtr.end(); ++std_it) {
		if ((std_it->getAllocatedPreference() != 0)
				&& (std_it->getPayment() != 11800)) {
			std_it->setPayment(-1);
		}
		std_it->setAllocatedPreference(0);
		std_it->setCenterId("NA");
		std_it->setCourseName("NA");
	}

	//Clear Capacity Vector
	vector<Capacity>::iterator cap_it;
	for (cap_it = cap_vtr.begin(); cap_it != cap_vtr.end(); ++cap_it) {
		cap_it->setFilledCapacity(0);
	}

	//Clear Center Capacity Map
	vector<Center>::iterator cntr_it;
	map<string, int>::iterator cntr_cap_it;
	for (cntr_it = cntr_vtr.begin(); cntr_it != cntr_vtr.end(); ++cntr_it) {
		for (cntr_cap_it = cntr_it->getCrsFillSeats().begin();
				cntr_cap_it != cntr_it->getCrsFillSeats().end();
				++cntr_cap_it) {
			cntr_cap_it->second = 0;
		}
	}
	allocateCentersRound1();
}

void AdmissionSystem::allocateCentersRound1() {
	vector<Center>::iterator cntr_it;
	map<string, int>::iterator cntr_crs_it;
	vector<Course>::iterator crs_it;
	vector<Student>::iterator std_it;
	vector<Preference>::iterator std_pref_it;
	vector<Allocation> alc_vtr;

	int preference_loop = 0;
	while (++preference_loop <= 10) {
		for (cntr_it = cntr_vtr.begin(); cntr_it != cntr_vtr.end(); ++cntr_it) {
			cout << "Center : " << cntr_it->getCenterId() << endl;
			for (cntr_crs_it = cntr_it->getCrsMaxCap().begin();
					cntr_crs_it != cntr_it->getCrsMaxCap().end();
					++cntr_crs_it) {
				cout << "Course : " << cntr_crs_it->first;
				alc_vtr.clear();
				for (crs_it = crs_vtr.begin(); crs_it != crs_vtr.end();
						++crs_it) {
					if (cntr_crs_it->first == crs_it->getName()) {
						cout << " - Section : " << crs_it->getCcatSection()
								<< endl;
						if (crs_it->getCcatSection() == "A") {
							sort(std_vtr.begin(), std_vtr.end(), sortByRankA);
							break;
						}
						if (crs_it->getCcatSection() == "B") {
							sort(std_vtr.begin(), std_vtr.end(), sortByRankB);
							break;
						}
						if (crs_it->getCcatSection() == "C") {
							sort(std_vtr.begin(), std_vtr.end(), sortByRankC);
							break;
						}
					}
				}
				struct Allocation temp_alc;
				for (std_it = std_vtr.begin(); std_it != std_vtr.end();
						++std_it) {
					for (std_pref_it = std_it->getPreferences().begin();
							std_pref_it != std_it->getPreferences().end();
							++std_pref_it) {
						if ((std_pref_it->getCenterId()
								== cntr_it->getCenterId())
								&& (std_pref_it->getCourseName()
										== cntr_crs_it->first) && (std_pref_it->getPreferenceNo()==preference_loop)) {
							if (!(std_it->getPayment() < 0)) {
								temp_alc.formNo = std_it->getFormNo();
								temp_alc.prefNo =
										std_pref_it->getPreferenceNo();
								temp_alc.name = std_it->getName();
								temp_alc.center_id = cntr_it->getCenterId();
								temp_alc.course_name = cntr_crs_it->first;
								if (crs_it->getCcatSection() == "A") {
									temp_alc.rank = std_it->getRankA();
								} else if (crs_it->getCcatSection() == "B") {
									temp_alc.rank = std_it->getRankB();
								} else if (crs_it->getCcatSection() == "C") {
									temp_alc.rank = std_it->getRankC();
								}
								alc_vtr.push_back(temp_alc);
							}
						}
					}
				}
				sort(alc_vtr.begin(), alc_vtr.end(), sortByPref);
				print_alc_vtr(alc_vtr, std_vtr, cap_vtr, cntr_vtr);
				cout
						<< "======================================================="
						<< endl;
			}
			cout << "*******************" << endl;
		}
	}

	vector<Capacity>::iterator cap_it;
	// Update Center Vector (Course-Capacity Map)
	for (cntr_it = cntr_vtr.begin(); cntr_it != cntr_vtr.end(); ++cntr_it) {
		for (cap_it = cap_vtr.begin(); cap_it != cap_vtr.end(); ++cap_it) {
			if (cntr_it->getCenterId() == cap_it->getCenterId()) {
				for (cntr_crs_it = cntr_it->getCrsFillSeats().begin();
						cntr_crs_it != cntr_it->getCrsFillSeats().end();
						++cntr_crs_it) {
					if (cap_it->getCourseName() == cntr_crs_it->first) {
						cntr_crs_it->second = cap_it->getFilledCapacity();
					}
				}
			}
		}
	}
}

void AdmissionSystem::adminLogin(){
	adminMenu(20);
}
void AdmissionSystem::adminLogout(){
	adminMenu(21);
}

void AdmissionSystem::adminMenu(int choice) {
	switch (choice) {
	case 1: {
		Course::listCoursesAndEligibility(crs_vtr);
		break;
	}
	case 2: {
		//Center::listCentersAndCapacitiesUsingMap(cntr_vtr);
		Center::listCentersAndCapacities(cntr_vtr,cap_vtr);
		break;
	}
	case 3: {
		Student::listStudents(std_vtr);
		break;
	}
	case 4: {
		break;
	}
	case 5: {
		allocateCentersRound1();
		sort(std_vtr.begin(),std_vtr.end(),sortByFormNo);
		break;
	}
	case 6: {
		allocateCentersRound2();
		sort(std_vtr.begin(),std_vtr.end(),sortByFormNo);
		break;
	}
	case 7: {
		Student::listAllocatedStudents(std_vtr);
		break;
	}
	case 8: {
		Student::listPaidStudents(std_vtr);
		break;
	}
	case 9: {
		Student::listReportedtoCenterStudents(std_vtr);
		break;
	}
	case 10: {
		Student::generatePRNNumber(std_vtr);
		break;
	}
	case 11: { //listAdmitedStudents at given Center
		string center_id;
		cout << "Enter Center Id: ";
		cin >> center_id;
		Center curr_cntr_obj;
		curr_cntr_obj.get_Center(cntr_vtr, center_id);
		curr_cntr_obj.listAdmittedStudents(std_vtr);
		break;
	}
	case 20: { //SignIn
		if (adminLogIn) {
			break;
		}
		string username, password;
		cout << "Username : ";
		cin >> username;
		cout << "Password : ";
		cin >> password;
		if (username == "admin" && password == "admin") {
			cout << "Logged In Successfully !" << endl;
			adminLogIn = 1;
		} else {
			cerr << "Invalid User" << endl;
		}
		break;
	}
	case 21: { //Logout
		if(!adminLogIn){
			break;
		}
		adminLogIn = 0;
		cout<<"Logout Successfully"<<endl;
	}
	}
}

void AdmissionSystem::studentLogin(){
	studentMenu(20);
}

void AdmissionSystem::studentLogout(){
	studentMenu(21);
}
void AdmissionSystem::studentMenu(int choice) {
	static Student curr_std_obj;
	static int std_vtr_index;
	switch (choice) {
	case 1: { // Register Student
		break;
	}
	case 2: {
		curr_std_obj.listCoursesAsPerEligibility(crs_vtr);
		break;
	}
	case 3: {
		Center::listCentersAndCapacitiesUsingMap(cntr_vtr);
		break;
	}
	case 4: { //Give Preferences
		if (curr_std_obj.getPreferences().size() == 0) {
			cout << "No Preference has been given Early" << endl;
			cout<<"Want To Add Preference :  y/n : ";
		} else if (curr_std_obj.getPreferences().size() >= 10) {
			cerr << "10 Preferences Already Given !" << endl;
			break;
		}else{
			cout<<"Already Filled Preferences By You "<<endl;
			curr_std_obj.listFilledPreferences(pre_vtr);
			string check;
			cout << "Do You want to Clear Already Filled Preferences y/n : ";
			do {
				cin >> check;
				if (check == "y") {
					curr_std_obj.clearAlreadyFilledPreferences(pre_vtr);
					std_vtr[std_vtr_index].setPreferences(curr_std_obj.getPreferences());
					//curr_std_obj.setStudent(std_vtr); // To update preferences in student vector
					cout<<"Do You Want To Add Preference :  y/n : ";
					break;
				}else if(check == "n"){
					cout<<"Do You Want To Add More Preference :  y/n : ";
				}else if (check != "n") {
					cerr << "Invalid Input" << endl;
				}
			} while (check != "n");
		}
		string check;
		do{
			cin>>check;
			if (check == "y") {
				break;
			}else if(check != "n"){
				cerr<<"Invalid Input"<<endl;
			}
		}while(check != "n");

		if(check == "n" ){
			break;
		}
		while (curr_std_obj.getPreferences().size() < 11) {
			vector<eligiblePreferences> elgb_pref_vtr;
			cout << "Choose Preferences From Below Options " << endl;
			elgb_pref_vtr = Center::listPreferencesAsPerEligilibity(
					curr_std_obj, crs_vtr, cntr_vtr, pre_vtr);
			curr_std_obj.givePreferences(crs_vtr, pre_vtr, elgb_pref_vtr);
			std_vtr[std_vtr_index].setPreferences(curr_std_obj.getPreferences());
			//curr_std_obj.setStudent(std_vtr); // To update preferences in student vector
			cout << "Preference Added Successfully !" << endl;
			if (curr_std_obj.getPreferences().size() >= 10) {
				cerr << "10 Preferences Added Successfully !" << endl;
				break;
			}
			cout<<"Do You Want To Add More Preference :  y/n : ";
			string check;
			do {
				cin >> check;
				if (check == "y") {
					break;
				} else if (check != "n") {
					cerr << "Invalid Input" << endl;
				}
			} while (check != "n");
			if (check == "n") {
				break;
			}
		}
		break;
	}
	case 5: { // see allocated Center and Course
		if(curr_std_obj.getAllocatedPreference()==0){
			cout<<"You Haven't allocated to Any Center Yet "<<endl;
			break;
		}
		curr_std_obj.displayAllocatedCenterAndCourse();
		break;
	}
	case 6: { // update payment details
		bool check = curr_std_obj.updatePaymentDetails();
		if (check) {
			std_vtr[std_vtr_index].setPayment(curr_std_obj.getPayment());
			cout << "Payment Successful !" << endl;
		}
		break;
	}
	case 20: {
		if (isStudentLogIn()) {
			break;
		}
		std_vtr_index = curr_std_obj.LoginIn(std_vtr, pre_vtr);
		if (std_vtr_index != -1) {
			studentLogIn = 1;
			cout<<"Login Successfully !"<<endl;
		}
		break;
	}
	case 21: {
		if (!studentLogIn) {
			break;
		}
		studentLogIn = 0;
		cout << "Logout Successfully !" << endl;
	}
	}
}

void AdmissionSystem::coordinatorLogin(){
	coordinatorMenu(20);
}

void AdmissionSystem::coordinatorLogout(){
	coordinatorMenu(21);
}
void AdmissionSystem::coordinatorMenu(int choice) {
	static Center curr_cntr_obj;
	switch (choice) {
	case 1: {
		curr_cntr_obj.listCoursesOfCenter();
		break;
	}
	case 2: {
		curr_cntr_obj.listStudentsAllocatedToCenter(std_vtr);
		break;
	}
	case 3: {
		curr_cntr_obj.updateReportedStatus(std_vtr);
		break;
	}
	case 4: {
		curr_cntr_obj.listAdmittedStudents(std_vtr);
		break;
	}
	case 20: {
		if (coordinatorLogIn) {
			break;
		}
		curr_cntr_obj.LoginIn(cntr_vtr);
		if (curr_cntr_obj.getCoordinator() != "") {
			coordinatorLogIn = 1;
			cout << "Logged In Successfully !" << endl;
		}
		break;
	}
	case 21: {
		if (!coordinatorLogIn) {
			break;
		}
		coordinatorLogIn = 0;
		cout << "Logged Out Successfully !" << endl;
	}
	}
}

AdmissionSystem::~AdmissionSystem() {
	cout<<"Saving Files...."<<endl;
	save_eligibilities_csv(this->elgb_vtr);
	save_courses_csv(this->crs_vtr);
	save_preference_csv(this->pre_vtr);
	save_student_csv(this->std_vtr);
	save_capacity_csv(this->cap_vtr);
	save_center_csv(this->cntr_vtr);
}

Student& AdmissionSystem::getStdObjFix() {
	return std_obj_fix;
}

bool AdmissionSystem::isAdminLogIn() {
	return adminLogIn;
}

void AdmissionSystem::setAdminLogIn(int adminLogIn) {
	this->adminLogIn = adminLogIn;
}

bool AdmissionSystem::isCoordinatorLogIn() {
	return coordinatorLogIn;
}

void AdmissionSystem::setCoordinatorLogIn(bool coordinatorLogIn) {
	this->coordinatorLogIn = coordinatorLogIn;
}

bool AdmissionSystem::isStudentLogIn() {
	return studentLogIn;
}

void AdmissionSystem::setStudentLogIn(bool studentLogIn) {
	this->studentLogIn = studentLogIn;
}

void AdmissionSystem::setStdObjFix(Student& stdObjFix) {
	std_obj_fix = stdObjFix;
}
