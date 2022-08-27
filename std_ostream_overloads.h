#include <vector>
#include <array>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <iostream>


/*
Provides ostream overloads for standard C++ containers.

*/


namespace {
	template<size_t curIndex, class... Ts>
	void print_tuple(std::ostream& o, std::tuple<Ts...> tup) {
		constexpr size_t size = sizeof...(Ts);
		o << std::get<curIndex>(tup);
		if constexpr(curIndex+1 == size) {
			return;
		}
		else {
			o << ", ";
			print_tuple<curIndex + 1,Ts...>(o,tup);
		}
	}
}
//STANDARD CONTAINER OVERLOADS
//namespace sco {}


template<class T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec) {
	o << "vector[";
	if (vec.size() != 0) {
		o << vec[0];
		for (int i = 1; i < vec.size(); i++) {
			o << ", ";
			o << vec[i];
		}
	}
	o << "]";
	return o;
}
template<class T, std::size_t size>
std::ostream& operator<<(std::ostream& o, const std::array<T, size>& arr) {
	o << "array[";
	if (size != 0) {
		o << arr[0];
		for (int i = 1; i < arr.size(); i++) {
			o << ", ";
			o << arr[i];
		}
	}
	o << "]";
	return o;
}


template<class... Ts>
std::ostream& operator<<(std::ostream& o, const std::tuple<Ts...>& tup) {
	o << "tuple(";
	size_t size = sizeof...(Ts);
	if (sizeof...(Ts) != 0) {
		print_tuple<0, Ts...>(o, tup);
	}
	o << ")";
	return o;
}

template<class T>
std::ostream& operator<<(std::ostream& o, const std::set<T>& se) {
	o << "set{";
	bool first = true;
	for (const auto& val : se) {
		if (!first) {
			o << ", ";
		}
		first = false;
		o << val;
	}

	o << "}";
	return o;
}
template<class T>
std::ostream& operator<<(std::ostream& o, const std::unordered_set<T>& se) {
	o << "unordered_set{";
	bool first = true;
	for (const auto& val : se) {
		if (!first) {
			o << ", ";
		}
		first = false;
		o << val;
	}

	o << "}";
	return o;
}
template<class F, class S>
std::ostream& operator<<(std::ostream& o, const std::pair<F,S> p) {
	o << "pair(" << p.first << ", " << p.second << ")";
	return o;
}


template<class K, class V>
std::ostream& operator<<(std::ostream& o, const std::map<K,V>& m) {
	o << "map{";
	bool first = true;
	for (const auto& [key, value] : m) {
		if (!first) {
			o << ", ";
		}
		first = false;
		o << key << " : " << value;
	}

	o << "}";
	return o;
}
template<class K, class V>
std::ostream& operator<<(std::ostream& o, const std::unordered_map<K, V>& m) {
	o << "unordered_map{";
	bool first = true;
	for (const auto& [key, value] : m) {
		if (!first) {
			o << ", ";
		}
		first = false;
		o << key << " : " << value;
	}

	o << "}";
	return o;
}
