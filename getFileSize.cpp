#include <fstream>
#include <iostream>
#include <filesystem>

long long getFileSize(const char* fileName){
    std::filesystem::path pathToFile(fileName);
    if (std::filesystem::exists(pathToFile)) {
        return std::filesystem::file_size(pathToFile);
    }
    else {
        std::cerr << "File not found." << std::endl;
        return -1;
    }
}

