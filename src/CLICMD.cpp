#include "../include/CLICMD.h"

#include <algorithm>

CLICMD::CLICMD() : valid(false) {}

void CLICMD::parse_args(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		string str = string(argv[i]);
		
		if (i == 1) {
			std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
				return std::tolower(c);
			});
			action = str;
		}
		else values.push_back(argv[i]);
	}
	if (action != "") valid = true;
}