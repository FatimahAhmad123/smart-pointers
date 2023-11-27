#include <iostream>
#include <algorithm>
#include "database.hpp"

namespace rakurai::training
{

	Database::Database()
	{

		students.push_back(student("Fatimah", 22, 3.7, "A001"));
		students.push_back(student("Ahmad", 21, 3.5, "A002"));
		students.push_back(student("Bob", 23, 3.8, "A003"));
		students.push_back(student("John", 20, 3.6, "A004"));
		students.push_back(student("Ali", 22, 3.9, "A005"));
	}

	std::shared_ptr<student> Database::get_student_reference(const std::string student_name)
	{
		auto condition = [&student_name](const student &s)
		{
			return s.get_name() == student_name;
		};

		auto it = std::find_if(students.begin(), students.end(), condition);

		if (it != students.end())
		{
			std::cout << "The address of entry is: " << &(*it) << std::endl;
			return std::make_shared<student>(*it);
		}
		else
		{
			return nullptr;
		}
	}
}
