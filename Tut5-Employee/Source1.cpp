#include "Employee.h"
#include <string>
#include <iostream>

using namespace std;

int Employee::numberOfEmployee = 0;
Employee::Employee() {
}

Employee::~Employee() {

}

int Employee::getNumOfEmployee() {
	return numberOfEmployee;
}

double Employee::salary() {
	return Salary;
}

int Employee::staffNumber() {
	return StaffNum;
}

string Employee::name() {
	return Name;
}

SalaryEmployee::SalaryEmployee(int StaffNum_in, string name_in)
{
	StaffNum = StaffNum_in;
	Name = name_in;
	Employee::numberOfEmployee += 1;
}

void SalaryEmployee::setSalary(double salary_in) {
	Salary = salary_in;
}

double SalaryEmployee::salary() {
	return Salary;
}

SalaryEmployee::~SalaryEmployee() {
Empoyee:numberOfEmployee -= 1;
}

HourlyEmployee::HourlyEmployee(int StaffNum_in, string name_in) {
	StaffNum = StaffNum_in;
	Name = name_in;
	Employee::numberOfEmployee += 1;
}

void HourlyEmployee::setHourlyRate(double hourlyR_in) {
	hourlyR = hourlyR_in;
}

void HourlyEmployee::setHoursWorked(int HoursW_in) {
	HoursW = HoursW_in;
}

double HourlyEmployee::salary() {
	Salary = hourlyR*HoursW;
	return Salary;
}

HourlyEmployee::~HourlyEmployee() {
	Employee::numberOfEmployee -= 1;
}

CommissionEmployee::CommissionEmployee(int StaffNum_in, string name_in) {
	StaffNum = StaffNum_in;
	Name = name_in;
	Employee::numberOfEmployee += 1;
}

void CommissionEmployee::setBaseSalary(double Bsalary_in) {
	Bsalary = Bsalary_in;
}

void CommissionEmployee::setRate(double rate_in) {
	rate = rate_in;
}

void CommissionEmployee::setRevenue(int rev_in) {
	rev = rev_in;
}

double CommissionEmployee::salary() {
	Salary = Bsalary + rate*rev;
	return Salary;
}

CommissionEmployee::~CommissionEmployee() {
	Employee::numberOfEmployee -= 1;
}

int main() {
	double totalWages = 0;
	Employee *EmployeePtr;
	SalaryEmployee *S_Emp = new SalaryEmployee(123, "Dan");
	HourlyEmployee H_Emp(456, "Ben");
	CommissionEmployee C_Emp(789, "John");
	S_Emp->setSalary(500);
	H_Emp.setHourlyRate(3.4);
	H_Emp.setHoursWorked(50);
	C_Emp.setBaseSalary(200);
	C_Emp.setRate(3.2);
	C_Emp.setRevenue(900);
	EmployeePtr = S_Emp;
	totalWages += EmployeePtr->salary();
	EmployeePtr = &H_Emp;
	totalWages += EmployeePtr->salary();
	EmployeePtr = &C_Emp;
	totalWages += EmployeePtr->salary();
	cout << totalWages << endl;
	cout << EmployeePtr->getNumOfEmployee() << endl;
	delete S_Emp;
	cout << C_Emp.getNumOfEmployee() << endl;
}