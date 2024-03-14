//
// Created by Ting Xu on 3/13/2024.
// Student: Kyler Cude
// Varsity Tutors
//

#include "stdio.h"
#include "strings.h"

enum ShippingMethod {
    STANDARD, EXPRESS, ERROR
};

enum ShippingMethod user_shipping_method = ERROR;

int main() {
    char user_shipping_input[1];
    float totalWeight;
    float shippingCost;
    printf("Enter the total weight of the items(in pound):");
    scanf("%f", &totalWeight);

    do {
        printf("\nEnter the preferred shipping method(E:express, S:standard):");
        scanf("%s", user_shipping_input);

        if (strcmp("E", user_shipping_input) == 0 || strcmp("e", user_shipping_input) == 0) {
            user_shipping_method = EXPRESS;
        } else if (strcmp("S", user_shipping_input) == 0 || strcmp("s", user_shipping_input) == 0) {
            user_shipping_method = STANDARD;
        } else {
            user_shipping_method = ERROR;
            printf("Error! Please re-type your shipping method.");
        }
    } while (user_shipping_method == ERROR);

    if (totalWeight < 10) {
        switch (user_shipping_method) {
            case EXPRESS:
                shippingCost = 5.00*totalWeight;
                break;
            case STANDARD:
                shippingCost = 2.50*totalWeight;
                break;
            default:
                break;
        }
    } else if (totalWeight >= 10 && totalWeight <= 20) {
        switch (user_shipping_method) {
            case EXPRESS:
                shippingCost = 5.00*totalWeight*0.9;
                break;
            case STANDARD:
                shippingCost = 2.50*totalWeight*0.9;
                break;
            default:
                break;
        }
    } else {
        switch (user_shipping_method) {
            case EXPRESS:
                shippingCost = 5.00*totalWeight*0.9-10;
                break;
            case STANDARD:
                shippingCost = 2.5*totalWeight*0.9;
            default:
                break;
        }
    }

    printf("Total shipping cost: $%.2f",shippingCost);

}