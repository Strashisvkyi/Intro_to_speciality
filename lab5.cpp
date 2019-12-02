/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <math.h>
#include <conio.h>
#define _USE_MATH_DEFINES

#define n 5
#define m 5

/*
34 45 65 23 98
1 -4  67 -3 -18
23 -5 -1 94 -25
2 24 -4 79 -63
10 29 25 30 -6
*/

using namespace std;
int i,j;
class Matrix
{
public:
    friend void OutputArray(Matrix Arr[]);
    void SortArray(Matrix  Arr[]);
    void CalcArray(Matrix Arr[]);
    double M[m];
    friend void InputArray(Matrix  Arr[]);


};
void InputArray(Matrix  Arr[])
{
    cout<<"Enter array"<<endl;

    for(i = 0; i < n; i++){

        for(j = 0; j < m; j++){

           // cout<<"Input No.["<<i<<"]["<<j<<"]:";
            cin>>Arr[i].M[j];

        }

    }

}


void OutputArray(Matrix  Arr[])
{

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            cout << Arr[i].M[j] << "\t";
        }
        cout << endl;
    }
}
void SortArray(Matrix  arr[])
{
for (int i = 0; i < n; i++)
{
for (int BlockSizeIterator = 1; BlockSizeIterator < n; BlockSizeIterator *= 2)
{
for (int BlockIterator = 0; BlockIterator < n - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
{
int LeftBlockIterator = 0;
int RightBlockIterator = 0;
int LeftBorder = BlockIterator;
int MidBorder = BlockIterator + BlockSizeIterator;
int RightBorder = BlockIterator + 2 * BlockSizeIterator;
RightBorder = (RightBorder < n) ? RightBorder : n;
int* SortedBlock = new int[RightBorder - LeftBorder];

while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
{
if (arr[LeftBorder + LeftBlockIterator].M[i] < arr[MidBorder + RightBlockIterator].M[i])
{
SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].M[i];
LeftBlockIterator++;
}
else
{
SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].M[i];
RightBlockIterator++;
}
}
while (LeftBorder + LeftBlockIterator < MidBorder)
{
SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].M[i];
LeftBlockIterator++;
}
while (MidBorder + RightBlockIterator < RightBorder)
{
SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].M[i];
RightBlockIterator++;
}

for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
{
arr[LeftBorder + MergeIterator].M[i] = SortedBlock[MergeIterator];
}
delete SortedBlock;

}

}
}
}
void CalcArray(Matrix Arr[]) {
    double mult[n-1] = {1, 1, 1, 1};
    double Geom[n-1];
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {

            mult[i]*=Arr[i].M[j];

        }
    double z=pow((n-i-1),-1.0);
    Geom[i]=pow(fabs((mult[i])), z);
    }
    double haunt;
    for (int i = 0; i < n-1; i++) {
        
        haunt += Geom[i];
        cout << "f(" << i << "): " << Geom[i] << endl;
    }



    cout << "F(f(ij)): " << haunt << endl;


}



int main()
{
    Matrix   Array[n];
    cout<<"Enter elements of the matrix:"<<endl;
    InputArray(Array);
    cout<<endl<<"Original matrix:"<<endl;
    OutputArray(Array);
    SortArray(Array);
    cout<<endl<<"Sorted matrix:"<<endl;
    OutputArray(Array);
    cout<<endl<<"Calculations:"<<endl;
    CalcArray(Array);
}