export module PiFuncs;

import BasicMaths;
import <vector>;
import <cmath>;


double ChudnovskyAlgorithm(long long q)
{
	double numerator = (Factorial(6 * q)) * ((545140134 * q) + 13591409);
	double denominator = (Factorial(3 * q)) * (std::pow(Factorial(q), 3)) * (std::pow(-262537412640768000, q));
	return numerator / denominator;
}

export double CalcPi(int iterations, int threadCount)
{
	std::vector<double> toSum;
	for (auto i = 0; i < iterations; ++i)
	{
		toSum.push_back(ChudnovskyAlgorithm(i));
	}

	double ret = 0;
	for (auto& val : toSum)
	{
		ret += val;
	}
	return (426880 * std::sqrt(10005))/ret;
}


