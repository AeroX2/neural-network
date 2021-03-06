#!/bin/sh

function test {
    "$@"
    local status=$?
    if [ $status -ne 0 ]; then
        echo "error with $1" >&2
		exit
    fi
    return $status
}

if [ "$1" == "-s" ] || [ "$1" == "--sixty" ]; then
	test /c/Program\ Files/Cmake/bin/cmake.exe -G "MSYS Makefiles" -Dwindows="ON" -Dsixty="ON"
else
	test /c/Program\ Files/Cmake/bin/cmake.exe -G "MSYS Makefiles" -Dwindows="ON"
fi
test /c/MinGW/msys/1.0/bin/make.exe
test ./windows/NeuralNetwork.exe
