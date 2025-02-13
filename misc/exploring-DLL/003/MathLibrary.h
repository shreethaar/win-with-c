#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else 
#define MATHLIBRARY_API __declspec(dllimport)

MATHLIBRARY_API double add(double a, double b);
MATHLIBRARY_API double subtract(double a, double b);
MATHLIBRARY_API double multiply(double a, double b);
MATHLIBRARY_API double divide(double a, double b);

#endif
