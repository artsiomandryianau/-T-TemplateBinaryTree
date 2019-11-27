#include "tests.h"
#include "CNodeDynamic.h"
#include "CTreeDynamic.h"
#include "CTest.h"
#include <iostream>
using namespace std;

int main()
{

	cout << "------INT TREE----\n\n";
	test_int_tree();
	cout << "\n-------DOUBLE TREE----\n\n";
	test_double_tree();
	cout << "\n--------CTEST TREE----\n\n";
	test_CTest_tree();
	cout << "\n----------STRING TREE----\n\n";
	test_string_tree();

	cout << "\n\n---------sGetType-----";
	CTreeDynamic<int> cTreeDynamicInts;
	CTreeDynamic<string> cTreeDynamicStrings;
	CTreeDynamic<CTest> cTreeDynamicCTests;
	CTreeDynamic<double> cTreeDynamicDoubles;


	cout << "\n" << cTreeDynamicInts.pcGetRoot()->sGetKnownType();
	cout << "\n" << cTreeDynamicStrings.pcGetRoot()->sGetKnownType();
	cout << "\n" << cTreeDynamicCTests.pcGetRoot()->sGetKnownType();
	cout << "\n" << cTreeDynamicDoubles.pcGetRoot()->sGetKnownType();

	cout << endl;
	return 0;
}