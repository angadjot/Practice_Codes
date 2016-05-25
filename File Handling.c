//File Handling - Inventory System
#include<stdio.h>

struct accounts{
    
    float costprice;
    float saleprice;
    char net[20];
    float profit;
    float loss;
};
struct Inventory{
    char name[10];
    int number;
    float price;
    int quantity;
    struct accounts a1;
};

void printline(void );
void append(struct Inventory [],int , FILE *);
void profit_loss(struct accounts [],FILE *,char []);

int main(){
    
    FILE *fp;
    
    int n,choice,num;
    char filename[20];
    struct Inventory item[10];
    
    printline();
    printf("Enter the file name to store data\n");
    scanf("%s",filename);
    printline();
    
    printf("Enter the number of items to add in inventory\n");
    scanf("%d",&n);
    printline();
    
        fp=fopen(filename,"w");
    
    if (fp==NULL) {
        printf("File Not Found\n");
        printline();
        return(0);
    }
    
    printf("Enter Inventory Data :\n");
    printline();
    
    for (int i=0; i<n; i++) {
        printf("\nFor Item %d :\n\n",i+1);
        printf("Enter the Name of the Item\n");
        scanf("%s",item[i].name);
        printf("Enter the Item Number\n");
        scanf("%d",&item[i].number);
        printf("Enter the price of Item\n");
        scanf("%f",&item[i].price);
        printf("Enter the Quantity of Item\n");
        scanf("%d",&item[i].quantity);
    }
    
    printline();
    
    for (int i=0; i<n; i++) {
        fwrite(&item[i],sizeof(item[i]),1,fp);
    }
    
    fclose(fp);
    
    do{
        fp=fopen(filename,"a+");
        printf("Do you want to add more items to Inventory (1 for YES / 0 for NO)\n");
        scanf("%d",&choice);
        if (choice==1) {
            append(item,n,fp);
        }
    }while(choice==1);
    
    fclose(fp);
    
    printline();
    printf("Enter the Number of items to print\n");
    scanf("%d",&num);
    printline();
    printf("Inventory Data :\n");
    printline();
    
    do{
        printf("Would you like to calculate Profit and Loss (1 for YES / 0 for NO)\n");
        scanf("%d",choice);
        if (choice==1) {
            profit_loss(item,fp,filename);
        }
    }while (choice==1);
    
    fp=fopen(filename,"r");
    for (int i=0; i<num; i++) {
        fread(&item[i],sizeof(item[i]),1,fp);
        printf("\nItem %d :\n\n",i+1);
        printf("Item Name : %s\n",item[i].name);
        printf("Item Number : %d\n",item[i].number);
        printf("Item Price : %.2f\n",item[i].price);
        printf("Item Quantity : %d\n",item[i].quantity);
    }
    
    fclose(fp);
    printline();
        
    return(0);
}

void printline(void){
    
    for (int i=0; i<80; i++) {
        printf("-");
    }
    printf("\n");
}

void append(struct Inventory item[],int num, FILE *file){
    
    int n;
    
    printline();
    printf("Enter the amount of items to add\n");
    scanf("%d",&n);
    printline();
    
    printf("Enter Inventory Data :\n");
    printline();
    
    for (int i=num; i<(num+n); i++) {
        printf("\nFor Item %d :\n\n",i+1);
        printf("Enter the Name of the Item\n");
        scanf("%s",item[i].name);
        printf("Enter the Item Number\n");
        scanf("%d",&item[i].number);
        printf("Enter the price of Item\n");
        scanf("%f",&item[i].price);
        printf("Enter the Quantity of Item\n");
        scanf("%d",&item[i].quantity);
    }
    
    printline();
    
    for (int i=num; i<(num+n); i++) {
        fwrite(&item[i],sizeof(item[i]),1,file);
    }
    
}

void profit_loss(struct accounts item[],FILE *file,char name[]){
    
    int n;
    
    printf("Enter the number of items to find Profit or Loss\n");
    scanf("%d",&n);
    printline();
    
    file=fopen(name,"r");
    
    for (int i=0; i<n; i++) {
        fread(&item[i],sizeof(item[i]),1,file);
    }
    fclose(file);
    
    
    printf("Enter Inventory Data :\n");
    printline();
    
    for (int i=0; i<n; i++) {
        printf("\nFor Item %d :\n\n");
        printf("Enter the cost price of item\n");
        scanf("%f",&item[i].a1.costprice);
        printf("Enter the sale price of item\n");
        scanf("%f",&item[i].a1.saleprice);
    }
    
    for (int i=0; i<n; i++) {
        
        if (item[i].a1.costprice>item[i].a1.saleprice) {
            item[i].a1.net='LOSS';
            item[i].a1.loss=(item[i].a1.costprice-item[i].a1.saleprice);
        }
        else{
            item[i].a1.net='PROFIT';
            item[i].a1.profit=(item[i].a1.saleprice-item[i].a1.costprice);
        }
        
    }
    
    file=fopen(name,"w");
    for (int i=0; i<n; i++) {
        fwrite(&item[i],sizeof(item[i]),1,file);
    }
    
    fclose(file);
    
}