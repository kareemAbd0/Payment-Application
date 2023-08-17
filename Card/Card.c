//
// Created by kareem on 8/15/22.
//


#include "Card.h"

#include <stdio.h>
#include <string.h>
#include <stddef.h>

EN_cardError_t getCardHolderName(ST_cardData_t *cardData )
{
    printf("\nEnter the card holder name\n");

    fgets(( char *)cardData ->cardHolderName,30,stdin);
    cardData ->cardHolderName [strcspn(( char *)cardData ->cardHolderName, "\n")] = 0;

    int size = strlen( ( char *)cardData->cardHolderName);

    if ( (size > 24) || (size < 20) || (size == 0))
    {
        return WRONG_NAME ;
    } else
    {
        return OK;
    }

}



EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    printf("Enter card expiration date\n");
    scanf("%s", cardData ->cardExpirationDate);

    int size = strlen( ( char *)cardData->cardExpirationDate);

    if ( size == 5) {
        for (int i = 0; i < 5; ++i) {
            if (i != 2) {
                if (((int) cardData->cardExpirationDate[i] < 48) || ((int) cardData->cardExpirationDate[i] > 57)) {
                    return WRONG_EXP_DATE;
                }
            } else {
                if ((int) cardData->cardExpirationDate[i] != '/') {
                    return WRONG_EXP_DATE;
                }
            }

        }
        return OK;

    }
        return WRONG_EXP_DATE;

}

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
    printf("Enter the card PAN\n");

    scanf("%s", cardData ->primaryAccountNumber);

    int size = strlen( ( char *)cardData->primaryAccountNumber);

    if ( (size > 19) || (size < 16))
    {
        return WRONG_PAN ;
    } else
    {
        return OK;
    }

}


