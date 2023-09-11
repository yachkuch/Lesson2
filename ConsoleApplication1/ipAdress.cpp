#include "ipAdress.h"

#include<vector>

ipAdress::ipAdress(std::string adr)
{
	ip_adress = adr;
	auto iter = adr.begin();
	int counter = 0;
	std::string buff;
	while (iter!=adr.end())
	{
		buff.append(1,*iter);
		if (*iter == '.') {
			if (counter == 0) {
				this->first = std::stoi(buff);
			}
			else if (counter == 1) {
				this->second = std::stoi(buff);
			}
			else if (counter == 2) {
				this->third = std::stoi(buff);
			}
			counter++;
			buff.clear();
		}
		iter++;
	}
	this->fouth = std::stoi(buff);
}

ipAdress::ipAdress(const ipAdress& adr)
{
	first = adr.first;
	second = adr.second;
	third = adr.third;
	fouth = adr.fouth;
	ip_adress = adr.ip_adress;
}

ipAdress::ipAdress(ipAdress&& adr)
{
	first = adr.first;
	second = adr.second;
	third = adr.third;
	fouth = adr.fouth;
	ip_adress = adr.ip_adress;
}

 bool ipAdress::operator==( ipAdress &data) const
{
	if (first == data.first && second == data.second && third == data.third && fouth == data.fouth) {
		return true;
	}
	return false;
}

bool ipAdress::operator>( ipAdress &data) const
{
	std::vector<int> firste;
	firste.push_back(first);
	firste.push_back(second);
	firste.push_back(third);
	firste.push_back(fouth);
	std::vector<int> seconde;
	seconde.push_back(data.first);
	seconde.push_back(data.second);
	seconde.push_back(data.third);
	seconde.push_back(data.fouth);
	return firste>seconde;
}

bool ipAdress::operator<(const ipAdress &data) const
{
	std::vector<int> firste;
	firste.push_back(first);
	firste.push_back(second);
	firste.push_back(third);
	firste.push_back(fouth);
	std::vector<int> seconde;
	seconde.push_back(data.first);
	seconde.push_back(data.second);
	seconde.push_back(data.third);
	seconde.push_back(data.fouth);
	return firste<seconde;
}

ipAdress& ipAdress::operator=(ipAdress&& adr)
{
	if (*this == adr) return *this;

	first = adr.first;
	second = adr.second;
	third = adr.third;
	fouth = adr.fouth;
	ip_adress = adr.ip_adress;
	return *this;
}


bool ipAdress::operator ()(ipAdress const& ab) const {
	return false;
}

int ipAdress::get_first()
{
	return first;
}

void ipAdress::printAsdress()
{
	std::cout << first << "." << second << "." << third << "" << fouth << std::endl;
}

int ipAdress::get_second()
{
	return second;
}

int ipAdress::get_third()
{
	return third;
}

int ipAdress::get_fouth()
{
	return fouth;
}
std::string ipAdress:: get_string_adress() {
	return ip_adress;
}