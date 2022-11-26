#include <iostream>
#include <random>

#include "../thirdparty/pcg_random.hpp"
#include "Colors/colors.hpp"
#include "files.hpp"

int main() {
    // idk how it works, but it repairs coloring in Windows cmd & PowerShell
#ifdef COLOR_TARGET_WINDOWS
    system("");
#endif

    std::vector<fs::path> files = get_files_in_dir(fs::current_path());

    if (!files.size()) {
        std::cout << Color::Red << "No files found, exiting..." << Color::Standard << std::endl;
        return EXIT_SUCCESS;
    }

    pcg32_fast rng(pcg_extras::seed_seq_from<std::random_device>{});

    // [0; files.size()]
    int rand = rng(files.size());

    print_info(fs::current_path(), files, rand);

    open_file_at_index(fs::current_path(), files, rand);

    std::cout << Color::Green << "You can now close this window" << Color::Standard << std::endl;

    return EXIT_SUCCESS;
}
