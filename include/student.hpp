#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include <map>

namespace rakurai::training
{
	class student
	{
	private:
		struct student_record
		{
			std::string name;
			std::string roll_no;
			int age;
			float cgpa;
		};

		std::map<std::string, int> result;
		student_record data;

	public:
		student(const std::string &name, int age, float cgpa, const std::string &roll_no);

		void set_name(std::string roll);
		std::string get_name() const;
		void set_roll_no(std::string roll);
		std::string get_roll_no() const;
		void set_age(int age);
		int get_age() const;
		void set_cgpa(float cgpa);
		float get_cgpa() const;
	};
}
#endif