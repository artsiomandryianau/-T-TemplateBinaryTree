#ifndef CNODEDYNAMIC_H
#define CNODEDYNAMIC_H


#include <vector>
#include <iostream>
#include <string>
using namespace std;

namespace {

	template <typename T>class CNodeDynamic
	{
	public:
		CNodeDynamic() { pc_parent_node = NULL; };
		~CNodeDynamic();

		void vSetValue(T iNewVal)
		{ 
			i_val = iNewVal; 
		};


		void vSetParent(CNodeDynamic<T>* pcNewParent)
		{
			pc_parent_node = pcNewParent; 
		};


		void vAddNewChild();

		void vAddNewChild(CNodeDynamic<T>* cNewChild);

		void vRemoveChild(CNodeDynamic<T>* cChild);


		int iGetChildrenNumber() 
		{
			return v_children.size();
		};

		CNodeDynamic<T> *pcGetChild(int iChildOffset);


		CNodeDynamic<T> *pcGetParent()
		{
			return pc_parent_node;
		};

		string sGetKnownType();


		void vPrint()
		{ 
			cout << " " << i_val;
		};
		void vPrintAllBelow();
		void vPrintUp();
		void vPrintTreeScheme(int iSpace);


	private:

		vector<CNodeDynamic<T> *> v_children;
		CNodeDynamic<T> *pc_parent_node;
		T i_val;
	};

	template <typename T>
	CNodeDynamic<T>::~CNodeDynamic()
	{
		for (int i = 0; i < v_children.size(); i++)
		{
			delete v_children[i];
		}
	}

	template <typename T>
	void CNodeDynamic<T>::vAddNewChild()
	{
		CNodeDynamic *c_new_child;
		c_new_child = new CNodeDynamic();
		c_new_child->vSetParent(this);

		v_children.push_back(c_new_child);
	}

	template <typename T>
	void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T>* cNewChild)
	{
		cNewChild->vSetParent(this);
		v_children.push_back(cNewChild);
	}

	template <typename T>
	void CNodeDynamic<T>::vRemoveChild(CNodeDynamic<T> * cChild)
	{
		for (int i = 0; i < v_children.size(); i++) {
			if (v_children[i] == cChild) {
				v_children.erase(v_children.begin() + i);
				return;
			}
		}
	}

	template <typename T>
	CNodeDynamic<T> * CNodeDynamic<T>::pcGetChild(int iChildOffset)
	{
		if (iChildOffset < 0 || iChildOffset > v_children.size() - 1) {
			return NULL;
		}
		else {
			return v_children[iChildOffset];
		}
	}

	template <typename T>
	string CNodeDynamic<T>::sGetKnownType()
	{
		string s_type = "Unknown";
		return(s_type);
	}

	template<>
	string CNodeDynamic<double>::sGetKnownType()
	{
		string s_type = "Double";
		return(s_type);
	}


	template <>
	string CNodeDynamic<int>::sGetKnownType()
	{
		string s_type = "INT";
		return(s_type);
	}


	template<>
	string CNodeDynamic<string>::sGetKnownType()
	{
		string s_type = "string";
		return (s_type);
	}

	template <typename T>
	void CNodeDynamic<T>::vPrintAllBelow()
	{
		vPrint();
		for (int i = 0; i < v_children.size(); i++) {
			v_children[i]->vPrintAllBelow();
		}
	}

	template <typename T>
	void CNodeDynamic<T>::vPrintUp()
	{
		vPrint();

		if (pc_parent_node != NULL) {
			pc_parent_node->vPrintUp();
		}
	}

	template <typename T>
	void CNodeDynamic<T>::vPrintTreeScheme(int iSpace)
	{
		vPrint();
		cout << "\n";
		for (int i = 0; i < v_children.size(); i++) {
			for (int j = 0; j < iSpace; j++) {
				cout << "|  ";
			}
			cout << "|--";
			v_children[i]->vPrintTreeScheme(iSpace + 1);

		}
	};
}
#endif 