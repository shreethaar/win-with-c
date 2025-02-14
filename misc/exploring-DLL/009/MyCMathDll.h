#ifdef MYCMATHDLL_EXPORTS
#define MYCMATHDLL_API __declspec(dllexport)
#else
#define MYCMATHDLL_API __declspec(dllimport)
#endif 

#define PI 3.1415


MYCMATHDLL_API double Powerof2 (double UserNumber);
MYCMATHDLL_API double Powerof3 (double UserNumber);
MYCMATHDLL_API double CircleArea (double UserRadius);
MYCMATHDLL_API double CircleCircum (double UserRadius);
MYCMATHDLL_API int giveANum (int a); 


/* Other ways to define the header file:
 *
 * 	__declspec(dllexport) double Powerof2 (double UserNumber);
 * 	__declspec(dllexport) double Powerof3 (double UserNumber);
 * 	__declspec(dllexport) CircleArea (double UserRadius);
 * 	__declspec(dllexport) CircleCircum (double UserRadius);
 */


