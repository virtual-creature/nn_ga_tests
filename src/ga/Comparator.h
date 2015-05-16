/*
 * Comparator.h
 *
 *  Created on: 7 мая 2015
 *      Author: vadim
 */

#ifndef GA_COMPARATOR_H_
#define GA_COMPARATOR_H_

template< typename C >
class Comparator
{
public:
	Comparator();
	virtual ~Comparator();

	bool operator() ( C & chr1, C & chr2 );
};

#endif /* GA_COMPARATOR_H_ */
