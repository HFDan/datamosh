#include <datamosh/format.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct image Jpeg_DetermineRealImageCoords(FILE* jpeg) {
	// Go to beginning of file
	fseek(jpeg, 0L, SEEK_SET);
	struct image img;
	// Repeteadly read 8 bits twice
	// See the jpeg standard: https://en.wikipedia.org/wiki/Jpeg
	uint8_t* token = calloc(2, sizeof(uint8_t));
	while (!feof(jpeg)) {  // Read from file until end
		fread(
			&token[0], sizeof(uint8_t), 1,
			jpeg);	// NOTE: We read token[0] and token[1] independently, so we
					// don't run into issues.

		switch (token[0]) {
			case 0xFF:	// 0xFF Denotes a possible marker following
				fread(&token[1], sizeof(uint8_t), 1, jpeg);
				switch (token[1]) {
					case 0xD8:	// 0xD8 after a 0xFF means SOI/Start Of Image

						break;

					case 0xD9:	// 0xD9 after a 0xFF means EOI/End Of Image
						img.end =
							ftell(jpeg) - 5;  // We decrement 5 just to be sure
						break;

					case 0xDA:	// 0xDA after 0xFF means SOS/Start Of Scan. This
								// should be the REAL start of the image
						img.start = ftell(jpeg) + 5;  // Increment 5 to be sure
						break;

					default:
						break;
				}
				break;

			default:
				break;
		}
	}

	return img;
}