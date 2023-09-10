#pragma once

#include<iostream>
#include<string>

class ipAdress
{
public:
	ipAdress(std::string adr);

    bool operator ==( ipAdress &data) const;
	bool operator >( ipAdress &data) const;
	bool operator<(const ipAdress& data) const;
	bool operator ()(ipAdress const& ab) const;

	int get_first();
	int get_second();
	int get_third();
	int get_fouth();

private:
	int first = 0;
	int second = 0;
	int third = 0;
	int fouth = 0;
};

