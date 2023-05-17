#include<iostream>
#include<vector>
#include <climits>
using namespace std;
static int count = 0;


void printStack(vector<int> stk){
		
	int s = stk.size();
	int i = 0;
	while(i < s){
		cout<< stk[i]<< " " ;
		i++;
	}
	cout << endl;
}

int findMin(vector<int> stk1, vector<int> stk2, int *whichStack){
	int min = INT_MAX;
	int size1 = stk1.size();
	int size2 = stk2.size();
	//cout<< __func__ << " > size : " << size << endl;
	if(size1 == 0 && size2 == 0){
		return 0;
	}
	if(size1 > 0){
		while(size1--){
			if(stk1[size1] < min){
				min = stk1[size1];
				*whichStack = 1;
			}
		}
	}
	
	if(size2 > 0){
		while(size2--){
			if(stk2[size2] < min){
				min = stk2[size2];
				*whichStack = 2;
			}
		}
	}
	
	
	return min;
}

void calCount(vector<int> s1,vector<int> s2,int min, int CheckWhichStack){
	int MinInWhere = 0;
	if(s1.empty() && s2.empty()){	
		cout<< "====== result ========"<< endl;
		cout<< "result : " << count << endl;
	}else{
		cout<<endl << "s1 : ";
		printStack(s1);
		cout<< "s2 : ";
		printStack(s2);
		cout<< endl;
	}
	
	if(!s1.empty() && CheckWhichStack == 1){
		int size = s1.size();
		while(size--){
			int value = s1[size];
			if(s1[size] == min){
				count++;
				cout<<"pop (" << value <<")";
				cout<<"<-find it! "<< endl << endl;
				cout<< "-------------------------------------"<< endl;
				s1.erase(s1.begin()+size);
				break;
			}else if(s1[size] != min){
				cout<<"pop (" << value <<")"<< endl;
				s2.push_back(value);
				s1.erase(s1.begin()+size);
				count++;
			}
		}
		if(s1.empty()){
			min =  findMin(s1,s2, &MinInWhere);
			cout<< "min : " << min << endl;
			calCount( s1, s2, min, MinInWhere);
		}else{
			min =  findMin(s1,s2,  &MinInWhere);
			cout<< "min : " << min << endl;
			calCount( s1, s2, min, 1);	
		}
	}else if(!s2.empty() && CheckWhichStack == 2){
		int size = s2.size();
		while(size--){
			int value = s2[size];
			if(s2[size] == min){
				count++;
				cout<<"pop (" << value <<")";
				cout<<"<-find it! "<< endl << endl;
				cout<< "-------------------------------------"<< endl;
				s2.erase(s2.begin()+size);
				break;
			}else if(s2[size] != min){
				cout<<"pop (" << value <<")"<< endl;
				s1.push_back(value);
				s2.erase(s2.begin()+size);
				count++;
			}
		}
		if(s2.empty()){
			min =  findMin(s1,s2, &MinInWhere);
			cout<< "min : " << min << endl;
			calCount( s1, s2, min, 1);
		}else{
			min =  findMin(s1,s2, &MinInWhere);
			cout<< "min : " << min << endl;
			calCount( s1, s2, min, MinInWhere);	
		}
	}	
	
}


int main(){
	vector<int> s1;
	vector<int> s2;
	
	int i ;
	int nums;
	int value;
	int min = INT_MAX;
	
	cout << "Numbers of value? ";
	cin >> nums;
	while(nums--){
		cout << "Input " << ++i << " th value : ";
		cin >> value;
		s1.push_back(value);	
		if(min > value){
			min = value;
		}
	}
	
	cout<< "min : " << min << endl;
	calCount(s1,s2,min,1);
	
} 
