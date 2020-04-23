#include <iostream>
#include <iomanip>
using namespace std;

#ifndef SRC_MENU_H_
#define SRC_MENU_H_

int mainMenu() {
	int choice;
	cout << setw(20) << right << "Login As" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Admin" << endl;
	cout << "2. Student" << endl;
	cout << "3. Centre Coordinator" << endl;
	cout << "Enter Choice : " << endl;
	cin >> choice;
	return choice;
}

int studentMenuList() {
	int choice;
	cout << "\n ** Student Menu **" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Register a New Student" << endl;
	cout << "2. List courses (as per eligibility)" << endl;
	cout << "3. List centers" << endl;
	cout << "4. Give preferences" << endl;
	cout << "5. See allocated center/course" << endl;
	cout << "6. Update payment details" << endl;
	cout << "Enter Choice : " << endl;
	cin >> choice;
	return choice;
}

int adminMenuList() {
	int choice;
	cout << "\n ** Admin Menu **" << endl;
	cout << "0. Exit" << endl;
	cout << "1. List courses & eligibilities" << endl;
	cout << "2. List centers & capacities" << endl;
	cout << "3. List Students" << endl;
	cout << "4. Update student ranks" << endl;
	cout << "5. Allocate centers (Round 1)" << endl;
	cout << "6. Allocate centers (Round 2)" << endl;
	cout << "7. List allocated students" << endl;
	cout << "8. List paid students" << endl;
	cout << "9. List reported (at center) students" << endl;
	cout << "10. Generate PRN" << endl;
	cout << "11. List admitted students (with PRN) for given center" << endl;
	cout << "Enter Choice : " << endl;
	cin >> choice;
	return choice;
}

int coordinatorMenuList() {
	int choice;
	cout << "\n ** Coordinator Menu **" << endl;
	cout << "0. Exit" << endl;
	cout << "1. List Courses (of that Centers)" << endl;
	cout << "2. List Students (Allocated to that Center)" << endl;
	cout << "3. Update Reported Status" << endl;
	cout << "4. List Admitted Students (with PRN)" << endl;
	;
	cout << "Enter Choice : " << endl;
	cin >> choice;
	return choice;
}

#endif /* SRC_MENU_H_ */
