/*
 * NeuralNetwork.h
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#ifndef NN_NEURALNETWORK_H_
#define NN_NEURALNETWORK_H_

#include "Neuron.h"
#include "Links.h"
#include "ThresholdFunctionSigma.h"

class NeuralNetwork
{
public:
	NeuralNetwork( const NeuralNetwork & src );
	NeuralNetwork & operator == ( const NeuralNetwork & src );
	virtual ~NeuralNetwork();

	vector<Neuron> m_Neurons;

	Links m_NeuronsLinks;

	int m_ActivationIterations;

	NeuralNetwork( int numberOfNeurons );

	void setNeuronFunction( int neuronNumber, ThresholdFunction * function, vector<double> params );

	void addLink(int activatorNeuronNumber, int receiverNeuronNumber, double weight);

	void putSignalToNeuron(int neuronIndx, double signalValue);

	double getAfterActivationSignal(int neuronIndx);

	void activate();
	void getWeightsOfLinks( vector<double> & weights );

	void setWeightsOfLinks( vector<double> & weights );
	vector<Neuron> & getNeurons();

	int getNeuronsCount();
	void setNeurons( vector<Neuron> & newNeurons );
	int getActivationIterations();
	void setActivationIterations(int activationIterations);
	Links & getNeuronsLinks();

private:

	ThresholdFunctionSigma m_DefaultThresholdFunction;

};

#endif /* NN_NEURALNETWORK_H_ */
