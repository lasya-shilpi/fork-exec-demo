all: fork_exec_demo simple_print

fork_exec_demo: fork_exec_demo.cpp
	g++ -std=c++17 -g -pedantic -Wall -Wextra -Werror -fsanitize=address,undefined -fno-omit-frame-pointer -o fork_exec_demo fork_exec_demo.cpp

simple_print: simple_print.cpp
	g++ -std=c++17 -g -pedantic -Wall -Wextra -Werror -fsanitize=address,undefined -fno-omit-frame-pointer -o simple_print simple_print.cpp

clean:
	rm -f fork_exec_demo simple_print
