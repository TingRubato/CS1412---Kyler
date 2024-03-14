//
// Created by Ting Xu on 3/12/2024.
// Student: Kyler Cude
// Varsity Tutors
//

#include "stdio.h"
#include "string.h"

enum Service {
    PREM, REG, ERROR
};
enum Service plan = ERROR;

int main() {
    char serviceCode_input[1];
    int accountNumber;
    int minuteUsed;
    int day_minute;
    int night_minute;

    float final_bill;


    printf("Enter your account number:");
    scanf("%d", &accountNumber);
    printf("\nYour account number is: %d", accountNumber);

    do {
        printf("\nEnter your Service code:");
        scanf("%s", serviceCode_input);
        printf("\nYour Service Code is: %s", serviceCode_input);

        if (strcmp("r", serviceCode_input) == 0 || strcmp("R", serviceCode_input) == 0) {
            plan = REG;
        } else if (strcmp("p", serviceCode_input) == 0 || strcmp("P", serviceCode_input) == 0) {
            plan = PREM;
        } else {
            plan = ERROR;
            printf("Error! Please re-type your service code."); }
    } while(plan == ERROR);


    switch (plan) {
        case REG:
            printf("Regular user, please input total minutes you used:");
            scanf("%d", &minuteUsed);
            printf("\nYou used %d minutes.", minuteUsed);

            if (minuteUsed <= 50) {
                final_bill = 10;

            } else {
                final_bill = 10 + (minuteUsed - 50) * 0.20;
            }
            printf("Amount due is: %.2f", final_bill);
            break;

        case PREM:
            printf("\nPremium user, please input total minutes you used during day time:");
            scanf("%d", &day_minute);
            printf("\nYou used %d minutes during the day.", day_minute);
            printf("\nPlease input total minutes you used at night:");
            scanf("%d", &night_minute);
            printf("\nYou used %d minutes during the night.", night_minute);
            float day_bill;
            float night_bill;

            if (day_minute <= 75) {
                day_bill = 0;
            } else {
                day_bill = (day_minute - 75) * 0.10;
            }

            if (night_minute <= 100) {
                day_bill = 0;
            } else {
                day_bill = (night_minute - 100) * 0.05;
            }

            final_bill = 25 + day_bill + night_bill;

            printf("Amount due is: %.2f", final_bill);

            break;


        default:
            break;
    }

    return 0;
}

