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

static void convertFromChar(char value)
{
	// CHAR
	std::cout << "char: '" << value << "'" << std::endl;

	// INT
	int i = static_cast<int>(value);
	std::cout << "int: " << i << std::endl;

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

static void convertFromFloat(float value)
{
	// CHAR
	if (std::isnan(value)
		|| std::isinf(value)
		|| value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(value);

		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	// INT
	if (std::isnan(value)
		|| std::isinf(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		int i = static_cast<int>(value);
		std::cout << "int: " << i << std::endl;
	}

	// FLOAT
	std::cout << "float: "
			  << std::fixed << std::setprecision(1)
			  << value << "f" << std::endl;

	// DOUBLE
	double d = static_cast<double>(value);

	std::cout << "double: "
			  << std::fixed << std::setprecision(1)
			  << d << std::endl;
}

static void convertFromDouble(double value)
{
	// CHAR
	if (std::isnan(value)
		|| std::isinf(value)
		|| value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(value);

		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	// INT
	if (std::isnan(value)
		|| std::isinf(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		int i = static_cast<int>(value);
		std::cout << "int: " << i << std::endl;
	}

	// FLOAT
	float f = static_cast<float>(value);

	std::cout << "float: "
			  << std::fixed << std::setprecision(1)
			  << f << "f" << std::endl;

	// DOUBLE
	std::cout << "double: "
			  << std::fixed << std::setprecision(1)
			  << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isPseudoLiteral(literal))
	{
		std::cout << "Pseudo literal detected" << std::endl;
		return;	
	}
	else if (isChar(literal))
	{
		std::cout << "Char detected" << std::endl;
		char value = literal[0];
		convertFromChar(value);
		return;
	}
	else if (isInt(literal))
	{
		std::cout << "Int detected" << std::endl;
		int value = std::atoi(literal.c_str());
		convertFromInt(value);
		return;
	}
	if (isFloat(literal))
	{
		std::cout << "Float detected" << std::endl;
		float value = static_cast<float>(std::strtod(literal.c_str(), NULL));
		convertFromFloat(value);
		return;	
	}
	if (isDouble(literal))
	{
		std::cout << "Double detected" << std::endl;
		double value = std::strtod(literal.c_str(), NULL);
		convertFromDouble(value);
		return;	
	}
	std::cout << "Invalid literal" << std::endl;
}

	// int minc = std::numeric_limits<char>::min();
    // int maxc = std::numeric_limits<char>::max();
    // std::cout << minc << std::endl;
    // std::cout << maxc << std::endl;