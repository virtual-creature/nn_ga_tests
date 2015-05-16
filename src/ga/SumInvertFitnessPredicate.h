/*
 * SumInvertFitnessPredicate.h
 *
 *  Created on: 12 мая 2015
 *      Author: vadim
 */

#ifndef GA_SUMINVERTFITNESSPREDICATE_H_
#define GA_SUMINVERTFITNESSPREDICATE_H_

#include "Chromosome.h"
#include "Fitness.h"

class SumInvertFitnessPredicate
{
public:
	SumInvertFitnessPredicate( Fitness * fitnessFunc );
	virtual ~SumInvertFitnessPredicate();

	ChromosomesType operator () ( ChromosomesType src_value, const Chromosome * chr ) const;

private:

	Fitness * m_FitnessFunc;

};

#endif /* GA_SUMINVERTFITNESSPREDICATE_H_ */
