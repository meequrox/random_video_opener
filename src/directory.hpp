#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include <filesystem>
#include <vector>

#include "../thirdparty/pcg_random.hpp"

namespace mqr {
namespace fs = std::filesystem;

class directory {
   private:
    std::vector<fs::path> files;
    fs::path wd;

    pcg32_fast random_generator;
    size_t randomIndex;

   public:
    directory(const fs::path dir);
    directory();

    void openRandomFile();

    void printInfo();

    void refresh();
};
}  // namespace mqr

#endif  // DIRECTORY_HPP
