#include "directory.hpp"

#include <algorithm>
#include <iostream>
#include <random>

#include "colors.hpp"

namespace mqr {
directory::directory()
    : wd(fs::current_path()), random_generator(pcg_extras::seed_seq_from<std::random_device>{}) {
    refresh();
}

inline static bool isCompatibleExtension(std::vector<std::string>& exts, fs::path file) {
    std::string file_ext = file.extension().generic_string();
    std::transform(file_ext.begin(), file_ext.end(), file_ext.begin(), ::tolower);

    return std::find(exts.begin(), exts.end(), file_ext) != exts.end();
}

void directory::refresh() {
    if (!files.empty()) files.clear();

    std::vector<std::string> extensions = {".mp4",  ".mkv", ".webm", ".flv", ".avi", ".mts",
                                           ".m2ts", ".ts",  ".mov",  ".wmv", ".m4v", ".3gp"};

    for (const fs::directory_entry& entry : fs::directory_iterator(wd)) {
        if (entry.is_regular_file() && isCompatibleExtension(extensions, entry.path())) {
            files.push_back(entry);

#if _PDEBUG_ == 1
            std::cout << Color::Green << "VIDEO: " << Color::Standard << entry.path() << std::endl;
#endif
        } else {
#if _PDEBUG_ == 1
            std::cout << Color::Red << "NOT VIDEO: " << Color::Standard << entry.path() << std::endl;
#endif
        }
    }

    std::shuffle(files.begin(), files.end(), random_generator);
    randomIndex = files.size() ? random_generator(files.size()) : 0;
}

void directory::printInfo() {
#ifdef COLOR_TARGET_WINDOWS
    // Fix colors in Windows cmd & PowerShell
    system("");
#endif

    if (!files.empty()) {
        std::cout << wd.generic_string() << ": " << files.size() << " video files." << std::endl;

        std::cout << "Choosing file " << Color::GreenBold
                  << files.at(randomIndex).filename().generic_string() << Color::Standard << std::endl;
    } else {
        std::cout << "No files found in " << wd.generic_string() << std::endl;
        return;
    }
}

void directory::openRandomFile() {
    if (files.empty()) return;

    std::string filename = files.at(randomIndex).filename().generic_string();

#ifdef COLOR_TARGET_WINDOWS
    std::string cmd = "start .\\\"";
#else
    std::string cmd = "xdg-open \"";
#endif

    cmd += filename + "\" &";
    system(cmd.c_str());
}
}  // namespace mqr
