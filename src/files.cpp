#include "files.hpp"
#include "Colors/colors.hpp"

#include <bits/stdc++.h> // std::sort

static bool is_compatible_format(std::vector<std::string> exts, fs::path path) {
    for (const auto &e : exts) {
        std::string file_ext = path.extension().generic_string();
        std::transform(file_ext.begin(), file_ext.end(), file_ext.begin(), ::tolower);
        if (file_ext == e) {
#if _PDEBUG_ == 1
            std::cout << Color::Green << "VIDEO: " << Color::Standard <<
                         path.filename().generic_string() << std::endl;
#endif
            return true;
        }
    }

#if _PDEBUG_ == 1
            std::cout << Color::Red << "NOT VIDEO: " << Color::Standard <<
                         path.filename().generic_string() << std::endl;
#endif

    return false;
}

std::vector<fs::path> get_files_in_dir(fs::path wd) {
    std::vector<std::string> video_exts({".webm", ".mkv", ".flv", ".avi",
                                         ".mts", ".m2ts", ".ts", ".mov",
                                         ".wmv", ".mp4", ".m4v", ".3gp"});

    std::vector<fs::path> files;

    for (const auto &entry : fs::directory_iterator(wd)) {
        if (entry.is_regular_file() && is_compatible_format(video_exts, entry))
            files.push_back(entry);
    }

    std::sort(files.begin(), files.end());

    return files;
}

void open_file_at_index(fs::path wd, std::vector<fs::path> files, unsigned int index) {
    std::string filename = files.at(index).filename().generic_string();
    std::string cmd = "xdg-open \"" + filename + "\" &";
    system(cmd.c_str());
}

void print_info(fs::path wd, std::vector<fs::path> files, unsigned int index) {
    /*
    /home/user/Downloads

    4 files, choosing number 1:
    1.mp4
    */

#if _PDEBUG_ == 1
    std::cout << std::endl;
#endif

    std::cout << Color::Cyan << wd.generic_string() << Color::Standard <<
                 std::endl << std::endl;

    std::cout << files.size() << " files, choosing number " <<
                 Color::GreenBold << index + 1 << Color::Standard <<
                 ":" << std::endl;
    std::cout << Color::GreenBold << files.at(index).filename().generic_string() << Color::Standard <<
                 std::endl << std::endl;

#if _PDEBUG_ == 1
    for (int i = 0; i < files.size(); i++)
        std::cout << files.at(i).filename().generic_string() << std::endl;
    std::cout << std::endl;
#endif
}
