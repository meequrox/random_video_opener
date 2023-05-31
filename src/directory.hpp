#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include <filesystem>
#include <pcg_random.hpp>
#include <vector>

namespace mqr {
namespace fs = std::filesystem;

class directory {
   private:
    std::vector<fs::path> files;
    fs::path wd;

    pcg32_fast random_generator;
    size_t randomIndex;

   public:
    directory();

    void printInfo();
    void refresh();
    void openRandomFile();
};
}  // namespace mqr

#endif  // DIRECTORY_HPP
