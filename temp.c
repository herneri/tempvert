/*
	temp.c: Convert a temperature unit to celsius, fahrenheit, or kelvin

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

#include <stdlib.h>

float convert_kelvin(const char target_unit, float value) {
	switch (target_unit) {
	case 'f': case 'F':
		value = 1.8 * (value - 273.15) + 32;
		break;
	case 'c': case 'C':
		value = value - 273.15;
		break;
	default:
		fprintf(stderr, "tempvert: Invalid target unit: %c \n", target_unit);
		exit(3);
	}

    return value;
}

float convert_celsius(const char target_unit, float value) {
    switch (target_unit) {
	case 'f': case 'F':
		value = (value * 9/5) + 32;
		break;
	case 'k': case 'K':
		value = value + 273.15;
		break;
	default:
		fprintf(stderr, "tempvert: Invalid target unit: %c \n", target_unit);
		exit(3);
    }

    return value;
}

float convert_fahrenheit(const char target_unit, float value) {
	switch (target_unit) {
	case 'c': case 'C':
   		value = (value - 32) * 5/9;
		break;
	case 'k': case 'K':
		value = (value + 459.67) * 5/9;
		break;
	default:
		fprintf(stderr, "tempvert: Invalid target unit: %c \n", target_unit);
		exit(3);
	}

    return value;
}
