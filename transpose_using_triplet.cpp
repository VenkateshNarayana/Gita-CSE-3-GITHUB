/* Store the transpose of a given matrix using triplet form
*/
#include<stdio.h>
void display_matrix(int mat[][3],int ,int );
void display_triplet(int mat[][3],int ,int );
void display_matrix_using_triplet(int mat[][3],int ,int );
int get_matrix_element(int mat[][3],int row,int col,int i,int j);
int main(){
	int mat_sparse[4][3]={
						{0,0,1},
						{5,0,0},
						{4,0,6},
						{0,2,0}};
	int rows=sizeof(mat_sparse)/sizeof(mat_sparse[0]); //sizeof matrix / size of 1 row
	int cols= sizeof(mat_sparse[0])/sizeof(int); //sizeof 1 row/size of one element
	display_matrix(mat_sparse,rows,cols);
	//convert into triplet form
	int non_zero_count=0;
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(mat_sparse[i][j]!=0){
				non_zero_count++;
			}	
		}
	}
	//declare triplet_mat with row = non zero count + 1 & col = 3
	int trip_row = non_zero_count + 1; //1 row for the header
	int triplet_mat[trip_row][3];
	//store the header information
	triplet_mat[0][0] = rows; //store the row dimension of the original matrix
	triplet_mat[0][1] = cols; //store the col dimension of the original matrix
	triplet_mat[0][2] = non_zero_count; //store the non zero count of original matrix
	int k= 1; //this is track the row counter for triplet matrix
	//store all the non zero element into triplet matrix
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(mat_sparse[i][j]!=0){
				triplet_mat[k][0] = i; //store the row dimension of the non zero element
				triplet_mat[k][1] = j; //store the col dimension of the non zero element
				triplet_mat[k][2] = mat_sparse[i][j]; //store the value of the non zero element
				k++; //increment the row counter of triplet matrix
			}
		}
	}
	display_triplet(triplet_mat,trip_row,3); //display the triplet form
	
//	//store the transpose of the triplet form
//	int triplet_trans[trip_row][3]; //new triplet contain the transpose 
//	for(int i=0;i<trip_row;i++){
//		//swap the values 1st col with 2nd col
//		triplet_trans[i][0]=triplet_mat[i][1];//store the col values of the triplet_mat into the triplet transpose row 
//		triplet_trans[i][1]=triplet_mat[i][0];//store the row values of the triplet_mat into the triplet transpose col
//		triplet_trans[i][2]=triplet_mat[i][2];//remains unchanged
//	}
//	printf("\nTranspose ");
//	display_triplet(triplet_trans,trip_row,3); //display the transpose triplet 
	
	//finally display the transpose matrix using triplet form
	display_matrix_using_triplet(triplet_trans,trip_row,3);
}
void display_matrix(int mat[][3],int rows,int cols){
	printf("\nGiven Matrix:\n");
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("%d ",mat[i][j]);	
		}
		printf("\n");
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
int get_matrix_element(int triplet_mat[][3],int trip_mat_row,int trip_mat_col,int i_row,int j_col){
	int element = 0;
	//check in the triplet if the value exist return else return 0
	for (int i=0;i<trip_mat_row;i++){
		if(triplet_mat[i][0]==i_row && triplet_mat[i][1]==j_col){	
			element = triplet_mat[i][2]; //pass the value of the matrix[i_row][j_col]
			return element;
		}
	}	
	return element;
}
void display_matrix_using_triplet(int triplet_mat[][3],int trip_row,int trip_col){
	printf("\nMatrix from TRIPLET FORM:\n");
	int rows = triplet_mat[0][0]; //row dimension of original matrix 
	int cols = triplet_mat[0][1]; //col dimension of origianl matrix
	//print the matrix from triplet form(using get_matrix_element function)
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("%d ",get_matrix_element(triplet_mat,trip_row, trip_col,i, j));	
		}
		printf("\n");
	}
}
