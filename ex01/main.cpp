#include "Serialization.hpp"

int	main(void)
{
	Data		data;
	Data		*ptr;
	uintptr_t	raw;

	data.name = "Imran";
	data.age = 24;
	data.score = 99.5;

	ptr = &data;

	std::cout << "Original pointer:     " << ptr << std::endl;

	raw = Serializer::serialize(ptr);
	std::cout << "Serialized value:     " << raw << std::endl;

	ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << ptr << std::endl;

	std::cout << std::endl;

	if (ptr == &data)
		std::cout << "Success: pointers are equal" << std::endl;
	else
		std::cout << "Error: pointers are different" << std::endl;

	std::cout << std::endl;
	std::cout << "Name:  " << ptr->name << std::endl;
	std::cout << "Age:   " << ptr->age << std::endl;
	std::cout << "Score: " << ptr->score << std::endl;

	return (0);
}