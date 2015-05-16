/*
 * ChromosomesComparator.h
 *
 *  Created on: 28 апр. 2015
 *      Author: vadim
 */

#ifndef GA_CHROMOSOMESCOMPARATOR_H_
#define GA_CHROMOSOMESCOMPARATOR_H_

#include "Chromosome.h"
#include "Fitness.h"
#include <map>
using namespace std;

class ChromosomesComparator
{
public:
	ChromosomesComparator();
	virtual ~ChromosomesComparator();

	bool operator () ( const Chromosome * chr1, const Chromosome * chr2 ) const;
	ChromosomesType operator () ( ChromosomesType src_value, Chromosome * chr ) const;

	void clearCache();

	void setFitness( Fitness * fitness );
	void setLikeliHood( double likelihood );

	ChromosomesType fit( const Chromosome * chr ) const;

private:

	Fitness * m_Fitness;
	mutable map< const Chromosome *, ChromosomesType > m_Cache;

};

#endif /* GA_CHROMOSOMESCOMPARATOR_H_ */
