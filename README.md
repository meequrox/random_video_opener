# Random Video Opener

**A simple program that opens a random video from the current directory.**
Uniform distribution is used.

[List of video formats](src/app/main.cpp#L8-L9)

## Build

- GNU/Linux, *BSD and other *nix
- macOS
- Windows with [CMake](https://community.chocolatey.org/packages/cmake), [Ninja](https://community.chocolatey.org/packages/ninja) and [MinGW](https://community.chocolatey.org/packages/mingw)

```bash
git clone https://github.com/meequrox/random_video_opener.git

cd random_video_opener

cmake --preset=release

cmake --build --preset=release
```

The compiled files will be located in the `build/bin` Directory.

## Usage

```bash
user@onhost:~/Videos$ ./random_video_opener
Directory: /home/user/Videos
Files: 140
Index: 99
File: Funny cat.mp4
```
