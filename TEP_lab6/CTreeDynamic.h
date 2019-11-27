#ifndef CTREEDYNAMIC_H
#define CTREEDYNAMIC_H

#include <iostream>
#include "CNodeDynamic.h"

template <typename T> class CTreeDynamic
{
private:
	CNodeDynamic<T> *pc_root;

public:
	CTreeDynamic();
	~CTreeDynamic();

	CNodeDynamic<T> *pcGetRoot() { return pc_root; }

	void vPrintTree();

	bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);

};

template <typename T>
CTreeDynamic<T>::CTreeDynamic()
{
	pc_root = new CNodeDynamic<T>();
}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic()
{
	delete pc_root;
}


template <typename T>
void CTreeDynamic<T>::vPrintTree()
{
	pc_root->vPrintAllBelow();
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> * pcParentNode, CNodeDynamic<T> * pcNewChildNode)
{
	if (pcParentNode == pcNewChildNode || pcParentNode == NULL || pcNewChildNode == NULL || pcNewChildNode->pcGetParent() == NULL) {
		return false;
	}

	pcNewChildNode->pcGetParent()->vRemoveChild(pcNewChildNode);
	pcParentNode->vAddNewChild(pcNewChildNode);
	return true;
};


#endif
