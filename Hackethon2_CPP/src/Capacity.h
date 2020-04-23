/*
 * Capacity.h
 *
 *  Created on: 16-Apr-2020
 *      Author: shiva
 */
#include <string>
using namespace std;

#ifndef SRC_CAPACITY_H_
#define SRC_CAPACITY_H_

class Capacity {
private:
	string center_id;
	string course_name;
	int max_capacity;
	int filled_capacity;
public:
	Capacity();
	Capacity(string center_id,string course_name,int max_capacity,int filled_capacity);
	~Capacity();
	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	const string& getCourseName() const;
	void setCourseName(const string& courseName);
	int getFilledCapacity() const;
	void setFilledCapacity(int filledCapacity);
	int getMaxCapacity() const;
	void setMaxCapacity(int maxCapacity);
};

#endif /* SRC_CAPACITY_H_ */
