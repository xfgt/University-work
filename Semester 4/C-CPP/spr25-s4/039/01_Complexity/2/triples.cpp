#include <iostream>



long long check(int x, int y, int z){

	int cnt{};
	int i, j, k;

    for(i = 1; i <= x; i++)
        for(j = 1; j <= y; j++)
            for(k = 1; k <= z; k++)
				if (i * k > j*j)
					cnt++;
    return cnt;
}
		
int main(){
	

	int x, y, z;
	while(std::cin >> x >> y >> z){

		if(x < 1 || y < 1 || z < 1) return -1;

		std::cout << check(x, y, z) << "\n";
	}
	return 0;
}
