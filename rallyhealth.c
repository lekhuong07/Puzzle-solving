#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int Numberdigits(int checked){
    int result=0;
    if(checked == 0){
        result ++;
        return result;
    }
    while(checked != 0){
        checked = checked / 10;
        result ++;
    }
    return result;
} 
int countEndingZeros(int checked){
    int result = 0;
    while((checked %10)  == 0){
        checked = checked / 10;
        result++;
    }
    return result;
}
char *RallyHealth(int seq, int N){
    int right, left;
    int N_dig = Numberdigits(N);
    int seq_dig = Numberdigits(seq);
    
    if ((N < 0) || (N == seq) || (N_dig > seq_dig)){ 
        printf("impossible\n" ) ;
        return 0;
    }
    
    //Simple version:
    char* mult = "*";
    char * plus  = "+"; 
    char * minus = "-";
    int right2= 0;
    int left2 = 0;
    bool flag = false;
    for(int i = pow(10,seq_dig - 1); i > 0; i /=10){
        left2 = seq / i;
        right2  = seq % i;
        if(left2 + right2 == N){
          printf("%d%c%d\n", left2, *plus ,right2);
          flag = true;
        }
        else if (left2 - right2 == N){
          printf("%d%c%d\n", left2, *minus ,right2);
          flag = true;
        }
        else if(left2 * right2 == N){
          printf("%d%c%d\n", left2, *mult ,right2);
          flag = true;
        }
   }
   
    int sub_seq_left = seq / pow(10, seq_dig- N_dig);
    int sub_seq_right = seq - sub_seq_left * pow(10,seq_dig - N_dig);
    //printf("%d %d\n", sub_seq_left, sub_seq_right);
    //printf("%d %d\n", Numberdigits(sub_seq_left),Numberdigits(sub_seq_right));
    int right3= 0;
    int left3 = 0;
    int temp3 = 1;
    
    int minsl = 1;
    int minsr = 1;
    int tempt3 = 0;
    
    left3  = sub_seq_left / (int) pow(10,Numberdigits(sub_seq_left) - minsl);
    right3 = sub_seq_left % (int) pow(10,Numberdigits(sub_seq_left) - minsr);
    //printf("%d %d %d\n" , left3, right3, tempt3);
    int prval1 = 0;
    for(int j = pow(10,Numberdigits(right3) - 1); j >0; j /= 10){
        int t_right3 = right3 /j;
        //printf("%d %d %d\n" , left3, t_right3, tempt3);
        if(N% (left3 * t_right3) != 0){
            break;
        }
        tempt3 = left3 * t_right3;
        prval1 = t_right3;
        minsl++;
        //printf("%d %d %d %d\n" , left3, t_right3, prval1, minsl);
    }

    // Split new:
    int newleft3  = sub_seq_left / (int) pow(10,Numberdigits(sub_seq_left) - minsl);
    int newright3 = seq % (int) pow(10,Numberdigits(seq) - Numberdigits(newleft3)) ;
    //printf("%d %d %d\n" , newleft3, newright3, tempt3);
    int ffres = 0;
    int newtempt3 = tempt3;
    int prval2 = 1;
    
    for(int j = pow(10,Numberdigits(newright3)-1); j >0; j /= 10){
        int t_right3 = newright3 /j;
        //printf("%d %d %d\n" , t_right3, tempt3 ,ffres);
        if(N% (newtempt3 * t_right3) != 0){
            //abc = Numberdigits(t_right3);
            break;
        }
        ffres = newtempt3 * t_right3;
        prval2 = t_right3;
    }
    int leftover = 0;
    int counttotal    = Numberdigits(left3) + Numberdigits(prval1) + Numberdigits(prval2);
    

    if((seq_dig - counttotal == 1) && (seq_dig % (int) pow(10,Numberdigits(seq_dig) - 1) == 0)){
        leftover = seq % 10;
        printf("%d%c%d%c%d%c%d\n", left3,*mult,prval1, *mult, prval2, *plus, leftover);
        printf("%d%c%d%c%d%c%d\n", left3,*mult,prval1, *mult, prval2, *minus, leftover);
    }
    else if(seq_dig - counttotal == 0){
        printf("%d%c%d%c%d\n", left3,*mult,prval1, *mult, prval2);
        printf("%d%c%d%c%d\n", left3,*mult,prval1, *mult, prval2);
    }
    else if(flag ==false){
       printf("impossible");
    }
}
int main()
{
    int N    = 2000;
    int seq[] = {2100100, 2200200, 55};

   
    printf("Input: \n%d\n%d\n%d\n%d\n", N, seq[0], seq[1], seq[2]);
    printf("Corresponding output: \n");
    for(int i = 0; i <3 ; i ++){
        RallyHealth(seq[i],N);
        printf("\n");
    }


        
   return 0;
}