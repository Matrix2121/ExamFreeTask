#pragma once
#include <set>
#include "fileManager.h"
#include "core/owner.h"

class Manager {
    private:
        static std::set<Owner> storageAllOwners;
    
    public:
        static void addOwner(Owner);
        static void removeOwner(Owner);
        static void editOwner(std::string, Owner);

        static void displayAllOwners();

        static void displayPersonByProperty(std::string);
        static void displayPropertiesByID(std::string);

        static void saveOwnersToFile();
};