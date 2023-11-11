#ifndef RANDOM_VIDEO_OPENER_FILE_LIST_BUILDER_HPP
#define RANDOM_VIDEO_OPENER_FILE_LIST_BUILDER_HPP

#include <set>
#include <string>
#include <vector>

namespace rvo {
class FileListBuilder {
   public:
    std::vector<std::string> build(const std::set<std::string>& extensions);
};
}  // namespace rvo

#endif  // RANDOM_VIDEO_OPENER_FILE_LIST_BUILDER_HPP
