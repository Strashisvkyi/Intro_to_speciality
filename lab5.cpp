#include <iostream>
#include <math.h>
#include <conio.h>
#define _USE_MATH_DEFINES

#define numberOfRows 5
#define numberOfColumns 5

/*
34 45 65 23 98
1 -4  67 -3 -18
23 -5 -1 94 -25
2 24 -4 79 -63
10 29 25 30 -6
*/

using namespace std;
int indexOfRows, indexOfColumns;
class Matrix
{
public:
  friend void outputArray (Matrix arrayConsistingOfRowElements[]);
  void sortArray (Matrix arrayConsistingOfRowElements[]);
  void calculateArray (Matrix arrayConsistingOfRowElements[]);
  double arrayOfEveryRowElement[numberOfColumns];
  friend void inputArray (Matrix arrayConsistingOfRowElements[]);


};
void inputArray (Matrix arrayConsistingOfRowElements[])
{


  for (indexOfRows = 0; indexOfRows < numberOfRows; indexOfRows++)
    {

      for (indexOfColumns = 0; indexOfColumns < numberOfColumns;
	   indexOfColumns++)
	{


	  cin >> arrayConsistingOfRowElements[indexOfRows].
	    arrayOfEveryRowElement[indexOfColumns];

	}

    }

}


void outputArray (Matrix arrayConsistingOfRowElements[])
{

  for (indexOfRows = 0; indexOfRows < numberOfRows; ++indexOfRows)
    {
      for (indexOfColumns = 0; indexOfColumns < numberOfColumns;
	   ++indexOfColumns)
	{
	  cout << arrayConsistingOfRowElements[indexOfRows].
	    arrayOfEveryRowElement[indexOfColumns] << "\t";
	}
      cout << endl;
    }
}

void sortArray (Matrix arr[])
{
  for (int indexOfRows = 0; indexOfRows < numberOfRows; indexOfRows++)
    {
      for (int blockSizeIterator = 1; blockSizeIterator < numberOfRows;
	   blockSizeIterator *= 2)
	{
	  for (int blockIterator = 0;
	       blockIterator < numberOfRows - blockSizeIterator;
	       blockIterator += 2 * blockSizeIterator)
	    {
	      int leftBlockIterator = 0;
	      int rightBlockIterator = 0;
	      int leftBorder = blockIterator;
	      int midBorder = blockIterator + blockSizeIterator;
	      int rightBorder = blockIterator + 2 * blockSizeIterator;
	      rightBorder =
		(rightBorder < numberOfRows) ? rightBorder : numberOfRows;
	      int *sortedBlock = new int[rightBorder - leftBorder];

	      while (leftBorder + leftBlockIterator < midBorder
		     && midBorder + rightBlockIterator < rightBorder)
		{
		  if (arr[leftBorder + leftBlockIterator].
		      arrayOfEveryRowElement[indexOfRows] <
		      arr[midBorder +
			  rightBlockIterator].
		      arrayOfEveryRowElement[indexOfRows])
		    {
		      sortedBlock[leftBlockIterator + rightBlockIterator] =
			arr[leftBorder +
			    leftBlockIterator].
			arrayOfEveryRowElement[indexOfRows];
		      leftBlockIterator++;
		    }
		  else
		    {
		      sortedBlock[leftBlockIterator + rightBlockIterator] =
			arr[midBorder +
			    rightBlockIterator].
			arrayOfEveryRowElement[indexOfRows];
		      rightBlockIterator++;
		    }
		}
	      while (leftBorder + leftBlockIterator < midBorder)
		{
		  sortedBlock[leftBlockIterator + rightBlockIterator] =
		    arr[leftBorder +
			leftBlockIterator].
		    arrayOfEveryRowElement[indexOfRows];
		  leftBlockIterator++;
		}
	      while (midBorder + rightBlockIterator < rightBorder)
		{
		  sortedBlock[leftBlockIterator + rightBlockIterator] =
		    arr[midBorder +
			rightBlockIterator].
		    arrayOfEveryRowElement[indexOfRows];
		  rightBlockIterator++;
		}

	      for (int mergeIterator = 0;
		   mergeIterator < leftBlockIterator + rightBlockIterator;
		   mergeIterator++)
		{
		  arr[leftBorder +
		      mergeIterator].arrayOfEveryRowElement[indexOfRows] =
		    sortedBlock[mergeIterator];
		}
	      delete sortedBlock;

	    }

	}
    }
}

void calculateArray (Matrix arrayConsistingOfRowElements[])
{
  double productOfElementsOverMainDiagonal[numberOfRows - 1] = { 1, 1, 1, 1 };
  double geometricMeanOfElementsOverMainDiagonal[numberOfRows - 1];
  for (int indexOfRows = 0; indexOfRows < numberOfRows - 1; indexOfRows++)
    {
      for (int indexOfColumns = indexOfRows + 1;
	   indexOfColumns < numberOfRows; indexOfColumns++)
	{

	  productOfElementsOverMainDiagonal[indexOfRows] *=
	    arrayConsistingOfRowElements[indexOfRows].
	    arrayOfEveryRowElement[indexOfColumns];

	}
      double power = pow ((numberOfRows - indexOfRows - 1), -1.0);
      geometricMeanOfElementsOverMainDiagonal[indexOfRows] =
	pow (fabs ((productOfElementsOverMainDiagonal[indexOfRows])), power);
    }
  double sumOfGeometricMeans;
  for (int indexOfRows = 0; indexOfRows < numberOfRows - 1; indexOfRows++)
    {

      sumOfGeometricMeans +=
	geometricMeanOfElementsOverMainDiagonal[indexOfRows];
      cout << "f(" << indexOfRows << "): " <<
	geometricMeanOfElementsOverMainDiagonal[indexOfRows] << endl;
    }



  cout << "F(f(ij)): " << sumOfGeometricMeans << endl;


}



int
main ()
{
  Matrix array[numberOfRows];
  cout << "Enter elements of the matrix:" << endl;
  inputArray (array);
  cout << endl << "Original matrix:" << endl;
  outputArray (array);
  sortArray (array);
  cout << endl << "Sorted matrix:" << endl;
  outputArray (array);
  cout << endl << "Calculations:" << endl;
  calculateArray (array);
}
