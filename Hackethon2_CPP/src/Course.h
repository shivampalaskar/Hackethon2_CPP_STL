#include <string>
#include <vector>
#include "Eligibility.h"
using namespace std;

#ifndef SRC_COURSE_H_
#define SRC_COURSE_H_

class Course {
private:
	int id;
	string name;
	string fees;
	string ccat_section;
	vector<Eligibility> eligibilities;
public:
	Course();
	Course(int id,string name,string fees,string ccat_section,vector<Eligibility> elgb_vtr);
	static void listCoursesAndEligibility(vector<Course> &crs_vtr);
	~Course();
	const string& getCcatSection() const;
	void setCcatSection(const string& ccatSection);
	const string& getFees() const;
	void setFees(const string& fees);
	int getId() const;
	void setId(int id);
	const string& getName() const;
	void setName(const string& name);
	vector<Eligibility>& getEligibilities();
	void setEligibilities(vector<Eligibility>& eligibilities);
};

#endif /* SRC_COURSE_H_ */
