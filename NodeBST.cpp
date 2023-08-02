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
// NodeBST.cpp
#include "NodeBST.h"
#include "Utils.h"
#include "Funcionario.h"

using namespace std;

NodeBST::NodeBST
(Funcionario data, NodeBST* parent, NodeBST* left, NodeBST* right)

	: m_Data(data)
	, m_Parent(parent)
	, m_Left(left)
	, m_Right(right)
{
}

NodeBST::~NodeBST()
{
	m_Parent = nullptr;
	m_Left = nullptr;
	m_Right = nullptr;
}
////////////////////////////////////////////////////////////////////////////////////////
void NodeBST::CopyDataFrom(const NodeBST* node)
{
	m_Data.SetName(node->GetName());

	m_Data.SetPost(node->GetPost());

	m_Data.SetMonthSalary(node->GetMonthSalary());

	m_Data.SetGrossSalary(node->GetGrossSalary());

	m_Data.SetUnit(node->GetUnit());

	m_Data.SetJorney(node->GetJorney());
}

Funcionario NodeBST::GetData() const {

	return m_Data;
}

string NodeBST::GetName() const
{
	return m_Data.GetName();
}

void NodeBST::SetName(string completeName)
{
	m_Data.SetName(completeName);
}

string NodeBST::GetPost() const
{
	return m_Data.GetPost();
}

void NodeBST::SetPost(string post)
{
	m_Data.SetPost(post);
}

float NodeBST::GetMonthSalary() const
{
	return m_Data.GetMonthSalary();
}

void NodeBST::SetMonthSalary(float monthSalary)
{
	m_Data.SetMonthSalary(monthSalary);
}

float NodeBST::GetGrossSalary() const
{
	return m_Data.GetGrossSalary();
}

void NodeBST::SetGrossSalary(float grossSalary)
{
	m_Data.SetGrossSalary(grossSalary);
}

string NodeBST::GetUnit() const
{
	return m_Data.GetUnit();
}

void NodeBST::SetUnit(string unit)
{
	m_Data.SetUnit(unit);
}

string NodeBST::GetJorney() const
{
	return m_Data.GetJorney();
}

void NodeBST::SetJorney(string jorney)
{
	m_Data.SetJorney(jorney);
}


////////////////////////////////////////////////////////////////////////////////////////
NodeBST* NodeBST::GetParent() const
{
	return m_Parent;
}

void NodeBST::SetParent(NodeBST* parent)
{
	m_Parent = parent;
}

NodeBST* NodeBST::GetLeft() const
{
	return m_Left;
}

void NodeBST::SetLeft(NodeBST* left)
{
	m_Left = left;
}

NodeBST* NodeBST::GetRight() const
{
	return m_Right;
}

void NodeBST::SetRight(NodeBST* right)
{
	m_Right = right;
}

bool NodeBST::IsRoot() const
{
	return m_Parent == nullptr;
}

bool NodeBST::IsLeaf() const
{
	return m_Left == nullptr && m_Right == nullptr;
}

int NodeBST::GetDegree() const
{
	int degree = 0;

	if (m_Left != nullptr)
		++degree;
	if (m_Right != nullptr)
		++degree;

	return degree;
}

int NodeBST::GetDepth() const
{
	return GetDepthInternal(this);
}

int NodeBST::GetDepthInternal(const NodeBST* node) const
{
	if (node->IsRoot())
	{
		return 0;
	}
	else
	{
		return 1 + GetDepthInternal(node->GetParent());
	}
}

int NodeBST::GetHeight() const
{
	return GetHeightInternal(this);
}

int NodeBST::GetHeightInternal(const NodeBST* node) const
{
	if (node == nullptr || node->IsLeaf())
	{
		return 0;
	}
	else
	{
		return 1 + Utils::Max(GetHeightInternal(node->GetLeft()), GetHeightInternal(node->GetRight()));
	}
}
