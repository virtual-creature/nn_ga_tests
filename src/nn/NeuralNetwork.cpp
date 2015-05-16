/*
 * NeuralNetwork.cpp
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#include "NeuralNetwork.h"
#include <cassert>
using namespace std;

NeuralNetwork::NeuralNetwork( int numberOfNeurons ) : m_ActivationIterations( 1 )
{
	for (int i = 0; i < numberOfNeurons; i++)
	{
		m_Neurons.push_back( Neuron( &m_DefaultThresholdFunction ) );
	}
}

NeuralNetwork::NeuralNetwork( const NeuralNetwork & src )
{
	m_ActivationIterations = src.m_ActivationIterations;
	m_DefaultThresholdFunction = src.m_DefaultThresholdFunction;
	m_Neurons = src.m_Neurons;
	m_NeuronsLinks = src.m_NeuronsLinks;
}

NeuralNetwork & NeuralNetwork::operator == ( const NeuralNetwork & src )
{
	if( this == &src )
	{
		return * this;
	}
	m_ActivationIterations = src.m_ActivationIterations;
	m_DefaultThresholdFunction = src.m_DefaultThresholdFunction;
	m_Neurons = src.m_Neurons;
	m_NeuronsLinks = src.m_NeuronsLinks;

	return *this;
}

NeuralNetwork::~NeuralNetwork()
{
}

void NeuralNetwork::setNeuronFunction( int neuronNumber, ThresholdFunction * function, vector<double> params )
{
	if( neuronNumber >= (int)m_Neurons.size() )
	{
		assert( false );
//		throw new RuntimeException("Neural network has " + this.neurons.size()
//				+ " neurons. But there was trying to accsess neuron with index " + neuronNumber);
	}
	m_Neurons[ neuronNumber ].setFunctionAndParams( function, params );
}

void NeuralNetwork::addLink(int activatorNeuronNumber, int receiverNeuronNumber, double weight)
{
	m_NeuronsLinks.addWeight( activatorNeuronNumber, receiverNeuronNumber, weight );
}

void NeuralNetwork::putSignalToNeuron(int neuronIndx, double signalValue)
{
	if( neuronIndx >= (int)m_Neurons.size() )
	{
		assert( false );
	}
	m_Neurons[ neuronIndx ].addSignal(signalValue);
}

double NeuralNetwork::getAfterActivationSignal( int neuronIndx )
{
	if( neuronIndx >= (int)m_Neurons.size() )
	{
		assert( false );
	}

	return m_Neurons[ neuronIndx ].getAfterActivationSignal();
}

void NeuralNetwork::activate()
{
	for( int iter = 0 ; iter < m_ActivationIterations ; iter++ )
	{
		for( unsigned int i = 0 ; i < m_Neurons.size() ; i++ ) {

			Neuron activator = m_Neurons[i];
			activator.activate();
			double activatorSignal = activator.getAfterActivationSignal();

			vector<int> receivers = m_NeuronsLinks.getReceivers( i );

			for( unsigned int receiver_i = 0 ; receiver_i < receivers.size() ; receiver_i++ )
			{
				int receiverNum = receivers[receiver_i];
				if( receiverNum >= (int)m_Neurons.size() )
				{
					assert( false );
//					throw new RuntimeException("Neural network has " + this.neurons.size()
//							+ " neurons. But there was trying to accsess neuron with index " + receiverNum);
				}
				Neuron receiver = m_Neurons[receiverNum];
				double weight = m_NeuronsLinks.getWeight(i, receiverNum);
				receiver.addSignal(activatorSignal * weight);
			}
		}
	}
}

void NeuralNetwork::getWeightsOfLinks( vector<double> & weights )
{
	m_NeuronsLinks.getAllWeights( weights );
}

void NeuralNetwork::setWeightsOfLinks( vector<double> & weights )
{
	m_NeuronsLinks.setAllWeights( weights );
}

vector<Neuron> & NeuralNetwork::getNeurons()
{
	return m_Neurons;
}

int NeuralNetwork::getNeuronsCount()
{
	return m_Neurons.size();
}

void NeuralNetwork::setNeurons( vector<Neuron> & newNeurons )
{
	m_Neurons = newNeurons;
}

int NeuralNetwork::getActivationIterations()
{
	return m_ActivationIterations;
}

void NeuralNetwork::setActivationIterations(int activationIterations)
{
	m_ActivationIterations = activationIterations;
}

Links & NeuralNetwork::getNeuronsLinks()
{
	return m_NeuronsLinks;
}



















