#include <iostream>
#include <fstream>
#include "stack.h"
using namespace std;

int main(){
Stack<int> test;

bool emptytest;
emptytest = test.empty();
cout << "empty(): " << emptytest << endl;
for(int i = 1; i<11; i++){
	test.push(i);
}
cout << "size() " << test.size() << endl;
cout <<"top() " << test.top() << endl;
test.pop();
test.pop();
cout << "size() " << test.size() << endl;

}