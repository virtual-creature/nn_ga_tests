/*
 * Chromosome.h
 *
 *  Created on: 28 апр. 2015
 *      Author: vadim
 */

#ifndef GA_CHROMOSOME_H_
#define GA_CHROMOSOME_H_

#include <vector>
using namespace std;

typedef double ChromosomesType;

class Chromosome
{
public:
	virtual ~Chromosome(){}

	virtual bool operator == ( const Chromosome & chr ) const { return true; }

	virtual vector< Chromosome * > crossover( Chromosome * anotherChromosome ) = 0;
	virtual Chromosome * mutate() = 0;
	virtual void getGenes( vector<ChromosomesType> & genes ) const = 0;
	void setDistributionProb( double value );
	double getDistributionProb() const;
	double getFitness() const;

private:

	double m_ProbabilityDistribution;

protected:

	double m_Fitness;

};


#endif /* GA_CHROMOSOME_H_ */
