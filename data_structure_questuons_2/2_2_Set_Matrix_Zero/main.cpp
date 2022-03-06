#include <iostream>
#include <string>
#include <vector>
using namespace  std;
void display(vector<vector<int>> matrix) {
    for(int i=0 ; i< matrix.size() ; i++) {
        for(int j = 0 ; j< matrix[i].size() ; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"______________"<<endl;
}

void set_matrix_zeros(vector<vector<int>> & matrix) {  
   
    int row_size = matrix.size();
    if(row_size==0)
        return;
    int col_size = matrix[0].size();
    if(col_size==0)
        return;
        
        bool first_row_has_zero = false;
        bool first_col_has_zero=false;
        //check for zero in first row
        for(int col = 0 ; col<col_size ; col++) {
            if(matrix[0][col] == 0) {
                first_row_has_zero=true;
                break;
            }
        }
           //check for zero in first col
        for(int row = 0 ; row < row_size ; row ++) {
            if(matrix[row][0] == 0)  {
                first_col_has_zero=true;
                break;
            }
        }
    
     for(int row = 1 ; row < row_size ; row++) {
         for(int col = 1 ; col < col_size ; col ++) {
             if(matrix[row][col] ==0) {
                 matrix[0][col]=0;
                 matrix[row][0]=0;
             }
         }
     }
     for(int row = 1 ; row < row_size ; row++) {
         for(int col = 1 ; col < col_size ; col ++) {
            if(matrix[0][col] ==0 || matrix[row][0] == 0) 
                    matrix[row][col]=0;
         }
     }
     
     if(first_row_has_zero) {
           for(int col = 0 ; col<col_size ; col++) {
            matrix[0][col] = 0;
        }
     }
     if(first_col_has_zero) {
            for(int row = 0 ; row < row_size ; row ++) {
            matrix[row][0] = 0;
        }
     }
}

int main()
{
    vector<vector<int>> matrix  {
        {1,2,3,4,0},
        {5,3,0,2,1},
        {2,4,3,0,9},
        {7,2,1,3,7},
    
    };

    display(matrix);
    set_matrix_zeros(matrix);
    display(matrix);

	return 0;
}


/*
void display(vector<vector<int>> matrix) {
    for(int i=0 ; i< matrix.size() ; i++) {
        for(int j = 0 ; j< matrix[i].size() ; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"______________"<<endl;
}



void row_function(bool flag , int row , int col , int row_size , vector<vector<int>> & matrix) {
    if(flag == false) {
     while(row - 1 >=0 )  {
        matrix[row -1][col]=0;
        row --;
       }
    } 
    else {
    while(row +1 < row_size) {
        matrix[row+1][col]=0;
        row++;
    }
    }
}
 
 void col_function(bool flag , int row , int col , int col_size , vector<vector<int>> & matrix) {
    if(flag == false) {
    while(col -1 >=0) {
        matrix[row][col - 1]=0;
        col--;
    }
    } else {
    while(col +1 <col_size) {
        matrix[row][col + 1]=0;
        col++;
    } 
    }
}
 
void start_the_transfer(int row, int col , vector<vector<int>> & matrix) { // 3
    int row_size = matrix.size();
    int col_size = matrix[row].size();
    row_function(true ,row , col , row_size , matrix);
    row_function(false ,row , col , row_size , matrix);
    col_function(true, row , col , col_size , matrix);
    col_function(false, row , col , col_size , matrix);
    
}

void transfer_all_zeros_to_zero( vector<vector<int>> & stack , vector<vector<int>> & matrix) {//2
    while(stack.size() > 0) {
        vector<int> temp = stack.front();
        stack.erase(stack.begin());
        int row = temp[0];
        int col =temp[1];
        start_the_transfer(row , col , matrix);
    }
}

void set_matrix_zeros(vector<vector<int>> & matrix) { // 1
     vector<vector<int>> stack;
    for(int row = 0 ; row < matrix.size() ; row ++) {
        for(int col = 0 ; col < matrix[row].size() ; col ++) {
            if(matrix[row][col] ==0)
                stack.push_back(vector<int> {row , col});
        }
    }
    transfer_all_zeros_to_zero(stack , matrix);
}

int main()
{
    vector<vector<int>> matrix  {
        /*{6,1,2,0},
        {3,4,5,2},
        {1,3,1,5},
    {1,1,1,1,1},
    {1,1,0,1,1},
    {1,1,1,1,1},
    };

    display(matrix);
    set_matrix_zeros(matrix);
    display(matrix);
    
      
    
	return 0;
}
*/