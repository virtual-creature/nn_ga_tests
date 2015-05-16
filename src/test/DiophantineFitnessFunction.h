/*
 * DiophantineFitnessFunction.h
 *
 *  Created on: 6 мая 2015
 *      Author: vadim
 */

#ifndef TEST_DIOPHANTINEFITNESSFUNCTION_H_
#define TEST_DIOPHANTINEFITNESSFUNCTION_H_

#include "Fitness.h"
#include "Alleli.h"

class DiophantineFitnessFunction : public Fitness
{
public:
	DiophantineFitnessFunction( int a, int b, int c, int d, int res );
	virtual ~DiophantineFitnessFunction();

	double calculate( const Chromosome * chromosome);

private:

	int m_A;
	int m_B;
	int m_C;
	int m_D;
	int m_ExpectedResult;

};

#endif /* TEST_DIOPHANTINEFITNESSFUNCTION_H_ */
