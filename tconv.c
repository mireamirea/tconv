/****************************************************************
 *	tconv.c -- simple temperature converter, C, F & K	*
 *	2017, Valeriy Antonov <hello@aulandsdalen.me>		*
 *	see LICENSE for licensing details			*
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tconv.h"

int main(int argc, char** argv) {
        if (argc < 2) {
                printf("Usage: %s <degrees> <scale>\n", argv[0]);
                return -1;
        } 
        float temp;
        temp = atof(argv[1]);
        if (argc == 2) {
        	printf("%.2f C:\n%.2f F\n%.2f K\n\n", temp, is_sane(temp, 'c')?ctof(temp):0.0, is_sane(temp, 'c')?ctok(temp):0.0);
			printf("%.2f F:\n%.2f C\n%.2f K\n\n", temp, is_sane(temp, 'f')?ftoc(temp):0.0, is_sane(temp, 'f')?ftok(temp):0.0);
			printf("%.2f K:\n%.2f C\n%.2f F\n", temp, is_sane(temp, 'k')?ktoc(temp):0.0,  is_sane(temp, 'k')?ktof(temp):0.0);
        }
		else {
			if (strlen(argv[2]) != 1) {
				printf("Invalid argument: '%s'\n", argv[2]);
			return 1;
		}
		if (!is_sane(temp, argv[2][0])) {
			printf("Temperatures less than absolute zero are not possible in this universe\n");
			return 2;
		}
		switch (argv[2][0]) {
			case 'c': case 'C':
				printf("%.2f C:\n%.2f F\n%.2f K\n", temp, ctof(temp), ctok(temp));
			break;
			case 'f': case 'F':
				printf("%.2f F:\n%.2f C\n%.2f K\n", temp, ftoc(temp), ftok(temp));
			break;
			case 'k': case 'K':
				printf("%.2f K:\n%.2f C\n%.2f F\n", temp, ktoc(temp), ktof(temp));
			break;
			default:
				printf("Unknown scale: '%c'\n", argv[2][0]);
			break;
		}
	}
        return 0;
}
