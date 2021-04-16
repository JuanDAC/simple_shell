
build:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "Buliding..."

run:
	@gcc -rdynamic -pg -finstrument-functions -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "Runing..."
	@./hsh ; rm -f hsh

valgrind-q:
	@gcc -rdynamic -pg -finstrument-functions -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@valgrind --quiet --leak-check=full --track-origins=yes ./hsh ; rm -f hsh
#	--trace-children=

valgrind:
	@gcc -rdynamic -pg -finstrument-functions -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./hsh ; rm -f hsh

gdb:
	@gcc -rdynamic -pg -finstrument-functions -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@gdb ./hsh ; rm -f hsh

gdb-c:
	@gcc -rdynamic -pg -finstrument-functions -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@gdb ./hsh ; rm -f hsh

