#pragma once
#include "core/Server.h"

#include <ctime>

class ExampleConverter: public TExternalDataTypeConverter {

public:
	// Class factory function / virtual constructor
	inline static TExternalDataTypeConverter *Create() { return new ExampleConverter; }

public:
	ExampleConverter() {
		FTypeName = L"Example converter";
		FFriendlyTypeName = FTypeName;
		FWidth = dtwFixed;
		FMaxTypeSize = sizeof(char32_t);
		FSupportedByteOrders = 1 << boLittleEndian | 1 << boBigEndian;
		FSupportsStrToBytes = TRUE;
	}

	void ChangeByteOrder(
		uint8_t *Bytes,
		int ByteCount,
		TByteOrder TargetByteOrder
	) override {
		// ?
	}

	TBytesToStrError BytesToStr(
		uint8_t *Bytes,
		int ByteCount,
		TIntegerDisplayOption IntegerDisplayOption,
		int &ConvertedByteCount,
		std::wstring &ConvertedStr
	) override {
		
		if(ByteCount < FMaxTypeSize) {
			ConvertedByteCount = 0;
			ConvertedStr = L"too few bytes!"; // Warning: do not return NULL, this will throw exceptions
			return btseBytesTooShort;
		}

		ConvertedByteCount = FMaxTypeSize;

		ConvertedStr = L"Hello world!";

		return btseNone;

	}

	TStrToBytesError StrToBytes(
		std::wstring Str,
		TIntegerDisplayOption IntegerDisplayOption,
		std::vector<uint8_t> &ConvertedBytes
	) override {

		srand(time(NULL));
		ConvertedBytes = {
			static_cast<uint8_t>(rand()),
			static_cast<uint8_t>(rand()),
			static_cast<uint8_t>(rand()),
			static_cast<uint8_t>(rand())
		};
		return stbeNone;

	}

};