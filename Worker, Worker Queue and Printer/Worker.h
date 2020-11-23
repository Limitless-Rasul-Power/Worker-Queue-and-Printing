#pragma once
#include <string>
class Worker
{

private:
	unsigned short w_id;
	std::string name;
	std::string surname;
	unsigned short age;
	unsigned short page_count;

public:

	static short id;

	Worker();

	Worker& operator = (const Worker& other);

	explicit inline Worker(const std::string& name);

	Worker(const std::string& name, const std::string& surname);

	Worker(const std::string& name, const std::string& surname, const short& age);

	Worker(const std::string& name, const std::string& surname, const short& age, const short& page_count);

	void Set_name(const std::string& name);
	std::string Get_name() const;

	void Set_surname(const std::string& surname);
	std::string Get_surname() const;

	void Set_age(const short& age);
	unsigned short Get_age() const;

	void Set_page_count(const short& page_count);
	unsigned short Get_page_count() const;

	void Set_id();
	void Equal_id(const short& id);

	unsigned short Get_id() const;
	short Get_current_id() const;

	void Show() const;
};