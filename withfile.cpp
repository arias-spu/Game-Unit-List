#include "unit.h"
#include "unitlist.h"

#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ofstream;
using std::ifstream;

int main(int argc, char* argv[]){

	string inputFileName, outputFileName;
	cout << "Input filename = ";
	cin >> inputFileName;
	cout << "Output filename = ";
	cin >> outputFileName;

	ifstream input(inputFileName);
	if (input.fail()){
		cerr << "Could not open input file" << endl;
		return 1;
	}
	ofstream output(outputFileName);
	if (output.fail()){
		cerr << "Could not open output file" << endl;
		return 1;
	}

	UnitList jasonList(5);
	size_t unitsRead = jasonList.Read(input);
	cout << unitsRead << " units loaded from file" << endl << endl;
	jasonList.Write(cout);
	for (size_t i = 0; i < jasonList.Size(); i++) {
		jasonList.Get(i)->IncreaseAttack(100);
	}
	jasonList.Write(output);

	input.close();
	output.close();

	return 0;
}
