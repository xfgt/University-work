#include <iostream>



struct Point{ int x, y; };

bool det(	int x1, int y1, 
			int x2, int y2,
			int x3, int y3 ){

	if((x1*(y2-y3) - y1 * (x2-x3) + 1 * (x2*y3-y2*x3)) != 0)
		return true;

	else
		return false;
}

int countPoints(Point arr[], int n){

	int result = 0;

	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			for(int k = j + 1; k < n; k++)
				if(det(	arr[i].x, arr[i].y,
						arr[j].x, arr[j].y,
						arr[k].x, arr[k].y))
					result++;


	return result;

}



int main(){

	int n;

	while(std::cin >> n){

		Point arr[n];
		for(int i = 0; i < n; i++)
			std::cin >> arr[i].x >> arr[i].y;

		std::cout << countPoints(arr,n) << std::endl;
	
	}
	return 0;
}
