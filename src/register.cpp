#include "core/Shared.h"

#include "converters/Int32Converter.h"

#include "converters/example.hpp"

std::vector<TConverterClassID> EntryPoint() {
	return {

		TInt32Converter::Create,

		ExampleConverter::Create

	};
}