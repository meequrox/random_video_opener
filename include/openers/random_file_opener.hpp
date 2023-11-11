#ifndef RANDOM_VIDEO_OPENER_RANDOM_FILE_OPENER_HPP
#define RANDOM_VIDEO_OPENER_RANDOM_FILE_OPENER_HPP

#include <string>
#include <vector>

namespace rvo {
class RandomFileOpener {
   public:
    void open(const std::vector<std::string>& files, bool verbose = false);
};
}  // namespace rvo

#endif  // RANDOM_VIDEO_OPENER_RANDOM_FILE_OPENER_HPP
