#include <cstdio>
#include <cstdlib>
using namespace std;

#define LIMIT 8



struct Item{
	char name[20];
	int weight;
	int price;
};

void knapspack(Item* item, int* items, int* value, int length);
int minWeightItem(Item* item, int length);

int main(void){
	Item item[5] = {
		{"A", 4, 4500},
		{"B", 5, 5700},
		{"C", 2, 2250},
		{"D", 1, 1100},
		{"E", 6, 6700}
	};
	int items[LIMIT+1] = {0};
	int value[LIMIT+1] = {0};

	printf("pack limit : 8\n");
	knapspack(item, items, value, 5);
	for(int i = LIMIT; i > minWeightItem(item, 5); i -= item[items[i]].weight){
		printf("%s\t%d\t%d\n", item[items[i]].name, item[items[i]].weight, item[items[i]].price);
	}
	printf("total value : %d\n", value[LIMIT]);

	return 0;
}

/*
Using DP to fill the form
EX : 
ans[8] = 1 + ans[7]
ans[7] = 2 + ans[5]
*/

void knapspack(Item* item, int* items, int* value, int length){
	int packWeight;
	int remainWeight;
	int newValue;
	for(int i = 0; i < length; i++){
		for(packWeight = item[i].weight; packWeight <= LIMIT; packWeight++){
			remainWeight = packWeight - item[i].weight;
			newValue = item[i].price + value[remainWeight];
			if(newValue > value[packWeight]){
				value[packWeight] = newValue;
				items[packWeight] = i;
			}
		}
	}
}

int minWeightItem(Item* item, int length){
	int m = item[0].weight;
	for(int i = 0; i < length; i++){
		if(item[i].weight < m){
			m = item[i].weight;
		}
	}
	return m;
}