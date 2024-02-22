#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    double a;
    double x = 0;
    double b;
    double c;
    double d; //assigning variables
    printf("Welcome!\n");
    printf("Please enter an positive number in order to find its square root.\n");
    scanf_s("%lf",&a);//getting variable "a" from user
    double f;
    f=x*x-a;

    b=(a/10);
    c= x+b;
    d= c-x;//doing extra math to make the code easier to write

    clock_t t1,t2;
    int executionTime1;
    t1=clock(); //clock function

    //INTERVAL SEARCH METHOD
    while(1){
        for(x=0;x<=a;){
            if((((x*x)-a)*((x+b)*(x+b)-a))>0){

           }//if f(x1)*f(x2) = positive = no root
            else if ((((x*x)-a)*((x+b)*(x+b)-a))<=0){
                printf("Your interval is this: %f %f\n",x , x+b);
                break;
            }//if f(x1)*f(x2) = negative = root
        x = x+b;
    }

        b=b/10;
        if(b<0.0001){
            printf("Your final root from first method %f\n",x);
            break; //calculating root until x2-x1 is less then 0.0001

        }

    }
    t2=clock();
    executionTime1=(int)(t2-t1);//clock function

    clock_t t3,t4;
    int executionTime2;
    t3=clock();//clock function

    printf("\nThis is the ending point of method 1 and starting point of method 2.\n");

    //NEWTON RAPSODY METHOD
    double x1 = a;
    double x2 = 0;
    double x3 = 0; // temp and final value of x on the interval

    if (a < 0) {
        printf("the value of a cannot be a negative number");
    }
    else {
        while ((x1 - x2) >= 0.0001 || (x1 - x2) < -0.0001) {
            x2 = x1;                     
            x3 = 0.5 * (x1 + a / x1);      
            x1 = x3;                       
        }
        printf("Your final root from second method %lf\n", x1);
    }


    t4=clock();
    executionTime2=(int)(t4-t3);//clock function

    double extime;
    extime = executionTime2+executionTime1 ;

    printf("Execution Time: %lf\n",extime);
    
    return 0;
}


