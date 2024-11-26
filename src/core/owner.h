#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
#include "person.h"

class Owner : public Person{
    private:
        int counter = 0;
        char *adr[5];

    public:
        Owner();
        Owner(std::string, std::string, std::string);
        Owner(const Person&);
        ~Owner();

        bool checkEstate(std::string) const;
        void addEstate(std::string);
        void removeEstate(int);

        void displayAllEstates() const;

        bool operator<(const Owner&) const;
        bool isEmpty() const;
        void empty();

        friend std::ostream& operator<<(std::ostream&, const Owner&);
        friend std::istream& operator>>(std::istream&, Owner&);
};
