#pragma once

#include<iostream>
#include<string>
#include <array>
#include <cstdint>
#include <tuple>

class ipAdress
{
	using uint8_t = std::uint8_t;
public:
	ipAdress(std::string &&adr);
	ipAdress(const ipAdress &adr);
	ipAdress(ipAdress&& adr);

	ipAdress& operator =(ipAdress&& adr);
    bool operator ==(const ipAdress &data) const;
	bool operator >( ipAdress &data) const;
	bool operator<(const ipAdress& data) const;
	bool operator ()(ipAdress const& ab) const;

	int get_first();
	int get_second();
	int get_third();
	int get_fouth();
	
	void printAsdress();
	std::string get_string_adress();

private:

	std::string ip_adress;
	std::array<uint8_t,4> ip_adr;
};

