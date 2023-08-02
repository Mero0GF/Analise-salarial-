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
// NodeBST.h
#ifndef __NODE_BST_H__
#define __NODE_BST_H__

#include <string>
#include "Funcionario.h"

using namespace std;

class NodeBST
{
public:
	NodeBST(Funcionario data, NodeBST* parent = nullptr, NodeBST* left = nullptr, NodeBST* right = nullptr);
	~NodeBST();

	Funcionario GetData() const;
	void CopyDataFrom(const NodeBST* node);

	string GetName() const;
	void SetName(string completeName);

	string GetPost() const;
	void SetPost(string post);

	float GetMonthSalary() const;
	void SetMonthSalary(float monthSalary);

	float GetGrossSalary() const;
	void SetGrossSalary(float grossSalary);

	string GetUnit() const;
	void SetUnit(string unit);

	string GetJorney() const;
	void SetJorney(string jorney);

	NodeBST* GetParent() const;
	void SetParent(NodeBST* parent);

	NodeBST* GetLeft() const;
	void SetLeft(NodeBST* left);

	NodeBST* GetRight() const;
	void SetRight(NodeBST* right);

	bool IsRoot() const;
	bool IsLeaf() const;

	int GetDegree() const;
	int GetDepth() const;
	int GetHeight() const;

private:
	Funcionario m_Data;

	NodeBST* m_Parent;
	NodeBST* m_Left;
	NodeBST* m_Right;

	int GetDepthInternal(const NodeBST* node) const;
	int GetHeightInternal(const NodeBST* node) const;
};

#endif
