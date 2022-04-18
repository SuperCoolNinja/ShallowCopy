#include "Shallow.h"

//Create ptr into heap then copy data to ptr :
Shallow::Shallow(int data, std::string name)
{
	this->ptr = new int;
	*this->ptr = data;
	this->name = name;

	std::cerr << "\nNew obj has been created with name :" << this->name << "\n";
}

//In this case only the pointer will be copied not what is pointing to :
Shallow::Shallow(const Shallow& source, std::string dt_name) :ptr(source.ptr), name{ dt_name }
{
	std::cerr << "\nCopy constructor has been made\n";
}

//This is used each time we exit a scope it will free the memory so this causing dangling memory the second time it will be called :
Shallow::~Shallow()
{
	delete ptr; //free storage.
	ptr = nullptr;
	std::cerr << "\nDestructor has free ptr of obj : " << this->name << std::endl;
}

const int Shallow::getShadowData()
{
	return *this->ptr;
}

const std::string Shallow::getShadowDataName()
{
	return this->name;
}

//This is used to set the new data to the ptr :
void Shallow::setShadowData(int data)
{
	*this->ptr = data;
	std::cerr << "\nNew data set for " << this->name << " with value " << *this->ptr;
}

