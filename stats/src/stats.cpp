#include "stats.h"
#include <cassert>

namespace main_savitch_2C
{
	statistician::statistician()
	{
		reset();
	}

	void statistician::next_number(double nextNum)
	{
		if (count <= 0)
		{
			count = 1;
			total = nextNum;
			tinyest = nextNum;
			largest = nextNum;
			return;
		}

		else
		{
			count += 1;
			total += nextNum;

			if (nextNum < tinyest)
				tinyest = nextNum;

			if (nextNum > largest)
				largest = nextNum;
		}

		mean();
	}

	void statistician::reset()
	{
		count = 0;
		total = 0;
		tinyest = 0;
		largest = 0;

	}

	double statistician::mean() const
	{
		assert(count > 0);
		return total / count;
	}

	double statistician::minimum() const
	{
		assert(count > 0);
		return tinyest;
	}

	double statistician::maximum() const
	{
		assert(count > 0);
		return largest;

	}
	statistician operator +(const statistician& s1, const statistician& s2)
	{
		statistician r;

		if (s1.length() == 0)
			return s2;
		if (s2.length() == 0)
			return s1;
		r.count = s1.length() + s2.length();
		r.total = s1.length() * s1.mean() + s2.length() * s2.mean();
		if (s1.minimum() < s2.minimum())
			r.tinyest = s1.minimum();
		else r.tinyest = s2.minimum();
		if (s1.maximum() > s2.maximum())
			r.largest = s1.maximum();
		else r.largest = s2.maximum();
		return r;
	}
	bool operator ==(const statistician& s1, const statistician& s2)
	{
	    if ((s1.length( ) == 0) || (s2.length( ) == 0))
	        return (s1.length( ) == 0) && (s2.length( ) == 0);
	    else return (s1.length( ) == s2.length( ))
	            &&  (s1.mean( ) == s2.mean( ))
		    &&  (s1.minimum( ) == s2.minimum( ))
		    &&  (s1.maximum( ) == s2.maximum( ))
		    &&  (s1.sum( ) == s2.sum( ));

	}
	statistician operator *(double scale, const statistician& s)
	{
	    statistician answer;

	    answer.count = s.count;
	    answer.total = scale * s.total;
	    if (scale >= 0)
	    {
		answer.tinyest = scale * s.tinyest;
		answer.largest = scale * s.largest;
	    }
	    else
	    {
		answer.tinyest = scale * s.largest;
		answer.largest = scale * s.tinyest;
	    }
	    return answer;
	}
}
