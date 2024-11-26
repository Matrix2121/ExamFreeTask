#include "fileManager.h"

std::fstream FileManager::ownersFile;

bool FileManager::initializeFile() {
    if (!std::filesystem::exists("data/owners.txt")) {
        ownersFile.open("data/owners.txt", std::ios::out);
        ownersFile.close();
    }
    ownersFile.open("data/owners.txt", std::ios::in);
    if (!ownersFile.is_open()) {
        std::cerr << "Error opening owners.txt" << std::endl;
        return false;
    }

    std::cout << "File initialized successfully." << std::endl;
    return true;
}

void FileManager::loadData() {
    Owner owner;

    ownersFile.clear();
    ownersFile.seekg(0);

    if (std::filesystem::file_size("data/owners.txt") > 0) {
        while (ownersFile >> owner) {
            if (ownersFile.eof()) {
                break;
            }

            if (!owner.isEmpty()) {
                Manager::addOwner(owner);
            } else {
                std::cout << "Empty owner encountered!" << std::endl;
                break;
            }
            owner.empty();
        }
    } else {
        std::cout << "owner.txt is empty." << std::endl;
    }
    ownersFile.close();
}

void FileManager::saveOwnerToFile(const Owner& owner){
    ownersFile << owner;
}

void FileManager::closeFile() {
    ownersFile.open("data/owners.txt", std::ios::out | std::ios::trunc);
    Manager::saveOwnersToFile();
    ownersFile.close();
}
