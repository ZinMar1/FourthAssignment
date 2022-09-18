// Created by Zin Mar 9/17/2022.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PersonalData
{

        int id;
        char username[30];
        char password[30];
        int amount;
        int age;
        char location[30];
}p;

void insertData();
void searchData();
void updateData();

 FILE *fp,*fp1;

int main() {

   int code=0;
    char aexit='0';



    do{
        printf("\n");
        printf("Press 1 to INSERT person data.\n");
        printf("Press 2 to SEARCH personal data. \n");
        printf("Press 3 to UPDATE personal data.\n\n");
        printf("Enter a number from above:");
        scanf("%d", &code);
        printf("\n");

            switch(code){

            case 1:

                   insertData();
                    break;
            case 2:
                   searchData();
                 break;
            case 3:
                updateData();
                 break;

            default:

                printf("Invalid Code");
                code=1;
                break;


            }


    printf("\n \n");
    printf("If you want to another operation, Press Y :");
    scanf(" %c", &aexit);
    printf("\n");
    if(aexit!='Y'){
    break;
    }

   }while(code!=0);

    return 0;
}

void insertData(){

    fp=fopen("personalData.txt","a");
    if(fp==NULL){
        puts("File Not Found!");
        exit(1);
    }

    else{
        puts("Enter the personal data: ID,  UserName,  Password,  Amount,  Age,  Location ");
        puts("Enter EOF to end input:");
        printf(">:");

        scanf("%d%s%s%d%d%s", &p.id, p.username, p.password, &p.amount, &p.age, p.location);

       while(!feof(stdin)){
            fprintf(fp,"%d%10s%10s%10d%10d%15s%c", p.id, p.username, p.password, p.amount, p.age, p.location, '\n');
            printf(">:");
            scanf("%d%s%s%d%d%s", &p.id, p.username, p.password, &p.amount, &p.age, p.location);
        }
        fclose(fp);

    }

}


void searchData(){

    fp = fopen("personalData.txt", "r");
    char searchname[30];
    int found=1;
    if(fp!=NULL){
             printf("Enter User Name that you want to search:");
            scanf("%s",searchname);

     while(fscanf(fp,"%d%10s%10s%10d%10d%15s", &p.id,p.username,p.password, &p.amount, &p.age, p.location)!=EOF){



        if(strcmp(p.username,searchname)==0){
                found=0;
                printf(">>>>>>>>>>>> %d", found);
            printf("\n %d %s %s %d %d %s", p.id, p.username, p.password, p.amount, p.age, p.location);
            break;
        }


     }

    }

     if(found!=0){
        printf("Record not found");

     }


    fclose(fp);



}
void updateData(){

    int f=0, updateAmount, updateid;
    char updatename[30], updatePass[30];


    fp=fopen("personalData.txt","r");
    fp1= fopen("temp.txt", "a");

    if(fp==NULL){
        printf("File Not Found!");
        exit(1);
    }


    // display personal data
   while(fscanf(fp,"%d%10s%10s%10d%10d%15s", &p.id,p.username,p.password, &p.amount, &p.age, p.location)!=EOF){
          printf("%d %10s %10s %10d %10d %15s \n", p.id, p.username, p.password,p.amount,p.age,p.location);


   }

   fclose(fp);


   //update personal data

   fp=fopen("personalData.txt","r");

    printf("\n\nEnter a Id number that you want to update data:");
    scanf("%d",&updateid);

   while(fscanf(fp,"%d%10s%10s%10d%10d%15s", &p.id, p.username, p.password, &p.amount, &p.age, p.location)!=EOF){


        if(p.id==updateid){

                f=1;
                puts("Enter new data: UserName Password Amount");
                printf(">:");
                scanf("%s %s %d",updatename, updatePass, &updateAmount);

                fprintf(fp1,"%d %10s %10s %10d %10d %15s \n",p.id,updatename,updatePass, updateAmount, p.age, p.location);

        }
        else{
            fprintf(fp1,"%d %10s %10s %10d %10d %15s \n", p.id, p.username, p.password, p.amount, p.age, p.location);

        }

    }
    if(f==0){

        printf("Recored Not found!\n\n");
    }
    else{
        printf("Successful Updated!\n\n");

    }
      fclose(fp);
      fclose(fp1);


      fp=fopen("personalData.txt","w");
      fp1=fopen("temp.txt","r");

      while(fscanf(fp1,"%d %s %s %d %d %s", &p.id, p.username, p.password, &p.amount, &p.age, p.location)!=EOF){
        fprintf(fp,"%d %10s %10s %10d %10d %15s \n", p.id, p.username, p.password, p.amount, p.age, p.location);
      }
      fclose(fp);
      fclose(fp1);

      fp1=fopen("temp.txt","w");
      fclose(fp1);


      fp=fopen("personalData.txt","r");
       while(fscanf(fp,"%d%10s%10s%10d%10d%15s", &p.id,p.username,p.password, &p.amount, &p.age, p.location)!=EOF){
          printf("%d %s %s %d %d %s \n", p.id, p.username, p.password,p.amount,p.age,p.location);


   }
   fclose(fp);


}
