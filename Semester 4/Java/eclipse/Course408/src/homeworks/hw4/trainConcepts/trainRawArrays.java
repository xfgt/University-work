package homeworks.hw4.trainConcepts;

import java.lang.Math;

import java.util.Arrays;


class Author {

    private String name;

    public Author(String name) {
        this.name = name;
    }

    void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Author{" + "name=" + name + '}';
    }

}



public class trainRawArrays {
	static int limit = 20;
	
	
	public static void simpleArrayOfRandoms(int n, double min, double max) {
		double[] arr = new double[n];	
		
		for(int i = 0; i < n; i++) {
			arr[i] = Math.random() * (max-1) + min;
		}
		
		System.out.println(arr.toString());
		
	}
	public static void getPseudoMatrix_PI_E(int n) {
		for(int i = 0; i < n; i++) {
			simpleArrayOfRandoms(n, -Math.PI, 2.7182818284590452354);
			System.out.println();
		}
	}
	
	
	public static void arrayCopyPrintSortFill() {
		// java.util.Arrays
		int bookCodesLibrary1[] = {77, 22, 66, 44, 11}; 			// initializer list
		System.out.println("bookCodesLibrary1: " + Arrays.toString(bookCodesLibrary1));

		// Copy array
		int[] arrayCopy = Arrays.copyOf(bookCodesLibrary1, bookCodesLibrary1.length);

		// Print array
		System.out.println("ArrayCopy (copy of bookCodesLibrary1, arrayCopy = Arrays.copyOf(bCL1, bCL.lenght)): " + Arrays.toString(arrayCopy));

		// Sort array
		Arrays.sort(arrayCopy);
		System.out.println("ArrayCopy sorted (Arrays.sort()): " + Arrays.toString(arrayCopy));

		// Fill array
		int[] arrayFilled = new int[10];
		Arrays.fill(arrayFilled, 6);							// memset(arr, x, value);
		System.out.println("arrayFilled (Arrays.fill(arrayFilled, NUMBER)): " + Arrays.toString(arrayFilled));
	}
	
	public static void ArrayOfObjects() {
		
		Author ivan = new Author("Ivan");
		Author maria = new Author("Maria");
		Author pesho = new Author("Pesho");

		Author authorsList1[] = {ivan, maria, pesho}; 
		for (Author author : authorsList1) {
		      System.out.print(author + " ");
		}
		
	}
	
	
	public static void ArraysShallowCopy() {
		
		int bookCodesLibrary1[] = {11, 22, 33, 44, 55};
		int bookCodesLibrary2[] = bookCodesLibrary1.clone();
		
		    System.out.print(Arrays.toString(			bookCodesLibrary1			));
		
		System.out.println();

		
		
		bookCodesLibrary1				[2] = 88; 		// change in 1 changes 2 as well
		//bookCodesLibrary2				[2] = 88; 		// change in 2 does not change 1
			
			System.out.print(Arrays.toString(				bookCodesLibrary2		));
	}
	
	
	
	public static void ArraysProperCopy() {
		
		int bookCodesLibrary1[] = {11, 22, 33, 44, 55};
		int bookCodesLibrary2[] = new int[5];
		
		
		
			// source address, 					source start				target address, 		target start, 				size
		System.arraycopy(bookCodesLibrary1, 	0, 							bookCodesLibrary2,		 1, 					3);
		
		
		
		
		
		
		    System.out.print(Arrays.toString(			bookCodesLibrary1			));
		
		System.out.println();

		
		
		bookCodesLibrary1				[2] = 88; 		// change in 1 changes 2 as well
		//bookCodesLibrary2				[2] = 88; 		// change in 2 does not change 1
			
			System.out.print(Arrays.toString(				bookCodesLibrary2		));
	}
	
	
	public static void staticMatrice() {
		System.out.println("staticMatrice()");
		double m[][] = {
				{ 0*0, 1*0, 2*0, 3*0 },
				{ 0*1, 1*1, 2*1, 3*1 },
				{ 0*2, 1*2, 2*2, 3*2 },
				{ 0*3, 1*3, 2*3, 3*3 }
				};
		int i, j;
		for(i=0; i<4; i++) {
			for(j=0; j<4; j++) {
				System.out.print(m[i][j] + " ");
			}
			System.out.println();
		}
	}
	
	public static void twoDMatrice() {
		System.out.println("twoDMatrice()");
		int twoD[][]= new int[4][5];
		int i, j, k = 0;
		for(i=0; i<4; i++) {
			for(j=0; j<5; j++) {
			twoD[i][j] = k;
			k++;
			}
		}
		for(i=0; i<4; i++) {
			for(j=0; j<5; j++) {
				System.out.print(twoD[i][j] + " ");
			  }  
			System.out.println();
		}
	}
	
	public static void threeDMatrice() {
		System.out.println("threeDMatrice()");
		int threeD[][][] = new int[3][4][5];
		int i, j, k;
		for(i=0; i<3; i++) {
			for(j=0; j<4; j++) {
				for(k=0; k<5; k++) {
					threeD[i][j][k] = i * j * k;
				}
			}
		}
		for(i=0; i<3; i++) {
			for(j=0; j<4; j++) {
				for(k=0; k<5; k++) {
					System.out.print(threeD[i][j][k] + " ");
				}
				System.out.println();
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		
		//getPseudoMatrix_PI_E(limit);
		//arrayCopyPrintSortFill();
		//ArrayOfObjects();
		//ArraysShallowCopy();
		//ArraysProperCopy();
		
		staticMatrice();
		twoDMatrice();
		threeDMatrice();
		
		
	}

}
