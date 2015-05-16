/*
 * SortByLikelihoodPredicate.h
 *
 *  Created on: 12 мая 2015
 *      Author: vadim
 */

#ifndef GA_SORTBYLIKELIHOODPREDICATE_H_
#define GA_SORTBYLIKELIHOODPREDICATE_H_

#include "Chromosome.h"
#include "Fitness.h"

class SortByLikelihoodPredicate
{
public:
	SortByLikelihoodPredicate( double totalLikelihood, Fitness * fitnessFunc );
	virtual ~SortByLikelihoodPredicate();

	bool operator () ( Chromosome * chr1, Chromosome * chr2 );

private:

	 double m_TotalLikelihood;
	 Fitness * m_FitnessFunc;

};

#endif /* GA_SORTBYLIKELIHOODPREDICATE_H_ */
