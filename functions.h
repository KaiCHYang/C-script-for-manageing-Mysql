//
//  functions.h
//  Mysql_usingFunction
//
//  Created by Haokai on 02/11/2022.
//

#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <mysql.h>
#include <string.h>

int databaseConnection (char *usr, char *passwd);

void defultTable (void);

void singalTable(void);

void deleteAndUpdate (void);

#endif /* functions_h */
