
build:
	@gcc -finstrument-functions -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "Buliding..."

run:
	@gcc -finstrument-functions -Wall -Werror -Wextra -pedantic *.c -o hsh
	@echo "Runing..."
	@./hsh ; rm -f hsh

valgrind-q:
	@gcc -finstrument-functions -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@valgrind --quiet --leak-check=full --track-origins=yes ./hsh ; rm -f hsh
#	--trace-children=

valgrind:
	@gcc -finstrument-functions -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@valgrind --leak-check=full --track-origins=yes ./hsh ; rm -f hsh

gdb:
	@gcc -finstrument-functions -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@gdb ./hsh ; rm -f hsh

gdb-c:
	@gcc -finstrument-functions -g -Wall -Werror -Wextra -pedantic *.c -o hsh
	@gdb ./hsh ; rm -f hsh

