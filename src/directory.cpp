#include "directory.hpp"

#include <bits/stdc++.h>

#include <iostream>

#include "../thirdparty/pcg_random.hpp"
#include "Colors/colors.hpp"

namespace mqr {
directory::directory() : wd(fs::current_path()) {
    refreshFiles();
    refreshIndex();
}

directory::directory(const fs::path dir) {
    wd = fs::exists(dir) ? dir : fs::current_path();
    refreshFiles();
    refreshIndex();
}

constexpr int SUPPORTED_VIDEO_FORMATS_COUNT = 12;

static bool isCompatibleExtension(std::array<std::string, SUPPORTED_VIDEO_FORMATS_COUNT>& exts,
                                  fs::path file) {
    std::string file_ext = file.extension().generic_string();
    std::transform(file_ext.begin(), file_ext.end(), file_ext.begin(), ::tolower);

    if (std::find(exts.begin(), exts.end(), file_ext) != exts.end()) {
#if _PDEBUG_ == 1
        std::cout << Color::Green << "VIDEO: " << Color::Standard << file.filename().generic_string()
                  << std::endl;
#endif

        return true;
    }

#if _PDEBUG_ == 1
    std::cout << Color::Red << "NOT VIDEO: " << Color::Standard << file.filename().generic_string()
              << std::endl;
#endif

    return false;
}

void directory::refreshFiles() {
    if (!files.empty()) files.clear();

    std::array<std::string, SUPPORTED_VIDEO_FORMATS_COUNT> extensions = {
        ".mp4", ".mkv", ".webm", ".flv", ".avi", ".mts", ".m2ts", ".ts", ".mov", ".wmv", ".m4v", ".3gp"};

    for (const fs::directory_entry& entry : fs::directory_iterator(wd)) {
        if (entry.is_regular_file() && isCompatibleExtension(extensions, entry.path()))
            files.push_front(entry);
    }

    std::sort(files.begin(), files.end());

#if _PDEBUG_ == 1
    std::cout << std::endl;
#endif
}

void directory::refreshIndex() {
    pcg32_fast rng(pcg_extras::seed_seq_from<std::random_device>{});

    randomIndex = files.size() ? rng(files.size()) : 0;
}

void directory::printInfo() {
    /*
    /home/user/Downloads

    4 files, choosing number 1:
    Hello.mp4
    */

#ifdef COLOR_TARGET_WINDOWS
    // fix coloring in Windows cmd & PowerShell
    system("");
#endif

    if (!files.empty()) {
        std::cout << wd.generic_string() << ": " << files.size() << " video files." << std::endl << std::endl;

        std::cout << "Choosing number " << randomIndex + 1 << ": ";
        std::cout << Color::GreenBold << files.at(randomIndex).filename().generic_string()
                  << Color::Standard << std::endl
                  << std::endl;
    } else {
        std::cout << "No files found." << std::endl;
        return;
    }

#if _PDEBUG_ == 1
    for (const fs::path& file : files) std::cout << file.filename().generic_string() << std::endl;
    std::cout << std::endl;
#endif
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

    std::cout << "Now you can close the terminal." << std::endl;
}
}  // namespace mqr
