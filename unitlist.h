/* UnitList class Declaration
** 2018 - 11 -26
** Carlos Arias
*/

#pragma once

#include "unit.h"

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class UnitList{
	size_t _capacity;
	size_t _size;
	Unit** _units;
public:
	UnitList(size_t);
	UnitList(const UnitList&);
	UnitList& operator=(const UnitList&);
	~UnitList();
	bool Add(const Unit&);
	bool Add(const string&, size_t, size_t);
//	bool Remove(const string&);
	size_t Read(istream&);
	size_t Write(ostream&)const;
	Unit* Get(size_t)const;
	size_t Size()const;
};
