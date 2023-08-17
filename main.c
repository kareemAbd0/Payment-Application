#include <stdio.h>
#include "Card/Card.h"
#include "Terminal/Terminal.h"
#include "Server/Server.h"
#include "Application/Application.h"
#include <stdint-gcc.h>



int main() {

//    ST_cardData_t  card ;
//    getCardHolderName(&card);
//    getCardExpiryDate(&card);
//    getCardPAN(&card);
//    ST_terminalData_t terminal ;
//    getTransactionAmount(&terminal);
//    getTransactionDate(&terminal);
//    setMaxAmount(&terminal);
//    ST_transaction_t transaction;
//    transaction.terminalData = terminal;
//    transaction.cardHolderData = card;
    //transactions[0].transState = APPROVED;
   // transactions[0].transactionSequenceNumber = 124532454;

    strcpy((char*)accountsDb[0].primaryAccountNumber,"4443345543548856568");
    accountsDb[0].balance = 1000000;




    appStart();




//    EN_transState_t transactionStates = receiveTransactionData(&transaction  );
//
//    if(transactionStates == DECLINED_STOLEN_CARD)
//    {
//        printf("card not found");
//    }else if (transactionStates == DECLINED_INSUFFECIENT_FUND)
//   {
//       printf("not enough balance");
//   } else if (transactionStates == APPROVED) {
//        printf("transaction completed");
//    } else if (transactionStates == INTERNAL_SERVER_ERROR)
//    {
//        printf("server error");
//    }

    return 0;
}

//25/11/2020
//12/20