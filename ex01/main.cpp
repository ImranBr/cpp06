#include "Serialization.hpp"

int main(void)
{

	Data *data = new Data;
	data->name = "Peter";
	data->value = 42;

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);
	
    std::cout << serialized->value << std::endl;
	std::cout << serialized->name << std::endl;


	delete data;
	return (0);
}