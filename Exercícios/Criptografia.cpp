#include <bits/stdc++.h>
#include <cstring>
 #include <iostream>
 #include <cstdlib> // necessário para atoi

// Nome de Tipos
typedef long ll;
typedef unsigned long long ull;
typedef long double ld;
// Valores
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define DINF (double)1e+30
#define EPS (double)1e-9
#define RAD(x) (double)(x*PI)/180.0
#define PCT(x,y) (double)x*100.0/y

// Atalhos
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define l length()
#define forn(i, n) for ( int i = 0; i < (n); ++i )
#define fornx(i, x, n) for ( int i = (x); i < (n); ++i )

using namespace std;
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    string palavra;

    cin >> palavra;


    for (int i=0; i < strlen(palavra); i++) {
        palavra[i]+3;
        cout << palavra[i];
    }

    
    printf("\n");

    return 0;
}

