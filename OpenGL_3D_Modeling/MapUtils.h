#pragma once
#include <functional>
using namespace std;

template <typename T>
bool mapContains(map<T const , T const > map, T elem) {
	try
	{
		map.at(elem);
		return true;
	}
	catch (const std::exception)
	{
		return false;
	}
}

template <typename T>
void mapForEach(map<T const , T const> mapFor, function< void(T) >& lambda) {
	//TODO : check 'typename' here
	for (typename map<T const, T const>::iterator it = mapFor.begin(); it != mapFor.end(); ++it) {
		lambda(it->first);
	}
}