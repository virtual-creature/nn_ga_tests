/*
 * FindChromosomePredicate.h
 *
 *  Created on: 12 мая 2015
 *      Author: vadim
 */

#ifndef GA_FINDCHROMOSOMEPREDICATE_H_
#define GA_FINDCHROMOSOMEPREDICATE_H_

#include "Chromosome.h"

class FindChromosomePredicate
{
public:
	FindChromosomePredicate( const Chromosome * chr );
	virtual ~FindChromosomePredicate();

	bool operator () ( const Chromosome * chr1 ) const;

private:

	 const Chromosome * m_Chromosome;

};

#endif /* GA_FINDCHROMOSOMEPREDICATE_H_ */
