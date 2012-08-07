#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

#include "tinyxml2/tinyxml2.h"
using namespace tinyxml2;

#include "pretty_printer.h"

/*
 * Usage:
 * 	$ pp "xml string"
 * 	$ xml_output_program | pp
 */

int main(int argc, char* argv[]) {

	/*
	 * No args.
	 * Read XML input from STDIN (used for piping)
	 */
	if(argc == 1) { 
    FILE* fp = stdin;
    if(!isatty(fileno(fp))){ //Check STDIN for input
			string str;
			char temp;
			while(!cin.eof()) { //Iterate file pointer until EOF
				cin.get(temp); //Get char
				str += temp; //append char to data string
			}
			print_xml(str.c_str()); //convert str to const char*, format, & print
    } else { //pp called with no args & no data on STDIN
    	arg_error();
		}
	}

	/*
	 * Single argument should be XML data
	 */
	else if(argc == 2) {
		print_xml(argv[1]); //format & print argument
	} else { //Something else
		arg_error();
	}
}

/*
 * Outputs "usage" message
 */
void arg_error(void) {
	cout << "Argument error, check the README.\nUsage:\n";
	cout << "\tpp \"<Hello>World</Hello>\"\n\tprogram_outputs_xml args | pp\n";
}

/*
 * Formats and prints document
 * Yay tinyxml2!
 */
void print_xml(const char* cstr) {
	XMLDocument doc;
	XMLPrinter printer;

	if (doc.Parse(cstr) == XML_SUCCESS) {
		XMLPrinter printer;
		doc.Print(&printer);
		cout << printer.CStr();
	} else {
		cout << "Error parsing XML document.\n";
	}
}
