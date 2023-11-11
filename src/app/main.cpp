#include "builders/file_list_builder.hpp"
#include "openers/random_file_opener.hpp"

int main() {
    rvo::FileListBuilder builder;
    rvo::RandomFileOpener opener;

    const std::set<std::string> extensions = {".mp4",  ".mkv", ".webm", ".flv", ".avi", ".mts", ".mpg",
                                              ".m2ts", ".ts",  ".mov",  ".wmv", ".m4v", ".3gp", ".mpeg"};

    const auto files = builder.build(extensions);
    opener.open(files, true);

    return 0;
}
