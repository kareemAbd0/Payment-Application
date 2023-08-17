//
// Created by kareem on 8/15/22.
//

#include "Application.h"

void clear_Structs (ST_cardData_t * card,ST_terminalData_t *terminal , ST_transaction_t * transaction )
{
    //strcpy((char *)card->cardHolderName,"");
    memset(card->cardHolderName,0,sizeof(card->cardHolderName));

    memset(card->primaryAccountNumber,0,sizeof(card->primaryAccountNumber));

    terminal->transAmount = 0;
    terminal->maxTransAmount = 0;
    memset(terminal->transactionDate,0,sizeof(terminal->transactionDate));
    transaction->transState = 404;
}

void print_transaction(ST_transaction_t * transaction)
{
    printf("%s\n %s\n %s\n",transaction->cardHolderData.cardHolderName,transaction->cardHolderData.primaryAccountNumber,transaction->cardHolderData.cardExpirationDate);
    printf("\n \n %s \n %f\n %f\n %d ",transaction->terminalData.transactionDate,transaction->terminalData.maxTransAmount,transaction->terminalData.transAmount,transaction->transState);

}

//kareem atif abdelbaset
//05/24
//4443345543548856568
//

void appStart(void)
{
    while (1) {


        ST_cardData_t card;
        ST_terminalData_t terminal;
        ST_transaction_t transaction;
        ST_accountsDB_t account;
        if (getCardHolderName(&card) == WRONG_NAME) {
            printf("invalid name\n");
            clear_Structs(&card, &terminal, &transaction);
            continue;
        }
        if (getCardExpiryDate(&card) == WRONG_EXP_DATE) {
            printf("invalid expiry date mm/yy \n");
            clear_Structs(&card, &terminal, &transaction);
            continue;
        }
        if ((getCardPAN(&card) == WRONG_PAN)) {
            printf("invalid pan\n");
            clear_Structs(&card, &terminal, &transaction);
            continue;
        }






        transaction.cardHolderData = card;

        if (getTransactionDate(&terminal) == WRONG_DATE) {
            printf("invalid date\n");
            clear_Structs(&card, &terminal, &transaction);
            continue;
        }
        if (isCardExpired(card, terminal) == EXPIRED_CARD) {
            printf("card expired\n");
            clear_Structs(&card, &terminal, &transaction);
            continue;
        }
        if (getTransactionAmount(&terminal) == INVALID_AMOUNT) {
            printf("invalid amount\n");
            clear_Structs(&card, &terminal, &transaction);
            continue;
        }
        if (setMaxAmount(&terminal) == INVALID_MAX_AMOUNT) {
            printf("invalid max amount\n");
            clear_Structs(&card, &terminal, &transaction);
            continue;
        }
        if (isBelowMaxAmount(&terminal) == EXCEED_MAX_AMOUNT) {
            printf("exceeded max amount\n");
            clear_Structs(&card, &terminal, &transaction);
            continue;

        }
        transaction.terminalData = terminal;
        receiveTransactionData(&transaction);


    }




}