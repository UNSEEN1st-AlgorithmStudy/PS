#include<iostream>
#include<algorithm>
using namespace std;
int N;
int mem[500];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>N;
	int arr[500][500];
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<=i; ++j){
			cin>>arr[i][j];
		}
	}
	
	for(int i = 0; i<N; ++i){
		mem[i] = arr[N-1][i];
	}
	
	for(int i = N-2; i>=0; --i){
		for(int j = 0; j<=i; ++j){
			mem[j] = arr[i][j] + max(mem[j], mem[j+1]);
		}
	}
	cout<<mem[0];
}