#ifndef RAKURAI_TRAINING_DATABASE_H
#define RAKURAI_TRAINING_DATABASE_H

#include <vector>
#include <memory>
#include "student.hpp"

namespace rakurai::training
{

	class Database
	{
	private:
		std::vector<student> students;

	public:
		Database();
		std::shared_ptr<student> get_student_reference(const std::string studentName);
	};

}

#endif