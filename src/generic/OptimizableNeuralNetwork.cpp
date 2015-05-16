/*
 * OptimizableNeuralNetwork.cpp
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#include "OptimizableNeuralNetwork.h"
#include "ThresholdFunctionManager.h"
#include <algorithm>
using namespace std;

OptimizableNeuralNetwork::~OptimizableNeuralNetwork()
{
}

OptimizableNeuralNetwork::OptimizableNeuralNetwork( int numberOfNeurons ) : NeuralNetwork( numberOfNeurons ),
		m_WeightsMutationInterval( 1 ), m_NeuronParamsMutationInterval( 1 )
{
}

OptimizableNeuralNetwork::OptimizableNeuralNetwork( const OptimizableNeuralNetwork & src ) :
		NeuralNetwork( src )
{
	m_WeightsMutationInterval = src.m_WeightsMutationInterval;
	m_NeuronParamsMutationInterval = src.m_NeuronParamsMutationInterval;
}

//OptimizableNeuralNetwork::OptimizableNeuralNetwork(NeuralNetwork & nn) : NeuralNetwork( nn ),
//		m_WeightsMutationInterval( 1 ), m_NeuronParamsMutationInterval( 1 )
//{
//	m_ActivationIterations = nn.getActivationIterations();
//	m_Neurons = nn.getNeurons();
//	m_NeuronsLinks = nn.getNeuronsLinks();
//}

vector< Chromosome * > OptimizableNeuralNetwork::crossover( Chromosome * anotherChromosome )
{
	OptimizableNeuralNetwork * anotherNN = dynamic_cast< OptimizableNeuralNetwork * >( anotherChromosome );
	OptimizableNeuralNetwork * anotherClone = new OptimizableNeuralNetwork( * anotherNN );
	OptimizableNeuralNetwork * thisClone = new OptimizableNeuralNetwork( * this );

	switch( rand() % 4 )
	{
		case 0:
		{
			vector<double> thisWeights;
			vector<double> anotherWeights;
			thisClone->m_NeuronsLinks.getAllWeights( thisWeights );
			anotherClone->m_NeuronsLinks.getAllWeights( anotherWeights );
			twoPointsWeightsCrossover( thisWeights, anotherWeights );
			thisClone->m_NeuronsLinks.setAllWeights( thisWeights );
			anotherClone->m_NeuronsLinks.setAllWeights( anotherWeights );
		}
		break;
		case 1:
		{
			vector<double> thisWeights;
			thisClone->m_NeuronsLinks.getAllWeights( thisWeights );
			vector<double> anotherWeights;
			anotherClone->m_NeuronsLinks.getAllWeights( anotherWeights );
			uniformelyDistributedWeightsCrossover( thisWeights, anotherWeights );
			thisClone->m_NeuronsLinks.setAllWeights( thisWeights );
			anotherClone->m_NeuronsLinks.setAllWeights( anotherWeights );
		}
		break;
		case 2:
		{
			twoPointsNeuronsCrossover( thisClone->m_Neurons, anotherClone->m_Neurons );
		}
		break;
		case 3:
		{
			uniformelyDistributedNeuronsCrossover( thisClone->m_Neurons, anotherClone->m_Neurons );
		}
		break;
	// TODO
	 case 4:
		{
			m_ActivationIterations += m_Random.nextInt(2) - m_Random.nextInt(2);
			m_ActivationIterations = ( m_ActivationIterations < 1 ) ? 1 : m_ActivationIterations;
		}
		break;
	}

	vector< Chromosome *> ret;
	ret.push_back( anotherClone );
	ret.push_back( thisClone );
	ret.push_back( anotherClone->mutate() );
	ret.push_back( thisClone->mutate() );
	return ret;
}

void OptimizableNeuralNetwork::getGenes( vector<double> & genes )
{
	getWeightsOfLinks( genes );
}

void OptimizableNeuralNetwork::twoPointsWeightsCrossover(vector<double> & thisWeights, vector<double> & anotherWeights)
{
	int left = rand() % thisWeights.size();
	int right = rand() % thisWeights.size();
	if( left > right )
	{
		int tmp = right;
		right = left;
		left = tmp;
	}
	for( int i = left ; i < right ; i++ )
	{
		double thisWeight = anotherWeights[ i ];
		thisWeights[ i ] = anotherWeights[ i ];
		anotherWeights[ i ] = thisWeight;
	}
}

void OptimizableNeuralNetwork::uniformelyDistributedWeightsCrossover(vector<double> & thisWeights, vector<double> & anotherWeights)
{
	int weightsSize = thisWeights.size();
	int itersCount = rand() % weightsSize;
	if( itersCount == 0 )
	{
		itersCount = 1;
	}
	vector<int> used;
	for( int iter = 0 ; iter < itersCount ; iter++ )
	{
		int i = rand() % weightsSize;
		if( weightsSize > 1 )
		{
			while( find( used.begin(), used.end(), i ) != used.end() )
			{
				i = rand() % weightsSize;
			}
		}
		double thisWeight = thisWeights[ i ];
		double anotherWeight = anotherWeights[ i ];

		anotherWeights[ i ] = thisWeight;
		thisWeights[ i ] = anotherWeight;
		used.push_back( i );
	}
}

void OptimizableNeuralNetwork::twoPointsNeuronsCrossover(vector<Neuron> & thisNeurons, vector<Neuron> & anotherNeurons)
{
	int left = rand() % thisNeurons.size();
	int right = rand() % thisNeurons.size();
	if( left > right )
	{
		int tmp = right;
		right = left;
		left = tmp;
	}
	for( int i = left ; i < right ; i++ )
	{
		Neuron thisNeuron = thisNeurons[ i ];
		thisNeurons[ i ] = anotherNeurons[ i ];
		anotherNeurons[ i ] = thisNeuron;
	}
}

void OptimizableNeuralNetwork::uniformelyDistributedNeuronsCrossover(vector<Neuron> & thisNeurons, vector<Neuron> & anotherNeurons)
{
	int neuronsSize = thisNeurons.size();
	int itersCount = rand() % neuronsSize;
	if (itersCount == 0) {
		itersCount = 1;
	}
	vector<int> used;
	for( int iter = 0 ; iter < itersCount ; iter++)
	{
		int i = rand() % neuronsSize;
		if (neuronsSize > 1)
		{
			while( find( used.begin(), used.end(), i ) != used.end() )
			{
				i = rand() % neuronsSize;
			}
		}
		Neuron thisNeuron = thisNeurons[ i ];
		Neuron anotherNeuron = anotherNeurons[ i];

		anotherNeurons[ i ] = thisNeuron;
		thisNeurons[ i ] = anotherNeuron;
		used.push_back( i );
	}
}

Chromosome * OptimizableNeuralNetwork::mutate()
{
	OptimizableNeuralNetwork * mutated = new OptimizableNeuralNetwork( *this );

	switch( rand() % 4 )
	{
		case 0:
		{
			vector<double> weights;
			mutated->m_NeuronsLinks.getAllWeights( weights );
			mutateWeights( weights );
			mutated->m_NeuronsLinks.setAllWeights( weights );
		}
		break;
		case 1:
		{
			mutateNeuronsFunctionsParams( mutated->m_Neurons );
		}
		break;
		case 2:
		{
			mutateChangeNeuronsFunctions( mutated->m_Neurons );
		}
		break;
		case 3:
		{
			vector<double> weights;
			mutated->m_NeuronsLinks.getAllWeights( weights );
			shuffleWeightsOnSubinterval(weights);
			mutated->m_NeuronsLinks.setAllWeights(weights);
		}
		break;
	}

	return mutated;
}

void OptimizableNeuralNetwork::mutateWeights(vector<double> & weights)
{
	int weightsSize = weights.size();
	int itersCount = rand() % weightsSize;
	if( itersCount == 0 )
	{
		itersCount = 1;
	}
	vector<int> used;
	for (int iter = 0; iter < itersCount; iter++)
	{
		int i = rand() % weightsSize;
		if( weightsSize > 1 )
		{
			while( find( used.begin(), used.end(), i ) != used.end() )
			{
				i = rand() % weightsSize;
			}
		}
		double w = weights[ i ];
		w += ( m_Random.nextGaussian() - m_Random.nextGaussian() ) * m_WeightsMutationInterval;
		// w += (this.random.nextdouble() - this.random.nextdouble()) *
		// weightsMutationInterval;
		weights[ i ] = w;
		used.push_back( i );
	}
}

void OptimizableNeuralNetwork::mutateNeuronsFunctionsParams(vector<Neuron> & neurons)
{
	int neuronsSize = neurons.size();
	int itersCount = rand() % neuronsSize;
	if (itersCount == 0)
	{
		itersCount = 1;
	}
	vector<int> used;
	for( int iter = 0 ; iter < itersCount ; iter++)
	{
		int i = rand() % neuronsSize;
		if( neuronsSize > 1 )
		{
			while( find( used.begin(), used.end(), i ) != used.end() )
			{
				i = rand() % neuronsSize;
			}
		}
		Neuron n = neurons[ i ];

		vector<double> params = n.getParams();
		for( unsigned int j = 0 ; j < params.size() ; j++)
		{
			double param = params[ j ];
			param += ( m_Random.nextGaussian() - m_Random.nextGaussian() ) * m_NeuronParamsMutationInterval;
			// param += (this.random.nextdouble() -
			// this.random.nextdouble()) * neuronParamsMutationInterval;
			params[ j ] = param;
		}
		n.setFunctionAndParams(n.getFunction(), params);
		used.push_back( i );
	}
}

void OptimizableNeuralNetwork::mutateChangeNeuronsFunctions( vector<Neuron> & neurons )
{
	int neuronsSize = neurons.size();
	int itersCount = rand() % neuronsSize;
	if( itersCount == 0 )
	{
		itersCount = 1;
	}
	vector<int> used;
	for( int iter = 0; iter < itersCount; iter++ )
	{
		int i = rand() % neuronsSize;
		if (neuronsSize > 1)
		{
			while( find( used.begin(), used.end(), i ) != used.end() )
			{
				i = rand() % neuronsSize;
			}
		}
		Neuron n = m_Neurons[ i ];
		ThresholdFunction * f = ThresholdFunctionManager::getInstance().getRandomFunction();
		n.setFunctionAndParams( f, f->getDefaultParams() );
		used.push_back( i );
	}
}

void OptimizableNeuralNetwork::shuffleWeightsOnSubinterval(vector<double> & weights)
{
	int left = rand() % weights.size();
	int right = rand() % weights.size();
	if( left > right )
	{
		int tmp = right;
		right = left;
		left = tmp;
	}
	vector<double> subListOfWeights( (right - left) + 1 );
	for( int i = 0 ; i < ((right - left) + 1) ; i++ )
	{
		subListOfWeights.push_back( weights[ left + i] );
	}
	random_shuffle( subListOfWeights.begin(), subListOfWeights.end() );
	for( int i = 0 ; i < ((right - left) + 1) ; i++ )
	{
		weights[ left + i ] = subListOfWeights[ i ];
	}
}





















