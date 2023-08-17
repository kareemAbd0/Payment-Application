//
// Created by kareem on 8/15/22.
//

#include "Terminal.h"
#include <stdio.h>
#include <string.h>

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    printf("Enter transaction date\n");
    scanf ("%s" ,termData ->transactionDate);

    int size = strlen( ( char *)termData->transactionDate);

    if ( size == 10)
    {
        for (int i = 0; i < 10; ++i)
        {
            if ((i != 2) && (i!=5))
            {
                if (((int) termData->transactionDate[i] < 48) || ((int) termData->transactionDate[i] > 57))
                {
                    return WRONG_DATE;
                }
            } else
            {
                if ((int) termData->transactionDate[i] != '/')
                {
                    return WRONG_DATE;
                }
            }

        }
        return GOOD;

    }
    return WRONG_DATE;

}


EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
    if (termData.transactionDate[8] > cardData.cardExpirationDate[3])
    {
        return EXPIRED_CARD;
    }
    else if ( termData.transactionDate[9] > cardData.cardExpirationDate[4] && (termData.transactionDate[8] == cardData.cardExpirationDate[3]))
    {
        return EXPIRED_CARD;
    } else if ((termData.transactionDate[8]== cardData.cardExpirationDate[3]) && (termData.transactionDate[9] == cardData.cardExpirationDate[4]))
    {
        if (termData.transactionDate[3] > cardData.cardExpirationDate[0])
        {
        return EXPIRED_CARD;

        } else if (termData.transactionDate[4] >= cardData.cardExpirationDate[1])
          {
            return EXPIRED_CARD;

          } else
            {
               return GOOD;
             }
    }
    else
    {
        return GOOD;
    }

}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    printf("enter the transaction amount \n");

    scanf("%f",&termData ->transAmount);

    if (termData->transAmount > 0)
    {
        return GOOD;
    } else
    {
        return INVALID_AMOUNT;
    }

}


EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{


    printf("enter the max amount \n");

    scanf("%f",&termData ->maxTransAmount);

    if (termData->maxTransAmount > 0)
    {
        return GOOD;
    } else
    {
        return INVALID_MAX_AMOUNT;
    }

}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    if(termData->transAmount > termData ->maxTransAmount)
    {
        return EXCEED_MAX_AMOUNT;
    } else
    {
        return GOOD;
    }


}





