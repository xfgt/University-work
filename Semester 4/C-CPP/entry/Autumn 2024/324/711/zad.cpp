// traykov Zadacha1 711

// 3 e prosto, 2 e prosto
// s kolko stupki da stanem v 2

#include <iostream>
// #include <bits/stdc++> // ima absolutno vsichko
#include <vector>
#include <queue>
using namespace std;

typedef ll long long;
vector<ll> prime[100005];
bool vis [100005]; // visited
ll dist[100005];

bool isPrime(ll x){
	for(int i = 2; i*i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}

// nehsto dali moje da se preobrazuva v nehsto drugo
// dali promqnata e korektna i stoinostta e prosta

/* 19, 23
 * 9 != 3
 * 1 != 2
 * cnt != 1; false;
 */
bool isValid(ll a, ll b){

	ll cnt = 0;
	while(a > 0){
		if(a % 10 != b % 10) // poslednite dali sa ednakvi ili razlichni
			cnt++;
		a/=10; // vzima ostanalite bez poslednoto
		b/=10;

		if(cnt == 1) return true;
		else return false;

	}
}

vector<ll> primes;


void graph(){ // tursene v dublochina i shirochina
			  // rebra
			  // nai malko stupki (rebra)
			  // grafite sa polezni sus svoite algoritmi

	// proverka mejdu intervala dali e prosto  ili ne
	
	for(ll i = 1000; i <= 9999; i++){
		if(isPrime(i))
			primes.push_back(i);
	}

	for(ll i = 0; i < primes.size(); i++){
		for(int j = i+1; j < primes.size(); j++){
			ll a = primes[i];
			ll b = primes[j];
			// vzimat se dve prosti chisla
			
			if(isValid(a,b){
					// postavqme rebro
					// grafa e neorientiran
				prime[a].push_back(b);
				prime[b].push_back(a);
			}
		}
	}
}


void bfs(ll x) { // opashka
			
	// poseten
	vis[x] = true;
	dist[x] = 0;
	queue<ll> q;
	q.push(x);
	while(!(q.empty)){
		ll y = q.front();
		q.pop();
		// susedite na susedite
		// novite susedi po btv comedy
	}
}

int main(){

	// namirame prostite mejdu n i m
	




	return 0;
}
