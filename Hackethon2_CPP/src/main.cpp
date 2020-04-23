#include <iostream>
#include <iomanip>
#include "menu.h"
#include "AdmissionSystem.h"
using namespace std;

int main() {
	int choice;
	AdmissionSystem admSys_obj;
	while ((choice = mainMenu()) != 0) {
		switch (choice) {
		case 1: {
			admSys_obj.adminLogin();
			while (admSys_obj.isAdminLogIn() && (choice = adminMenuList()) != 0) {
				admSys_obj.adminMenu(choice);
			}
			admSys_obj.adminLogout();
			break;
		}
		case 2: {
			admSys_obj.studentLogin();
			while(admSys_obj.isStudentLogIn() && (choice = studentMenuList()) != 0){
				admSys_obj.studentMenu(choice);
			}
			admSys_obj.studentLogout();
			break;
		}
		case 3: {
			admSys_obj.coordinatorLogin();
			while (admSys_obj.isCoordinatorLogIn() && (choice = coordinatorMenuList()) != 0) {
				admSys_obj.coordinatorMenu(choice);
			}
			admSys_obj.coordinatorLogout();
			break;
		}
		}
	}
	return 0;
}
