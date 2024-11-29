
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

static int d{};
unsigned sTime;

void startTimer() { sTime = clock(); }
void stopTimer() { std::cout << std::setprecision(7) << (float)(clock() - sTime) / CLOCKS_PER_SEC << "\t"; }


void hanoi(int n, char f, char t, char h){
	if(n > 1){
		hanoi(n-1, f, h, t);
		//std::cout << ++d << "\t" << f << "->" << t << '\n';
		hanoi(n-1, h, t, f);
	} //else
		//std::cout << ++d << "\t" << f << "->" << t << '\n';
}


int main(){

	// int n{};
	// std::cin >> n;
	//
	// char from;
	// char to;
	// char help;
	//
	// std::cin >> from >> to >> help;

	for(int x = 10; x <= 40; x+=5) {
		startTimer();
		hanoi(x, 'A', 'B', 'C');
		stopTimer();
		std::cout << x << std::endl;
	}


	return 0;
}
