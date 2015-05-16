/*
 * Diophantine.h
 *
 *  Created on: 6 мая 2015
 *      Author: vadim
 */

#ifndef TEST_DIOPHANTINE_H_
#define TEST_DIOPHANTINE_H_

#include "GeneticAlgorithm.h"
#include "Population.h"
#include "Alleli.h"
#include "DiophantineFitnessFunction.h"
#include <vector>
using namespace std;

class Diophantine : public IterartionListener
{
public:
	Diophantine( int a, int b, int c, int d, int res );
	virtual ~Diophantine();

	Alleli * Solve();

private:
	void dump( vector<Chromosome *> & chromosomes );
	void fillInitialPopulation( int populationSize );
	void update( GeneticAlgorithm * environment );

	int m_A;
	int m_B;
	int m_C;
	int m_D;
	int m_ExpectedResult;

	Population m_Population;
	DiophantineFitnessFunction m_FitnessFunction;

	GeneticAlgorithm * m_GA;

};

#endif /* TEST_DIOPHANTINE_H_ */
