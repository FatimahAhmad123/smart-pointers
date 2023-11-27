#include <iostream>
#include "student.hpp"

namespace rakurai::training
{
	student::student(const std::string &name, int age, float cgpa, const std::string &roll_no)
	{
		data.name = name;
		data.roll_no = roll_no;
		data.age = age;
		data.cgpa = cgpa;
	}

	void student::set_name(std::string std_name)
	{
		data.name = std_name;
	}

	std::string student::get_name() const
	{
		return data.name;
	}

	void student::set_roll_no(std::string roll)
	{
		data.roll_no = roll;
	}

	std::string student::get_roll_no() const
	{
		return data.roll_no;
	}

	void student::set_age(int age)
	{
		data.age = age;
	}

	int student::get_age() const
	{
		return data.age;
	}

	void student::set_cgpa(float cgpa)
	{
		data.cgpa = cgpa;
	}

	float student::get_cgpa() const
	{
		return data.cgpa;
	}

}