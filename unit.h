/* Unit class Declaration
** 2018 - 11 -26
** Carlos Arias
*/

#pragma once

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class Unit{
	size_t _attack;
	size_t _hitPoints;
	string _name;
public:
	Unit(const string&, size_t, size_t);
	void IncreaseAttack(size_t);
	bool ReceiveDamage(size_t);
	string GetName()const;
	void Read(istream&);
	void Write(ostream&);
};
