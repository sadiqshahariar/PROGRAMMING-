#include <iostream>
#include <limits.h>
using namespace std;

int main() {
	string ne,hay;
	int j=0,count=0,n,i,counter;

	while(cin>>n>>ne>>hay){
		if(ne.length()>hay.length()){
			cout<<endl;
		}
		if(ne.length()==hay.length()){
			if(hay==ne){
				cout<<0<<endl;
			}

		}
		if(ne.length()<hay.length()){
		for(int k=0;k<=(hay.length()-ne.length());++k){
			i=k;
			counter=0;
			for(j=0;j<ne.length();++j){
				if(hay[i]==ne[j]){

					++i;
					++counter;
					if(counter==n){
						cout<<i-n<<endl;
					}
			}
			else{
				break;
			}
			}
		}
		}
	}

	return 0;
}
