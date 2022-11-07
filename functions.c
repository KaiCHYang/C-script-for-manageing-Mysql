//
//  functions.c
//  Mysql_usingFunction
//
//  Created by Haokai on 02/11/2022.
//

#include "functions.h"


extern MYSQL *con;

void updateTable (void);

void deleteTable (void);


//connnection 
int databaseConnection (char *usr, char *passwd){
    
    if(mysql_real_connect(con, "localhost", usr, passwd, "demo_employee_list", 3306, NULL, 0) == NULL)
    {
        printf("connection failed!\n");
        fprintf(stderr, "%s\n",mysql_error(con));
        return 0;
    } else {
        printf("db connected!\n");
        return 1;
    }

}

//checking
void defultTable (void)
{

    MYSQL_RES * result = NULL;
    MYSQL_ROW row;
    MYSQL_FIELD * fd;

    char * Command = "select e.emp_no, e.emp_name, d.dept_name from emp e join dept d on e.dept_no = d.dept_no";
    
    if (mysql_query(con, Command) != 0)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        printf("\nchecking failed\nPlease choose your action again\n");
    }else{
        result = mysql_store_result(con);
        unsigned int field_num = mysql_num_fields(result);
        
        fd = mysql_fetch_field(result);
        
        for (int i = 0; i<field_num; i++)
        {
            printf("%s\t", fd[i].name);
        }
        printf("\n");
        
        int i;
        while ((row = mysql_fetch_row(result)) != NULL)
        {
            for (i = 0; i<field_num; i++)
            {
                printf("%s\t\t", row[i]);
            }
            printf("\n");
            i=0;
        }
    }
    printf("\nPlease select your next action!\n" );
    mysql_free_result(result);
    
}


//singal table
void singalTable(void)
{
    MYSQL_RES * result = NULL;
    MYSQL_ROW row;
    MYSQL_FIELD * fd;
    
    printf("\nWhich table you want to view? \n");
    printf("\nenter '1' to view table: <emp>\n");
    printf("\nenter '2' to view table: <dept>\n\n");
    
    int chooseTable = 0;
    
    scanf("%d", &chooseTable);
    
    char * Command = NULL;
    
    switch (chooseTable) {
        case 1:
            Command = "select * from emp";
            break;
            
        case 2:
            Command = "select * from dept";
            break;
            
        default:
            printf("invalid option\n");
            goto STFunctionEnd;
    }
    
    if (mysql_query(con, Command) != 0)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        printf("\nchecking failed\nPlease choose your action again\n");
    }else{
        result = mysql_store_result(con);
        unsigned int field_num = mysql_num_fields(result);
        
        fd = mysql_fetch_field(result);
        
        for (int i = 0; i<field_num; i++)
        {
            printf("%s\t\t", fd[i].name);
        }
        printf("\n");
        
        int i;
        while ((row = mysql_fetch_row(result)) != NULL)
        {
            for (i = 0; i<field_num; i++)
            {
                printf("%s\t\t\t\t", row[i]);
            }
            printf("\n");
            i=0;
        }
    }
    printf("\nPlease select your next action!\n" );
STFunctionEnd:
    mysql_free_result(result);
}


//delete and update----------------------------------------------------------
void deleteAndUpdate (void)
{
   
    int chooseAction;
    
    printf("enter '1' to update the table\n");
    printf("enter '2' to delete the line\n");
    
    scanf("%d", &chooseAction);
    
    switch (chooseAction) {
        case 1:
            updateTable();
            break;
            
        case 2:
            deleteTable();
            
        default:
            break;
    }
    

    
}

void updateTable (void)
{
    int chooseTable;
    printf("please select the table you want to operate with \n");
    printf("enter '1' to  choose table <emp>\n");
    printf("enter '2' to  choose table <dept>\n");
    scanf("%d", &chooseTable);


    char a_Command[140] = "UPDATE ";
    char * b_Command= "SET ";
    char * c_command;
    char PrimID [3]= "\0";
    char * tableName;
    char FieldName[140] = "\0";
    char undateValue[140] = "\0";
    char *equal = "='";
    char * black = " ";

    if (chooseTable == 1)
    {
        tableName = "emp ";
        c_command = " ' WHERE Primary_eID=";
    }else if (chooseTable == 2)
    {
        tableName = "dept ";
        c_command = " ' WHERE Primary_dID=";
    }

    printf("\nPlease enter the Primary ID of the object you want to update\n");
    scanf("%s", PrimID);
    printf("\nPlease enter the field name \n");
    scanf("%s", FieldName);
    printf("\nPlease enter the new value \n");
    scanf("%s", undateValue);

    strcat(a_Command, tableName);
    strcat(a_Command, black);
    strcat(a_Command, b_Command);
    strcat(a_Command, black);
    strcat(a_Command, FieldName);
    strcat(a_Command, black);
    strcat(a_Command, equal);
    strcat(a_Command, black);
    strcat(a_Command, undateValue);
   
    strcat(a_Command, c_command);
    strcat(a_Command, PrimID);

    if (mysql_query(con, a_Command) != 0)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit (0);
    }else{
        printf("update completed!\n");
        printf("\nPlease select your next action!\n" );
    }
}

    
void deleteTable (void)
{
    int chooseTable;
    printf("please select the table you want to operate with \n");
    printf("enter '1' to  choose table <emp>\n");
    printf("enter '2' to  choose table <dept>\n");
    scanf("%d", &chooseTable);


    char a_Command[140] = "delete from ";
    char * b_command;
    char PrimaryID[3] = "\0";
    char * tableName;
    char * black = " ";

    if (chooseTable == 1)
    {
        tableName = "emp";
        b_command = "where Primary_eID=";
    }else if (chooseTable == 2)
    {
        tableName = "dept";
        b_command = "where Primary_dID=";
    }

    printf("\nPlease enter the Primary ID of the object you want to delete\n");
    scanf("%s", PrimaryID);

    strcat(a_Command, tableName);
    strcat(a_Command, black);
    strcat(a_Command, b_command);
    strcat(a_Command, PrimaryID);

    if (mysql_query(con, a_Command) != 0)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        printf("\nchecking failed\nPlease choose your action again\n");
    }else{
        printf("delete completed!\n");
        printf("\nPlease select your next action!\n" );
    }
}



 
