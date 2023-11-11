#include "builders/file_list_builder.hpp"

#include <algorithm>
#include <filesystem>

namespace rvo {
std::vector<std::string> FileListBuilder::build(const std::set<std::string>& extensions) {
    namespace fs = std::filesystem;

    std::vector<std::string> files;

    for (const auto& entry : fs::directory_iterator(fs::current_path())) {
        std::string ext = entry.path().extension();
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

        if (entry.is_regular_file() && extensions.find(ext) != extensions.end()) {
            files.push_back(entry.path().filename());
        }
    }

    return files;
}
}  // namespace rvo
