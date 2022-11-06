#include "files.hpp"

#include "Colors/colors.hpp"
#include "URNG/URNG.hpp"

#include <iostream>

int main() {
    std::vector<fs::path> files = get_files_in_dir(fs::current_path());

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
