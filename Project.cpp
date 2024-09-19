#include<iostream>
#include<fstream>
using namespace std;

bool validfile(ifstream&,char*,int&,int&);
float** readfile(ifstream&,char*,float**,int&,int&);
void input(float**&,int,int);
float** dynamic(float**,int,int);
void output(float**,int,int);
void writefile(ofstream&,float**,int,int);
void delete_pointer(float**,int,int);

float sum_of_matrix(float**,int,int);
float product_of_matrix(float**,int,int);
float* row_wise_avg(float**,int,int);
float* col_wise_avg(float**,int,int);
float avg_of_matrix(float**,int,int);
void row_wise_sorting(float**,int,int);
void col_wise_sorting(float**,int,int);
void scaler_sum(float**,int,int,float);
float** addition_of_matrix(float**,int,int,float**,int,int);
void scaler_subtract(float**,int,int,float);
void scaler_multiplication(float**,int,int,float);
float** subtraction_of_matrix(float**,int,int,float**,int,int);
float** multiplication_of_matrix(float**,int,int,int,float**);
void scaler_division(float**,int,int,float);
float** transpose(float**,int,int);
float determinant(float**,int,int);

bool valid_scaler(float**,int,int);

int main(){
ifstream infile;
ofstream outfile;
char* file_name=new char [100];
float** matrix,**matrix2,**resultant;
float *ptr=NULL,avg=0;
int row=0,col=0,row2=0,col2=0,option=0,write=0,sum=0,product;
bool valid=0;
int user_input=0;

while(user_input!=18){

cout<<"1.  Sum of Matrix "<<endl;
cout<<"2.  Product of Matrix "<<endl;
cout<<"3.  Row-wise Average "<<endl;
cout<<"4.  Column-wise Average "<<endl;
cout<<"5.  Average of whole Matrix "<<endl;
cout<<"6.  Row-wise sorting of Matrix "<<endl;
cout<<"7.  Column-wise sorting of Matrix "<<endl;
cout<<"8.  Scalar Matrix Addition "<<endl;
cout<<"9.  Addition of two Matrices "<<endl;
cout<<"10. Scalar Matrix Subtraction "<<endl;
cout<<"11. Subtraction of two Matrices "<<endl;
cout<<"12. Scalar Matrix Multiplication "<<endl;
cout<<"13. Multiplication of two Matrices "<<endl;
cout<<"14. Scalar Matrix Division "<<endl;
cout<<"15. Matrix transpose "<<endl;
cout<<"16. Matrix determinant "<<endl;
cout<<"17. Matrix Inverse "<<endl;
cout<<"18. To end the program "<<endl;
cout<<"\nPlease enter option number to perfrom task."<<endl;
cin>>user_input;

if(user_input==1){
matrix=NULL,row=0,col=0,option=0;
valid=0,write=0;
cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;
if(option==1){
valid=1;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
        cout<<"Invalid number of rows and coloumns."<<endl;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);

        matrix=readfile(infile,file_name,matrix,row,col);
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        sum=sum_of_matrix(matrix,row,col);
        outfile<<"The sum of the matrix is: "<<sum<<endl;
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        sum=sum_of_matrix(matrix,row,col);
        cout<<"\nThe sum of the matrix is: "<<sum<<endl;
        
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=0;
        cout<<"Invalid number of rows and coloumns."<<endl;
    }
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        sum=sum_of_matrix(matrix,row,col);
        outfile<<"The sum of the matrix is: "<<sum<<endl;
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        sum=sum_of_matrix(matrix,row,col);
        cout<<"\nThe sum of the matrix is: "<<sum<<endl;
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==2){
matrix=NULL,row=0,col=0,option=0;
valid=0,write=0;

cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);

        matrix=readfile(infile,file_name,matrix,row,col);
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        product=product_of_matrix(matrix,row,col);
        outfile<<"The product of the matrix is: "<<product<<endl;
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        sum=sum_of_matrix(matrix,row,col);
        cout<<"\nThe sum of the matrix is: "<<sum<<endl;
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }  
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);

    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        product=product_of_matrix(matrix,row,col);
        outfile<<"The product of the matrix is: "<<product<<endl;
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        product=product_of_matrix(matrix,row,col);
        cout<<"\nThe product of the matrix is: "<<product<<endl;
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==3){
matrix=NULL,row=0,col=0,option=0;
valid=0;
cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1,write=0;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);

        matrix=readfile(infile,file_name,matrix,row,col);
        ptr=new float [row];
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        ptr=row_wise_avg(matrix,row,col);
        for(int i=0;i<row;i++){
            outfile<<"The average of row ["<<i<<"] = "<<ptr[i]<<endl;
        }
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        ptr=row_wise_avg(matrix,row,col);
        for(int i=0;i<row;i++){
        cout<<"\nThe average of row ["<<i<<"] = "<<ptr[i]<<endl;
        }
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
ptr=new float [row];
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);

    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        ptr=row_wise_avg(matrix,row,col);
        for(int i=0;i<row;i++){
            outfile<<"The average of row ["<<i<<"] = "<<ptr[i]<<endl;
        }
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);

        ptr=row_wise_avg(matrix,row,col);
    
        for(int i=0;i<row;i++){
        cout<<"\nThe average of row ["<<i<<"] = "<<ptr[i]<<endl;
            }
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==4){
matrix=NULL,row=0,col=0,option=0;
valid=0,write=0;

cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);

        matrix=readfile(infile,file_name,matrix,row,col);
        ptr=new float [col];
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        ptr=col_wise_avg(matrix,row,col);
        for(int i=0;i<col;i++){
            outfile<<"The average of col ["<<i<<"] = "<<ptr[i]<<endl;
        }
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        ptr=col_wise_avg(matrix,row,col);
        for(int i=0;i<col;i++){
        cout<<"\nThe average of col ["<<i<<"] = "<<ptr[i]<<endl;
        }
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);

    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        ptr=col_wise_avg(matrix,row,col);
        for(int i=0;i<row;i++){
            outfile<<"The average of col ["<<i<<"] = "<<ptr[i]<<endl;
        }
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);

        ptr=col_wise_avg(matrix,row,col);
    
        for(int i=0;i<col;i++){
        cout<<"\nThe average of col ["<<i<<"] = "<<ptr[i]<<endl;
            }
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}

}
if(user_input==5){
matrix=NULL,row=0,col=0,option=0;
valid=0,write=0;

cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);

        matrix=readfile(infile,file_name,matrix,row,col);
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        avg=avg_of_matrix(matrix,row,col);
        outfile<<"The average of the matrix is: "<<avg<<endl;
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        avg=avg_of_matrix(matrix,row,col);
        cout<<"The average of the matrix is: "<<avg<<endl;
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }    
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        avg=avg_of_matrix(matrix,row,col);
        outfile<<"The average of the matrix is: "<<avg<<endl;
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        avg=avg_of_matrix(matrix,row,col);
        cout<<"\nThe average of the matrix is: "<<avg<<endl;
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==6){
matrix=NULL,row=0,col=0,option=0;
valid=0,write=0;

cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);

        matrix=readfile(infile,file_name,matrix,row,col);
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        row_wise_sorting(matrix,row,col);
        outfile<<"The matrix after row wise sorting is: "<<endl;
        writefile(outfile,matrix,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        row_wise_sorting(matrix,row,col);
        cout<<"The matrix row wise sorting is: "<<endl;
        output(matrix,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }    
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        row_wise_sorting(matrix,row,col);
        outfile<<"The matrix after row wise sorting is: "<<endl;
        writefile(outfile,matrix,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        row_wise_sorting(matrix,row,col);
        cout<<"\nThe matrix after row wise sorting is: "<<endl;
        output(matrix,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==7){
matrix=NULL,row=0,col=0,option=0;
valid=0,write=0;

cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);

        matrix=readfile(infile,file_name,matrix,row,col);
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        col_wise_sorting(matrix,row,col);
        outfile<<"The matrix after col wise sorting is: "<<endl;
        writefile(outfile,matrix,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        col_wise_sorting(matrix,row,col);
        cout<<"The matrix col wise sorting is: "<<endl;
        output(matrix,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }    
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        col_wise_sorting(matrix,row,col);
        outfile<<"The matrix after col wise sorting is: "<<endl;
        writefile(outfile,matrix,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        col_wise_sorting(matrix,row,col);
        cout<<"\nThe matrix after col wise sorting is: "<<endl;
        output(matrix,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==8){
matrix=NULL,row=0,col=0,option=0;
valid=0,write=0;
float num=0;
cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);
        matrix=readfile(infile,file_name,matrix,row,col);
        cout<<"Enter the number for scaler addition: ";
        cin>>num;
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        scaler_sum(matrix,row,col,num);
        outfile<<"The scaler sum of the matrix is: "<<endl;
        writefile(outfile,matrix,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        scaler_sum(matrix,row,col,num);
        cout<<"The scaler sum of matrix is: "<<endl;
        output(matrix,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }    
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);
cout<<"Enter the number for scaler addition: ";
cin>>num;
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        scaler_sum(matrix,row,col,num);
        outfile<<"The scaler sum of matrix is: "<<endl;
        writefile(outfile,matrix,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        scaler_sum(matrix,row,col,num);
        cout<<"\nThe scaler sum of the matrix is: "<<endl;
        output(matrix,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==9){
matrix=NULL,matrix2=NULL,resultant=NULL,row=0,col=0,option=0,row2=0,col2=0;
valid=0,write=0;
float num=0;
bool check=0;
cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open to read matrix 1: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    matrix=dynamic(matrix,row,col);
    matrix=readfile(infile,file_name,matrix,row,col);
    
    cout<<"Enter the filename you want to open to read matrix 2: ";
    cin>>file_name;

    valid=validfile(infile,file_name,row2,col2);

    if((row2 == 0)|| (col2 == 0)){
        valid=false;
    }
    matrix2=dynamic(matrix2,row2,col2);
    matrix2=readfile(infile,file_name,matrix2,row2,col2);
    
    if((row!=row2) || (col!=col2)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        
        outfile<<"The matrix 1 read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        
        outfile<<"The matrix 2 read from file is : "<<endl;
        writefile(outfile,matrix2,row2,col2);

        resultant=addition_of_matrix(matrix,row,col,matrix2,row2,col2);
        outfile<<"The addition of the matrixes is: "<<endl;
        writefile(outfile,resultant,row,col);
        
        outfile.close();
        delete_pointer(matrix,row,col);

        }
        if(write==2){
        cout<<"\nThe matrix 1 read from file is : "<<endl;
        output(matrix,row,col);
        
        cout<<"\nThe matrix 2 read from file is : "<<endl;
        output(matrix2,row2,col2);

        resultant=addition_of_matrix(matrix,row,col,matrix2,row2,col2);
        
        cout<<"The sum of the matrixes is: "<<endl;
        output(resultant,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }    
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
matrix=dynamic(matrix,row,col);
input(matrix,row,col);

cout<<"Enter the size of row of 2D martrix: ";
cin>>row2;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col2;
    if((row2 == 0)|| (col2 == 0)){
        valid=false;
    }
matrix2=dynamic(matrix2,row2,col2);
input(matrix2,row2,col2);

if((row!=row2) || (col!=col2)){
    valid=false;
}

if(valid==1){
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        
        outfile<<"The matrix 1 entered is : "<<endl;
        writefile(outfile,matrix,row,col);
        
        outfile<<"The matrix 2 entered is : "<<endl;
        writefile(outfile,matrix2,row2,col2);

        outfile<<"The sum of matrixes is: "<<endl;
        resultant=addition_of_matrix(matrix,row,col,matrix2,row2,col2);
        writefile(outfile,resultant,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix 1 read from file is : "<<endl;
        output(matrix,row,col);

        cout<<"\nThe matrix 2 read from file is : "<<endl;
        output(matrix2,row2,col2);

        resultant=addition_of_matrix(matrix,row,col,matrix2,row2,col2);
        cout<<"\nThe sum of the matrixes is: "<<endl;
        output(resultant,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==10){
matrix=NULL,row=0,col=0,option=0;
valid=0,write=0;
float num=0;
cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);
        matrix=readfile(infile,file_name,matrix,row,col);
        cout<<"Enter the number for scaler subtraction: ";
        cin>>num;
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        scaler_subtract(matrix,row,col,num);
        outfile<<"The scaler subtraction of the matrix is: "<<endl;
        writefile(outfile,matrix,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        scaler_subtract(matrix,row,col,num);
        cout<<"The scaler subtraction of matrix is: "<<endl;
        output(matrix,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }    
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);
cout<<"Enter the number for scaler subtraction: ";
cin>>num;
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        scaler_subtract(matrix,row,col,num);
        outfile<<"The scaler subtraction of matrix is: "<<endl;
        writefile(outfile,matrix,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        scaler_subtract(matrix,row,col,num);
        cout<<"\nThe scaler subtraction of the matrix is: "<<endl;
        output(matrix,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==11){
matrix=NULL,matrix2=NULL,resultant=NULL,row=0,col=0,option=0,row2=0,col2=0;
valid=0,write=0;
float num=0;
bool check=0;
cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open to read matrix 1: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    matrix=dynamic(matrix,row,col);
    matrix=readfile(infile,file_name,matrix,row,col);
    
    cout<<"Enter the filename you want to open to read matrix 2: ";
    cin>>file_name;

    valid=validfile(infile,file_name,row2,col2);

    if((row2 == 0)|| (col2 == 0)){
        valid=false;
    }
    matrix2=dynamic(matrix2,row2,col2);
    matrix2=readfile(infile,file_name,matrix2,row2,col2);
    
    if((row!=row2) || (col!=col2)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        
        outfile<<"The matrix 1 read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        
        outfile<<"The matrix 2 read from file is : "<<endl;
        writefile(outfile,matrix2,row2,col2);

        resultant=subtraction_of_matrix(matrix,row,col,matrix2,row2,col2);
        outfile<<"The subtraction of the matrixes is: "<<endl;
        writefile(outfile,resultant,row,col);
        
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix 1 read from file is : "<<endl;
        output(matrix,row,col);
        
        cout<<"\nThe matrix 2 read from file is : "<<endl;
        output(matrix2,row2,col2);

        resultant=subtraction_of_matrix(matrix,row,col,matrix2,row2,col2);
        
        cout<<"The subtraction of the matrixes is: "<<endl;
        output(resultant,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }    
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
matrix=dynamic(matrix,row,col);
input(matrix,row,col);

cout<<"Enter the size of row of 2D martrix: ";
cin>>row2;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col2;
    if((row2 == 0)|| (col2 == 0)){
        valid=false;
    }
matrix2=dynamic(matrix2,row2,col2);
input(matrix2,row2,col2);

if((row!=row2) || (col!=col2)){
    valid=false;
}

if(valid==1){
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        
        outfile<<"The matrix 1 entered is : "<<endl;
        writefile(outfile,matrix,row,col);
        
        outfile<<"The matrix 2 entered is : "<<endl;
        writefile(outfile,matrix2,row2,col2);

        outfile<<"The subtraction of matrixes is: "<<endl;
        resultant=subtraction_of_matrix(matrix,row,col,matrix2,row2,col2);
        writefile(outfile,resultant,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix 1 read from file is : "<<endl;
        output(matrix,row,col);

        cout<<"\nThe matrix 2 read from file is : "<<endl;
        output(matrix2,row2,col2);

        resultant=subtraction_of_matrix(matrix,row,col,matrix2,row2,col2);
        cout<<"\nThe subtraction of the matrixes is: "<<endl;
        output(resultant,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==12){
matrix=NULL,row=0,col=0,option=0;
valid=0,write=0;
float num=0;
cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);
        matrix=readfile(infile,file_name,matrix,row,col);
        cout<<"Enter the number for scaler multiplication: ";
        cin>>num;
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        scaler_multiplication(matrix,row,col,num);
        outfile<<"The scaler multiplication of the matrix is: "<<endl;
        writefile(outfile,matrix,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        scaler_multiplication(matrix,row,col,num);
        cout<<"The scaler multiplication of matrix is: "<<endl;
        output(matrix,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }    
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);
cout<<"Enter the number for scaler multiplication: ";
cin>>num;
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        scaler_multiplication(matrix,row,col,num);
        outfile<<"The scaler multiplication of matrix is: "<<endl;
        writefile(outfile,matrix,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        scaler_multiplication(matrix,row,col,num);
        cout<<"\nThe scaler multiplication of the matrix is: "<<endl;
        output(matrix,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==13){
matrix=NULL,matrix2=NULL,resultant=NULL,row=0,col=0,option=0,row2=0,col2=0;
valid=0,write=0;
float num=0;
bool check=0;
cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open to read matrix 1: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    matrix=dynamic(matrix,row,col);
    matrix=readfile(infile,file_name,matrix,row,col);
    
    cout<<"Enter the filename you want to open to read matrix 2: ";
    cin>>file_name;

    valid=validfile(infile,file_name,row2,col2);

    if((row2 == 0)|| (col2 == 0)){
        valid=false;
    }
    matrix2=dynamic(matrix2,row2,col2);
    matrix2=readfile(infile,file_name,matrix2,row2,col2);
    
    if(row!=col2){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        
        outfile<<"The matrix 1 read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        
        outfile<<"The matrix 2 read from file is : "<<endl;
        writefile(outfile,matrix2,row2,col2);

        resultant=multiplication_of_matrix(matrix,row,col2,col,matrix2);
        outfile<<"The multiplication of the matrixes is: "<<endl;
        writefile(outfile,resultant,row,col2);
        
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix 1 read from file is : "<<endl;
        output(matrix,row,col);
        
        cout<<"\nThe matrix 2 read from file is : "<<endl;
        output(matrix2,row2,col2);

        resultant=multiplication_of_matrix(matrix,row,col2,col,matrix2);
        
        cout<<"The multiplication of the matrixes is: "<<endl;
        output(resultant,row,col2);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }    
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
matrix=dynamic(matrix,row,col);
input(matrix,row,col);

cout<<"Enter the size of row of 2D martrix: ";
cin>>row2;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col2;
    if((row2 == 0)|| (col2 == 0)){
        valid=false;
    }
matrix2=dynamic(matrix2,row2,col2);
input(matrix2,row2,col2);

if(row!=col2){
    valid=false;
}

if(valid==1){
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        
        outfile<<"The matrix 1 entered is : "<<endl;
        writefile(outfile,matrix,row,col);
        
        outfile<<"The matrix 2 entered is : "<<endl;
        writefile(outfile,matrix2,row2,col2);

        outfile<<"The multiplication of matrixes is: "<<endl;
        resultant=multiplication_of_matrix(matrix,row,col2,col,matrix2);
        writefile(outfile,resultant,row,col2);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix 1 read from file is : "<<endl;
        output(matrix,row,col);

        cout<<"\nThe matrix 2 read from file is : "<<endl;
        output(matrix2,row2,col2);

        resultant=multiplication_of_matrix(matrix,row,col2,col,matrix2);
        cout<<"\nThe multiplicationof the matrixes is: "<<endl;
        output(resultant,row,col2);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==14){
matrix=NULL,row=0,col=0,option=0;
valid=0,write=0;
float num=0;
cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);
        matrix=readfile(infile,file_name,matrix,row,col);
        cout<<"Enter the number for scaler division: ";
        cin>>num;
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        scaler_division(matrix,row,col,num);
        outfile<<"The scaler division of the matrix is: "<<endl;
        writefile(outfile,matrix,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        scaler_division(matrix,row,col,num);
        cout<<"The scaler division of matrix is: "<<endl;
        output(matrix,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }    
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);
cout<<"Enter the number for scaler division: ";
cin>>num;
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        scaler_division(matrix,row,col,num);
        outfile<<"The scaler division of matrix is: "<<endl;
        writefile(outfile,matrix,row,col);
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        scaler_division(matrix,row,col,num);
        cout<<"\nThe scaler division of the matrix is: "<<endl;
        output(matrix,row,col);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input==15){
matrix=NULL,row=0,col=0,option=0;
valid=0,write=0;
float num=0;
cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;

if(option==1){
valid=1;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);
        matrix=readfile(infile,file_name,matrix,row,col);

        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,col,row);
        
        resultant=transpose(matrix,row,col);
        outfile<<"The trasnpose of the matrix is: "<<endl;
        writefile(outfile,resultant,col,row);
        
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        
        resultant=transpose(matrix,row,col);
        cout<<"The transpose of matrix is: "<<endl;
        
        output(resultant,col,row);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }    
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=false;
    }
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);

    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        
        resultant=transpose(matrix,row,col);
        outfile<<"The transpose of matrix is: "<<endl;
        writefile(outfile,resultant,col,row);
        
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        
        resultant=transpose(matrix,row,col);
        cout<<"\nThe transpose of the matrix is: "<<endl;
        
        output(resultant,col,row);
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}    
}
if(user_input==16){
matrix=NULL,row=0,col=0,option=0;
valid=0,write=0;
cout<<"Select from the options given: "<<endl;
cout<<"Press 1: To read data from file."<<endl;
cout<<"Press 2: To input data on console."<<endl;
cin>>option;
if(option==1){
valid=1;
cout<<"Enter the filename you want to open: ";
cin>>file_name;

    valid=validfile(infile,file_name,row,col);

    if((row == 0)|| (col == 0)){
        valid=false;
        cout<<"Invalid number of rows and coloumns."<<endl;
    }
    if(valid==1){
    while((write!=1) && (write!=2)){
        matrix=dynamic(matrix,row,col);

        matrix=readfile(infile,file_name,matrix,row,col);
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        sum=determinant(matrix,row,col);
        outfile<<"The determinant of the matrix is: "<<sum<<endl;
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        sum=determinant(matrix,row,col);
        cout<<"\nThe determinant of the matrix is: "<<sum<<endl;
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else if(option==2){
valid=1,write=0;
cout<<"Enter the size of row of 2D martrix: ";
cin>>row;
cout<<"Enter the size of coloum of 2D matrix: ";
cin>>col;
    if((row == 0)|| (col == 0)){
        valid=0;
        cout<<"Invalid number of rows and coloumns."<<endl;
    }
if(valid==1){
matrix=dynamic(matrix,row,col);

//Calling the input function to take input in the matrix:
input(matrix,row,col);
    while((write!=1) && (write!=2)){
        cout<<"Please choose from the options: "<<endl;
        cout<<"Press 1 to write data in file."<<endl;
        cout<<"Press 2 to output data on console."<<endl;
        cin>>write;

        if(write==1){
        cout<<"Enter the file name in which you want to store data: ";
        cin>>file_name;
        outfile.open(file_name);
        outfile<<"The matrix read from file is : "<<endl;
        writefile(outfile,matrix,row,col);
        sum=determinant(matrix,row,col);
        outfile<<"The determinant of the matrix is: "<<sum<<endl;
        outfile.close();
        delete_pointer(matrix,row,col);
        }
        if(write==2){
        cout<<"\nThe matrix read from file is : "<<endl;
        output(matrix,row,col);
        sum=determinant(matrix,row,col);
        cout<<"\nThe determinant of the matrix is: "<<sum<<endl;
        }
        else if((write!=1) && (write!=2)){
            cout<<"Invalid option selected."<<endl;
            cout<<"Enter the value again: "<<endl;
            }
        }
    }
}
else{
    cout<<"You selected an invalid option."<<endl;
}
}
if(user_input!=18){
    cout<<"Press any key to continue (except 18): ";
    cin>>user_input;
    system("CLS");
}
if((user_input>=19 )||(user_input<=0)){
    cout<<"Enter value between 1 to 18."<<endl;
}
}


return 0;
}
bool validfile(ifstream& infile,char* file_name,int& row,int& col){
bool valid=0,flag=0;
float num=0;
//Function to count rows and coloumns
infile.open(file_name);
if(infile.is_open()){
    valid=1;
    cout<<file_name<<" successfully opened."<<endl;
    while(!infile.eof()){
    infile>>num;
    if(num==-99){
        flag=1;
        row++;
    }    
    if(flag==0){
        if(num!=-99){
            col++;
            }
        }
    }
infile.close();
}
else{
    cout<<"Error in opening "<<file_name<<" file."<<endl;
    valid=0;
}

return valid;
}
void input(float**& matrix,int row,int col){
    //creation of dynamic memory
    matrix=dynamic(matrix,row,col);

    //Taking input in 2D matrix
    cout<<"Enter data in 2-D Matrix: "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"Enter number at row ["<<i<<"] col["<<j<<"] = ";
            cin>>matrix[i][j];
        }
    }
}
float** readfile(ifstream& infile,char* file_name,float** matrix,int& row,int& col){
//Function to read data from file
    float num=0;
    infile.open(file_name);
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; ){
			infile >> num;
			if (num != -99){
				matrix[i][j] = num;
				j++;
			}
		}
	}
    infile.close();
return matrix;
}
void delete_pointer(float** matrix, int row, int col) {
	//Function for deleting pointer
    for (int i = 0; i < row; i++) {
		delete[]matrix[i];
	}
	delete[] matrix;
}
float** dynamic(float** matrix,int row,int col){
    
    //Function for creating dynamic memory

    matrix=new float *[row];
    for(int i=0;i<row;i++){
        matrix[i]=new float [col];
    }

return matrix;
}
void output(float** matrix,int row,int col){
//Function to output data on screen

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void writefile(ofstream& outfile,float** matrix,int row,int col){
//Function to write data in file

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            outfile<<matrix[i][j]<<" ";
        }
        outfile<<endl;
    }
    outfile<<"Data successfully written in file."<<endl;
}
float sum_of_matrix(float** matrix,int row,int col){
    //Function to calculate sum of the whole matrix

    float sum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            sum=sum+matrix[i][j];
        }
    }
    return sum;
}
float product_of_matrix(float** matrix,int row,int col){
    //Function to calculate product of the whole matrix
    float product=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
  
            product=product*matrix[i][j];
        }
    }
    return product;
}
float* row_wise_avg(float** matrix,int row,int col){
    //Function to calculate row wise avergae of matrix
    float sum=0,total=0;
    float *ptr=new float [row];
    total=col;
    for(int i=0;i<row;i++){
        sum=0;
        for(int j=0;j<col;j++){
            sum=sum+matrix[i][j];
        }
        sum=sum/total;
        ptr[i]=sum;
    }
    return ptr;
}
float* col_wise_avg(float** matrix,int row,int col){
    //Function to calculate coloumn wise avergae of matrix
    float sum=0,total=0;
    float* ptr=new float [col];
    total=row;
    for(int i=0;i<col;i++){
        sum=0;
        for(int j=0;j<row;j++){
            sum=sum+matrix[j][i];
        }
        sum=sum/total;
        ptr[i]=sum;
    }
    return ptr;
}
float avg_of_matrix(float** matrix,int row,int col){
    //Function to calculate avergae of whole matrix
    float sum=0,total=0;
    total=row*col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            sum=sum+matrix[i][j];
        }
    }
        sum=sum/total;
        return sum;
}
void row_wise_sorting(float** matrix,int row,int col){
    float temp=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            for(int k=0;k<col;k++){
                if(matrix[i][j]<matrix[i][k]){
                    temp=matrix[i][j];
                    matrix[i][j]=matrix[i][k];
                    matrix[i][k]=temp;
                }
            }
        }
    }
}
void col_wise_sorting(float** matrix,int row,int col){
    float temp=0;
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            for(int k=0;k<row;k++){
                if(matrix[j][i]<matrix[k][i]){
                    temp=matrix[j][i];
                    matrix[j][i]=matrix[k][i];
                    matrix[k][i]=temp;
                }
            }
        }
    }
}
bool valid_scaler(float** matrix,int row,int col){
    bool scaler=true;
    float num=0;
    if(row!=col){
        scaler=false;
    }
    else if(row==col){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                num=matrix[0][0];
                if(i==j){
                    if(matrix[i][j]!=num){
                        scaler=false;
                    }
                }
                if(i!=j){
                    if(matrix[i][j]!=0){
                        scaler=false;
                    }
                }
            }
            if(scaler==false){
                break;
            }
        }
    }
    return scaler;
}
void scaler_sum(float** matrix,int row,int col,float num){
    float sum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            matrix[i][j]=num+matrix[i][j];
        }
    }
}
void scaler_subtract(float** matrix,int row,int col,float num){
    float subtract=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            matrix[i][j]=matrix[i][j]-num;
        }
    }
}
void scaler_multiplication(float** matrix,int row,int col,float num){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            matrix[i][j]=matrix[i][j]*num;
        }
    }
}
void scaler_division(float** matrix,int row,int col,float num){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            matrix[i][j]=matrix[i][j]/num;
        }
    }
}
float** addition_of_matrix(float** matrix1,int row1,int col1, float** matrix2,int row2,int col2){
    float** resultant=NULL;
    resultant=dynamic(resultant,row1,col1);
    for(int i=0;i<row1;i++){
        for(int j=0;j<row2;j++){
            resultant[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
    return resultant;
}
float** subtraction_of_matrix(float** matrix1,int row1,int col1, float** matrix2,int row2,int col2){
    float** resultant=NULL;
    resultant=dynamic(resultant,row1,col1);
    for(int i=0;i<row1;i++){
        for(int j=0;j<row2;j++){
            resultant[i][j]=matrix1[i][j]-matrix2[i][j];
        }
    }
    return resultant;
}
float** multiplication_of_matrix(float** matrix1,int row1,int col2,int col1,float** matrix2){
    float** resultant=NULL,sum=0;
    resultant=dynamic(resultant,row1,col2);
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            sum=0;
            for(int k=0;k<col1;k++){
                sum=sum+matrix1[i][k]*matrix2[k][j];
            }
            resultant[i][j]=sum;
        }
    }
    return resultant;
}
float** transpose(float** matrix,int row,int col){
    float** resultant=NULL;
    resultant=dynamic(resultant,col,row);

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            resultant[j][i]=matrix[i][j];
        }
    }
return resultant;
}
float determinant(float** matrix,int row,int col){
    float num1=0,num2=0,ans=0;
    for(int i=0;i<row;i++){
        if(i==0){
        num1=matrix[i][i]*matrix[col-1][col-1];
        }
        if(i==1){
        num2=matrix[0][i]*matrix[i][0];
        }
    }
    ans=num1-num2;
    return ans;
}