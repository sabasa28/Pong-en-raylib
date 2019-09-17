#include "console.h"
#include <time.h>
const int screenWidth = 800;
const int screenHeight = 450;
int cronometer;
float cronometerflo;
void initCronometers() {
	cronometer = (double)clock() / 1000;
	cronometerflo = (double)clock() / 1000;
}
