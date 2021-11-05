#pragma once
#include <stdbool.h>

/**
 * @brief Get option by argument
 *
 * @param arg The argument to look for
 * @param argc The argument count
 * @param argv The argument vector
 * @return char* Will return NULL if argument does not exist
 */
const char* get_option(
	const char* short_arg, const char* long_arg, const int argc,
	const char** argv);

/**
 * @brief Does option exist?
 *
 * @param arg The argument to look for
 * @param argc The argument count
 * @param argv The argument vector
 * @return true If the argument is found
 * @return false If the argument is not found
 */
bool option_exists(const char* arg, int argc, const char** argv);