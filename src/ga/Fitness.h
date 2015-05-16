/*
 * Fitness.h
 *
 *  Created on: 28 апр. 2015
 *      Author: vadim
 */

#ifndef GA_FITNESS_H_
#define GA_FITNESS_H_

#include "Chromosome.h"

class Fitness
//C must implement Chromosome, T implement Comparable
{
public:
	virtual ~Fitness(){}
	/**
	 * Assume that chromosome1 is better than chromosome2 <br/>
	 * fit1 = calculate(chromosome1) <br/>
	 * fit2 = calculate(chromosome2) <br/>
	 * So the following condition must be true <br/>
	 * fit1.compareTo(fit2) <= 0 <br/>
	 */
	virtual double calculate( const Chromosome * chromosome ) = 0;

};

#endif /* GA_FITNESS_H_ */
