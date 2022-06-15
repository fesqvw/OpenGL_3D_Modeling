#pragma once
template <typename T>
bool mapContains(map<T const, T const> map, T elem) {
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
void mapForEach(map<T const, T const> map, T elem) {

}