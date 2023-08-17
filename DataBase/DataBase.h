//
// Created by kareem on 10/18/22.
//



#ifndef PAYMENT_APPLICATION_DATABASE_H
#define PAYMENT_APPLICATION_DATABASE_H

#include <stdio.h>
#include <string.h>
#include "../Server/Server.h"


void Save_Transaction(ST_transaction_t *transaction);

void Get_Transaction(char * PAN,ST_transaction_t *transaction);

void Get_Account(char *PAN,ST_accountsDB_t *account);

void Change_Balance(char *PAN,float trans_amount);






#endif //PAYMENT_APPLICATION_DATABASE_H
