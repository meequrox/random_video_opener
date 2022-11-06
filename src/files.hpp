#ifndef FILES_HPP
#define FILES_HPP

#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

std::vector<fs::path> get_files_in_dir(fs::path wd);
void open_file_at_index(fs::path wd, std::vector<fs::path> files, unsigned int index);
void print_info(fs::path wd, std::vector<fs::path> files, unsigned int index);

#endif // FILES_HPP
