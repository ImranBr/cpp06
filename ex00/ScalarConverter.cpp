#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string &str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		return (true);
	return (false);
}

void ScalarConverter::convert(const std::string &literal)
{
	std::cout << literal << std::endl;
}

// {
// 	bool isFinite = false;
// 	double value = 0.0;

// 	if (literal.empty())
// 	{
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl;
// 		std::cout << "float: impossible" << std::endl;
// 		std::cout << "double: impossible" << std::endl;
// 		return;
// 	}

// 	if (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
// 	{
// 		value = static_cast<unsigned char>(literal[0]);
// 		isFinite = true;
// 	}
// 	else if (literal == "nan" || literal == "nanf")
// 	{
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl;
// 		std::cout << "float: nanf" << std::endl;
// 		std::cout << "double: nan" << std::endl;
// 		return;
// 	}
// 	else if (literal == "+inf" || literal == "+inff")
// 	{
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl;
// 		std::cout << "float: inff" << std::endl;
// 		std::cout << "double: inf" << std::endl;
// 		return;
// 	}
// 	else if (literal == "-inf" || literal == "-inff")
// 	{
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl;
// 		std::cout << "float: -inff" << std::endl;
// 		std::cout << "double: -inf" << std::endl;
// 		return;
// 	}
// 	else
// 	{
// 		char *end = 0;
// 		std::string numeric = literal;
// 		if (numeric.size() > 0 && numeric[numeric.size() - 1] == 'f')
// 			numeric.erase(numeric.size() - 1);

// 		value = std::strtod(numeric.c_str(), &end);
// 		if (end == numeric.c_str() || *end != '\0')
// 		{
// 			std::cout << "char: impossible" << std::endl;
// 			std::cout << "int: impossible" << std::endl;
// 			std::cout << "float: impossible" << std::endl;
// 			std::cout << "double: impossible" << std::endl;
// 			return;
// 		}
// 		isFinite = (value == value
// 			&& value != std::numeric_limits<double>::infinity()
// 			&& value != -std::numeric_limits<double>::infinity());
// 	}

// 	std::cout << "char: ";
// 	if (!isFinite || value < 0 || value > 127)
// 	{
// 		std::cout << "impossible" << std::endl;
// 	}
// 	else
// 	{
// 		char c = static_cast<char>(value);
// 		if (std::isprint(static_cast<unsigned char>(c)))
// 			std::cout << '\'' << c << '\'' << std::endl;
// 		else
// 			std::cout << "Non displayable" << std::endl;
// 	}

// 	std::cout << "int: ";
// 	if (!isFinite
// 		|| value < static_cast<double>(std::numeric_limits<int>::min())
// 		|| value > static_cast<double>(std::numeric_limits<int>::max()))
// 	{
// 		std::cout << "impossible" << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << static_cast<int>(value) << std::endl;
// 	}

// 	std::ostringstream floatStream;
// 	floatStream << value;
// 	std::string floatResult = floatStream.str();
// 	if (floatResult.find('.') == std::string::npos && floatResult.find('e') == std::string::npos && floatResult.find('E') == std::string::npos)
// 		floatResult += ".0";
// 	floatResult += 'f';

// 	std::ostringstream doubleStream;
// 	doubleStream << value;
// 	std::string doubleResult = doubleStream.str();
// 	if (doubleResult.find('.') == std::string::npos && doubleResult.find('e') == std::string::npos && doubleResult.find('E') == std::string::npos)
// 		doubleResult += ".0";

// 	std::cout << "float: " << floatResult << std::endl;
// 	std::cout << "double: " << doubleResult << std::endl;
// }