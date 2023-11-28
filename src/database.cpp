#include <iostream>
#include <memory>
#include "database.hpp"

namespace rakurai::training
{

	Database::Database()
	{

		students.push_back(student("Fatimah", 22, 3.9, "A001"));
		students.push_back(student("Ahmad", 21, 3.5, "A002"));
		students.push_back(student("Bob", 23, 3.8, "A003"));
		students.push_back(student("John", 20, 3.6, "A004"));
		students.push_back(student("Ali", 22, 3.4, "A005"));
	}

	std::shared_ptr<student> Database::get_student_reference(const std::string student_name)
	{
		for (auto it = students.begin(); it != students.end(); ++it) // auto used to automatically deduce type of var by compiler
		{
			const student &s = *it; // binds the student object to the value iterator is pointing to, const so value of it is not changed by s
			if (s.get_name() == student_name)
			{
				try
				{
					std::cout << "The address of entry is: " << &s << std::endl;
					return std::make_shared<student>(s); // make_shared creates a dynamically allocated copy of s object (on the heap)
														 // return statement returns this pointer
				}
				catch (const std::bad_alloc)
				{
					std::cout << "Error: Memory allocation failed." << std::endl;
					return nullptr;
				}
			}
		}

		return nullptr;
	}

	std::unique_ptr<student> Database::get_student_unique(const std::string student_name)
	{
		for (auto it = students.begin(); it != students.end(); ++it)
		{
			const student &s = *it;
			if (s.get_name() == student_name)
			{
				try
				{
					std::cout << "The address of entry is: " << &s << std::endl;
					return std::make_unique<student>(s);
				}
				catch (const std::bad_alloc)
				{
					std::cout << "Error: Memory allocation failed." << std::endl;
					return nullptr;
				}
			}
		}

		return nullptr;
	}
}
