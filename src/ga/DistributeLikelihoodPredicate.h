/*
 * DistributeLikelihoodPredicate.h
 *
 *  Created on: 12 мая 2015
 *      Author: vadim
 */

#ifndef GA_DISTRIBUTELIKELIHOODPREDICATE_H_
#define GA_DISTRIBUTELIKELIHOODPREDICATE_H_

#include "Chromosome.h"

class DistributeLikelihoodPredicate
{
public:
	DistributeLikelihoodPredicate( double totalLikelihood );
	DistributeLikelihoodPredicate( const DistributeLikelihoodPredicate & src );
	virtual ~DistributeLikelihoodPredicate();

	void operator () ( Chromosome * chr );

private:

	double m_SumPercent;
	double m_TotalLikelihood;

};

#endif /* GA_DISTRIBUTELIKELIHOODPREDICATE_H_ */
