#include "owner.h"

Owner::Owner(){}

Owner::Owner(std::string name, std::string ID, std::string address) : Person(name, ID){
    for(int i = 0; i < 5; i++){
        this->adr[i] = nullptr;
    }
    Owner::addEstate(address);
}

Owner::Owner(const Person& person) : Person(person) {
    for(int i = 0; i < 5; i++){
        this->adr[i] = nullptr;
    }
    Owner::addEstate(person.getAddress());
}

Owner::~Owner(){
    for(int i = 0; i < counter; i++){
        delete[] this->adr[counter];
    }
}

bool Owner::checkEstate(std::string property) const{
    for(int i = 0; i < counter; i++){
        if(adr[i] == property){
            return true;
        }
    }
    return false;
}

void Owner::addEstate(std::string property){
    if (counter < 5) {
        this->adr[counter] = new char[property.length() + 1];
        strcpy(this->adr[counter], property.c_str());
        counter++;
    }
}

void Owner::removeEstate(int index){
    if(index < 0 || index >= counter){
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    delete[] adr[index];

    for (int i = index; i < counter - 1; i++) {
        this->adr[i] = this->adr[i + 1];
    }

    this->adr[counter - 1] = nullptr;
    counter--;

}

void Owner::displayAllEstates() const{
    std::cout << "{";
    for(int i = 0; i < counter; i++){
        if(i == counter - 1){
            std::cout << adr[i] << "}";
        } else {
            std::cout << adr[i] << ", ";
        }
    }
}

bool Owner::operator<(const Owner& owner) const {
    return this->ID < owner.ID;
}

bool Owner::isEmpty() const
{
    return name == "" && ID == "" && address == "";
}

void Owner::empty(){
    name = "";
    ID = "";
    counter = 0;
}

std::ostream& operator<<(std::ostream& os, const Owner& owner)
{   
    os << "[" << owner.getName() << ", " << owner.getID() << ", " << owner.counter << "{";
    for(int i = 0; i < owner.counter; i++){
        if(i == owner.counter - 1){
            os << owner.adr[i] << "}";
            return os << "]";
        } else {
            os << owner.adr[i] << ", ";
        }
    }
    return os << "}]";
}

std::istream& operator>>(std::istream& is, Owner& owner)
{
    if(is.peek() != '['){
        return is;
    }

    char ch;
    std::string input;

    is >> ch;
    std::getline(is, input, ',');
    owner.setName(input);
    is.ignore(1);

    std::getline(is, input, ',');
    owner.setID(input);
    is.ignore(1);

    std::getline(is, input, '{');
    int p = stoi(input);

    for(int i = 0; i < p; i++){
        if(i == p - 1){
            std::getline(is, input, '}');
        } else {
            std::getline(is, input, ',');
            is.ignore(1);
        }
        owner.addEstate(input);
    }
    is.ignore(1);
    return is;
}
