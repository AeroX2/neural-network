#!/bin/sh

function test {
	echo $@
    "$@"
    local status=$?
    if [ $status -ne 0 ]; then
        echo "error with $1" >&2
	exit
    fi
    return $status
}

function print_usage {
	echo "Usage: $0
	  -d, --debug     Compile with gcc -g for debug mode
	  -p, --parallel  Use the OpenMP library, to allow the program to run in parallel
	  -w, --windows   Cross compile in Linux for Windows  
	  -s, --sixty     Compile in 64 bit mode only for windows"
	exit 1;
}

for arg in "$@"; do
  shift
  case "$arg" in
    "--debug")    set -- "$@" "-d" ;;
    "--parallel") set -- "$@" "-p" ;;
    "--windows")  set -- "$@" "-w" ;;
    "--sixty")    set -- "$@" "-s" ;;
    *)            set -- "$@" "$arg"
  esac
done

cmake_flags=". ";

while getopts "dpws" opt
do
  case "$opt" in
	"d") cmake_flags+="-Ddebug=ON" ;;
    "p") cmake_flags+="-Dparallel=ON" ;;
    "w") windows=true ;;
    "s") sixty=true ;;
    "?") print_usage;
  esac
done

if [ ! $windows ] && [ $sixty ]; then
	echo "Invalid option --sixty without --windows"
	exit 1
fi

if [ $windows ]; then
	if [ $sixty ]; then
		test x86_64-w64-mingw32-cmake -Dcrosscompile="ON" -Dsixty="ON" .
	else
		test i686-w64-mingw32-cmake -Dcrosscompile="ON" .
	fi
	test make
	test wine NeuralNetwork.exe
else
	test cmake $cmake_flags
	test make
	test ./neural_network
fi
