#ifndef TESTUTILITY_H
#define TESTUTILITY_H
#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif 

using namespace std;

template <typename ForwardIterator>
void print( ForwardIterator begin, ForwardIterator end ){
	for ( ForwardIterator it = begin; it != end; it++ ){
		cout << (*it) << ' ';
	}
	cout << endl;
}

template <typename ForwardIterator>
void loadFromInputstream( ForwardIterator begin, ForwardIterator end ){
	for ( ForwardIterator it = begin; it != end; it++ ){
		cin >> (*it);
	}
}

template <typename T>
void mySwap ( T& a, T& b )
{
	#if DEBUG
		cout << "Swaping " << a << " and " << b << " ... ";
	#endif
	T c(a);
	a=b;
	b=c;
	#if DEBUG
		cout << "Done!" << endl;
	#endif
}

template <typename ForwardIterator>
bool isSorted( ForwardIterator begin, ForwardIterator end ){
	for ( ForwardIterator it = begin + 1; it != end; it++ ){
		if ( (*it) < (*(it-1)) ){
			return false;
		}
	}
	return true;
}
#endif