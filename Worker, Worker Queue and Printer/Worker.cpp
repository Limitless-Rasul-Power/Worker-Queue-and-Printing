#include <iostream>
#include <assert.h>
#include "Worker.h"

Worker::Worker():w_id(0), name(""), surname(""), age(0), page_count(0)
{}

Worker& Worker::operator = (const Worker& other)
{
	Set_name(other.name);
	Set_surname(other.surname);
	Set_age(other.age);
	Set_page_count(other.page_count);
	Equal_id(other.w_id);

	return *this;
}

inline Worker::Worker(const std::string& name)
{
	Set_name(name);
}

Worker::Worker(const std::string& name, const std::string& surname)
	:Worker(name)
{
	Set_surname(surname);
}

Worker::Worker(const std::string& name, const std::string& surname, const short& age)
	:Worker(name, surname)
{
	Set_age(age);
}

Worker::Worker(const std::string& name, const std::string& surname, const short& age, const short& page_count)
	:Worker(name, surname, age)
{
	Set_page_count(page_count);
	Set_id();
}

void Worker::Set_name(const std::string& name)
{
	assert(name.empty() == false && "Name is Empty!");
	this->name = name;
}

std::string Worker::Get_name() const
{
	return name;
}

void Worker::Set_surname(const std::string& surname)
{
	assert(surname.empty() == false && "Name is Empty!");
	this->surname = surname;
}

std::string Worker::Get_surname() const
{
	return surname;
}

void Worker::Set_age(const short& age)
{
	assert(age > 17 && "We don't have this age Worker!");
	this->age = age;
}

unsigned short Worker::Get_age() const
{
	return age;
}

void Worker::Set_page_count(const short& page_count)
{
	assert(page_count > 0 && "Page count is 0!");
	this->page_count = page_count;
}

unsigned short Worker::Get_page_count() const
{
	return page_count;
}

void Worker::Set_id()
{
	this->w_id = ++id;
}

void Worker::Equal_id(const short& id)
{
	assert(id > 0 && "ID is 0!");
	this->w_id = id;
}

unsigned short Worker::Get_id() const
{
	return w_id;
}

short Worker::Get_current_id() const
{
	return id;
}

void Worker::Show() const
{
	std::cout << "Worker ID: " << Get_id() << '\n';
	std::cout << "Worker Name: " << Get_name() << '\n';
	std::cout << "Worker Surname: " << Get_surname() << '\n';
	std::cout << "Worker Age: " << Get_age() << '\n';
	std::cout << "Worker Page Count: " << Get_page_count() << "\n\n";
}