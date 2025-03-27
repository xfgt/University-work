package org.example.hard;

public class MatrixOperations {

    // Adds two matrices of the same dimensions.
    public double[][] add(double[][] matrix1, double[][] matrix2) {
        validateSameDimensions(matrix1, matrix2);
        int rows = matrix1.length;
        int cols = matrix1[0].length;
        double[][] result = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        return result;
    }

    // Multiplies two matrices.
    public double[][] multiply(double[][] matrix1, double[][] matrix2) {
        if (matrix1[0].length != matrix2.length) {
            throw new IllegalArgumentException("Incompatible dimensions for multiplication.");
        }
        int rows = matrix1.length;
        int cols = matrix2[0].length;
        int commonDim = matrix1[0].length;
        double[][] result = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < commonDim; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        return result;
    }

    // Transposes a given matrix.
    public double[][] transpose(double[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        double[][] transposed = new double[cols][rows];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }

    // Computes the determinant of a square matrix.
    public double determinant(double[][] matrix) {
        if (!isSquareMatrix(matrix)) {
            throw new IllegalArgumentException("Determinant can only be calculated for square matrices.");
        }
        return determinantRecursive(matrix);
    }

    // Returns the inverse of a 2x2 matrix.
    // For matrices larger than 2x2, an UnsupportedOperationException is thrown.
    public double[][] inverse(double[][] matrix) {
        if (!isSquareMatrix(matrix)) {
            throw new IllegalArgumentException("Inverse can only be calculated for square matrices.");
        }
        int n = matrix.length;
        double det = determinant(matrix);
        if (det == 0) {
            throw new IllegalArgumentException("Matrix is singular and cannot be inverted.");
        }
        if (n == 2) {
            double[][] inv = new double[2][2];
            inv[0][0] = matrix[1][1] / det;
            inv[0][1] = -matrix[0][1] / det;
            inv[1][0] = -matrix[1][0] / det;
            inv[1][1] = matrix[0][0] / det;
            return inv;
        } else {
            throw new UnsupportedOperationException("Inverse not implemented for matrices larger than 2x2.");
        }
    }

    // ----------------------- Private Helper Methods -----------------------

    // Validates that two matrices have the same dimensions.
    private void validateSameDimensions(double[][] matrix1, double[][] matrix2) {
        if (matrix1 == null || matrix2 == null ||
                matrix1.length != matrix2.length ||
                matrix1[0].length != matrix2[0].length) {
            throw new IllegalArgumentException("Matrices must have the same dimensions.");
        }
    }

    // Checks if a matrix is square.
    private boolean isSquareMatrix(double[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return false;
        }

        for (double[] row : matrix) {
            if (row.length != matrix.length) {
                return false;
            }
        }

        return true;
    }

    // Recursively computes the determinant of a square matrix.
    private double determinantRecursive(double[][] matrix) {
        int n = matrix.length;
        if (n == 1) {
            return matrix[0][0];
        }

        if (n == 2) {
            // Base case for 2x2 matrix.
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }

        double det = 0;

        for (int col = 0; col < n; col++) {
            det += matrix[0][col] * cofactor(matrix, 0, col);
        }

        return det;
    }

    // Computes the cofactor for the given row and column.
    private double cofactor(double[][] matrix, int row, int col) {
        double[][] minor = getMinor(matrix, row, col);
        double sign = ((row + col) % 2 == 0) ? 1 : -1;
        return sign * determinantRecursive(minor);
    }

    // Creates the minor matrix by removing the specified row and column.
    private double[][] getMinor(double[][] matrix, int rowToRemove, int colToRemove) {
        int n = matrix.length;
        double[][] minor = new double[n - 1][n - 1];
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (i == rowToRemove) continue;
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (j == colToRemove) continue;
                minor[r][c] = matrix[i][j];
                c++;
            }
            r++;
        }
        return minor;
    }
}

