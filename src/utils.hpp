#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <random>
#include <iostream>
#include <algorithm>

#if defined(_WIN32)
	#include <ctime>
#endif


using namespace std;

class Utils
{
	public:
		static mt19937& random_engine();
		static float random_range_float(float min, float max);
		static int random_range_int(int min, int max);
		static float random_normalised();
		static float random_clamped();

		static float sigmoid(float num);
		static float constrain(float num, float min, float max);
};

#endif
