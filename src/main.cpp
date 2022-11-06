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

    std::cout << Color::Cyan << wd.generic_string() << Color::Standard <<
                 std::endl << std::endl;

    std::cout << files.size() << " files, choosing number " <<
                 Color::GreenBold << index + 1 << Color::Standard <<
                 ":" << std::endl;
    std::cout << Color::GreenBold << files.at(index).filename().generic_string() << Color::Standard <<
                 std::endl << std::endl;

#ifdef _PDEBUG_
    for (int i = 0; i < files.size(); i++)
        std::cout << files.at(i).generic_string() << std::endl;
    std::cout << std::endl;
#endif
}

void open_file_at_index(fs::path wd, std::vector<fs::path> files, unsigned int index) {
    std::string filename = files.at(index).filename().generic_string();
    std::string cmd = "xdg-open \"" + filename + "\" &";
    system(cmd.c_str());
}


int main() {
    std::vector<fs::path> files = get_paths(fs::current_path());

    if (!files.size()) {
        std::cout << Color::Red << "No files found, exiting..." << Color::Standard << std::endl;
        return EXIT_SUCCESS;
    }

    int rand = URNG(0, files.size() - 1);

    print_info(fs::current_path(), files, rand);

    open_file_at_index(fs::current_path(), files, rand);

    std::cout << Color::Green << "You can now close this window" << Color::Standard << std::endl;

    return EXIT_SUCCESS;
}
