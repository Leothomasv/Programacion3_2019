#pragma once
#include <string>

class Person
{
public:
	std::string getId();
	void setId(std::string id);
	std::string getFirstName();
	void setFirstName(std::string str);
	std::string getLastName();
	void setLastName(std::string LastName);


	
private:
	std::string id;
	std::string FirstName;
	std::string LastName;
	unsigned int age;
	float weight;
	float height;


};