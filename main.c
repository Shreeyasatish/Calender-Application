#include <stdio.h>
#include <stdlib.h>

int get_1st_weekday(int year){

  int d;
  d=(((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;//number of days passed till the given year, and obtain how many perfect weeks are there, and the number
  return d;
}

int main()
{
  //  system("Color 3F");
   int year,month,day,daysInMonth,weekDay=0,startingDay;
   printf("\nEnter your desired year:");
   scanf("%d",&year);

   char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
   int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};

   if((year%4==0&&year%100!=0)||year%400==0)
       monthDay[1]=29;

   startingDay=get_1st_weekday(year);

   for(month=0;month<12;month++){

      daysInMonth=monthDay[month];
      printf("\n\n---------------%s-------------------\n",months[month]);
      printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

      for(weekDay=0;weekDay<startingDay;weekDay++)//until the day(sun/mon/tue/wed/thu/fri/sat) for the 1st of any month comes, it prints whitespace.
        printf("     ");//wd=1

      for(day=1;day<=daysInMonth;day++){
        printf("%5d",day);

        if(++weekDay>6){
            printf("\n");
            weekDay=0;
        }
        startingDay=weekDay;
      }

   }

   int flag;
    int i = 0;//takes the value 1 or 0, corresponding to whether the user wants to add an event or not.
   struct event{
     //int date[8];
     int date[8];
     char ev_name[20];
   };
   struct event ev_list[100];

   do{
      printf("\n\ndo you want to add any event to any day of this year? type 1 if yes, 0 if no : ");
      scanf("%d",&flag);
      if(flag!=1 && flag!=0){
        printf("invalid option entered\n");
        printf("do you want to add any event to any day of this year? type 1 if yes, 0 if no : ");
        scanf("%d",&flag);
      }
      else if(flag==1){
      struct event ev_list[i];
      printf("enter the date that you want to add event to in ddmmyyyy, do not include spaces : ");
      for(int j=0; j<8; j++)
      {
        ev_list[i].date[j]=getchar();

      }


      printf("enter the name of the event you want to add to the above mentioned date:");
      scanf(" %[^\n]%s",ev_list[i].ev_name);



      }
      i++;
   }while(flag!=0);
  }
