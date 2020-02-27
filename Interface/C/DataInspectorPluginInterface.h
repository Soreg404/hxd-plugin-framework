#pragma once

#ifdef __cplusplus  
extern "C" {
#endif

#include "Windows.h"
#include "DataInspectorShared.h"

void* __stdcall CreateConverter(
	TConverterClassID ClassIdOrFactoryFunc,
	const wchar_t** TypeName,
	const wchar_t** FriendlyTypeName,
	TDataTypeWidth* Width,
	int* MaxTypeSize,
	TByteOrders* SupportedByteOrders);

void __stdcall DestroyConverter(
	void* ThisPtr);

void __stdcall AssignConverter(
	void* ThisPtr,
	void* Source);

void __stdcall ChangeByteOrder(
	void* ThisPtr,
	uint8_t* Bytes,
	int ByteCount,
	TByteOrder TargetByteOrder);

TBytesToStrError __stdcall BytesToStr(
	void* ThisPtr,
	uint8_t* Bytes,
	int ByteCount,
	TIntegerDisplayOption IntegerDisplayOption,
	int* ConvertedByteCount,
	const wchar_t** ConvertedStr);

TStrToBytesError __stdcall StrToBytes(
	void* ThisPtr,
	const wchar_t* Str,
	TIntegerDisplayOption IntegerDisplayOption,
	uint8_t** ConvertedBytes,
    int* ConvertedByteCount);

BOOL __stdcall GetDataTypeConverterClassIDs(
	PConverterClassID* ClassIdsOrFactoryFuncs,
	int* Count);

#ifdef __cplusplus  
}
#endif
