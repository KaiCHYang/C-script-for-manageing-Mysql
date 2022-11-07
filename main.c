//
//  main.c
//  Mysql_usingFunction
//
//  Created by Haokai on 02/11/2022.
//

#include <stdio.h>
#include <mysql.h>
#include "functions.h"

MYSQL *con;

int main(int argc, const char * argv[]) {
    
    //user pw & user name
    char passwd[20];
    char usr[20];
    printf("Please enter user name\n");
    scanf("%s", usr);
    printf("please enter the password\n");
    scanf("%s", passwd);
    
    //initialise
    con = mysql_init(NULL);
    
    //connection checking
    int connnectionResult = databaseConnection(usr, passwd);
    if (connnectionResult == 0)
    {
        goto finishingProgram;
    }
    
    //mysql - CRUD
    printf("\n\n\n");
    printf("what do you want to do?\n");
    printf("enter '1' to viewing the defult table\n");
    printf("enter '2' to checking single table in the database\n");
    printf("enter '3' to delete or update the table \n");
    printf("enter '4' to exit\n\n");
    int choose = 0;
    
begain_Action: scanf("%d", &choose);
    
//    if( choose >4 || choose < 1)
//    {
//        printf("your entered a invalid number!\nPlease reenter your number!\n");
//
//        goto begain_Action;
//    }
    
    switch (choose)
    {
        case 1:
            defultTable ();
            break;
            
        case 2:
            singalTable();
            break;
            
        case 3:
            deleteAndUpdate();
            break;
            
        case 4:
            goto finishingProgram;
            break;

        default:
            printf("\ninvalid number\nPlease enter your choose!\n");
            break;
    }
    choose = 0;
    goto begain_Action;

    
    
    
//    if (choose == 1)
//    {
//        defultTable ();
//        goto begain_Action;
//    }
//
//
    
    
    
finishingProgram:
    mysql_close(con);
    return 0;
}
