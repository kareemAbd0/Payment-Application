//
// Created by kareem on 8/15/22.
//

#ifndef PAYMENT_APPLICATION_SERVER_H
#define PAYMENT_APPLICATION_SERVER_H
#include <stdio.h>
#include <stdint-gcc.h>
#include "../Card/Card.h"
#include "../Terminal/Terminal.h"





typedef enum EN_transState_t
{
    APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;


typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    enum EN_transState_t transState;
    uint32_t transactionSequenceNumber;
}ST_transaction_t;


typedef enum EN_serverError_t
{
    DONE, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE
}EN_serverError_t ;


typedef struct ST_accountsDB_t
{
    float balance;
    uint8_t primaryAccountNumber [20];
}ST_accountsDB_t;


extern ST_accountsDB_t accountsDb [255];
extern ST_transaction_t transactions [255];
extern int theaccountelement;



EN_transState_t receiveTransactionData(ST_transaction_t *transData);
EN_serverError_t isValidAccount(ST_cardData_t *cardData,ST_accountsDB_t * account);
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData,ST_accountsDB_t account);
EN_serverError_t saveTransaction(ST_transaction_t *transDate);
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData);
#endif //PAYMENT_APPLICATION_SERVER_H
