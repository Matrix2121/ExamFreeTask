#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Person{
    protected:
        std::string name;
        std::string ID;
        std::string address;

    public:
        Person();
        Person(std::string, std::string);
        Person(std::string, std::string, std::string);
        ~Person();

        void setName(std::string);
        std::string getName() const;

        void setID(std::string);
        std::string getID() const;

        void setAddress(std::string);
        std::string getAddress() const;

        friend std::ostream& operator<<(std::ostream&, const Person&);
        friend std::istream& operator>>(std::istream&, Person&);
};