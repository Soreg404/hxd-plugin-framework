#pragma once

#ifdef __cplusplus  
extern "C" {
#endif

#include "Shared.h"
#include <Windows.h>

__declspec(dllexport) BOOL __stdcall GetDataTypeConverterClassIDs(
	PConverterClassID *ClassIDsOrFactoryFuncs,
	int *Count);


__declspec(dllexport) void *__stdcall CreateConverter(
	TConverterClassID ClassIDOrFactoryFunc,
	const wchar_t **TypeName,
	const wchar_t **FriendlyTypeName,
	TDataTypeWidth *Width,
	int *MaxTypeSize,
	TByteOrders *SupportedByteOrders,
	BOOL *SupportsStrToBytes);

__declspec(dllexport) void __stdcall DestroyConverter(
	void *ThisPtr);

__declspec(dllexport) void __stdcall AssignConverter(
	void *ThisPtr,
	void *Source);


__declspec(dllexport) void __stdcall ChangeByteOrder(
	void *ThisPtr,
	uint8_t *Bytes,
	int ByteCount,
	TByteOrder TargetByteOrder);

__declspec(dllexport) TBytesToStrError __stdcall BytesToStr(
	void *ThisPtr,
	uint8_t *Bytes,
	int ByteCount,
	TIntegerDisplayOption IntegerDisplayOption,
	int *ConvertedByteCount,
	const wchar_t **ConvertedStr);

__declspec(dllexport) TStrToBytesError __stdcall StrToBytes(
	void *ThisPtr,
	const wchar_t *Str,
	TIntegerDisplayOption IntegerDisplayOption,
	uint8_t **ConvertedBytes,
	int *ConvertedByteCount);

#ifdef __cplusplus  
}
#endif
