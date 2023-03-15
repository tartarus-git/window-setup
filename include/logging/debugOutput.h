#pragma once

#include <cstdint>
#include <string>

class DebugOutput {
public:
	const DebugOutput& operator<<(const char* input) const;
	const DebugOutput& operator<<(char* input) const;
	const DebugOutput& operator<<(char input) const;

	const DebugOutput& operator<<(std::string& input) const;

	const DebugOutput& operator<<(int32_t input) const;
	const DebugOutput& operator<<(uint32_t input) const;
	const DebugOutput& operator<<(int16_t input) const;
};

namespace debuglogger {
	inline DebugOutput out;

	inline const char* error = "ERROR: ";
}
