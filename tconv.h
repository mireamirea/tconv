/****************************************************
 *	tconv.h -- temperature converter routines		*
 *	2017, Valeriy Antonov <hello@aulandsdalen.me> 	*
 *	see LICENSE for licensing details				*
 ****************************************************/


/* Celsius to Fahrenheit & Kelvin conversion */
float ctof(float deg_c) {
        return 1.8 * deg_c  + 32;
}

float ctok(float deg_c) {
        return deg_c + 273.15;
}

/* Kelvin to Celsius & Fahrenheit conversion */
float ktoc(float deg_k) {
        return deg_k - 273.15;
}

float ktof(float deg_k) {
        return 1.8 * deg_k - 459.67;
}

/* Fahrenheit to Celsius & Kelvin conversion */
float ftoc(float deg_f) {
        return (deg_f - 32) * (5.0/9.0); 
}

float ftok(float deg_f) {
	return (deg_f + 459.67) * (5.0/9.0);
}

int is_sane(float temperature, char scale) {
	if(((scale == 'c' || scale == 'C') && temperature < -273.15) || ((scale == 'f' || scale == 'F') && temperature < -459.67) || ((scale == 'k' || scale == 'K') && temperature < 0))
		return 0;
	else
		return 1;
}