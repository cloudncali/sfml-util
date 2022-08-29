#ifndef RANDOM_HPP_INCLUDED
#define RANDOM_HPP_INCLUDED
#include <random>
#include <time.h>
namespace Random
{
	std::random_device g_RandomDevice;

	void Seed()
	{
	}

	std::uniform_int_distribution<> distrib;
	std::uniform_int_distribution<> distrib2(1, 2);
	std::uniform_int_distribution<> distrib4(1, 4);
	std::uniform_int_distribution<> distrib6(1, 6);
	std::uniform_int_distribution<> distrib8(1, 8);
	std::uniform_int_distribution<> distrib10(1, 10);
	std::uniform_int_distribution<> distrib12(1, 12);
	std::uniform_int_distribution<> distrib20(1, 20);
	std::uniform_int_distribution<> distrib100(1, 100);
	std::uniform_real_distribution<float> distribf(0.f, 1.f);
	unsigned int Get() { return distrib(std::mt19937(g_RandomDevice())); }
	unsigned int Get2() { return distrib2(std::mt19937(g_RandomDevice())); }
	unsigned int Get4() { return distrib4(std::mt19937(g_RandomDevice())); }
	unsigned int Get6() { return distrib6(std::mt19937(g_RandomDevice())); }
	unsigned int Get8() { return distrib8(std::mt19937(g_RandomDevice())); }
	unsigned int Get10() { return distrib10(std::mt19937(g_RandomDevice())); }
	unsigned int Get12() { return distrib12(std::mt19937(g_RandomDevice())); }
	unsigned int Get20() { return distrib20(std::mt19937(g_RandomDevice())); }
	unsigned int Get100() { return distrib100(std::mt19937(g_RandomDevice())); }
	float GetFloat() { return distribf(std::mt19937(g_RandomDevice())); } //returns a random float between 0 and 1. Used for prcentage based calulations.
}
#endif