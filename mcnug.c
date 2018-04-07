#include <stdio.h>
#include <stdlib.h>

#include "prices.h"

int dollars(double money);
int nugs(double count);

int main(int argc, char** argv[]){
	double num;
	char *ptr;
	num = strtod(argv[2], &ptr);

	if(strcmp(argv[1], "-d") == 0){
		return dollars(num);
	}

	else if(strcmp(argv[1], "-n") == 0){
		return nuggets((int)num);
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
	printf("Starting Money: $%.2f\n\n", money);
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
	printf("Remaining Money: $%.2f\n", money);
	int totalnugs = 0;
	totalnugs = totalnugs + (fourpack*4);
	totalnugs = totalnugs + (tenpack*10);
	totalnugs = totalnugs + (twentypack*20);
	totalnugs = totalnugs + (fortypack*40);
	printf("Total Nuggets: %i\n", totalnugs);
	return 0;
}

int nuggets(int count, int defecit){
	int fourpack = 0;
	int tenpack = 0;
	int twentypack = 0;
	int fortypack = 0;
	int total = 0;

	while(total < count){
		if(count - total >= 40){
			fortypack++;
			total+=40;
		}

		else if(count - total >= 20){
			twentypack++;
			total+=20;
		}

		else if(count - total >= 10){
			tenpack++;
			total+=10;
		}

		else if(count - total >= 4){
			fourpack++;
			total+=4;
		}
		else break;
		printf("40: %i | 20: %i | 10: %i | 4: %i\n", fortypack, twentypack, tenpack, fourpack);

	}

	if(count != total){
		fourpack++;
		total+=4;
	}

	printf("Four-Packs to buy: %i\n", fourpack);
	printf("Ten-Packs to buy: %i\n", tenpack);
	printf("Twenty-Packs to buy: %i\n", twentypack);
	printf("Forty-Packs to buy: %i\n", fortypack);
	double money = 0.0;
	money+= (FOUR_NUGS + (FOUR_NUGS*TAXRATE)) * fourpack;
	money+= (TEN_NUGS + (TEN_NUGS*TAXRATE)) * tenpack;
	money+= (TWENTY_NUGS + (TWENTY_NUGS*TAXRATE)) * twentypack;
	money+= (FORTY_NUGS + (FORTY_NUGS*TAXRATE)) * fortypack;
	printf("Money Spent: $%.2f\n", money);
	int totalnugs = 0;
	totalnugs = totalnugs + (fourpack*4);
	totalnugs = totalnugs + (tenpack*10);
	totalnugs = totalnugs + (twentypack*20);
	totalnugs = totalnugs + (fortypack*40);
	printf("Total Nuggets: %i\n", totalnugs);
	printf("Nugget Excess: %i\n", total-count);
	return 0;

}
