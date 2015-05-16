/*
 * Alleli.h
 *
 *  Created on: 6 мая 2015
 *      Author: vadim
 */

#ifndef TEST_ALLELI_H_
#define TEST_ALLELI_H_

#include "Chromosome.h"
#include <vector>
using namespace std;

class Alleli : public Chromosome
{
public:
	Alleli( int expectedResult );
	Alleli( const Alleli & src );
	virtual ~Alleli();

	vector<Chromosome *> crossover( Chromosome * anotherChromosome );
	Chromosome * mutate();
	Chromosome * mutateChangeRandomOneGene();
	Chromosome * mutateChangeRandomAllGenes();
	Chromosome * mutateRearangeRandomOneGenes();
	Chromosome * mutateRearangeRandomAllGenes();
	Chromosome * mutateRandomPlusOne();
	Chromosome * mutateRandomMinusOne();
	void getGenes( vector<ChromosomesType> & genes ) const;
	void setGenes( vector<ChromosomesType> & genes );

	void setFitness( double fitness );
	Alleli & operator = ( const Alleli & src );

private:

	vector<ChromosomesType> m_Genes;

	int m_ExpectedResult;

};

#endif /* TEST_ALLELI_H_ */
