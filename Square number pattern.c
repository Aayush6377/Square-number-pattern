#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define finame "Square number pattern.txt"  //Macro for changing file name

int main(){
    int n,len;
    printf("Enter a number:");
    scanf("%d",&n);
    char arr[100];
    sprintf(arr,"%d ",n);
    len=strlen(arr); //checking length of entered number
    
    printf("Your file is ready with a name \"%s\" which contains following pattern\n",finame);
    
    FILE *fi=fopen(finame,"w+");
    
    // First half square
    int u=n,m=2*n-1;
    for (int i=1,ii=n+1; i<=n; i++,ii--){
        for (int j=1,jj=ii,o=n; j<=2*n-1; j++){
            char num[len+1];  // checking each element length

            if (j>=i && j<=m){
                sprintf(num,"%d",u);
                fprintf(fi,"%d",u);
                printf("%d",u);
            }
            else if (i>j){
                sprintf(num,"%d",o);
                fprintf(fi,"%d",o);
                printf("%d",o--);
            }
            else {
                sprintf(num,"%d",jj);
                fprintf(fi,"%d",jj);
                printf("%d",jj++);
            }
            
            //Space modifier 1
            for (int k=1; k<=len-strlen(num);k++) {
                fprintf(fi," ");
                printf(" ");
            }
        }
        u--;m--;
        for (int k=1; k<len;k++){  //No. of line checker
            fprintf(fi,"\n");
            printf("\n"); 
        }
    }
    
    // Second half square
    for (int i=1; i<n; i++){
        for (int j=1,m=n,o=i+1; j<=2*n-1; j++){
            char num[len+1]; //checking each element length
           
            if (j>=n-(i-1) && j<=n+(i-1)){
                sprintf(num,"%d",i+1);
                fprintf(fi,"%d",i+1);
                printf("%d",i+1);
            }
            else if (j>=1 && j<n-(i-1)){
                sprintf(num,"%d",m);
                fprintf(fi,"%d",m);
                printf("%d",m--);
            }
            
            else {
                sprintf(num,"%d",o);
                fprintf(fi,"%d",o);
                printf("%d",o++);
            }
            
            //Space modifier 2
            for (int k=1; k<=len-strlen(num); k++){
                fprintf(fi," ");
                printf(" ");
            }
        }
        for (int k=1;k<len; k++){ //No. of line checker
            fprintf(fi,"\n");
            printf("\n");
        }
    }
    
    fclose(fi);
}