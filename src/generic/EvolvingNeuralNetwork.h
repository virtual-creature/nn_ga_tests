/*
 * EvolvingNeuralNetwork.h
 *
 *  Created on: 16 мая 2015
 *      Author: vadim
 */

#ifndef TEST2_EVOLVINGNEURALNETWORK_H_
#define TEST2_EVOLVINGNEURALNETWORK_H_

#include "CNetwork.h"
#include "Chromosome.h"
#include "Random.h"

class EvolvingNeuralNetwork: protected CNetwork, public Chromosome
{
public:
	EvolvingNeuralNetwork( CLayersConfiguration & sequence );
	EvolvingNeuralNetwork( const EvolvingNeuralNetwork & src );
	virtual ~EvolvingNeuralNetwork();

	vector<Chromosome *> crossover( Chromosome * anotherChromosome );
	Chromosome * mutate();
	void getGenes( vector<double> & genes ) const;

private:

	void setGenes( vector<double> & genes );
	void twoPointsWeightsCrossover( vector<double> & thisWeights, vector<double> & anotherWeights );
	void uniformelyDistributedWeightsCrossover( vector<double> & thisWeights, vector<double> & anotherWeights );
	void twoPointsNeuronsCrossover( vector<INeuron *> & thisNeurons, vector<INeuron *> & anotherNeurons );
	void uniformelyDistributedNeuronsCrossover( vector<INeuron *> & thisNeurons, vector<INeuron *> & anotherNeurons );

	void mutateWeights( vector<double> & weights );
	void mutateNeuronsFunctionsParams( vector<INeuron *> & neurons );
	void mutateChangeNeuronsFunctions( vector<INeuron *> & neurons );
	void shuffleWeightsOnSubinterval( vector<double> & weights );

	Random m_Random;
};

#endif /* TEST2_EVOLVINGNEURALNETWORK_H_ */
