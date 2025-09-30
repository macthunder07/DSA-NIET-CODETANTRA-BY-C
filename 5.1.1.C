#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    double value;
    double weight;
    double ratio; // value-to-weight ratio
} Item;

// Comparator function for sorting items by ratio in descending order
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item2->ratio > item1->ratio) return 1;
    else if (item2->ratio < item1->ratio) return -1;
    else return 0;
}

int main() {
    int n;
    double W;
    scanf("%d %lf", &n, &W);

    Item items[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &items[i].value, &items[i].weight);
        items[i].ratio = items[i].value / items[i].weight;
    }

    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    double remainingCapacity = W;

    for (int i = 0; i < n && remainingCapacity > 0; i++) {
        if (items[i].weight <= remainingCapacity) {
            // Take the whole item
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            // Take fraction of the item
            totalValue += items[i].ratio * remainingCapacity;
            remainingCapacity = 0;
        }
    }

    printf("%.6lf\n", totalValue);
    return 0;
}
