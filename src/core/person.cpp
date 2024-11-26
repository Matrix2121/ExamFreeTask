#include "person.h"

Person::Person(){}

Person::Person(std::string name, std::string ID){
    this->name = name;
    this->ID = ID;
}

Person::Person(std::string name, std::string ID, std::string address){
    this->name = name;
    this->ID = ID;
    this->address = address;
}

Person::~Person(){

}

void Person::setName(std::string name){
    this->name = name;
}

std::string Person::getName() const{
    return this->name;
}

void Person::setID(std::string ID){
    this->ID = ID;
}

std::string Person::getID() const{
    return this->ID;
}

void Person::setAddress(std::string address){
    this->address = address;
}

std::string Person::getAddress() const{
    return this->address;
}

std::ostream& operator<<(std::ostream& os, const Person& person){
    return os << "[" << person.name << ", " << person.ID << ", " << person.address  << "]";
}

std::istream& operator>>(std::istream& is, Person& person)
{
    char ch;
    std::string str;
    is >> ch;
    std::getline(is, person.name, ',');
    is.ignore(1);
    std::getline(is, person.ID, ',');
    is.ignore(1);
    std::getline(is, person.address, ']');
    return is;
}
