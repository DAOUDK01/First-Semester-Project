#include <stdio.h>    // using this header file to get access to predefined function like printf and scanf 
#include <stdlib.h>     // using this header file to get access to predefined function for clear screen
#include <unistd.h>  // using this header file to get access to predefined function for sleep
#include <time.h>    // using for ctime and time function and time_t datatype
int  h ,m ,s, opt,opt1,n,counter=0;     // All variables using in this project

//  Function for set Time 
void setTime(int h,int m , int s){
	  while(1){     // external infinite loop 
       for(h;h<24;h++ ){     // loop for hours 
         for(m;m<60;m++ ){  // loop for minutes 
         for(s;s<60;s++ ){  // loop for seconds
         sleep(1);   // sleep for 1000 mili-seconds 
           system("cls");   // clear screen after every display
         printf("\t\t\tTime : %02d::%02d::%02d\n",h,m,s);    // h::m::s    
 }
       s=0;   
       
     }
         m=0;
     }
     h=0;
   }
  
}

//  Function for Timer
void Timer(int m, int s){
	  int totalTime = m * 60 + s;// total time = 1*60+0= 60 seconds
	   
    while (totalTime > 0) { //   60>0  
        int currentMinutes = totalTime / 60;   //mintes are in seconds therefore we divide it by 60
        int currentSeconds = totalTime % 60;   // Reamining seconds are added in currentSeconds
        
        printf("\t\t\tTimer : %02d:%02d\n", currentMinutes, currentSeconds);  //  01::00
      
           sleep(1);               // Wait for one second
           system("cls");
        totalTime--;
         
        
    }

    printf("Time's up!\n");
}

// Function for count number of digits 
void Count(){
	printf("\n\t\t\t-------ENTER DIGITS TO COUNT------- \n\t\t\t");
		printf("\n Enter Any Number :");
		scanf("%d",&n);
		while(n!=0){ // Run until n equals to 0
			n/=10; // Every value behind decimal point will get ignored by compiler. By using 10 we are adding decimal points 
			++counter; // increment in variable counter
		}
		printf(" Total Digits Are : %d ", counter);
}

// Function to find Current time  
void current(){
	time_t t;   // creating object t
	time(&t); //  passing object address as an argument
	printf( "\n \t\t\t %s",ctime(&t));
}

// Function to take data 
int takedata(){
	printf("\n\t\t\t------ENTER TIME------\n");
	printf("\nEnter Hours   :  ");    
  scanf("%d", &h);  // taking hours from user
  printf("Enter Minutes :  ");
  scanf("%d", &m);   // taking minutes from user
    printf("Enter Seconds :  ");
     scanf("%d", &s);
     return h,m,s;
}

// Main Function
int main(){
  
       
 printf("\t\t\t\t------ Main Menu ------\n \n\t\t 1) Clock \n \t\t 2) Timer \n \t\t 3) Counter \n\t\t 4) Current Time \n\t\t 5) Exit \n\t\t ");
 printf("\n\t\t\tSelect one of the above : ");
  scanf("%d",&opt);
  switch (opt){
  	case 1:
  		takedata();
  		setTime(h,m,s);
  		break;
  	case 2:
  			takedata();
  	     	Timer(m,s);
  	    	break;
  	case 3:
  			Count();
  			break;
  	case 4:
          current();
  		break;
  	case 5:
  		close(1);
  		break;
  	
  	default:
  		printf("\n\t\t\t--------Invalid Expression!--------");
  	
  }  
  }
   
 
 
