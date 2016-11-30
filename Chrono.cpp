#include "Chrono.h"


Chrono::Chrono()
{
	QueryPerformanceFrequency(&Frequency_);
}

void Chrono::Start()
{
	QueryPerformanceCounter(&StartingTime_);
}

void Chrono::Stop()
{
	QueryPerformanceCounter(&EndingTime_);
}

LONGLONG Chrono::Read()
{
	const int FACTEUR_MICROSECONDE = 1000000;
	ElapsedMicroseconds_.QuadPart = EndingTime_.QuadPart - StartingTime_.QuadPart;
	////
	//// We now have the elapsed number of ticks, along with the
	//// number of ticks-per-second. We use these values
	//// to convert to the number of elapsed microseconds.
	//// To guard against loss-of-precision, we convert
	//// to microseconds *before* dividing by ticks-per-second.
	////
	ElapsedMicroseconds_.QuadPart *= FACTEUR_MICROSECONDE;
	ElapsedMicroseconds_.QuadPart /= Frequency_.QuadPart;
	return ElapsedMicroseconds_.QuadPart;
}

