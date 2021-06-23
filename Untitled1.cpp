#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

void cryptography_msg(int key[3][3], int message[3][4], int result[3][4]) {
	int sum=0;
	for( int i=0; i<3; i++) {
		for(int j=0; j<4; j++) {
			sum = 0;
			for(int k=0; k<3; k++) {
				sum=sum+key[i][k]*message[k][j];
			}
			result[i][j]=sum;
		}
	}
}

int main() {
	
	char msg[12];
	int i_key[3][3];
	int i,j;
	int temp;
	int result[3][4];
	int encode[3][4];
	int decode[3][4];
	int determinant;
	int key[3][3]= { {-3,-3,-4},{0,1,1},{4,3,4} };
	
	cout<<"\n Enter 12 Character Message : ";
	
	for(i=0; i<12; i++) {
		cin>>msg[i];
	}
	
	int a=((key[1][1]*key[2][2])-(key[2][1]*key[1][2]));
	int b=((key[1][0]*key[2][2])-(key[2][0]*key[1][2]));
	int c=((key[1][0]*key[2][1])-(key[2][0]*key[1][1]));
	temp=(key[0][0]*a)-(key[0][1]*b)+(key[0][2]*c);
	
	determinant=1/temp;
	
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			i_key[i][j]= ((key[(j+1)%3][(i+1)%3] * key[(j+2)%3][(i+2)%3]) -
			              (key[(j+1)%3][(i+2)%3] * key[(j+2)%3][(i+1)%3]))/ determinant;
		}
	}
	
	for(i=0; i<4; i++) {
		for(j=0; j<3; j++) {
			if(msg[j+(i*3)]>='a' && msg[j+(i*3)]<='z') {
				encode[j][i]=msg[j+(i*3)]-96;
			}
			if(msg[j+(i*3)]=='\0') {
				break;
			}
		}
	}
	
	cryptography_msg(key,encode,result);
	
	cout<<"\nEncoded message to be sent : ";
	
	for(int i=0; i<4; i++) {
		for(int j=0; j<3; j++) {
			cout<<result[i][j]<<" ";
		}
	}
	
	cryptography_msg(i_key,result,decode);
	
	cout<<"\nDecoded message is : ";
	
	for(int i=0; i<4; i++) {
		for(j=0; j<3; j++) {
			if ( ((decode[j][i]+96)) >= 97 && ((decode[j][i]+96) <= 123))
				cout<<(char)(decode[j][i] + 96);
		}
	}
	
	return 0;

}
