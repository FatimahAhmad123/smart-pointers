#include <iostream>
#include "student.hpp"
#include "database.hpp"

void print_student_record(std::unique_ptr<rakurai::training::student> student_ptr)
{
	if (student_ptr)
	{
		try
		{
			std::cout << "Name: " << student_ptr->get_name() << std::endl;
			std::cout << "Roll No: " << student_ptr->get_roll_no() << std::endl;
			std::cout << "Age: " << student_ptr->get_age() << std::endl;
			std::cout << "CGPA: " << student_ptr->get_cgpa() << std::endl;
			std::cout << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	else
	{
		std::cout << "Student not found.\n";
	}
}

int main()
{

	rakurai::training::Database database;

	std::shared_ptr<rakurai::training::student> studentPtr = database.get_student_reference("Fatimah");

	if (studentPtr)
	{
		std::cout << "Using shared pointer:\n";
		std::cout << "Name: " << studentPtr->get_name() << std::endl;
		std::cout << "Roll No: " << studentPtr->get_roll_no() << std::endl;
		std::cout << "Age: " << studentPtr->get_age() << std::endl;
		std::cout << "CGPA: " << studentPtr->get_cgpa() << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Student not found.\n";
	}

	std::unique_ptr<rakurai::training::student> studentUniquePtr = database.get_student_unique("Ali");

	if (studentUniquePtr)
	{
		std::cout << "Using unique pointer:\n";
		std::cout << "Name: " << studentUniquePtr->get_name() << std::endl;
		std::cout << "Roll No: " << studentUniquePtr->get_roll_no() << std::endl;
		std::cout << "Age: " << studentUniquePtr->get_age() << std::endl;
		std::cout << "CGPA: " << studentUniquePtr->get_cgpa() << std::endl;
		std::cout << std::endl;
		std::cout << "Printing using the print_student_record function: " << std::endl;
		print_student_record(std::move(studentUniquePtr)); // have to use move because the unique pointer doesn't allow copy, it only allows move
														   // because of single ownership of the pointer. After moving, the ownership of the pointer is transfered to the function.
		// After this the pointer belongs to the function and cannot be used in main.
		// without using move you get compilation errors.
	}
	else
	{
		std::cout << "Student not found.\n";
	}

	return 0;
}
