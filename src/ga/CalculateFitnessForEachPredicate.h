/*
 * CalculateFitnessForEachPredicate.h
 *
 *  Created on: 12 мая 2015
 *      Author: vadim
 */

#ifndef GA_CALCULATEFITNESSFOREACHPREDICATE_H_
#define GA_CALCULATEFITNESSFOREACHPREDICATE_H_

#include "Chromosome.h"
#include "Fitness.h"

class CalculateFitnessForEachPredicate
{
public:
	CalculateFitnessForEachPredicate( Fitness * fitnessFunc );
	virtual ~CalculateFitnessForEachPredicate();

	void operator() ( const Chromosome * chr ) const;

private:

	 Fitness * m_FitnessFunc;

};

#endif /* GA_CALCULATEFITNESSFOREACHPREDICATE_H_ */
