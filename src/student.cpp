#include <iostream>
#include "student.h"

student::student()
{
	std::cout << "Constuctor Called" << std::endl;

	data.roll_no = "";
	data.age = 0;
	data.cgpa = 0.0;
}

student::~student()
{
	std::cout << "Destuctor Called" << std::endl;
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

void student::set_subject_marks(std::string subject, int marks)
{
	result[subject] = marks;
}

int student::get_subject_marks(std::string subject)
{
	std::map<std::string, int>::const_iterator it = result.find(subject);
	if (it != result.end())
	{
		return it->second;
	}
	else
	{
		return -1;
	}
}

void student::print_all_marks()
{
	std::map<std::string, int>::const_iterator it;
	for (it = result.begin(); it != result.end(); ++it)
	{
		std::cout << "Subject: " << it->first << ", Marks: " << it->second << std::endl;
	}
}