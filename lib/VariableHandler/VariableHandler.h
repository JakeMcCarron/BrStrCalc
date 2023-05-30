#pragma once
#include <string>
#include <map>
#include <optional>

//Maintains a map based on a varible (std::wstring) and a value (stored as a double - means they can only be so many digits).
class VariableHandler
{
	public:

		inline bool AddToMap(const std::wstring var, const double val)
		{
			if (VariableHandler::RetrieveFromMap(var).has_value())
			{
				return false;
			}
			varValMap.insert(std::make_pair(var, static_cast<double>(val)));
			return true;
		}
	
		inline void AddToMapOverride(const std::wstring var, const double val)
		{
			varValMap.insert_or_assign(var, static_cast<double>(val));
		}
	
		inline std::optional<double> RetrieveFromMap(const std::wstring var)
		{
			for (auto varVal : varValMap)
			{
				if (var == varVal.first)
					return std::optional<double>(varVal.second);
			}
			return std::nullopt;
		}

		inline auto GetFullMap()
		{
			return varValMap;
		}
	
private:
	std::map<std::wstring, double> varValMap;
};

