#ifndef QUICKSORT_H
#define QUICKSORT_H
#define DEBUG 0
#include "Utility.h"



template <typename RandomAccessIterator>
void QuickSort( RandomAccessIterator begin, RandomAccessIterator end ){
	if ( begin < end ){
		RandomAccessIterator it_smaller = begin;
		RandomAccessIterator it_greater_or_equal = (end - 1);
		while ( it_smaller < it_greater_or_equal ){
			if ( ( *(it_smaller + 1) ) < ( *it_smaller ) ){
				mySwap( *(it_smaller), *(it_smaller + 1) );
				it_smaller++;
			}
			else{
				mySwap( *(it_smaller + 1), *it_greater_or_equal );
				it_greater_or_equal--;
			}
		}	
		QuickSort( begin, it_smaller );
		QuickSort( it_greater_or_equal + 1, end );
	}
}
#endif