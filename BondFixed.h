#ifndef BONDFIXED_H
#define BONDFIXED_H

#include "Bond.h"
#include <string>

namespace BondPricer
{
	class BondFixed :public Bond
	{
	public:
		BondFixed();
		~BondFixed();
	private:
		std::string bond_type;


	};
	
	inline BondFixed::~BondFixed(){}

}//namespace BondPricer

#endif // !BONDFIXED_H

