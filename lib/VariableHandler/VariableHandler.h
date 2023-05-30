#pragma once
#include <string>
#include <map>
#include <optional>

class VariableHandler
{

	public:

		bool AddToMap(const std::wstring var, const double val)
		{
			if (VariableHandler::RetrieveFromMap(var).has_value())
			{
				return false;
			}
			varValMap.insert(std::make_pair(var, static_cast<double>(val)));
			return true;
		}
	
		void AddToMapOverride(const std::wstring var, const double val)
		{
			varValMap.insert_or_assign(var, static_cast<double>(val));
		}
	
		std::optional<double> RetrieveFromMap(const std::wstring var)
		{
			for (auto varVal : varValMap)
			{
				if (var == varVal.first)
					return std::optional<double>(varVal.second);
			}
			return std::nullopt;
		}

		auto GetFullMap()
		{
			return varValMap;
		}
	
private:
	std::map<std::wstring, double> varValMap;
};

