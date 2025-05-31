//#include <stdlib.h>
#include "weather_utils.h"

int TempMin (WeatherTable table){
	int temp=table[0u][january][0u]._min_temp;

	for (unsigned int year=0u; year<YEARS; year++){
		for (month_t month=january; month<=december; month++){
			for (unsigned int day=0u; day<DAYS; day++){
				if(table[year][month][day]._min_temp < temp){
					temp=table[year][month][day]._min_temp;	
				}
			}
		}
	}

	return temp;
}


void TempMax (WeatherTable table, int a[YEARS]){
	int temp=table[0u][january][0u]._max_temp;

	for (unsigned int year=0u; year<YEARS; year++){
		temp=table[year][january][0u]._max_temp;
		for (month_t month=january; month<=december; month++){
			for (unsigned int day=0u; day<DAYS; day++){
				if (table[year][month][day]._max_temp > temp){
					temp=table[year][month][day]._max_temp;	
				}
			}
		}
		a[year]=temp; 
	}	
}


void RainMax (WeatherTable table, int a[YEARS]){
	unsigned int rain;
	unsigned int rain_max;
	unsigned int rain_month;

	for (unsigned int year=0u; year<YEARS; year++){
		rain_max=0u;

		for (month_t month=january; month<=december; month++){
			rain=0u;
			for (unsigned int day=0u; day<DAYS; day++){
				rain=rain+table[year][month][day]._rainfall;
			}

			if (rain>rain_max){
				rain_max=rain;
				rain_month=month;
			}
		}

	a[year]=rain_month;
	}
}



