#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include <filesystem>
#include <pcg_random.hpp>
#include <vector>

namespace fs = std::filesystem;

class directory {
   private:
    std::vector<fs::path> videoFiles;
    fs::path workingDirectory;

    pcg32_fast randomGenerator;
    size_t randomIndex;

   public:
    directory();

    void refreshInfo();
    void printInfo();
    void openRandomFile();
};

#endif  // DIRECTORY_HPP
