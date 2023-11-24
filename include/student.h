#include <iostream>
#include <string>
#include <map>

class student
{
private:
	struct student_record
	{
		std::string roll_no;
		int age;
		float cgpa;
	};

	std::map<std::string, int> result;
	student_record data;

public:
	student();	// Constructor
	~student(); // Destructor

	void set_roll_no(std::string roll);
	std::string get_roll_no() const;
	void set_age(int age);
	int get_age() const;
	void set_cgpa(float cgpa);
	float get_cgpa() const;

	void set_subject_marks(std::string subject, int marks);
	int get_subject_marks(std::string subject);
	void print_all_marks();
};