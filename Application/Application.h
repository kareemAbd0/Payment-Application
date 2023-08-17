//
// Created by kareem on 8/15/22.
//

#ifndef PAYMENT_APPLICATION_APPLICATION_H
#define PAYMENT_APPLICATION_APPLICATION_H
#include "../Server/Server.h"
#include <string.h>
#include "../DataBase/DataBase.h"
void appStart(void);
void clear_Structs(ST_cardData_t * card,ST_terminalData_t *terminal , ST_transaction_t * transaction );



#endif //PAYMENT_APPLICATION_APPLICATION_H
