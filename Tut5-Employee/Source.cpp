#pragma once
#include <string>

using namespace std;
class Employee
{
protected:
	double Salary;
	string Name;
	int StaffNum;
	static int numberOfEmployee;
public:
	Employee();
	string name();
	int staffNumber();
	int getNumOfEmployee();
	virtual double salary();
	~Employee();
};

class SalaryEmployee : public Employee {

public:
	SalaryEmployee(int StaffNum_in, string name_in);
	void setSalary(double salary_in);
	virtual double salary();
	~SalaryEmployee();
};

class HourlyEmployee : public Employee {
protected:
	double hourlyR;
	int HoursW;
public:
	HourlyEmployee(int StaffNum_in, string name_in);
	void setHourlyRate(double hourlyR_in);
	void setHoursWorked(int HoursW_in);
	virtual double salary();
	~HourlyEmployee();
};

class CommissionEmployee : public Employee {
protected:
	double Bsalary;
	double rate;
	int rev;
public:
	CommissionEmployee(int StaffNum_in, string name_in);
	void setBaseSalary(double Bsalary_in);
	void setRate(double rate_in);
	void setRevenue(int rev_in);
	virtual double salary();
	~CommissionEmployee();
};