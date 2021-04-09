
build:
	@gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "buliding..."
	@./hsh

run:
	@gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "buliding..."
	@./hsh ; rm -f hsh

valgrind-q:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "buliding..."
	@valgrind --quiet --leak-check=full --track-origins=yes ./hsh ; rm -f hsh
#	--trace-children=

valgrind:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "buliding..."
	@valgrind --leak-check=full --track-origins=yes ./hsh ; rm -f hsh

gdb:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "buliding..."
	@gdb ./hsh ; rm -f hsh

