#include "tests.h"
#include "CTreeDynamic.h"
#include "CNodeDynamic.h"
#include "CTest.h"


void test_int_tree()
{
	CTreeDynamic<int> cTreeDynamic1;
	cTreeDynamic1.pcGetRoot()->vSetValue(0);

	cTreeDynamic1.pcGetRoot()->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	cTreeDynamic1.pcGetRoot()->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->vSetValue(2);

	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(3);
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(4);

	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(5);
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(6);

	cTreeDynamic1.pcGetRoot()->vPrintTreeScheme(0);
}


void test_double_tree()
{
	CTreeDynamic<double> cTreeDynamic1;
	cTreeDynamic1.pcGetRoot()->vSetValue(0.7);

	cTreeDynamic1.pcGetRoot()->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->vSetValue(1.1);
	cTreeDynamic1.pcGetRoot()->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->vSetValue(2.3);

	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(3.534);
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(4.73344);

	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(1.95);
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(0.35);

	cTreeDynamic1.pcGetRoot()->vPrintTreeScheme(0);
}


void test_CTest_tree()
{
	CTreeDynamic<CTest> cTreeDynamic1;
	cTreeDynamic1.pcGetRoot()->vSetValue(CTest(1));

	cTreeDynamic1.pcGetRoot()->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->vSetValue(CTest(2));
	cTreeDynamic1.pcGetRoot()->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->vSetValue(3);

	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(CTest(13));
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(CTest(440));

	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(CTest(-312));
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(CTest(60));

	cTreeDynamic1.pcGetRoot()->vPrintTreeScheme(0);

}



void test_string_tree()
{
	CTreeDynamic<std::string> cTreeDynamic1;

	cTreeDynamic1.pcGetRoot()->vSetValue("a");

	cTreeDynamic1.pcGetRoot()->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->vSetValue("aa");
	cTreeDynamic1.pcGetRoot()->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->vSetValue("aa");

	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue("aaa");
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue("aaa");

	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue("aaa");
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic1.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue("aaa");

	cTreeDynamic1.pcGetRoot()->vPrintTreeScheme(0);
}