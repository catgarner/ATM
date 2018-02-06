/*
Program Description: Assignment: Code for controlling the PIN on an ATM.
Author: Catherine Garner
Date: 25/10/2016
OS Version: Windows 10 - 64 bit
*/

#include <stdio.h>
#include <conio.h> // to allow getch() to work
#include <string.h> // to allow strings to work
#include <windows.h> //to allow sleep to work
#define PIN 5

int main()
{
    char pinin[PIN] = {"0000"};//Verifying PIN
    char pinorig[PIN] = {"1234"};// Original PIN
    char newpin[PIN] = {"0000"};//Entering a new PIN
    char verpin[PIN] = {"0000"};//Re-entering a new PIN
    unsigned int ch;
    unsigned int ch2;
    unsigned int ch3;
    int pinin_count = 0; // counter for verifying PIN
    int newpin_count = 0; // counter for entering a new PIN
    int verpin_count = 0; // counter for re-entering PIN
    char option;
    int cor = 0; //counter for PIN entered correctly
    int incor = 0; //counter for PIN entered incorrect
    char exit;
    
    do
    {
        printf("\n--------------------------------------------------\n                    Menu\n--------------------------------------------------\n");
        
        printf("1) Enter PIN and verify correct");
        printf("\n2) Change PIN");
        printf("\n3) Display the number of times the PIN was entered");
        printf("\n   (i) Successfully\n   (ii) Incorrectly");
        printf("\n4) Exit Program");
        
        printf("\n\nSelect an option: ");
        option = getch(); //This prevents the user from entering more than one character 
    
        switch(option)
        {
            case '1':
            {
                printf("\n\nPlease enter your PIN number\n");
                
                pinin_count = 0;
                
                while (pinin_count < 4)//Will loop until 4 correct numbers have been entered
                {
                    ch = getch();//Takes in the input without displaying it
                    
                    if(ch >= '0' && ch <= '9') // Is a number so allow to enter array
                    {
                        putchar( ch );//Displays the input
                        pinin[pinin_count] = ch;//Adds the entered number into the array
                        pinin_count++;//Adds one to the counter for verifying PIN
                        
                        if(pinin_count == 4)//When 4 correct numbers have been entered
                        {
                            if(strcmp(pinin,pinorig)==0) //If the PIN that is entered is the same as the correct PIN
                            {
                                cor++; //Add one to correct counter
                                printf("\n\nPIN entered is correct\n\n"); 
                                printf("Please press enter to return to menu and try again\n");
                            }// End if
                            
                            else //if the PIN that is entered is not the same as the correct PIN
                            {
                                incor++; //Add one to incorrect counter
                                printf("\n\nPIN entered is incorrect\n\n");
                                printf("Please press enter to return to menu and try again\n");
                            }//End else
                            
                        }//End if 
                        
                    }//End if 
                    
                    else//If a letter is entered
                    {
                        incor++;//Add one to incorrect counter
                        printf("\n\nInvalid Entry!\n");
                        printf("\nPlease press enter to return to menu and try again\n");
                        break;
                    }//And if
                }//End while
                
                break;
                
            }//End case 1 
            
            case '2':
            {
                printf("\nPlease enter your desired PIN\n");
                
                newpin_count = 0;
                verpin_count = 0;
                
                while (newpin_count < 4)//Will loop until 4 correct numbers have been entered
                {
                    ch2 = getch();//Takes in the entry without displaying it
                    flushall();
                    
                    if(ch2 >= '0' && ch2 <= '9') // Is a number so allow to enter array
                    {
                        putchar( ch2 );//Displays the entry
                        newpin[newpin_count] = ch2;//Enters the number into the array
                        newpin_count++;//Adds one to the counter for new PIN
            
                        if(newpin_count == 4)//When 4 correct numbers have been entered
                        {
                            printf("\n\nPlease re-enter your desired PIN\n");
                            
                            while(verpin_count <4)//Will loop until 4 correct numbers have been entered
                            {
                                ch3 = getch();//Takes in the entry without displaying it
                                
                                if(ch3 >= '0' && ch3 <= '9') // Is a number so allow to enter array
                                {
                                    putchar( ch3 );//Displays the number
                                    verpin[verpin_count] = ch3;//Enter the number into the array
                                    verpin_count++;//Add one to the counter for re-entering the PIN
                                    
                                    if(verpin_count == 4)//When 4 correct numbers have been entered
                                    {
                                        if(strcmp(newpin,verpin)==0) //if the PIN that is entered is the same as the correct PIN
                                        {
                                            cor++; //add one to correct counter
                                            printf("\n\nYour PIN has been changed successfully\n\n"); 
                                            printf("Please press enter to return to menu and try again\n");
                                            
                                            strcpy(pinorig,verpin);//Copy the value of the newpin into the pinorig
                                            
                                        }// end if
                                        
                                        else//If the PIN entered is not the same as the correct PIN
                                        {
                                            incor++;//Add one to the counter for incorrect PIN
                                            printf("\n\nThe PIN's entered do not match\n\n");
                                            printf("Please press enter to return to menu and try again\n");
                                        }//End else
                                    }//End if
                                }//End if
                            
                                else//Not a vaild entry
                                {
                                    printf("\nInvalid Entry!\n");
                                    printf("Please press enter to return to menu and try again\n");
                                    break;
                                }//End else
                                
                            }//End while
                        }//End if
                    }//End if
                    
                    else// Not a valid entry
                    {
                        printf("\nInvalid Entry!\n");
                        printf("Please press enter to return to menu and try again\n");
                        break;
                    }//End else
                }//End while
                break;
            }//End case 2
            
            case '3':
            {
                printf("\n(i) PIN has been entered successfully %d times",cor);
                printf("\n(ii) PIN has been entered incorrectly %d times\n\n\n",incor);
                printf("Please press enter to return to menu and try again\n");
                break;
            }//End case 3
            
            case '4':
            {
                printf("\n\nAre you sure you would like to exit (y/n)?\n");
                exit = getchar();
                
                if(exit == 'y')
                {
                    break;
                }//End if
                
                break;
                
            }//End case 4
            
            default://Not a valid entry
            {
                printf("\nInvalid entry\n");
                printf("\nPlease press enter to return to menu and try again\n");
                break;
            }//End default
            
        }//End switch
        
        getchar();
        
    }//End do
    while(exit != 'y');//Continue the loop until the user enters y to end the program
    
    printf("\nGoodbye");
    Sleep(1000);
    
    flushall();
    return 0;
}//end main
