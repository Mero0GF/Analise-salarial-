//-----------------------------------------------------------------------------------------------------------------
//NOME: PEDRO LOUREIRO MORONE BRANCO VOLPE   TIA: 42131936
//
//NOME: ERIC AKIO UCHIYAMADA                 TIA: 42107865
//
//NOME: Oliver Kieran Galvão McCormack       TIA: 42122058
// 
//NOME: Renan Luiz Rodrigues Tagliaferro     TIA: 42105846
//
//NOME: Thiago Leandro Liporace              TIA:42128481
//
//NOME: Lucas Goulart de Farias Meres        TIA:42127359
//-----------------------------------------------------------------------------------------------------------------
// BST.h
#ifndef __BST_H__
#define __BST_H__

#include "NodeBST.h"
#include <string>

class BST
{
public:
	BST();
	~BST();

	NodeBST* GetRoot() const;

	bool IsEmpty() const;
	void Clear();

	int GetDegree() const;
	int GetHeight() const;

	std::string TraverseInOrder();
	std::string TraversePreOrder() const;
	std::string TraversePostOrder() const;
	std::string TraverseDepthOrder() const;

	NodeBST* FindMin() const;
	NodeBST* FindMax() const;

	NodeBST* Predecessor(std::string name) const;
	NodeBST* Successor(std::string name) const;

	NodeBST* SearchIterative(std::string name) const;
	NodeBST* Search(std::string name) const;
	NodeBST* Insert(Funcionario data);
	void Remove(std::string name);
	int GetCount();

private:
	NodeBST* m_Root;
	int count;

	void Destroy(NodeBST* node);

	int GetDegreeInternal(const NodeBST* node) const;

	std::string TraverseInOrderInternal(const NodeBST* node,int &count);
	std::string TraversePreOrderInternal(const NodeBST* node) const;
	std::string TraversePostOrderInternal(const NodeBST* node) const;
	std::string TraverseDepthOrderInternal(const NodeBST* node) const;

	NodeBST* FindMinInternal(NodeBST* node) const;
	NodeBST* FindMaxInternal(NodeBST* node) const;

	NodeBST* PredecessorInternal(NodeBST* node) const;
	NodeBST* SuccessorInternal(NodeBST* node) const;

	NodeBST* SearchInternal(NodeBST* node, std::string name) const;
	NodeBST* InsertInternal(NodeBST* node, NodeBST* parent, Funcionario data);
	NodeBST* RemoveInternal(NodeBST* node, std::string name);
	NodeBST* RemoveNode(NodeBST* node);
	void UpdateParentChild(NodeBST* parent, const NodeBST* child, NodeBST* newChild);
};

#endif
