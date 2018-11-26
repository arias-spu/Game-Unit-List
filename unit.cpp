/* Unit class Definition
** 2018 - 11 -26
** Carlos Arias
*/


#include "unit.h"

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

/*
IF we had a default constructor:
Unit::Unit(){
	_name = "Weak_Pawn";
	_attack = 1;
	_hitPoints = 1;
}
*/

// Choice 1
Unit::Unit(const string& name, size_t attack, size_t hitPoints):
	_name(name), _attack(attack), _hitPoints(hitPoints){

}
// Choice 2
/*
Unit::Unit(const string& name, size_t attack, size_t hitPoints){
	_name = name;		// THIS IS SLOWER
	_attack = attack;
	_hitPoints = hitPoints;
}
*/
void Unit::IncreaseAttack(size_t amount){
	_attack += amount;
}
bool Unit::ReceiveDamage(size_t damage){
	if (_hitPoints - damage < 0){
		_hitPoints = 0;
		return false;
	}
	_hitPoints -= damage;
	return true;
}
string Unit::GetName()const{
	return _name;
}
void Unit::Read(istream& input){
	input >> _name >> _attack >> _hitPoints;
}
void Unit::Write(ostream& output){
	output << _name << " " << _attack << " " << _hitPoints;
}
