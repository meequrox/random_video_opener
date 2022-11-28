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
    wd = (fs::exists(dir)) ? dir : fs::current_path();
    refreshFiles();
    refreshIndex();
}

void directory::refreshFiles() {
    if (!files.empty()) files.clear();

    for (const fs::directory_entry& entry : fs::directory_iterator(wd)) {
        if (entry.is_regular_file()) files.push_front(entry);
    }

    std::sort(files.begin(), files.end());
}

void directory::refreshIndex() {
    pcg32_fast rng(pcg_extras::seed_seq_from<std::random_device>{});

    randomIndex = rng(files.size());
}

void directory::printInfo() {
    /*
    /home/user/Downloads

    4 files, choosing number 1:
    Hello.mp4
    */

#if _PDEBUG_ == 1
    std::cout << std::endl;
#endif

#ifdef COLOR_TARGET_WINDOWS
    // fix coloring in Windows cmd & PowerShell
    system("");
#endif

    std::cout << Color::Cyan << wd.generic_string() << Color::Standard << std::endl << std::endl;

    if (!files.empty()) {
        std::cout << files.size() << " files, choosing number " << Color::GreenBold << randomIndex + 1
                  << Color::Standard << ":" << std::endl;
        std::cout << Color::GreenBold << files.at(randomIndex).filename().generic_string()
                  << Color::Standard << std::endl
                  << std::endl;
    } else {
        std::cout << Color::Red << "No files found." << Color::Standard << std::endl;
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
    // fix coloring in Windows cmd & PowerShell
    system("");

    std::string cmd = "start .\\\"";
#else
    std::string cmd = "xdg-open \"";
#endif
    cmd += filename + "\" &";
    system(cmd.c_str());

    std::cout << Color::Green << "Now you can close the terminal." << Color::Standard << std::endl;
}
}  // namespace mqr
