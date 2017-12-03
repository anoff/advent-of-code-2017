# advent of code 2017 🎄🗓

> Solving [adventofcode.com](http://adventofcode.com/2017/about) with a bunch of new languages 🐟

## Challenges 🏋️‍

I want to use the following languages at least once during this course:

* [ ] javascript (node)
* [ ] typscript
* [x] golang
* [ ] bash
* [ ] rust
* [ ] C
* [x] F#
* [ ] Swift
* [x] Python
* [ ] Lua
* [ ] Java

### Docker 🐳

Don't want to put a bunch of compilers and runtimes on my machine so all code should be executable in a docker container. The docker images and run commands are hidden in the [run script](./run).

```sh
# use the following to run go code
./run go myfile.go argument1
# or node
./run node myfile.js argument1
```

I tried to select the smallest possible images:

| Language | Image | Size |
|----------|-------|------|
| C | [frolvlad/alpine-gcc:latest](https://hub.docker.com/r/frolvlad/alpine-gcc/) | 99.2MB |
| F# | [fsharp:4.1](https://hub.docker.com/_/fsharp/) | 550MB |
| go | [golang:1.9-alpine](https://hub.docker.com/_/golang/) | 269MB |
| node | [node:8-alpine](https://hub.docker.com/_/node/) | 65.8MB |
| python | [python:3-alpine](https://hub.docker.com/_/python/) | 89.1MB |
| rust | [frolvlad/alpine-rust:latest](https://hub.docker.com/r/frolvlad/alpine-rust/) | 220MB |
| swift | [swift:4](https://hub.docker.com/_/swift/) | 1.31GB |

## Usage 🏃‍

For each challenge put the input strings into a file `1.input`, `2.input`, .. and `cat` it into the command when calling the solution.

### Day1

**Language**: `go`

**Usage**: `./run go 1-captcha.go "$(cat 1.input)"`

To run the modified challenge of _half-way round the string_ matching `go run 1-captcha.go 123123 half`

### Day2

**Language**: `python, F#`

**Usage**:
* `./run python 2-checksum.py "$(cat 2.input)"`
* `./run fs 2-checksum.fs "$(cat 2.input)"`

**Part2**:
* `./run python 2-checksum.py "$(cat 2.input)" divisible`
* `./run fs 2-checksum.fs "$(cat 2.input)" divisible`
