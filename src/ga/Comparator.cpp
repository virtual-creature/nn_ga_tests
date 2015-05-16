/*
 * Comparator.cpp
 *
 *  Created on: 7 мая 2015
 *      Author: vadim
 */

#include <Comparator.h>

template< typename C >
Comparator< C >::Comparator()
{
}

template< typename C>
Comparator< C >::~Comparator()
{
}

template< typename C>
bool Comparator< C >::operator() ( C & chr1, C & chr2 )
{
	return true;
}














