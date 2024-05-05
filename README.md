# Random Video Opener

**A simple program that opens a random video from the current directory.**
Uniform distribution is used.

[List of video formats](video/video.go#L33)

## Build

```bash
git clone https://github.com/meequrox/random_video_opener.git

cd random_video_opener

# Default build
go build -o build/

# Optimized build
go build -o build/ -ldflags="-s -w"
```

The binary will be located in the `build/` directory.

## Usage

```bash
user@onhost:~/Videos$ ./random_video_opener
Directory: /home/user/Videos
Files: 190
File [99]: Funny cat.mp4
Command: /sbin/xdg-open Funny cat.mp4
```

Or you can simply double-click the binary file using the file manager.
