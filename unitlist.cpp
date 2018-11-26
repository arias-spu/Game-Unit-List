/* UnitList class Definition
** 2018 - 11 -26
** Carlos Arias
*/

#include "unit.h"
#include "unitlist.h"

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;
using std::endl;

UnitList::UnitList(size_t capacity) : _capacity(capacity), _size(0){
	_units = new Unit*[_capacity];
	for (size_t i = 0; i < _capacity; i++) {
		_units[i] = nullptr;
	}
}
UnitList::UnitList(const UnitList& rhs){
	_capacity = rhs._capacity;
	_units = new Unit*[_capacity];
	for (size_t i = 0; i < rhs._size; i++) {
		// Add(*rhs._units[i]);
		_units[i] = new Unit(*rhs._units[i]);
	}
	_size = rhs._size;
}
UnitList& UnitList::operator=(const UnitList& rhs){
	for (size_t i = 0; i < _size; i++) {
		delete _units[i];
		_units[i] = nullptr;
	}
	if (_capacity != rhs._capacity){
		delete[] _units;
		_units = new Unit*[rhs._capacity];
		for (size_t i = 0; i < _capacity; i++) {
			_units[i] = nullptr;
		}
		_capacity = rhs._capacity;
	}

	for (size_t i = 0; i < rhs._size; i++) {
		// Add(*rhs._units[i]);
		_units[i] = new Unit(*rhs._units[i]);
	}
	_size = rhs._size;
	return *this;
}
UnitList::~UnitList(){
	// ****** A ******
	for (size_t i = 0; i < _size; i++) {
		delete _units[i];
	}
	// ****** B ******
	delete[] _units;
}
bool UnitList::Add(const Unit& unit){
	if (_size == _capacity)
		return false;
	_units[_size] = new Unit(unit);
	_size++;
	return true;
}
bool UnitList::Add(const string& name, size_t attack, size_t hitPoints){
	return Add(Unit(name, attack, hitPoints));
/*
	if (_size == _capacity)
		return false;
	_units[_size] = new Unit(name, attack, hitPoints);
	_size++;
	return true;

*/

}
//	bool Remove(const string&);
size_t UnitList::Read(istream& input){
	size_t unitsRead = 0;
	Unit unit("", 0, 0);
	while (input){
		unit.Read(input);
		if (!Add(unit))
			break;
		unitsRead++;
	}
	return unitsRead;
}
size_t UnitList::Write(ostream& output)const{
	for (size_t i = 0; i < _size; i++) {
		_units[i]->Write(output);
		output << endl;
	}
	return _size;
}
const Unit* UnitList::Get(size_t position)const{
	if (position >= _size)
		return nullptr;
	return _units[position];
}
