#!/bin/sh
set -a

gcc -pedantic -Wall -Wextra -Werror -lm $@ -o app
./app