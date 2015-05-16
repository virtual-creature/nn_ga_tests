/*
 * OptimizableNeuralNetwork.h
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#ifndef NN_OPTIMIZABLENEURALNETWORK_H_
#define NN_OPTIMIZABLENEURALNETWORK_H_

#include "NeuralNetwork.h"
#include "Chromosome.h"
#include "Random.h"
#include <vector>
using namespace std;

class OptimizableNeuralNetwork : public NeuralNetwork, public Chromosome
{
public:
	OptimizableNeuralNetwork( const OptimizableNeuralNetwork & src );
	virtual ~OptimizableNeuralNetwork();

	OptimizableNeuralNetwork( int numberOfNeurons );
//	OptimizableNeuralNetwork(NeuralNetwork & nn);

	vector<Chromosome *> crossover( Chromosome * anotherChromosome );
	void twoPointsWeightsCrossover( vector<double> & thisWeights, vector<double> & anotherWeights );
	void uniformelyDistributedWeightsCrossover( vector<double> & thisWeights, vector<double> & anotherWeights );
	void twoPointsNeuronsCrossover( vector<Neuron> & thisNeurons, vector<Neuron> & anotherNeurons );
	void uniformelyDistributedNeuronsCrossover( vector<Neuron> & thisNeurons, vector<Neuron> & anotherNeurons );
	Chromosome * mutate();
	void getGenes( vector<double> & genes );
	void mutateWeights( vector<double> & weights );
	void mutateNeuronsFunctionsParams( vector<Neuron> & neurons );
	void mutateChangeNeuronsFunctions( vector<Neuron> & neurons );
	void shuffleWeightsOnSubinterval( vector<double> & weights );

private:

	double m_WeightsMutationInterval;
	double m_NeuronParamsMutationInterval;

	Random m_Random;
};

#endif /* NN_OPTIMIZABLENEURALNETWORK_H_ */
