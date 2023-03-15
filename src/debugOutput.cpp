#define _CRT_SECURE_NO_WARNINGS																						// Disables warnings for functions that are deemed insecure by the standard. It's only for _itoa, which I am using safely, so I can turn of the warnings.

#include "../include/logging/debugOutput.h"

#include <Windows.h>

#include <cstdint>
#include <cstdlib>																									// This is included because we need access to _itoa.
#include <string>

const DebugOutput& DebugOutput::operator<<(const char* input) const {
#ifndef _DEBUG
	return *this;
#endif
	OutputDebugStringA(input);
	return *this;
}

const DebugOutput& DebugOutput::operator<<(char* input) const {
#ifndef _DEBUG
	return *this;
#endif
	OutputDebugStringA(input);
	return *this;
}

const DebugOutput& DebugOutput::operator<<(char input) const {
#ifndef _DEBUG
	return *this;
#endif
	char buffer[] = { input, '\0' };																				// List initialization of basic types is apparently just as efficient as doing it per hand, contrary to custom types and such. Use equal sign because that makes it compatible with C.
	OutputDebugStringA(buffer);
	return *this;
}

const DebugOutput& DebugOutput::operator<<(std::string& input) const {
#ifndef _DEBUG
	return *this;
#endif
	OutputDebugStringA(input.c_str());
	return *this;
}

const DebugOutput& DebugOutput::operator<<(int32_t input) const {
#ifndef _DEBUG
	return *this;
#endif
	char buffer[12];																								// Maximum length that an int32_t could have when expressed as a string.
	_itoa(input, buffer, 10);
	OutputDebugStringA(buffer);
	return *this;
}

const DebugOutput& DebugOutput::operator<<(uint32_t input) const {
#ifndef _DEBUG
	return *this;
#endif
	char buffer[11];																								// Maximum length that a uint32_t could have when expressed as a string.
	_itoa(input, buffer, 10);
	OutputDebugStringA(buffer);
	return *this;
}

const DebugOutput& DebugOutput::operator<<(int16_t input) const {
#ifndef _DEBUG
	return *this;
#endif
	char buffer[7];
	_itoa(input, buffer, 10);
	OutputDebugStringA(buffer);
	return *this;
}