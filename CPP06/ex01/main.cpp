#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data originalData;
	originalData.value = 42;
	originalData.name = "Test";

	Data* originalPtr = &originalData;
	uintptr_t serialized = Serializer::serialize(originalPtr);
	Data* deserializedPtr = Serializer::deserialize(serialized);

	// Check that pointers are equal
	std::cout << "Original pointer: " << originalPtr << std::endl;
	std::cout << "Serialized value: " << serialized << std::endl;
	std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;

	if (originalPtr == deserializedPtr)
		std::cout << "SUCCESS: Pointers are equal!" << std::endl;
	else
		std::cout << "ERROR: Pointers are different!" << std::endl;

	return 0;
}
