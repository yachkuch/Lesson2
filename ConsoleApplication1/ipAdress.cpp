#include "ipAdress.h"

#include<vector>

ipAdress::ipAdress(std::string && adr)
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
				this->ip_adr[0] = std::stoi(buff);
			}
			else if (counter == 1) {
				this->ip_adr[1] = std::stoi(buff);
			}
			else if (counter == 2) {
				this->ip_adr[2] = std::stoi(buff);
			}
			counter++;
			buff.clear();
		}
		iter++;
	}
	this->ip_adr[3] = std::stoi(buff);
}

ipAdress::ipAdress(const ipAdress& adr)
{
	this->ip_adr[0] = adr.ip_adr[0];
	this->ip_adr[1] = adr.ip_adr[1];
	this->ip_adr[2] = adr.ip_adr[2];
	this->ip_adr[3] = adr.ip_adr[3];
	ip_adress = adr.ip_adress;
}

ipAdress::ipAdress(ipAdress&& adr)
{
	this->ip_adr[0] = adr.ip_adr[0];
	this->ip_adr[1] = adr.ip_adr[1];
	this->ip_adr[2] = adr.ip_adr[2];
	this->ip_adr[3] = adr.ip_adr[3];
	ip_adress = adr.ip_adress;
}

 bool ipAdress::operator==(const ipAdress &data) const
{
	if (this->ip_adr[0] == data.ip_adr[0] && this->ip_adr[1] == data.ip_adr[1] && this->ip_adr[2] == data.ip_adr[2] &&
	 this->ip_adr[3] == data.ip_adr[3]) {
		return true;
	}
	return false;
}

bool ipAdress::operator>( ipAdress &data) const
{
	auto makeTie = [](const ipAdress& d) {
		return std::tie(d.ip_adr[0], d.ip_adr[1], d.ip_adr[2], d.ip_adr[3]);
	};
	return makeTie(*this) > makeTie(data);
}

bool ipAdress::operator<(const ipAdress &data) const
{
	auto makeTie = [](const ipAdress& d) {
		return std::tie(d.ip_adr[0], d.ip_adr[1], d.ip_adr[2], d.ip_adr[3]);
	};
	return makeTie(*this) < makeTie(data);
}

ipAdress& ipAdress::operator=(ipAdress&& adr)
{
	if (*this == adr) return *this;

	this->ip_adr[0] = adr.ip_adr[0];
	this->ip_adr[1] = adr.ip_adr[1];
	this->ip_adr[2] = adr.ip_adr[2];
	this->ip_adr[3] = adr.ip_adr[3];
	ip_adress = adr.ip_adress;
	return *this;
}


bool ipAdress::operator ()(const ipAdress & ab) const {
	return false;
}

int ipAdress::get_first()
{
	return this->ip_adr[0];
}

void ipAdress::printAsdress()
{
	std::cout << this->ip_adr[0] << "." << this->ip_adr[1] << "." << this->ip_adr[2] << "" << this->ip_adr[3] << std::endl;
}

int ipAdress::get_second()
{
	return this->ip_adr[1];
}

int ipAdress::get_third()
{
	return this->ip_adr[2];
}

int ipAdress::get_fouth()
{
	return this->ip_adr[3];
}
std::string ipAdress:: get_string_adress() {
	return ip_adress;
}