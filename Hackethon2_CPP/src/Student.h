/*
 * Student.h
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */
#include <string>
#include <vector>
#include "Course.h"
#include "Preference.h"
using namespace std;
#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

struct eligiblePreferences{
	unsigned int sr_no;
	string center_id,course;
};

class Student {
private :
	int form_no;
	string name;
	int rank_a,rank_b,rank_c;
	string degree;
	double degree_marks;
	string course_name;
	string center_id;
	double payment;
	int reported;
	int allocated_preference;
	string prn;
	vector<Preference> preferences;
public:
	Student();
	Student(int formNo,string name,int rank_a,int rank_b,int rank_c,string degree,double degree_marks,int allocated_preference,string allocated_course_name,string allocated_center_id ,double payment,int reportedToCenter,string prn,vector<Preference> &pre_vtr);
	Student(vector<Student> &std_vtr,vector<Preference> &pre_vtr,int formNo);
	int getStudent(vector<Student> &std_vtr, vector<Preference> &pre_vtr,int formNo);
	void setStudent(vector<Student> &std_vtr);
	void displayAllocatedCenterAndCourse();
	bool updatePaymentDetails();
	static void listStudents(vector<Student> &std_vtr);
	static void listStudentsWithPreferences(vector<Student> &std_vtr,
			vector<Preference> &pre_vtr);
	static void listAllocatedStudents(vector<Student> &std_vtr);
	static void listPaidStudents(vector<Student> &std_vtr);
	static void listReportedtoCenterStudents(vector<Student> &std_vtr);
	static void generatePRNNumber(vector<Student> &std_vtr);
	static void listAdmitedStudents(vector<Student> &std_vtr);
	void listFilledPreferences(vector<Preference> &pre_vtr);
	bool validateStudent(int username,string password,vector<Student> &std_vtr);

	int LoginIn(vector<Student> &std_vtr,vector<Preference> &pre_vtr);
	~Student();

	void listCoursesAsPerEligibility(vector<Course> &crs_vtr);
	void givePreferences(vector<Course> &crs_vtr, vector<Preference> &pre_vtr,
			vector<eligiblePreferences> &elgb_pref_vtr);
	void clearAlreadyFilledPreferences(vector<Preference> &pre_vtr);

	void displayStudentDetails();

	Student getStudentDetailsByID(int std_id);
	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	const string& getCourseName() const;
	void setCourseName(const string& courseName);
	const string& getDegree() const;
	void setDegree(const string& degree);
	double getDegreeMarks() const;
	void setDegreeMarks(double degreeMarks);
	const string& getName() const;
	void setName(const string& name);
	int getPayment() const;
	void setPayment(int payment);
	const string& getPrn() const;
	void setPrn(const string& prn);
	int getRankA() const;
	void setRankA(int rankA);
	int getRankB() const;
	void setRankB(int rankB);
	int getRankC() const;
	void setRankC(int rankC);
	int getReported() const;
	void setReported(int reported);
	int getFormNo() const;
	void setFormNo(int formNo);
	vector<Preference>& getPreferences();
	void setPreferences(vector<Preference>& preferences);
	int getAllocatedPreference();
	void setAllocatedPreference(int allocatedPreference);
};

#endif /* SRC_STUDENT_H_ */
