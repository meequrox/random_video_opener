# RandomVideoOpener

__A simple program that opens a random video in the current directory__

[List of supported formats](src/directory.cpp#L23)

_GNU/Linux and Windows are currently supported_

## Build

GNU/Linux:

```bash
git clone https://github.com/meequrox/RandomVideoOpener.git

cd RandomVideoOpener

mkdir build && cd build

cmake .. -DCMAKE_BUILD_TYPE="Release"

make
```

Windows (with [MinGW](http://www.equation.com/servlet/equation.cmd?fa=fortran) and [CMake](https://cmake.org/download/#latest) installed):

```bash
git clone https://github.com/meequrox/RandomVideoOpener.git

cd RandomVideoOpener

mkdir build && cd build

cmake .. -DCMAKE_BUILD_TYPE="Release" -D"CMAKE_CXX_COMPILER=g++" -G "MinGW Makefiles" -D"CMAKE_MAKE_PROGRAM=make"

make
```

## Usage

```bash
user@onhost:~/Vids$ RandomVideoOpener

Found 16 video files in "/home/user/Vids"

Choosing file "07. Iterators.mp4"
```
