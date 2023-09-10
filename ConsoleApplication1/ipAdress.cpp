#include "ipAdress.h"

ipAdress::ipAdress(std::string adr)
{
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

 bool ipAdress::operator==( ipAdress &data) const
{
	if (first == data.first && second == data.second && third == data.third && fouth == data.fouth) {
		return true;
	}
	return false;
}

bool ipAdress::operator>( ipAdress &data) const
{
	if (first >= data.first) {
		if (second >= data.second) {
			if (third >= data.third) {
				if (fouth >= data.fouth) {
					return true;
				}
				return true;
			}
			return true;
		}
		return true;
	}
	return false;
}

bool ipAdress::operator<(const ipAdress &data) const
{
	if (first <= data.first) {
		if (second <= data.second) {
			if (third <= data.third) {
				if (fouth <= data.fouth) {
					return true;
				}
				return true;
			}
			return true;
		}
		return true;
	}
	return false;
}


bool ipAdress::operator ()(ipAdress const& ab) const {
	//if (a.alfa < b.alfa) return true;
	//if (a.alfa > b.alfa) return false;

	//if (a.x < b.x) return true;
	//if (a.x > b.x) return false;

	return false;
}

int ipAdress::get_first()
{
	return first;
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