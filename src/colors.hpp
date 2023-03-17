#ifndef __COLORS_HPP__
#define __COLORS_HPP__

#include <ostream>

#if defined(_WIN32) || defined(_WIN64)
#define COLOR_TARGET_WINDOWS
#endif

namespace Color {
constexpr std::string_view Black = "\e[0;30m";
constexpr std::string_view Darkgrey = "\e[01;30m";

constexpr std::string_view Red = "\e[0;31m";
constexpr std::string_view RedBold = "\e[01;31m";

constexpr std::string_view Green = "\e[0;32m";
constexpr std::string_view GreenBold = "\e[01;32m";

constexpr std::string_view Yellow = "\e[0;33m";
constexpr std::string_view YellowBold = "\e[01;33m";

constexpr std::string_view Blue = "\e[0;34m";
constexpr std::string_view BlueBold = "\e[01;34m";

#ifdef COLOR_TARGET_WINDOWS
constexpr std::string_view Magenta = "\e[01;35m";
#else
constexpr std::string_view Magenta = "\e[0;35m";
#endif

constexpr std::string_view MagentaBold = "\e[01;35m";

constexpr std::string_view Cyan = "\e[0;36m";
constexpr std::string_view CyanBold = "\e[01;36m";

constexpr std::string_view Grey = "\e[0;37m";
constexpr std::string_view White = "\e[01;37m";

constexpr std::string_view Standard = "\e[0m";
constexpr std::string_view Normal = Standard;
constexpr std::string_view Reset = Standard;
}  // namespace Color

#endif  // __COLORS_HPP__
