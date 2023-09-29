# RandomVideoOpener

__A simple program that opens a random video from the current directory.__

[List of video formats](src/directory/directory.cpp#L17)

## Build

- GNU/Linux
- *BSD
- Windows with [CMake](https://community.chocolatey.org/packages/cmake), [Ninja](https://community.chocolatey.org/packages/ninja) and [MinGW](https://community.chocolatey.org/packages/mingw)
- Possibly macOS

```bash
git clone https://github.com/meequrox/RandomVideoOpener.git

cd RandomVideoOpener

cmake --preset=release

cmake --build --preset=release
```

The compiled files will be located in the `build/bin` directory.

## Usage

```bash
user@onhost:~/Videos$ ./RandomVideoOpener
Found 140 video files in "/home/user/Videos"
Choosing file "Funny cat.mp4"
```
