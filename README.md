## get_next_line

### Description:
`get_next_line.c` reads line from the file accroding to the file descriptor and writes the result to the input pointer
* supports reading line by line
* supports multiple file descriptors

### Installation:
* `git clone "https://github.com/cardengo/get_next_line.git"`

### Usage:
* `make` --> compile files
* `./gnl` + `file-to-raed` --> launch binary
* `make clean` --> delete `gnl` binary
* `make val` --> check for memory leaks (required [Valgrind](https://valgrind.org/))

### Return value:
* `1` --> line was read
* `0` --> there is no more lines in the file (end of the file)
* `-1`--> error occured

### Comment:
directory contains `main.c` and two files (in `files/`) for quick demonstration
