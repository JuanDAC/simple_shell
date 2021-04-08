build:
	@gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "buliding..."
	@./hsh
valgrind-q:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "buliding..."
	@valgrind --quiet --leak-check=full --track-origins=yes ./hsh
#	--trace-children=
valgrind:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "buliding..."
	@valgrind --leak-check=full --track-origins=yes ./hsh
