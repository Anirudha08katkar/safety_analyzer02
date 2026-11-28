#include<stdio.h>
#include <string.h>
#include <ctype.h>
void passwordanalyzer();
void spam_messageanalyzer();
void urlanalyzer();

int main(){
    int choice;


    printf("================SMART SAFETY ANALYZER===============\n");
    printf("1.Password safety\n");
    printf("2. Spam message safety\n");
    printf("3.URL safety\n");
   

    printf("Enter your choice:");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            passwordanalyzer();
            break;
        case 2:
            spam_messageanalyzer();
            break;
        case 3:
            urlanalyzer();
            break;
        default:
            printf("Invalid choice");
    }
}


    void passwordanalyzer()
    {
        char password[100];
        int score=0;
        int length=0;
        int uppercase=0;
        int lowercase=0;
        int digit=0;
        int specialchar=0;

        printf("\n========Password Safety Analyzer========\n");
        printf("Enter your password:");
        scanf("%99s",password);

        //Length check
        if(strlen(password)>10){
            score+=25;
        }
        //character check
        for(int i=0;password[i] != '\0';i++){
            if(isupper(password[i])){
                uppercase =1;
            }
            if(islower(password[i])){
                lowercase =1;
            }
            if(isdigit(password[i])){
                digit =1;
            }
            if(!isalnum(password[i])){
                specialchar =1;

            }
        }
        if (uppercase == 1){
            score +=20;
        }
        if (lowercase == 1){
            score +=15;
        }
        if(digit == 1){
            score +=20;
        }
        if(specialchar == 1){
            score +=20;
        }

        printf("\nPassword score: %d\n",score);

        if(score>=80){
            printf("Your password is very strong\n");

        }
        else if(score>=60 && score<80){
            printf("Your password is strong enough\n");

        }
        else if(score>=40 && score<60){
            printf("Your password is of medium strength\n");
        }
        else{
            printf("Your password is weak\n");

        }





    }

    void spam_messageanalyzer()
    {
        int score=0;
        char message[1000];
        int urgent=0;
        int prize=0;
        int otp=0;
        int link=0;

        printf("\n========Spam Message Safety Analyzer========\n");
        printf("Enter or copy paste your message:");
        fgets(message, sizeof(message), stdin);

        //convert to lowercase for case insensitive comparison
        for(int i=0; message[i] != '\0'; i++){
            message[i] = tolower(message[i]);
        }

        //check for urgent words
        if(strstr(message,"urgent") != NULL || 
        strstr(message,"immediate") != NULL || 
        strstr(message,"within 24 hours") != NULL)
        {
            urgent = 1;
            score += 20;
        }

        //check for prize/lottery words
        if(strstr(message,"prize") !=NULL ||
           strstr(message,"lottery") !=NULL ||
           strstr(message,"winner") !=NULL ||
           strstr(message,"congratulations") !=NULL ||
           strstr(message,"claim") !=NULL)
           {
            prize = 1;
            score += 20;

           }


        //check for suspicious messages
        if(strstr(message,"otp") !=NULL ||
           strstr(message,"password") !=NULL ||
           strstr(message,"bank") !=NULL ||
           strstr(message,"account") !=NULL )
           {
            otp=1;
            score+=20;
           }
        printf("\n=====ANALYSIS RESULT=====\n");
        printf("Spam message score: %d/100\n", score);

        if(score >=60){

           printf("Risk level:HIGH\n");
        }
           else if(score >=30 && score <60){
            printf("Risk level:MEDIUM\n");
           }
           else{
            printf("Risk level:LOW\n");
           }
           if(urgent==1){
            printf("Message contains urgent words\n");
           }
           if(prize==1){
            printf("Message contains prize/lottery words\n");
           }
           if(link==1){
            printf("Message contains suspicious links\n");
           }
           if(otp==1){
            printf("Message contains OTP/password/bank/account words\n");
           }
           if(urgent==0 && prize==0 && link==0 && otp==0){
            printf("Message does not contain any suspicious words\n");
           }

    }

    void urlanalyzer()
    {
        int score=0;
        char url[100];
        int http=0;

        printf("\n========URL Safety Analyzer========\n");
        printf("Enter your URL here:");
        fgets(url,sizeof(url),stdin);

        //length check
        if(strlen(url)>10){
            score+=20;
        }
        //check for https
        if(strstr(url,"http://") != NULL){
            http = 1;
            score += 20;
        }
        
        if(score>=30){
            printf("your URL is not safe\n");

        }
        else if(score>=10 && score<30){
            printf("your URL is safe\n");
        }
        else{
            printf("your URL is very safe\n");
        }


    }





