#ifndef CTEST_H
#define CTEST_H

#include <iostream>
#include <string>
using namespace std;

class CTest
{
public:

	CTest() { i_val = 0; };
	CTest(int iVal) { i_val = iVal; };
	
	
	friend ostream& operator <<(ostream& outputStream, const CTest& cTest) 
	{
		outputStream << "CTValue: " << cTest.i_val;
		return outputStream;
	};


private:
	int i_val;
};
#endif