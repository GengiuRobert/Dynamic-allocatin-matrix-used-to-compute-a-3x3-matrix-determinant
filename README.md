# Dynamic-allocation-matrix-used-to-compute-a-3x3-matrix-determinant


-------------------------------------------------------------------

This is a console applicantion

The code will generate a matrix that has random numbers in the [0,1) interval and deletes a row or a column in the matrix by a given index

You have to give as entrace 3(n, m ,idx) integers and 1 character (ov)

n -> number of rows of the matrix

n -> number of columns of the matrix

idx -> index of the row or column that is gonna be deleted

ov -> can be 'v' character or 'o' caracter

'v' -> deletes vertically, which means the that the column at the given index is gonna be deleted 

'o' -> deletes horizontally, which means the that the row at the given index is gonna be deleted 

In the code is the function delete_rc that is gonna help us determinate the 3x3 determinant value, if the parameters that represents the number of rows and columns do not make a 3x3 matrix, the determinant is not gonna be calculated

--------------------------------------------------------------------
