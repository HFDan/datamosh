#pragma once
#include <stdbool.h>

/**
 * @brief Get option by argument
 *
 * @param short_arg The argument to look for (short)
 * @param long_arg The argument to look for (long)
 * @param argc The argument count
 * @param argv The argument vector
 * @param required Not implemented
 * @return char* Will return NULL if argument does not exist
 */
const char* get_option(
	const char* short_arg, const char* long_arg, const int argc,
	const char** argv, bool required);

/**
 * @brief Does option exist?
 *
 * @param short_arg The argument to look for (short)
 * @param long_arg The argument to look for (long)
 * @param argc The argument count
 * @param argv The argument vector
 * @param required Not implemented
 * @return true If the argument is found
 * @return false If the argument is not found
 */
bool option_exists(
	const char* short_arg, const char* long_arg, int argc, const char** argv,
	bool required);