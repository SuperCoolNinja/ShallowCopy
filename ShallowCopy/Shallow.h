#pragma once
#include <iostream>
#include <string>


//Exemple of why it's a bad idea to use shallow copy using pointer :
class Shallow
{
public:
	Shallow(int data, std::string dt_name);
	Shallow(const Shallow& source, std::string dt_name);
	~Shallow();
	const int getShadowData();
	const std::string getShadowDataName();
	void setShadowData(int data);

private:
	int* ptr;
	std::string name;
};

