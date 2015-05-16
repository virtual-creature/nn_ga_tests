/*
 * EvolvingNeuralNetwork.cpp
 *
 *  Created on: 16 мая 2015
 *      Author: vadim
 */

#include "EvolvingNeuralNetwork.h"

EvolvingNeuralNetwork::EvolvingNeuralNetwork( CLayersConfiguration & sequence ) : CNetwork( sequence )
{
}

EvolvingNeuralNetwork::EvolvingNeuralNetwork( const EvolvingNeuralNetwork & src ) : CNetwork( * src.getLayersConfiguration() )
{
	vector<double> genes;
	src.getGenes( genes );
	double * ptr = &genes[0];
	setGenes( genes );
}

EvolvingNeuralNetwork::~EvolvingNeuralNetwork()
{
}

vector<Chromosome *> EvolvingNeuralNetwork::crossover( Chromosome * anotherChromosome )
{
	int choise = m_Random.nextInt( 4 );
	switch( choise )
	{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
	}
	vector< Chromosome *> ret;
	return ret;
}

Chromosome * EvolvingNeuralNetwork::mutate()
{
	EvolvingNeuralNetwork * mutated = new EvolvingNeuralNetwork( *this );

	int choise = 0;//m_Random.nextInt( 4 );
	switch( choise )
	{
		case 0:
			{
				vector<double> weights;
				mutated->getGenes( weights );
				mutateWeights( weights );
				mutated->setGenes( weights );
			}
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
	}
	return mutated;
}

void EvolvingNeuralNetwork::getGenes( vector<double> & genes ) const
{
	vector<ILayer *> layers;
	this->getLayersConfiguration()->getLayers( layers );
	size_t layers_count = layers.size();

	for( size_t layer_i = 1 ; layer_i < layers_count ; layer_i++ )
	{
		ILayer * layer = layers[layer_i];

		size_t neurons_count = layer->getNeuronsCount();
		for( size_t neuron_i = 0 ; neuron_i < neurons_count ; neuron_i++ )
		{
			vector<double> weights;
			layer->getNeuron( neuron_i )->getWeights( weights );

			genes.insert( genes.end(), weights.begin(), weights.end() );
		}
	}
}

void EvolvingNeuralNetwork::setGenes( vector<double> & genes )
{
	vector<ILayer *> layers;
	this->getLayersConfiguration()->getLayers( layers );
	size_t layers_count = layers.size();

	unsigned int genesOffset = 0;

	for( size_t layer_i = 1 ; layer_i < layers_count ; layer_i++ )
	{
		ILayer * prevLayer = layers[layer_i - 1];

		unsigned int neuronsCount = prevLayer->getNeuronsCount();
		unsigned int weightsCount = neuronsCount + 1;
		for( size_t neuron_i = 0 ; neuron_i < neuronsCount ; neuron_i++ )
		{
			vector<double> weights( genes.begin() + genesOffset, genes.begin() + genesOffset + weightsCount );
			prevLayer->getNeuron( neuron_i )->setWeights( weights );

			genesOffset += weightsCount;

//			genes.insert( genes.end(), weights.begin(), weights.end() );
		}
	}
}

void EvolvingNeuralNetwork::twoPointsWeightsCrossover( vector<double> & thisWeights, vector<double> & anotherWeights )
{
	;
}

void EvolvingNeuralNetwork::uniformelyDistributedWeightsCrossover( vector<double> & thisWeights, vector<double> & anotherWeights )
{
	;
}

void EvolvingNeuralNetwork::twoPointsNeuronsCrossover( vector<INeuron *> & thisNeurons, vector<INeuron *> & anotherNeurons )
{
	;
}

void EvolvingNeuralNetwork::uniformelyDistributedNeuronsCrossover( vector<INeuron *> & thisNeurons, vector<INeuron *> & anotherNeurons )
{
	;
}

void EvolvingNeuralNetwork::mutateWeights( vector<double> & weights )
{
	;
}

void EvolvingNeuralNetwork::mutateNeuronsFunctionsParams( vector<INeuron *> & neurons )
{
	;
}

void EvolvingNeuralNetwork::mutateChangeNeuronsFunctions( vector<INeuron *> & neurons )
{
	;
}
void EvolvingNeuralNetwork::shuffleWeightsOnSubinterval( vector<double> & weights )
{
	;
}








