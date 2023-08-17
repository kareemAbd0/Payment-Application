//
// Created by kareem on 8/15/22.
//

#include "Server.h"
#include <string.h>
#include "../DataBase/DataBase.h"

ST_accountsDB_t accountsDb [255];
ST_transaction_t transactions [255];
int theaccountelement;


EN_transState_t receiveTransactionData(ST_transaction_t *transData)
{


    ST_accountsDB_t account;

    transData->transState = 404;

    if (isValidAccount(&transData->cardHolderData,&account) == TRANSACTION_NOT_FOUND)
 {
     transData->transState = DECLINED_STOLEN_CARD;


 }else if (isAmountAvailable(&transData->terminalData,account)== LOW_BALANCE)
 {

      transData->transState = DECLINED_INSUFFECIENT_FUND;
 } else
    {

     transData ->transState = APPROVED;
    }




    if(saveTransaction(transData)== SAVING_FAILED)
 {

     return INTERNAL_SERVER_ERROR;

 } else if (transData->transState ==  DECLINED_STOLEN_CARD)
    {
        return DECLINED_STOLEN_CARD;
    } else if (transData->transState == DECLINED_INSUFFECIENT_FUND)
    {
        return DECLINED_INSUFFECIENT_FUND;
    } else if (transData ->transState == APPROVED)
 {
     Change_Balance(account.primaryAccountNumber,transactions->terminalData.transAmount);
     return APPROVED;
 }

}


EN_serverError_t isValidAccount(ST_cardData_t *cardData,ST_accountsDB_t * account)
{

    Get_Account(cardData->primaryAccountNumber,account);
    if (account->balance == -1) {
        return TRANSACTION_NOT_FOUND;
    } else
    {
        return DONE;
    }



}


EN_serverError_t isAmountAvailable(ST_terminalData_t *termData,ST_accountsDB_t account)
{

    if (termData->transAmount > account.balance)
    {
        return LOW_BALANCE;
    } else
    {
        return DONE;
    }

}

EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
    int static tsn;


    if (transData->transState == DECLINED_STOLEN_CARD)
    {
        Save_Transaction(transData);

        return ACCOUNT_NOT_FOUND;


    } else if (transData->transState == DECLINED_INSUFFECIENT_FUND)
    {
        Save_Transaction(transData);
        return LOW_BALANCE;
    } else if (transData->transState == APPROVED)
    {
        Save_Transaction(transData);

        return  DONE;

    } else
    {

        return SAVING_FAILED;
    }


}

EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData)
{
    Get_Transaction((char *) transactionSequenceNumber, transData);

    if (transData->transState ==  DECLINED_STOLEN_CARD)
    {
        return  TRANSACTION_NOT_FOUND;
    } else if (transData->transState == DECLINED_INSUFFECIENT_FUND)
    {
        return LOW_BALANCE;
    } else if (transData ->transState == APPROVED)
    {
        return DONE;
    }

}












