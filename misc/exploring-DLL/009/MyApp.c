#include <stdio.h>
#include "MyCMathDll.h"

int main() {
	double p2 = 10.0;
	double p3 = 5.0;
	double radius = 4.0;
	printf("The number %.2f to the power of 2 is %.2f.\n",p2,Powerof2(p2));
	printf("The number %.2f to the power of 3 is %.2f.\n",p3,Powerof3(p3));
	printf("A circle with a radius of %.2f, the area is %.2f\n",radius,CircleArea(radius));
	printf("A circle with a radius of %.2f, the circumference is %.2f\n",radius,CircleCircum(radius));
	printf("new function implemented: %d\n",giveANum(5));
	return 0;
}
