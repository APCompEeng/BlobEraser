// filename: listprog7.cpp
// author:   Adam Pesch
// cpsc122 01 Yerion
// programming assignment 8 fall 2017

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int MAXROWS = 25;
const int MAXCOLUMNS = 50;

// prints a number of newlines
// pre: desiredNumber is assigned
// post: prints desiredNumber newlines on the screen
void printNewLines(int desiredNumber);

// opens a file within the directory and outputs an error if said file is not found
// pre: an ifstream variable infile exists and is passed by reference
// post: opens the given file and passes it to the ifstream variable infile
// usage: openInputFile(infile);
void openInputFile(ifstream& infile);

// closes an open ifstream file infile
// pre: an ifstream variable infile exists and is passed by reference
// post: the ifstream variable infile is now closed, and will no longer be used in main
// usage: closeInputFile(infile);
void closeInputFile(ifstream& infile);

// prints the number of blobs in an easy to read format
// pre: a 2d boolean array exists that is filled with values
// post: the output screen now contains a handy, easy to read line of information showing how
//  many blobs there are in the 2d boolean array blobs
// usage: numberOfBlobs(blobs);
void numberOfBlobs(bool blobs[][MAXCOLUMNS]);

// takes the ifstream variable infile and reads it into a 2d boolean array blobs
// pre: an ifstream variable infile exists and is passed by reference, and a 2d array exists, ready to be filled
// post: 2d array blobs now contains the equivalent of the given ifstream variable infile, now in boolean format
	// (true for '1's and false for '0')
// usage: readBlobsFile(infile, blobs);
void readBlobsFile(ifstream& infile, bool blobs[][MAXCOLUMNS]);

// prints the 2d boolean array blobs to the screen in an easy to read format
// pre: a 2d boolean array exists that is filled with values
// post: the 2d boolean array is outputted exactly as it appears onto the screen
// usage: printBlobs(blobs);
void printBlobs(bool blobs[][MAXCOLUMNS]);

// returns the number of blobs found within the 2d boolean array blobs
// pre: a 2d boolean array exists that is filled with values
// post: the function has gone through the 2d boolean array copy (which is an exact replica of blobs)
	// and discovers how many blobs there are, stores said value into an int countOfBlobs, and returns it
// usage: cout << countBlobs(blobs);
int countBlobs(bool blobs[][MAXCOLUMNS]);

// finds a part of a blob and recursively erases it and all the true values that make it up
// pre: a 2d boolean array exists that is filled with values, arpw and acolumn are existing int values
// post: the space in the 2d array defined by arow and acolumn, if true, becomes false, and all other
	// connected true values are made false as well using recursion
// usage: eraseABlob(arow, acolumn, blobs);
void eraseABlob(int arow, int acolumn, bool blobs[][MAXCOLUMNS]);

// returns the number of blobs found within the 2d boolean array blobs
// pre: the 2d boolean arrays blobs and copy exist, and blobs is filled with values
// post: the 2d boolean array copy is a perfect replica of the the 2d boolean array blobs
// usage: copyBlobs(blobs, copy);
void copyBlobs(bool blobs[][MAXCOLUMNS], bool copy[][MAXCOLUMNS]);
 
int main()
{
    ifstream infile;
    bool blobs[MAXROWS][MAXCOLUMNS];

    openInputFile(infile);
    readBlobsFile(infile, blobs);
    closeInputFile(infile);
    printNewLines(2);
    printBlobs(blobs);
	
    printNewLines(2);
    numberOfBlobs(blobs);
    
    printNewLines(2);

    return 0;
}

// prints a number of newlines
// pre: desiredNumber is assigned
// post: prints desiredNumber newlines on the screen
// usage: printNewLines(4);
void printNewLines(int desiredNumber)
{
    for (int k = 0; k < desiredNumber; k++)
    {
        cout << endl;
    }
}

// opens a file within the directory and outputs an error if said file is not found
// pre: an ifstream variable infile exists and is passed by reference
// post: opens the given file and passes it to the ifstream variable infile
// usage: openInputFile(infile);
void openInputFile(ifstream& infile)
{
    infile.open("herecometheblobs.dat");
    if (infile.fail())
    {
        cout << "Error in Opening blobs file" << endl;
        exit(1);
    }
}

// closes an open ifstream file infile
// pre: an ifstream variable infile exists and is passed by reference
// post: the ifstream variable infile is now closed, and will no longer be used in main
// usage: closeInputFile(infile);
void closeInputFile(ifstream& infile)
{
    infile.close();
    if (infile.fail())
    {
        cout << "That file cannot be closed" << endl;
        exit(1);
    }
}

// prints the number of blobs in an easy to read format
// pre: a 2d boolean array exists that is filled with values
// post: the output screen now contains a handy, easy to read line of information showing how
//  many blobs there are in the 2d boolean array blobs
// usage: numberOfBlobs(blobs);
void numberOfBlobs(bool blobs[][MAXCOLUMNS])
{
    cout << "There are currently " << countBlobs(blobs) << " blobs in the 'herecometheblobs.dat' file"<< endl;
}

// takes the ifstream variable infile and reads it into a 2d boolean array blobs
// pre: an ifstream variable infile exists and is passed by reference, and a 2d array exists, ready to be filled
// post: 2d array blobs now contains the equivalent of the given ifstream variable infile, now in boolean format
	// (true for '1's and false for '0')
// usage: readBlobsFile(infile, blobs);
void readBlobsFile(ifstream& infile, bool blobs[][MAXCOLUMNS])
{
    char achar; int ascii, realValue;

	for(int row =0; row < MAXROWS; row++)
	{
		for(int column = 0; column < MAXCOLUMNS; column++)
		{
			infile.get(achar);
			ascii = achar;
			realValue = ascii - '0';
			blobs[row][column] = realValue;
		}
		infile.get(achar); //newline character at the end of the line
	}
           
        
}

// prints the 2d boolean array blobs to the screen in an easy to read format
// pre: a 2d boolean array exists that is filled with values
// post: the 2d boolean array is outputted exactly as it appears onto the screen
// usage: printBlobs(blobs);
void printBlobs(bool blobs[][MAXCOLUMNS])
{
	cout << "   ";
	for(int column = 0; column < MAXCOLUMNS; column++)
	{
		if(column/10 > 0)
		{
			cout << column / 10;
		}
		else
		{
			cout << " ";
		}
	}
	cout << endl;
	cout << "   ";
	for(int column = 0; column < MAXCOLUMNS; column++)
	{
		cout << column % 10;
	}
	
	cout << endl;
	
	for(int row = 0; row < MAXROWS; row++)
	{
		cout << row << ":";
		if(row < 10)
		{
			cout << " ";
		}
		for(int column = 0; column < MAXCOLUMNS; column++)
		{
			cout << blobs[row][column];
		}
		cout << endl;
	}
}

// returns the number of blobs found within the 2d boolean array blobs
// pre: a 2d boolean array exists that is filled with values
// post: the function has gone through the 2d boolean array copy (which is an exact replica of blobs)
	// and discovers how many blobs there are, stores said value into an int countOfBlobs, and returns it
// usage: cout << countBlobs(blobs);
int countBlobs(bool blobs[][MAXCOLUMNS])
{
	int countOfBlobs = 0;
	// make a copy of blobs
	bool copy [MAXROWS][MAXCOLUMNS];
	copyBlobs(blobs, copy);
	// search for the start of each blob
	for(int row = 0; row < MAXROWS; row++)
	{
		for(int column = 0; column < MAXCOLUMNS; column++)
		{
			if (copy[row][column])
			{
				countOfBlobs++;
				eraseABlob(row, column, copy);
			}
		}
	}
	return countOfBlobs;
	
}

// finds a part of a blob and recursively erases it and all the true values that make it up
// pre: a 2d boolean array exists that is filled with values, arpw and acolumn are existing int values
// post: the space in the 2d array defined by arow and acolumn, if true, becomes false, and all other
	// connected true values are made false as well using recursion
// usage: eraseABlob(arow, acolumn, blobs);
void eraseABlob(int arow, int acolumn, bool blobs[][MAXCOLUMNS])
{
	if(arow >= 0 and arow < MAXROWS and acolumn >= 0 and acolumn < MAXCOLUMNS)
	{
	   if (blobs[arow][acolumn])
	   {
		   blobs[arow][acolumn] = 0; //erase
		   eraseABlob(arow - 1, acolumn, blobs); //up
		   eraseABlob(arow - 1, acolumn - 1, blobs); //upper left
		   eraseABlob(arow, acolumn - 1, blobs); //left
		   eraseABlob(arow + 1, acolumn - 1, blobs); //lower left
		   eraseABlob(arow + 1, acolumn, blobs); //down
		   eraseABlob(arow + 1, acolumn + 1, blobs); //lower right
		   eraseABlob(arow, acolumn + 1, blobs); //right
		   eraseABlob(arow - 1, acolumn + 1, blobs); //upper right
		   
	   }
	}
}

// returns the number of blobs found within the 2d boolean array blobs
// pre: the 2d boolean arrays blobs and copy exist, and blobs is filled with values
// post: the 2d boolean array copy is a perfect replica of the the 2d boolean array blobs
// usage: copyBlobs(blobs, copy);
void copyBlobs(bool blobs[][MAXCOLUMNS], bool copy[][MAXCOLUMNS])
{
	for(int row =0; row < MAXROWS; row++)
	{
		for(int column = 0; column < MAXCOLUMNS; column++)
		{
			copy[row][column] = blobs[row][column];
		}
	}
}



