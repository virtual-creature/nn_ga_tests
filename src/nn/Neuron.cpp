/*
 * Neuron.cpp
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#include "Neuron.h"
#include <cassert>
using namespace std;

Neuron::~Neuron()
{
}

Neuron::Neuron( ThresholdFunction * function )
{
	setFunctionAndParams( function, function->getDefaultParams() );
}

void Neuron::setFunctionAndParams( ThresholdFunction * function, vector<double> & params)
{
	if( params.size() != function->getDefaultParams().size() )
	{
		assert( false );
//		throw new IllegalArgumentException("Function needs " + function.getDefaultParams().size()
//				+ " parameters. But params count is " + params.size());
	}
	m_ThresholdFunction = function;
	m_Params = params;
}

void Neuron::addSignal(double value)
{
	m_InputSignal += value;
}

void Neuron::activate()
{
	m_AfterActivationSignal = m_ThresholdFunction->calculate( m_InputSignal, m_Params );
	m_InputSignal = 0;
}

double Neuron::getAfterActivationSignal()
{
	return m_AfterActivationSignal;
}

ThresholdFunction * Neuron::getFunction()
{
	return m_ThresholdFunction;
}

vector<double> Neuron::getParams()
{
	return m_Params;
}






















