#include "openers/random_file_opener.hpp"

#include <algorithm>
#include <filesystem>
#include <iostream>
#include <random>

namespace rvo {
void RandomFileOpener::open(const std::vector<std::string>& files, bool verbose) {
    if (verbose) {
        std::cout << "Directory: " << std::filesystem::current_path().string() << '\n';
        std::cout << "Files: " << files.size() << '\n';
    }

    if (files.empty()) {
        std::cout << "Empty filelist" << std::endl;
        return;
    }

    using UIntD = std::uniform_int_distribution<size_t>;

    UIntD distribution(UIntD::param_type(0, files.size() - 1));
    std::random_device random_generator;
    const size_t index = distribution(random_generator);

    std::string cmd;
#if defined(_WIN32)
    cmd += "start .\\\"";
#elif defined(__APPLE__)
    cmd += "open \"";
#else
    cmd += "xdg-open \"";
#endif
    cmd += files[index] + "\" &";

    if (verbose) {
        std::cout << "Index: " << index << '\n';
        std::cout << "File: " << files[index] << std::endl;
    }

    system(cmd.c_str());  // NOLINT
}
}  // namespace rvo
