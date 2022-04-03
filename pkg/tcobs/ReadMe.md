# TCOBS Framing Encoder and Decoder

- [ ] Encoder and Decoder in other languages are easy to implement using the TCOBS specification and the given **C**- and **Go**-code.

## TCOBS Encoding

- [x] `tcobs.h` and `tcobs.c` contain the encoder as **C**-code.
- [x] The encoding in **Go** is possible with `tcobs.go` using `tcobs.c` with CGO.

## TCOBS Decoding

- [x] `tcobs.go` contains the decoder as **Go**-code.
- [ ] The decoding in **C** is not implemented (yet).

## TCOBS Testing

- [x] `tcobs_test.go` contains test code. CGO is not supported inside test files but usable through **Go** functions. 
  - Testing: `go test ./...`: ![../../docs/ref/Test.PNG](../../docs/ref/Test.PNG)
- The test execution can take several seconds. If your computer is slow you can reduce the loop count in the test functions `TestEncodeDecode*`.

## Issues

- When using a Windows PC with some **antivirus** software, the `go vet ./...` and `go test ./...` execution could be disturbed:
  - Possible message: `cgo: cannot parse $WORK\b080\_cgo_.o as ELF, Mach-O, PE or XCOFF`
