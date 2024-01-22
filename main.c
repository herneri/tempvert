/*
	tempvert: CLI utility to convert units of temperature

	Copyright 2024 Eric Hernandez

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		https://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

#include <stdio.h>
#include "temp.c"

int main(int argc, char *argv[]) {
	char origin_unit;
	float value;
	char target_unit;

	if (argc < 4) {
		fprintf(stderr, "tempvert: usage: tempvert [origin unit] [number] [target unit] \n");
		return 1;
	}

	origin_unit = argv[1][0];
	value = atof(argv[2]);
	target_unit = argv[3][0];

	switch (origin_unit) {
    case 'c': case 'C':
		printf("%.2f %c \n", convert_celsius(target_unit, value), target_unit);
		break; 
    case 'f': case 'F':
		printf("%.2f %c \n", convert_fahrenheit(target_unit, value), target_unit);
		break; 
    case 'k': case 'K':
		printf("%.2f %c \n", convert_kelvin(target_unit, value), target_unit);
		break;
    default:
		fprintf(stderr, "tempvert: Invalid origin unit: %c \n", origin_unit);
		return 1;
	}

	return 0;
}
