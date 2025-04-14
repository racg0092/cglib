


run_test:
	clang -std=c99 -Wall -Werror  ./test/${test}.c *.c ./test/tests.c -o _test && \
		valgrind --leak-check=full ./_test && rm ./_test
