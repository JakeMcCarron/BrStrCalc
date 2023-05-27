#pragma once
#include <string>
#include <map>
#include <optional>
#include <variant>

class VariableHandler
{

	public:
		template<typename T>
		bool AddToMap(const std::wstring var, T val)
		{
			if (VariableHandler::RetrieveFromMap<T>(var).has_value())
			{
				return false;
			}
			varValMap.insert(std::make_pair(var, val));
			return true;
		}
	
		template<typename T>
		void AddToMapOverride(const std::wstring var, const T val)
		{
			varValMap.insert_or_assign(var, val);
		}
	
		template<typename T>
		std::optional<T> RetrieveFromMap(const std::wstring var)
		{
			for (auto varVal : varValMap)
			{
				if (var == varVal.first)
					return std::optional<T>(std::get<T>(varVal.second));
			}
			return std::nullopt;
		}
	
private:
	std::map<std::wstring, std::variant<long long, double>> varValMap;
};

