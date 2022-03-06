#include <iostream>
#include <string>
#include <vector>
using namespace  std;

void display ( vector<vector<int>> image ) {
    for(int i=0 ; i < image.size() ; i++) {
        for(int j = 0 ;  j <  image[i].size() ; j++) 
            cout<<image[i][j]<<" ";
        cout<<endl;
    }
    cout<<"__________________"<<endl;
}

void rotate_image_by_90degree( vector<vector<int>> &  image) {
    int m=image.size();
    int n=image[0].size();
    
    //here swap the first row with the first col and increse row by so col == row to take the next row with the next col
    for(int row =0 ; row < m ; row ++) {
        for(int col = row ; col < n ; col ++) {
            swap(image[row][col] , image[col][row]);
        }
    }
    //reverse each row 
    for(int row = 0 ; row < m ; row ++) {
        int s=0;
        int e=n -1;
        while( s < e) {
            swap(image[row][s] , image[row][e]) ;
            s++;
            e--;
        }
    }
}
void rotate_image_by_minus_90degree( vector<vector<int>> &  image) {
    int m=image.size();
    int n=image[0].size();
    
    //here swap the first row with the first col and increse row by so col == row to take the next row with the next col
    for(int row =0 ; row < m ; row ++) {
        for(int col = row ; col < n ; col ++) {
            swap(image[row][col] , image[col][row]);
        }
    }
    //reverse each row 
    for(int col = 0 ; col < n-1 ; col ++) {
        int s=0;
        int e=n -1;
        while( s < e) {
            swap(image[s][col] , image[e][col]) ;
            s++;
            e--;
        }
    }
}

int main()
{
    vector<vector<int>> image {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
    };
    
    display(image);
    rotate_image_by_90degree(image);
    display(image);
        vector<vector<int>> image2 {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
    };
    rotate_image_by_minus_90degree(image2);
    display(image2);
}
