#include <string>
#include <vector>
using namespace std;

#ifndef SRC_ELIGIBILITY_H_
#define SRC_ELIGIBILITY_H_

class Eligibility {
private:
	string course_name;
	string degree;
	double min_percentage;
public:
	Eligibility();
	Eligibility(string course_name,string degree,double min_percentage);
	Eligibility(vector<Eligibility> &elgb_vtr , string name);
	~Eligibility();
	string& getCourseName() ;
	void setCourseName(string& courseName);
	string& getDegree();
	void setDegree(string& degree);
	double getMinPercentage();
	void setMinPercentage(double minPercentage);
};

#endif /* SRC_ELIGIBILITY_H_ */
