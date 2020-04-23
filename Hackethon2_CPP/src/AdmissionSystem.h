#include <iostream>
#include <vector>
#include "Center.h"
//#include "Course.h"
#include "Student.h"
#include "Capacity.h"
using namespace std;

#ifndef SRC_ADMISSIONSYSTEM_H_
#define SRC_ADMISSIONSYSTEM_H_

class AdmissionSystem {
private:
	Student std_obj_fix;
	/*Center centers;
	Course courses;
	Student students;
	string degrees;
	Capacity capacities;*/

	bool adminLogIn;
	bool studentLogIn;
	bool coordinatorLogIn;

	vector<Student> std_vtr;
	vector<Preference> pre_vtr;
	vector<Eligibility> elgb_vtr;
	vector<Course> crs_vtr;
	vector<Capacity> cap_vtr;
	vector<Center> cntr_vtr;

public:
	void load_student_csv(vector<Student> &std_vtr,vector<Preference> &pre_vtr);
	void load_preference_csv(vector<Preference> &pre_vtr);
	void load_eligibilities_csv(vector<Eligibility> &elgb_vtr);
	void load_courses_csv(vector<Course> &crs_vtr, vector<Eligibility> &elgb_vtr);
	void load_capacity_csv(vector<Capacity> &cap_vtr);
	void load_center_csv(vector<Center> &cntr_vtr,vector<Capacity> &cap_vtr,vector<Course> &crs_vtr);

	void save_eligibilities_csv(vector<Eligibility> &elgb_vtr);
	void save_courses_csv(vector<Course> &crs_vtr);
	void save_preference_csv(vector<Preference> &pre_vtr);
	void save_student_csv(vector<Student> &std_vtr);
	void save_capacity_csv(vector<Capacity> &cap_vtr);
	void save_center_csv(vector<Center> &cntr_vtr);

	void adminLogin();
	void adminLogout();
	void studentLogin();
	void studentLogout();
	void coordinatorLogin();
	void coordinatorLogout();

	void studentMenu(int choice);
	void adminMenu(int choice);
	void coordinatorMenu(int choice);

	void allocateCentersRound1();
	void allocateCentersRound2();
	AdmissionSystem();
	~AdmissionSystem();

	Student& getStdObjFix();
	void setStdObjFix(Student& stdObjFix);

	bool isAdminLogIn();
	void setAdminLogIn(int adminLogIn);
	bool isCoordinatorLogIn();
	void setCoordinatorLogIn(bool coordinatorLogIn);
	bool isStudentLogIn();
	void setStudentLogIn(bool studentLogIn);
};

#endif /* SRC_ADMISSIONSYSTEM_H_ */
