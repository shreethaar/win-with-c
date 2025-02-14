#include <stdio.h>
#define PI 3.1415

double Powerof2 (double UserNumber);
double Powerof3 (double UserNumber);
double CircleArea (double UserRadius);
double CircleCircum (double UserRadius);

int main() {
	double p2 = 10.0;
	double p3 = 5.0;
	double radius = 4.0;
	printf("The number of %.2f to the power of 2 is %.2f.\n",p2,Powerof2(p2));
	printf("The number of %.2f to power of 3 is %.2f.\n",p3,Powerof3(p3));
	printf("A circule with a radius of %.2f, the area is %.2f.\n",radius,CircleArea(radius));
	printf("A circle with a radius of %.2f, the circumferenece is %.2f.\n",radius,CircleArea(radius));
	return 0;

double Powerof2(double UserNumber) {
	return UserNumber * UserNumber;
}

double Powerof3(double UserNumber) {
	return UserNumber * UserNumber * UserNumber;
}

double CircleArea(double UserRadius) {
	return UserRadius * UserRadius * PI;
}

double CircleCircum(double UserRadius) {
	return 2 * UserRadius * PI;
}

