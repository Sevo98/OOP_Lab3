#pragma once

struct Time
{
	int Year, Month, Day, Hour, Minute;
};

void ReadTimeFromConsole(Time& time);
void WriteTimeFromConsole(Time& time);