export module PiFuncs;

import BasicMaths;
import <vector>;
import <cmath>;

//Needs better bitlength data types to work properly. GMP??
long double ChudnovskyAlgorithm(long long q)
{
	long long numerator = (Factorial(6 * q)) * ((545140134 * q) + 13591409);
	long long denominator = (Factorial(3 * q)) * (powll(Factorial(q), 3)) * (powll(-262537412640768000, q));

	return static_cast<double>(numerator / denominator);
}

export long double CalcPi(int iterations, int threadCount)
{
	std::vector<long double> toSum;
	for (auto i = 0; i < iterations; ++i)
	{
		toSum.push_back(ChudnovskyAlgorithm(i));
	}

	long double ret = 0;
	for (auto& val : toSum)
	{
		ret += val;
	}
	return (426880 * std::sqrt(10005))/ret;
}


