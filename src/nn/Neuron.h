/*
 * Neuron.h
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#ifndef NN_NEURON_H_
#define NN_NEURON_H_

#include "ThresholdFunction.h"
#include <vector>
using namespace std;

class Neuron
{
public:
	Neuron( ThresholdFunction * function );
	virtual ~Neuron();

	double m_InputSignal;

	double m_AfterActivationSignal;

	ThresholdFunction * m_ThresholdFunction;

	vector<double> m_Params;

	void setFunctionAndParams( ThresholdFunction * function, vector<double> & params );
	void addSignal(double value);
	void activate();
	double getAfterActivationSignal();

	ThresholdFunction * getFunction();
	vector<double> getParams();
};

#endif /* NN_NEURON_H_ */
