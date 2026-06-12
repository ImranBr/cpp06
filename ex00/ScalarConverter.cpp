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

static bool isChar(const std::string &str)
{
	if (str.length() == 1)
	{
		if (!std::isdigit(str[0]))
		return (true);
	}
	return (false);
}

static bool isInt(const std::string &str)
{
	size_t i = 0;

	if (str.empty())
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.length())
		return (false);
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool isFloat(const std::string &str)
{
	char *end;
	std::strtod(str.c_str(), &end);
	
	if (str == "nanf"|| str == "+inff" || str == "-inff")
		return (true);
	if (*end == 'f' && *(end + 1) == '\0')
		return (true);
	return (false);
}

bool isDouble(const std::string &str)
{
	char *end;

	if (str == "nan" || str == "+inf" || str == "-inf")
		return (true);
	std::strtod(str.c_str(), &end);
	if (*end != '\0')
		return (false);
	if (str.find('.') == std::string::npos)
		return (false);
	return (true);

}

static void convertFromInt(int value)
{
	// CHAR
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(value);

		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	// INT
	std::cout << "int: " << value << std::endl;

	// FLOAT
	float f = static_cast<float>(value);
	std::cout << "float: "
			  << std::fixed << std::setprecision(1)
			  << f << "f" << std::endl;

	// DOUBLE
	double d = static_cast<double>(value);
	std::cout << "double: "
			  << std::fixed << std::setprecision(1)
			  << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isPseudoLiteral(literal))
	{
		std::cout << "Pseudo literal detected" << std::endl;
		return;	
	}
	// std::cout << "Not a pseudo literal : " << literal << std::endl;
	else if (isChar(literal))
	{
		std::cout << "Char detected" << std::endl;
		return;
	}
	// std::cout << "Not a char: " << literal << std::endl;
	else if (isInt(literal))
	{
		std::cout << "Int detected" << std::endl;
		int value = std::atoi(literal.c_str());
		convertFromInt(value);
		return;
	}
	// std::cout << "Not an int: " << literal << std::endl;
	if (isFloat(literal))
	{
		std::cout << "Float detected" << std::endl;
		return;	
	}
	// std::cout << "Not a Float: " << literal << std::endl;
	if (isDouble(literal))
	{
		std::cout << "Double detected" << std::endl;
		return;	
	}
	// std::cout << "Not a Double: " << literal << std::endl;
}

	// int minc = std::numeric_limits<char>::min();
    // int maxc = std::numeric_limits<char>::max();
    // std::cout << minc << std::endl;
    // std::cout << maxc << std::endl;