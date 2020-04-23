/*
 * Preference.h
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */
#include <string>
#include <vector>
using namespace std;

#ifndef SRC_PREFERENCE_H_
#define SRC_PREFERENCE_H_

class Preference {
private :
	int student_form_no;
	int preference_no;
	string course_name;
	string center_id;
public:
	Preference();
	Preference(int student_form_no,int preference_no,string course_name,string center_id);
	Preference(vector<Preference> &pre_vtr,int formNo);
	virtual ~Preference();
	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	const string& getCourseName() const;
	void setCourseName(const string& courseName);
	int getPreferenceNo() const;
	void setPreferenceNo(int preferenceNo);
	int getStudentFormNo() const;
	void setStudentFormNo(int studentFormNo);
};

#endif /* SRC_PREFERENCE_H_ */
