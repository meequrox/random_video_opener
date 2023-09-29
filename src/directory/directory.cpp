#include <algorithm>
#include <directory/directory.hpp>
#include <iostream>

directory::directory() : workingDirectory(fs::current_path()), randomGenerator(), distribution(0, 1) {
    refreshInfo();
}

static bool isCompatibleExtension(std::vector<std::string>& exts, fs::path file) {
    std::string file_ext = file.extension().generic_string();
    std::transform(file_ext.begin(), file_ext.end(), file_ext.begin(), ::tolower);

    return std::find(exts.begin(), exts.end(), file_ext) != exts.end();
}

void directory::refreshInfo() {
    videoFiles.clear();

    std::vector<std::string> extensions = {".mp4",  ".mkv", ".webm", ".flv", ".avi", ".mts", ".mpg",
                                           ".m2ts", ".ts",  ".mov",  ".wmv", ".m4v", ".3gp", ".mpeg"};

    for (const auto& entry : fs::directory_iterator(workingDirectory)) {
        if (entry.is_regular_file() && isCompatibleExtension(extensions, entry.path())) {
            videoFiles.push_back(entry);
        }
    }

    distribution.reset();
    distribution.param(std::uniform_int_distribution<int>::param_type(0, videoFiles.size() - 1));
    randomIndex = videoFiles.empty() ? -1 : distribution(randomGenerator);
}

void directory::printInfo() {
    if (!videoFiles.empty()) {
        std::cout << "Found " << videoFiles.size() << " video files in " << workingDirectory
                  << std::endl;

        std::cout << "Choosing file " << videoFiles.at(randomIndex).filename() << std::endl;
    } else {
        std::cout << "No video found in " << workingDirectory << std::endl;
    }
}

void directory::openRandomFile() {
    if (videoFiles.empty()) return;

#ifdef _WIN32
    std::string cmd = "start .\\\"";
#else
    std::string cmd = "xdg-open \"";
#endif

    std::string filename = videoFiles.at(randomIndex).filename();

    cmd += filename + "\" &";
    system(cmd.c_str());
}
