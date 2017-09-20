#ifndef BONDPRICER_H
#define BONDPRICER_H

#include "Bond.h"

namespace BondPricer
{

	class BondPricer
	{
	public:
		BondPricer();
		~BondPricer();
		double CalculatePV(const Bond& bond);

	private:
		std::map<int, double> discount_crv;
		
	};



}//namespace BondPricer



#endif // !BONDPRICER_H
