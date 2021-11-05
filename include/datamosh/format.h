#pragma once

struct image {
	long start;
	long end;
};

enum fileFormat { JPG, UNSUPPORTED };

enum fileFormat DetermineFileFormat(const char* fileName);