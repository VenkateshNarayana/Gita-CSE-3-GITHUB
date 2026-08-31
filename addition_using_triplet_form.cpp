/*perform matrix addition using triplet form
Algorithm 
============
Step1 : Check if the Dimensions(row and col) of matrix1 and matrix2 are same? if Not, addition cannot be performed
Step2 : transform the matrix1 & matrix 2 into triplet forms
Step3 : create the resultant triplet matrix with dimension (n = r1-1 + r2-1) +1(header) and col = 3
Step4 : fill the header information(r,c,v) ---> r = r1/r2, c = c1/c2, v = (n)-1 
Step5 : populate the row information as per the following 3 conditions,
		case 1: when r1 = r2 and c1 = c2 then
				fill the information(r,c,v) ---> r = r1/r2, c = c1/c2, v = v1+v2
		case 2: when r1 = r2 and c1 != c2 then
				if c1 < c2 then
					fill the information(r,c,v) ---> r = r1, c = c1, v = v1
				else
				    fill the information(r,c,v) ---> r = r2, c = c2, v = v2
		case 3: when r1 != r2 and c1 != c2 then
				if r1 < r2 then
					fill the information(r,c,v) ---> r = r1, c = c1, v = v1
				else
				    fill the information(r,c,v) ---> r = r2, c = c2, v = v2
				
*/
#include<stdio.h>
//param1:original matrix,param2:orginal matrix row,param3:orginal matrix col,param4:trip matrix ,param5:non zero count
void populate_sparse_into_triplet(int[][3], int,int,int[][3],int);
void display_triplet(int triplet_mat[][3],int row,int col);
void perform_addition_triplet(int trip_mat1[][3],int trip_mat2[][3],int result_mat[][3]);
int main(){
	int sparse_mat1[3][3]={
						  {0,0,3 },
				          {0,1,0 },
					      {2,0,0 }
					      };
	int mat1_rows=sizeof(sparse_mat1)/sizeof(sparse_mat1[0]); //sizeof matrix / size of 1 row
	int mat1_cols= sizeof(sparse_mat1[0])/sizeof(int); //sizeof 1 row/size of one element
	int sparse_mat2[3][3]={
						  {1,0,0 },
				          {0,3,0 },
					      {5,0,6 }
					      };
	int mat2_rows=sizeof(sparse_mat2)/sizeof(sparse_mat2[0]); //sizeof matrix / size of 1 row
	int mat2_cols= sizeof(sparse_mat2[0])/sizeof(int); //sizeof 1 row/size of one element				      
	
	//find the count of non zero elements of matrix1
	int non_zero_count=0;
	for (int i=0;i<mat1_rows;i++){
		for(int j=0;j<mat1_cols;j++){
			if(sparse_mat1[i][j]!=0){
				non_zero_count++;
			}	
		}
	}
	//create triplet matrix1 using non zero count of matrix1
	int triplet_mat1[non_zero_count + 1][3];
	//populate sparse into triplet matrix
	populate_sparse_into_triplet(sparse_mat1,mat1_rows,mat1_cols,triplet_mat1,non_zero_count);
	//display matrix 1 in triplet form
	display_triplet(triplet_mat1,non_zero_count+1,3);
	
	//find the count of non zero elements of matrix2
	non_zero_count=0;
	for (int i=0;i<mat2_rows;i++){
		for(int j=0;j<mat2_cols;j++){
			if(sparse_mat2[i][j]!=0){
				non_zero_count++;
			}	
		}
	}
	//create triplet matrix2 using non zero count of matrix2
	int triplet_mat2[non_zero_count + 1][3];
	//populate sparse into triplet matrix
	populate_sparse_into_triplet(sparse_mat2,mat2_rows,mat2_cols,triplet_mat2,non_zero_count);
	//display matrix 1 in triplet form
	display_triplet(triplet_mat2,non_zero_count+1,3);
	
	int no_of_rows = (triplet_mat1[0][2])+(triplet_mat2[0][2]); //take the header rows from 2 matrixes and add
	//create triplet result matrix using non zero count of matrix1 & matrix2
	int triplet_res[no_of_rows][3];
	//perform addition of triplet matrix1 with triplet matrix2 and save result in triplet result matrix
	perform_addition_triplet(triplet_mat1,triplet_mat2,triplet_res);
	//display matrix 1 in triplet form
	display_triplet(triplet_res,no_of_rows,3);
}
void perform_addition_triplet(int triplet_mat1[][3],int triplet_mat2[][3],int result_mat[][3]){
	//step1: add header
	result_mat[0][0] = triplet_mat1[0][0]; //triplet matrix1 rows
	result_mat[0][1] = triplet_mat1[0][1]; //triplet matrix1 cols
	result_mat[0][2] = (triplet_mat1[0][2])+(triplet_mat2[0][2]);//non zero count of triplet matrix1 and triplet matrix2
	int k = 1; //row counter for the result triplet matrix
	for(int i=1;i<result_mat[0][0];i++){
//		for(int j=0;j<result_mat[0][1];j++){
			//step2: add the (r,c,v) from triplet mat1 and triplet mat2 based on the following 3 conditions
			//case 1 : when trip mat1 row == trip mat2 row and trip mat2 col == trip mat2 col
			//		   then (r,c,v) --> result mat row(r) = r1/r2 ,result mat col (c)= c1/c2,result mat value(v)=v1 + v2	
			if((triplet_mat1[i][0] == triplet_mat2[i][0]) && (triplet_mat1[i][1] == triplet_mat2[i][1])) {
				result_mat[k][0] = triplet_mat1[i][0]; //row of trip1/trip2
				result_mat[k][1] = triplet_mat1[i][1]; //col of trip1/trip2
				result_mat[k][2] = triplet_mat1[i][2]+triplet_mat2[i][2];//mat1 value + mat2 value
				k++; //increment k by 1 for next row
			}else if((triplet_mat1[i][0] == triplet_mat2[i][0]) && (triplet_mat1[i][1] != triplet_mat2[i][1])){
				if ((triplet_mat1[i][1] < triplet_mat2[i][1])) {
					result_mat[k][0] = triplet_mat1[i][0]; //row of trip1
					result_mat[k][1] = triplet_mat1[i][1]; //col of trip1
					result_mat[k][2] = triplet_mat1[i][2]; //mat1 value
					k++;
				}else{
					result_mat[k][0] = triplet_mat2[i][0]; //row of trip2
					result_mat[k][1] = triplet_mat2[i][1]; //col of trip2
					result_mat[k][2] = triplet_mat2[i][2]; //mat2 value
					k++;
				}
			}else{
				if ((triplet_mat1[i][0] < triplet_mat2[i][0])) {
					result_mat[k][0] = triplet_mat1[i][0]; //row of trip1
					result_mat[k][1] = triplet_mat1[i][1]; //col of trip1
					result_mat[k][2] = triplet_mat1[i][2]; //mat1 value
					k++;
				}else{
					result_mat[k][0] = triplet_mat2[i][0]; //row of trip2
					result_mat[k][1] = triplet_mat2[i][1]; //col of trip2
					result_mat[k][2] = triplet_mat2[i][2]; // mat2 value
					k++;
				}
			}
//		}
	}
}
void populate_sparse_into_triplet(int orig_mat[][3], int orig_mat_row,int orig_mat_col,int trip_mat[][3],int non_zero_count){
	//step1: add header
	trip_mat[0][0] = orig_mat_row; //original matrix rows
	trip_mat[0][1] = orig_mat_col; //original matrix cols
	trip_mat[0][2] = non_zero_count;//original non zero element count
	int k = 1; //row counter for the triplet matrix
	for(int i=0;i<orig_mat_row;i++){
		for(int j=0;j<orig_mat_col;j++){
			//step3: add the (r,c,v)
			if(orig_mat[i][j]!=0){
				trip_mat[k][0] = i; //original matrix row
				trip_mat[k][1] = j; //original matrix col
				trip_mat[k][2] = orig_mat[i][j];//original non zero element
				k++; //increment k by 1 for next row
			}
		}
	}
}
void display_triplet(int triplet_mat[][3],int row,int col){
	printf("Triplet form:\n");
	printf("\nRow\t Col \t Value\n");
	for (int i=0;i<row;i++){
		printf("%d\t %d\t %d",triplet_mat[i][0],triplet_mat[i][1],triplet_mat[i][2]);	
		printf("\n");
	}
}
