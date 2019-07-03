
#include <stdio.h>
#include "includes/core.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    if(argc == 2 && !strcmp(argv[1], "-a")) {
		initMorse(1);
	} else { initMorse(0); }
	return 0; 
}