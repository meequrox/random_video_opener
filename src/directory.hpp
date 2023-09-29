#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include <filesystem>
#include <random>
#include <vector>

namespace fs = std::filesystem;

class directory {
   private:
    std::vector<fs::path> videoFiles;
    fs::path workingDirectory;

    std::random_device randomGenerator;
    std::uniform_int_distribution<int> distribution;
    int32_t randomIndex;

   public:
    directory();

    void refreshInfo();
    void printInfo();
    void openRandomFile();
};

#endif  // DIRECTORY_HPP
