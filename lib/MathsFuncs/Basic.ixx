export module BasicMaths;

export template<typename T> T Addition(const T x, const T y)
{
	return x + y;
};
export template<typename T> T Subtraction(const T x, const T y)
{
	return x - y;
};
export template<typename T> T Multiplication(const T x, const T y)
{
	return x * y;
};
export template<typename T> T Division(const T x, const T y)
{
	if (y == 0)
		return 0;
	
	return x / y;
};