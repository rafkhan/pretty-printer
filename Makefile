all:
	g++ pretty_printer.cpp tinyxml2/tinyxml2.cpp -o pp

install:
	g++ pretty_printer.cpp tinyxml2/tinyxml2.cpp -o pp
	mv ./pp /usr/local/bin

uninstall:
	rm -f /usr/local/bin/pp
