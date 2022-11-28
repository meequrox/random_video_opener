#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include <deque>
#include <filesystem>

namespace mqr {
namespace fs = std::filesystem;

class directory {
   private:
    std::deque<fs::path> files;
    fs::path wd;
    size_t randomIndex;

   public:
    directory(const fs::path dir);
    directory();

    void openRandomFile();

    void printInfo();

    void refreshFiles();
    void refreshIndex();
};
}  // namespace mqr

#endif  // DIRECTORY_HPP
