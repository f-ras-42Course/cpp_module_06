#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "=== Serializer Test ===\n\n";
		std::cerr << "Usage: " << argv[0] << " <id> <message> <value>\n";
		std::cerr << "Example: " << argv[0] << " 69 \"Some Message\" 3.14159265358\n";
		return 1;
	}

	Data originalData(atoi(argv[1]), argv[2], atof(argv[3]));
	Data* originalPtr = &originalData;

	std::cout << "Original pointer: " << originalPtr << "\n";
	std::cout << "Original Data:\n";
	std::cout << "  Pointer Address: " << originalPtr << "\n";
	std::cout << "  ID: " << originalData.id_ << "\n";
	std::cout << "  Message: " << originalData.message_ << "\n";
	std::cout << "  Value: " << originalData.value_ << "\n\n";
	
	uintptr_t serialized = Serializer::serialize(originalPtr);
	std::cout << "Value of serialized pointer: " << serialized << "\n";
	std::cout << "Serialized value in hex: 0x" << std::hex << serialized << std::dec << "\n\n";
	
	Data* deserializedPtr = Serializer::deserialize(serialized);

	std::cout << "Deserialized pointer: " << deserializedPtr << "\n";
	std::cout << "Deserialized Data:\n";
	std::cout << "  Pointer Address: " << deserializedPtr << "\n";
	std::cout << "  ID: " << deserializedPtr->id_ << "\n";
	std::cout << "  Message: " << deserializedPtr->message_ << "\n";
	std::cout << "  Value: " << deserializedPtr->value_ << "\n\n";

	if (originalPtr == deserializedPtr) {
		std::cout << "Serialization successful!\n";
	} else {
		std::cout << "Serialization failed!\n";
	}
	
	return 0;
}
