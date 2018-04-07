#include <stdio.h>
#include <stdlib.h>

#include "prices.h"

int dollars(double money);
//int nugs(double);

int main(int argc, char** argv[]){
	double num;
	char *ptr;
	num = strtod(argv[2], &ptr);

	if(strcmp(argv[1], "-d") == 0){
		return dollars(num);
	}

	else if(strcmp(argv[1], "-n") == 0){
		//return nuggets(num);
		return 1;
	}

	else{
		//printf(USAGE);
		return -1;
	}
}

int dollars(double money){
	int fourpack = 0;
	int tenpack = 0;
	int twentypack = 0;
	int fortypack = 0;
	printf("Starting Money: $%f\n\n", money);
	while(money >= (FOUR_NUGS*TAXRATE)+FOUR_NUGS){
		if(money >= FORTY_NUGS){
			fortypack++;
			money = money - (FORTY_NUGS*TAXRATE);
			money = money - FORTY_NUGS;
		}

		else if(money >= TWENTY_NUGS){
			twentypack++;
			money = money - (TWENTY_NUGS*TAXRATE);
			money = money - TWENTY_NUGS;
		}

		else if(money >= TEN_NUGS){
			tenpack++;
			money = money - (TEN_NUGS*TAXRATE);
			money = money - TEN_NUGS;
		}

		else{
			fourpack++;
			money = money - (FOUR_NUGS*TAXRATE);
			money = money - FOUR_NUGS;
		}
	}

	printf("Four-Packs to buy: %i\n", fourpack);
	printf("Ten-Packs to buy: %i\n", tenpack);
	printf("Twenty-Packs to buy: %i\n", twentypack);
	printf("Forty-Packs to buy: %i\n", fortypack);
	printf("Remaining Money: $%f\n", money);
	int totalnugs = 0;
	totalnugs = totalnugs + (fourpack*4);
	totalnugs = totalnugs + (tenpack*10);
	totalnugs = totalnugs + (twentypack*20);
	totalnugs = totalnugs + (fortypack*40);
	printf("Total Nuggets: %i\n", totalnugs);
}
