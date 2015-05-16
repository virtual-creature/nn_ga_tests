/*
 * ThresholdFunctionManager.cpp
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#include "ThresholdFunctionManager.h"
#include <cstdlib>

ThresholdFunctionManager::ThresholdFunctionManager()
{
	m_AllFunctions.push_back( new ThresholdFunctionSigma() );
}

ThresholdFunctionManager::~ThresholdFunctionManager()
{
}

ThresholdFunction * ThresholdFunctionManager::getRandomFunction()
{
	return ( m_AllFunctions[ rand() % m_AllFunctions.size() ] );
}

ThresholdFunctionManager & ThresholdFunctionManager::getInstance()
{
	static ThresholdFunctionManager instance;
	return instance;
}























