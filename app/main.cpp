#include <iostream>
#include "student.h"

int main()
{
	student student;
	student.set_roll_no("12345");
	student.set_age(20);
	student.set_cgpa(3.8);

	student.set_subject_marks("English", 91);
	student.set_subject_marks("Urdu", 57);
	student.set_subject_marks("Math", 95);
	student.set_subject_marks("Physics", 87);

	student.print_all_marks();

	std::cout << "Roll No: " << student.get_roll_no() << std::endl;
	std::cout << "Age: " << student.get_age() << std::endl;
	std::cout << "CGPA: " << student.get_cgpa() << std::endl;

	return 0;
}
