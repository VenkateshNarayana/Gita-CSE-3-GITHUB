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
void display_triplet(int triplet_mat[][3]);
int get_element_from_triplet(int[][3],int,int);
void display_matrix_from_triplet(int[][3]);//param1=triplet matrix 2d name

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
	display_triplet(triplet_mat1);
	
	//find the count of non zero elements of matrix2
	non_zero_count=0;
	for (int i=0;i<mat2_rows;i++){
		for(int j=0;j<mat2_cols;j++){
			if(sparse_mat2[i][j]!=0){
				non_zero_count++;
			}	
		}
	}
	//perform matrix addition check--> row1 == row2 and col1==col2
	if (mat1_rows != mat2_rows || mat1_cols != mat2_cols){
    	printf("Matrix addition cannot be performed.");
    	return 0;
	}
	//create triplet matrix2 using non zero count of matrix2
	int triplet_mat2[non_zero_count + 1][3];
	//populate sparse into triplet matrix
	populate_sparse_into_triplet(sparse_mat2,mat2_rows,mat2_cols,triplet_mat2,non_zero_count);
	//display matrix 1 in triplet form
	display_triplet(triplet_mat2);
	
	int no_of_rows = (triplet_mat1[0][2])+(triplet_mat2[0][2])+1; //take the header rows from 2 matrixes and add 1 for header
	//create triplet result matrix using non zero count of matrix1 & matrix2
	int triplet_res[no_of_rows][3]={0};//deckare and initialise to zero
	
	//perform addition of triplet matrix1 with triplet matrix2 and save result in triplet result matrix
	perform_addition_triplet(triplet_mat1,triplet_mat2,triplet_res);
	
}
void perform_addition_triplet(int triplet_mat1[][3],int triplet_mat2[][3],int result_mat[][3]){
	int i=1,j=1,k=1; //i is for mat1, j is for mat2, k is for result matrix
	int trip_mat1_rows = triplet_mat1[0][2];
	int trip_mat2_rows = triplet_mat2[0][2];
	
	//step1: add header row 0
	result_mat[0][0]=triplet_mat1[0][0];//dimension row
	result_mat[0][1]=triplet_mat2[0][1];//dimension col
	result_mat[0][2]=trip_mat1_rows + trip_mat2_rows;//non zero count mat1 + non zero count mat2
	
	//step2: scan the rows of mat1 and mat2
	while(i<(trip_mat1_rows+1) && j<(trip_mat2_rows+1)){
		//check 3 conditions
		//case 1: when row & col of both matrix are same
		if(triplet_mat1[i][0]==triplet_mat2[j][0] && triplet_mat1[i][1]==triplet_mat2[j][1]){
			//there will be only 1 entry in result mat
			result_mat[k][0]=triplet_mat1[i][0];//dimension row
			result_mat[k][1]=triplet_mat1[i][1];//dimension col
			result_mat[k][2]= triplet_mat1[i][2]+triplet_mat2[j][2];//add the values of (mat1 +  mat2)
			k++;//move to next row or result matrix
			i++;//move to next row of mat1
			j++;//move to next row of mat2
		}else if(triplet_mat1[i][0]<triplet_mat2[j][0] || triplet_mat1[i][1] < triplet_mat2[j][1]){
			//case 2: when row1 < row2 or col1 < col2 
			//there will 2 entries -> first entry will the col which less and next will col which is greater
			
			result_mat[k][0]= triplet_mat1[i][0];//dimension row of mat1
			result_mat[k][1]= triplet_mat1[i][1];//dimension col of mat1
			result_mat[k][2]= triplet_mat1[i][2] ;//add the values of (mat1)
			k++;//move to next row or result matrix
			i++;//move to next row of mat1
			//next entry
			result_mat[k][0]= triplet_mat2[j][0];//dimension row of mat2
			result_mat[k][1]= triplet_mat2[j][1];//dimension col of mat2
			result_mat[k][2]= triplet_mat2[j][2] ;//add the values of (mat2)
			k++;//move to next row or result matrix
			j++;//move to next row of mat2
			
		}else {
			//case 3: when row1>row2 or col1>col2 
			result_mat[k][0]= triplet_mat2[j][0];//dimension row of mat2
			result_mat[k][1]= triplet_mat2[j][1];//dimension col of mat2
			result_mat[k][2]= triplet_mat2[j][2] ;//add the values of (mat2)
			k++;//move to next row or result matrix
			j++;//move to next row of mat2
			
			//next entry
			result_mat[k][0]= triplet_mat1[i][0];//dimension row of mat1
			result_mat[k][1]= triplet_mat1[i][1];//dimension col of mat1
			result_mat[k][2]= triplet_mat1[i][2] ;//add the values of (mat1)
			k++;//move to next row or result matrix
			i++;//move to next row of mat1	

		}

	}
	//push all the leftovers from mat1 into result matrix
	while(i<(trip_mat1_rows+1)){
		result_mat[k][0]= triplet_mat1[i][0];//dimension row of mat1
		result_mat[k][1]= triplet_mat1[i][1];//dimension col of mat1
		result_mat[k][2]= triplet_mat1[i][2] ;//add the values of (mat1)
		k++;//move to next row or result matrix
		i++;//move to next row of mat1
	}
	//push all the leftovers from mat2 into result matrix
	while(j<(trip_mat2_rows+1)){
		result_mat[k][0]= triplet_mat2[j][0];//dimension row of mat2
		result_mat[k][1]= triplet_mat2[j][1];//dimension col of mat2
		result_mat[k][2]= triplet_mat2[j][2] ;//add the values of (mat2)
		k++;//move to next row or result matrix
		j++;//move to next row of mat2
	}
	//finally call the display triplet
	printf("Result ");
	display_triplet(result_mat);
	
	printf("Result ");
	//display the matrix
	display_matrix_from_triplet(result_mat);
}
int get_element_from_triplet(int triplet[][3],int i,int j){
	int trip_row = triplet[0][2]+1; //no of non zero count + 1(for the header)
	for(int row=1;row<trip_row;row++){
		if (triplet[row][0]==i && triplet[row][1]==j ){
			return triplet[row][2]; //return the actual value
		}
	}
	return 0;//if not found in the triplet matrix return 0
}
void display_matrix_from_triplet(int triplet_mat1[][3]){
	//display matrix from triplet
	int sparse_rows = triplet_mat1[0][0]; //rows
	int sparse_cols = triplet_mat1[0][1]; //cols
	printf(" Matrix:\n");
	for(int i=0;i<sparse_rows;i++){
		for(int j=0;j<sparse_cols;j++){
			printf("%d ",get_element_from_triplet(triplet_mat1,i,j));
		}
		printf("\n");
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
void display_triplet(int triplet_mat[][3]){
	int row = triplet_mat[0][2]+1 ;//1 for the header
	printf("Triplet form:\n");
	printf("\nRow\t Col \t Value\n");
	for (int i=0;i<row;i++){
		printf("%d\t %d\t %d",triplet_mat[i][0],triplet_mat[i][1],triplet_mat[i][2]);	
		printf("\n");
	}
}
