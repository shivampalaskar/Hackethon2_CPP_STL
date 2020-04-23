/*
 * Center.h
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */
#include "Capacity.h"
#include "Course.h"
#include "Student.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

#ifndef SRC_CENTER_H_
#define SRC_CENTER_H_

class Center {
private :
	string center_id;
	string center_name;
	string address;
	string coordinator;
	string password;
	map<string, int> crs_max_cap;
	map<string, int> crs_fill_seats;
public:
	Center();
	Center(string center_id, string center_name, string address,
			string coordinator, string password,vector<Capacity> &cap_vtr,vector<Course> &crs_vtr);
	static void listCentersAndCapacities(vector<Center> &cntr_vtr, vector<Capacity> &cap_vtr);
	static void listCentersAndCapacitiesUsingMap(vector<Center> &cntr_vtr);
	static vector<eligiblePreferences> listPreferencesAsPerEligilibity(Student curr_std_obj,vector<Course> &crs_vtr,vector<Center> &cntr_vtr,vector<Preference> &pre_vtr);
	void listStudentsAllocatedToCenter(vector<Student> &std_vtr);
	void listAdmittedStudents(vector<Student> &std_vtr);
	void updateReportedStatus(vector<Student> &std_vtr);


	void get_Center(vector<Center> &cntr_vtr,string username);
	void LoginIn(vector<Center> &cntr_vtr);
	void listCoursesOfCenter();


	virtual ~Center();
	const string& getAddress() const;
	void setAddress(const string& address);
	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	const string& getCenterName() const;
	void setCenterName(const string& centerName);
	const string& getCoordinator() const;
	void setCoordinator(const string& coordinator);
	const string& getPassword() const;
	void setPassword(const string& password);
	vector<Capacity>& getCntrCapVtr();
	void setCntrCapVtr(vector<Capacity>& cntrCapVtr);
	map<string, int>& getCrsFillSeats();
	void setCrsFillSeats(map<string, int>& crsFillSeats);
	map<string, int>& getCrsMaxCap();
	void setCrsMaxCap(map<string, int>& crsMaxCap);
};

#endif /* SRC_CENTER_H_ */
