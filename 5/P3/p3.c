#include <stdio.h>
#pragma warning(disable:4996)
#define COL 2
#define ROW 6
#define MAX_WEI 16

struct item_list {
    int item;
    int value;
    int weight;
    float benefit;
};

void Structinit (struct item_list *temp, int index, int index_weight, int index_value)
{
    temp->item = index;
    temp->value = index_value;
    temp->weight = index_weight;
    temp->benefit = (index_value / (float)index_weight);
}

void Structswap(struct item_list* one, struct item_list* two)
{
    struct item_list temp;

    temp.item = one->item;
    temp.value = one->value;
    temp.weight = one->weight;
    temp.benefit = one->benefit;
        
    one->item = two->item;
    one->value = two->value;
    one->weight = two->weight;
    one->benefit = two->benefit;
        
    two->item = temp.item;
    two->value = temp.value;
    two->weight = temp.weight;
    two->benefit = temp.benefit;
}

void Bubble(struct item_list *arr)
{
    for (int i = 0; i < ROW - 1; i++) {
        for (int j = 1; j < ROW; j++)
            if ((arr + j - 1)->benefit < (arr + j)->benefit)
                Structswap(arr + j - 1, arr + j);
    }
}

void Greedy(struct item_list* arr)
{
    Bubble(arr);
    int total_weight = 0;
    float total_value = 0;
    int i = 0, j = 0;
    int cnt = 0;

    for (i = 0; i < ROW; i++) {
        if (total_weight + arr[i].weight < MAX_WEI) {

            total_value += arr[i].value;
            total_weight += arr[i].weight;
            cnt++;
            printf("take item %d --------- weight %d remaing\n", arr[i].item, MAX_WEI - total_weight);
        
        }
        else {

            while (total_weight < MAX_WEI) {
                if (total_weight + 1 <= MAX_WEI) {
                    total_weight++;
                    total_value += arr[i].benefit;
                    cnt++;
                    j++;
                }
                else break;
            }

            if(cnt != 0)
                printf("\n\nmaximum value is %f\n", total_value);
                printf("partially taken item : %d, fraction number : %d / %d\n", arr[i].item, arr[i].value * j, arr[i].weight);
            break;
        }
    }
}

int main(void) 
{
    struct item_list item[ROW];

    Structinit(item, 1, 6, 60);
    Structinit(item + 1, 2, 10, 20);
    Structinit(item + 2, 3, 3, 12);
    Structinit(item + 3, 4, 5, 80);
    Structinit(item + 4, 5, 1, 30);
    Structinit(item + 5, 6, 3, 60);

    Greedy(item);

    return 0;
}