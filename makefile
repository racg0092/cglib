


run_test:
	clang -std=c99 -Werror -Wall ./test/${test}.c *.c ./test/tests.c -o _test && \
		valgrind --leak-check=full ./_test & rm ./_test
