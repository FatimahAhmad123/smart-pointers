#include <iostream>
#include "student.hpp"
#include "database.hpp"

int main()
{

	rakurai::training::Database database;

	std::shared_ptr<rakurai::training::student> studentPtr = database.get_student_reference("Ali");

	if (studentPtr)
	{

		std::cout << "Student Info:\n";
		std::cout << "Name: " << studentPtr->get_name() << "\n";
		std::cout << "Roll No: " << studentPtr->get_roll_no() << "\n";
		std::cout << "Age: " << studentPtr->get_age() << "\n";
		std::cout << "CGPA: " << studentPtr->get_cgpa() << "\n";
	}
	else
	{
		std::cout << "Student not found.\n";
	}

	return 0;
}
