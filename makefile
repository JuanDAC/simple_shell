
build:
	@gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "Buliding..."

run:
	@gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "Runing..."
	@./hsh ; rm -f hsh

valgrind-q:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@valgrind --quiet --leak-check=full --track-origins=yes ./hsh ; rm -f hsh
#	--trace-children=

valgrind:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@valgrind --leak-check=full --track-origins=yes ./hsh ; rm -f hsh

gdb:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@gdb ./hsh ; rm -f hsh

gdb-c:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@gdb ./hsh ; rm -f hsh

