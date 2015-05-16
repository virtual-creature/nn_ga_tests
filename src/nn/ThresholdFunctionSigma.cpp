/*
 * ThresholdFunctionSigma.cpp
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#include "ThresholdFunctionSigma.h"
#include <cmath>

ThresholdFunctionSigma::ThresholdFunctionSigma()
{
	double a = 1;
	double b = 1;
	double c = 1;
	m_DefaultParams.push_back( a );
	m_DefaultParams.push_back( b );
	m_DefaultParams.push_back( c );
}

ThresholdFunctionSigma::~ThresholdFunctionSigma()
{
}

double ThresholdFunctionSigma::calculate(double value, vector<double> & params)
{
	double a = params[0];
	double b = params[1];
	double c = params[2];
	return a / (b + expm1(-value * c) + 1);
}

vector<double> & ThresholdFunctionSigma::getDefaultParams()
{
	return m_DefaultParams;
}



















