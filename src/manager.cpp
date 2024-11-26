#include "manager.h"

std::set<Owner> Manager::storageAllOwners;

void Manager::addOwner(Owner owner){
    storageAllOwners.insert(owner);
}

void Manager::removeOwner(Owner owner){
    storageAllOwners.erase(owner);
}

void Manager::editOwner(std::string oldID, Owner newOwner){
    for(auto& owner : storageAllOwners){
        if(oldID == owner.getID()){
            removeOwner(owner);
            storageAllOwners.insert(newOwner);
            return;
        }
    }
}

void Manager::displayPersonByProperty(std::string property){
    int counter = 1;
    std::cout << "People on this address:\n";
    for(const auto& owner : storageAllOwners){
        if(owner.checkEstate(property)){
            std::cout << "\nPerson #" << counter << ":\nName: " << owner.getName();
            std::cout << "\nID: " << owner.getID()<< std::endl;
            counter++;
        }
    }
}

void Manager::displayPropertiesByID(std::string ID){
    std::cout << "\nEstates that the person with ID " << ID << " owns:\n";
    for(const auto& owner : storageAllOwners){
        if(owner.getID() == ID){
            owner.displayAllEstates();
        }
    }
}

void Manager::displayAllOwners(){
    for(const Owner& owner : storageAllOwners){
        std::cout << owner;
    }
}

void Manager::saveOwnersToFile(){
    for(const auto& owner : storageAllOwners){
        FileManager::saveOwnerToFile(owner);
    }
}