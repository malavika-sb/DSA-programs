/*sum of two sparse polynomials using array*/
#include<stdio.h>
#define max 100
typedef struct{
    int coeff;
    int expo;
}term;
term terms[max];
int avail=0;
int read_poly(int *start,int *finish){
    int i,n,coeff,expo;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    *start=avail;
    printf("Enter the terms(coeff expo)in descending order:");
    for(i=0;i<n;i++){
       scanf("%d %d",&coeff,&expo);
       if(avail>max){
        printf("Term limit exceeded!\n");
        return 0;
       }
       terms[avail].coeff=coeff;
       terms[avail].expo=expo;
       avail++;
    }
    *finish=avail-1;
}
void display_poly(int start,int finish){
    int i;
    for(i=start;i<=finish;i++){
        if(i>start && terms[i].coeff>0)
            printf("+");
        printf("%dx^%d",terms[i].coeff,terms[i].expo);
    }
    printf("\n");
}
void add_poly(int startA,int startB,int finishA,int finishB,int *startD,int *finishD){
    int i=startA,j=startB;
    *startD=avail;
    while(i<=finishA && j<=finishB){
        if(terms[i].expo==terms[j].expo){
            int sum=terms[i].coeff + terms[j].coeff;
            if(sum!=0){
                terms[avail].coeff=sum;
                terms[avail].expo=terms[i].expo;
                avail++;
            }
            i++;
            j++;
        }
        else if(terms[i].expo>terms[j].expo){
            terms[avail]=terms[i];
            avail++;
            i++;
        }
        else{
            terms[avail]=terms[j];
            avail++;
            j++;
        }
    }
    while(i<=finishA){
        terms[avail]=terms[i];
        avail++;
        i++;
    }
    while(j<=finishB){
        terms[avail]=terms[j];
        avail++;
        j++;
    }
    *finishD=avail-1;
}
int main(){
    int startA,finishA,startB,finishB,startD,finishD;
    printf("Enter polynomial A:\n");
    read_poly(&startA,&finishA);
    printf("Enter polynomial B:\n");
    read_poly(&startB,&finishB);
    printf("POLYNOMIAL A\n");
    display_poly(startA,finishA);
    printf("POLYNOMIAL B\n");
    display_poly(startB,finishB);
    add_poly( startA, startB, finishA, finishB, &startD, &finishD);
    printf("SUM\n");
    display_poly(startD,finishD);

    return 0;
}