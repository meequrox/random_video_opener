# RandomVideoOpener

![Screenshot](images/screenshot.png)

__A simple program that opens a random video in the current directory__

[List of supported formats](src/files.cpp#L28)

_Currently only *nix OS are supported_

## Build

### Release

The program outputs:
- current working directory
- number of files in the directory
- selected file number and name

```
mkdir build

cd build

cmake .. -DCMAKE_BUILD_TYPE="Release"

make
```

The output binary will be named `RandomVideoOpener`

### Debug

The program outputs the same information as [Release](#release) and:
- check result for each file (VIDEO/NOT VIDEO)
- list of all files in the directory

```
mkdir build

cd build

cmake .. -DCMAKE_BUILD_TYPE="Debug"

make
```

The output binary will be named `RandomVideoOpener`
