//
// Created by kareem on 8/15/22.
//

#ifndef PAYMENT_APPLICATION_TERMINAL_H
#define PAYMENT_APPLICATION_TERMINAL_H
#include <stdint-gcc.h>
#include "../Card/Card.h"
#include "../Terminal/Terminal.h"


typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;


typedef enum EN_terminalError_t
{
    GOOD, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;


EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);
EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData);



#endif //PAYMENT_APPLICATION_TERMINAL_H
