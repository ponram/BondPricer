#ifndef BOND_H
#define BOND_H
#include <string>
#include <map>
#include "boost/date_time/gregorian/gregorian.hpp"

namespace BondPricer
{
	class Bond
	{
	public:
		Bond();
		Bond(double notional
			,double redemption
			,std::string currency
			,double rate
			,int freq
			,boost::gregorian::date issue
			, boost::gregorian::date maturity);
		~Bond();
	private:
		double notional;
		double redemption_price;
		std::string currency;
		double rate;
		int cpn_freq_months;
		std::string bond_type;
		boost::gregorian::date issue_date;
		boost::gregorian::date maturity_date;
		std::map <boost::gregorian::date, double> cashflows;
	};

	inline Bond::Bond()
	{
		notional = 0;
		redemption_price = 0;
		currency = "USD";
		rate = 0;
		cpn_freq_months = 0;
		bond_type = "FIXED";
	}

	inline Bond::~Bond() {}


}//namespace BondPricer


#endif // !BOND_H

