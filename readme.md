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
* [ ] F#
* [ ] Swift
* [ ] Python
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

## day1

**Language**: `go`

**Usage**: `./run go 1-captcha.go 112334233`

To run the modified challenge of _half-way round the string_ matching `go run 1-captcha.go 123123 half`