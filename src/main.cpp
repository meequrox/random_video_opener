#include "Colors/colors.hpp"
#include "URNG/URNG.hpp"

#include <vector>
#include <filesystem>
#include <iostream>
#include <bits/stdc++.h>

#define _PDEBUG_

namespace fs = std::filesystem;

std::vector<fs::path> get_paths(fs::path wd) {
    std::vector<fs::path> files;

    for (const auto &entry : fs::directory_iterator(wd)) {
        // TODO: Format check
        if (entry.is_regular_file())
            files.push_back(entry);
    }

    std::sort(files.begin(), files.end());

    return files;
}

void print_info(fs::path wd, std::vector<fs::path> files, unsigned int index) {
    /*
    /home/user/Downloads

    4 files, choosing number 1:
    1.mp3
    */

    int fname_begin = files.at(index).generic_string().find_last_of('/') + 1;

    std::cout << wd.generic_string() << std::endl << std::endl;

    std::cout << files.size() << " files, choosing number " << index + 1 << ":" << std::endl;
    std::cout << files.at(index).generic_string().substr(fname_begin) << std::endl << std::endl;

#ifdef _PDEBUG_
    for (int i = 0; i < files.size(); i++)
        std::cout << files.at(i).generic_string() << std::endl;
#endif
}


int main() {
    std::vector<fs::path> files = get_paths(fs::current_path());

    if (!files.size()) {
        std::cout << Color::Red << "No files found, exiting..." << Color::Reset << std::endl;
        return EXIT_SUCCESS;
    }

    int rand = URNG(0, files.size());

    // Change 0 to random index
    print_info(fs::current_path(), files, rand);

    return EXIT_SUCCESS;
}
