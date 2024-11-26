#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include "manager.h"
#include "core/owner.h"

class FileManager {
    public:
        static std::fstream ownersFile;

    public:
        static bool initializeFile();
        static void loadData();

        static void saveOwnerToFile(const Owner&);

        static void closeFile();
};