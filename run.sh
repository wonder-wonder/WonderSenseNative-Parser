#!/bin/bash

build() {
  mkdir -p build
  cd build
  cmake ..
  make

  if [[ $? -eq 0 ]]; then
    make test
    ./test/Test_app
  fi
}


clean() {
  rm -Rf build
}


main() {
  for OPT in "$@"; do
    shift 1
    case "$OPT" in
      "build")
        build
        shift
        ;;

      "clean")
        clean
        ;;
    esac
  done
}


main $@
