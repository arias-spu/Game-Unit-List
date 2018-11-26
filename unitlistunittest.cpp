#include "unit.h"
#include "unitlist.h"

#include <cassert>
#include <sstream>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::stringstream;

int main(int argc, char* argv[]){

	stringstream unitBuffer;
	unitBuffer.str(
			"Heroe 200 1000\n"
			"Giant 20 10000\n"
			"Archer 20 500\n"
			"Barbarian 50 500\n"
			"Witch 100 100\n"
			"Dragon 1000 10"
	);

	UnitList jasonList(5);
	assert(jasonList.Size() == 0);
	assert(jasonList.Get(0) == nullptr);
	assert(jasonList.Read(unitBuffer) == 5);
	assert(jasonList.Get(0)->GetName() == "Heroe");
	assert(jasonList.Get(1)->GetName() == "Giant");
	assert(jasonList.Get(2)->GetName() == "Archer");
	assert(jasonList.Get(3)->GetName() == "Barbarian");
	assert(jasonList.Get(4)->GetName() == "Witch");
	assert(jasonList.Get(5) == nullptr);
	assert(jasonList.Size() == 5);

	jasonList.Write(cout);


	cout << "All unit test passed" << endl;
	return 0;
}
