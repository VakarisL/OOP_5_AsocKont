#include <iostream>
#include <fstream>
#include "../src/Headers/text.h"


int main(){
	std::ifstream input;
	try {
		input.open("Main/Resources/text.txt");
		if (input.fail()) throw "Test failas nerastas folderyje";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::terminate();
	}

	text test(input);

	input.close();

	test.print_contents();

	return 0;
}