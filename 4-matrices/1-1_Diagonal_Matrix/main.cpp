#include <iostream>
#include <string>
using namespace std;

/*
 * هنا الماتركس لازم يكون 2 دايمنشنال اراى  بس  لازم كل ارقام الاندكس المتشابهة يكون فيهم ارقام زي
 * 1 0 0
 * 0 2 0
 * 0 0 3
 * 
 * بس الفكرة ان لو عملت اراى كدا هياخد من اليمورى وييستهلك فيها  على الفاضى فا هعمل اراى عادى جدا واباصى لية 
 * لما الاى بسياوى  الجى  حط الرقم فى الاراى العادى ودا فى الحل اللى بعدة اما هنا توضيح فقط*/
void set_arr(int arr[], int i, int c , int x) {
    if(i==c) {
        arr[i]=x;
    }else 
        return;
}
int get_data(int arr[], int &i, int &c) {
    if(i==c)
        return arr[c];
        else 
            return 0;
}

int main()
{
    int arr[5];
    int i;
    int x;
    int c;
    int matricex[5][5]{0};
     for( i=0 ; i<5 ; i++) {
         for( c=0 ; c<5 ; c++) {
             if(i ==c) {
                 cout<<"enter the number"<<endl;
                 cin >> x;
                 matricex[i][c]=x;
                 set_arr(arr,i ,c ,x);
                 cout<<"get_Data:"<<get_data(arr,i , c)<<endl;
             }
         }
     }
     cout<<"_____________"<<endl;
     
}
