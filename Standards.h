#ifndef STANDARDS_H
#define STANDARDS_H
#include "CompoundingMethod.h"
#include "InterpolationMethods.h"
#include <vector>
#include "boost/date_time/gregorian/gregorian.hpp"


namespace BondPricer
{
	typedef std::vector <boost::gregorian::date> DateVector;
	typedef std::vector <double> DoubleVector;
	typedef DateVector::const_iterator v_Date_Const_Iter;
	typedef std::map <boost::gregorian::date, double>::const_iterator m_Date_Const_Iter;
	typedef std::map<boost::gregorian::date, double>::iterator m_Date_Iter;

	
}


#endif // !STANDARDS_H
