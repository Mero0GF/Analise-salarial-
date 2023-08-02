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
// BST.cpp
#include "NodeBST.h"
#include "BST.h"
#include "Utils.h"
#include <sstream>
#include <queue>
#include <iostream> // TraverseDepthOrderInternal


BST::BST()
	: m_Root(nullptr)
{
}

BST::~BST()
{
	Clear();
}

NodeBST* BST::GetRoot() const
{
	return m_Root;
}

bool BST::IsEmpty() const
{
	return m_Root == nullptr;
}

void BST::Clear()
{
	Destroy(m_Root);
	m_Root = nullptr;
}

void BST::Destroy(NodeBST* node)
{
	if (node != nullptr)
	{
		Destroy(node->GetLeft());
		Destroy(node->GetRight());
		count = 0;
		delete node;
		node = nullptr;
	}
}

int BST::GetDegree() const
{
	return GetDegreeInternal(m_Root);
}

int BST::GetDegreeInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		int left = GetDegreeInternal(node->GetLeft());
		int right = GetDegreeInternal(node->GetRight());
		return Utils::Max(node->GetDegree(), Utils::Max(left, right));
	}

	return 0;
}

int BST::GetHeight() const
{
	if (m_Root == nullptr)
		return -1;

	return m_Root->GetHeight();
}

std::string BST::TraverseInOrder()
{
  int count = 0;
  std::string res = TraverseInOrderInternal(m_Root,count);
  std::cout <<"Count = "<<count<<"\n";
  return res;
}
std::string BST::TraverseInOrderInternal(const NodeBST* node,int &count)
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraverseInOrderInternal(node->GetLeft(),count);
		oss << node->GetName() << "\n\n";
    count++;
		oss << TraverseInOrderInternal(node->GetRight(),count);
		return oss.str();
	}
	return "";
}

std::string BST::TraversePreOrder() const
{
	return TraversePreOrderInternal(m_Root);
}

std::string BST::TraversePreOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << node->GetName() << "\n\n";
		oss << TraversePreOrderInternal(node->GetLeft());
		oss << TraversePreOrderInternal(node->GetRight());
		return oss.str();
	}

	return "";
}

std::string BST::TraversePostOrder() const
{
	return TraversePostOrderInternal(m_Root);
}

std::string BST::TraversePostOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraversePostOrderInternal(node->GetLeft());
		oss << TraversePostOrderInternal(node->GetRight());
		oss << node->GetName() << "\n\n";
		return oss.str();
	}

	return "";
}
std::string BST::TraverseDepthOrder() const
{
	return TraverseDepthOrderInternal(m_Root);
}

std::string BST::TraverseDepthOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		std::queue<const NodeBST*> queue;

		queue.push(node);

		while (!queue.empty())
		{
			const NodeBST* n = queue.front();
			queue.pop();

			oss << n->GetName() << "\n\n";

			if (n->GetLeft() != nullptr)
				queue.push(n->GetLeft());

			if (n->GetRight() != nullptr)
				queue.push(n->GetRight());
		}

		return oss.str();
	}

	return "";
}
NodeBST* BST::FindMin() const
{
	return FindMinInternal(m_Root);
}

NodeBST* BST::FindMinInternal(NodeBST* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetLeft() == nullptr)
		return node;
	else
		return FindMinInternal(node->GetLeft());
}

NodeBST* BST::FindMax() const
{
	return FindMaxInternal(m_Root);
}

NodeBST* BST::FindMaxInternal(NodeBST* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetRight() == nullptr)
		return node;
	else
		return FindMaxInternal(node->GetRight());
}

NodeBST* BST::Predecessor(std::string name) const
{
	NodeBST* node = SearchInternal(m_Root, name);
	return node == nullptr ? nullptr : PredecessorInternal(node);
}

NodeBST* BST::PredecessorInternal(NodeBST* node) const
{
	if (node->GetLeft() != nullptr)
	{
		return FindMaxInternal(node->GetLeft());
	}
	else
	{
		NodeBST* current = node;
		NodeBST* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetLeft())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeBST* BST::Successor(std::string name) const
{
	NodeBST* node = SearchInternal(m_Root, name);
	return node == nullptr ? nullptr : SuccessorInternal(node);
}

NodeBST* BST::SuccessorInternal(NodeBST* node) const
{
	if (node->GetRight() != nullptr)
	{
		return FindMinInternal(node->GetRight());
	}
	else
	{
		NodeBST* current = node;
		NodeBST* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetRight())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeBST* BST::SearchIterative(std::string name) const
{
	NodeBST* current = m_Root;
	while (current != nullptr && current->GetName() != name)
	{
		if (current->GetName() > name)
			current = current->GetLeft();
		else
			current = current->GetRight();
	}

	return current;
}

NodeBST* BST::Search(std::string name) const
{
	return SearchInternal(m_Root, name);
}

NodeBST* BST::SearchInternal(NodeBST* node, std::string name) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetName() == name)
		return node;
	else if (node->GetName() > name)
		return SearchInternal(node->GetLeft(), name);
	else
		return SearchInternal(node->GetRight(), name);
}


NodeBST* BST::Insert(Funcionario data)
{
	if (IsEmpty())
	{
		m_Root = new NodeBST(data);
		count++;
		return m_Root;
	}
	return InsertInternal(m_Root, nullptr, data);
}

NodeBST* BST::InsertInternal(NodeBST* node, NodeBST* parent, Funcionario data)
{
	if (node == nullptr){
    node = new NodeBST(data, parent);
    count++;
  }
	else if (node->GetName() == data.GetName()){
		return nullptr; // Error! Cannot insert duplicate.
  }
	else if (node->GetName() > data.GetName())
		node->SetLeft(InsertInternal(node->GetLeft(), node, data));
	else if (node->GetName() < data.GetName())
		node->SetRight(InsertInternal(node->GetRight(), node, data));

	return node;
}

void BST::Remove(std::string name)
{
	RemoveInternal(m_Root, name);
}

NodeBST* BST::RemoveInternal(NodeBST* node, std::string name)
{
	if (node == nullptr) {
		return nullptr;
	}
	else if (node->GetName() == name)
		node = RemoveNode(node);
	else if (node->GetName() > name)
		node->SetLeft(RemoveInternal(node->GetLeft(), name));
	else
		node->SetRight(RemoveInternal(node->GetRight(), name));

	return node;
}

NodeBST* BST::RemoveNode(NodeBST* node)
{
	count--;
	NodeBST* parent = node->GetParent();

	// Case 1: The node to be removed is a leaf.
	if (node->IsLeaf())
	{
		UpdateParentChild(parent, node, nullptr);

		delete node;
		node = nullptr;
	}
	// Case 2: The node to be removed has no left child/subtree.
	else if (node->GetLeft() == nullptr)
	{
		NodeBST* newChild = node->GetRight();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 3: The node to be removed has no right child/subtree.
	else if (node->GetRight() == nullptr)
	{
		NodeBST* newChild = node->GetLeft();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 4: The node to be removed has both left and right children/subtrees.
	else
	{
		// To remove the node, we are reducing the problem to Case 3.
		// In this case, predecessor is located in the node's left child/subtree and
		// is the node that has no right child/subtree.
		NodeBST* predecessor = Predecessor(node->GetName());

		// Instead of only updating pointers, we are copying the data from the
		// predecessor to the node pointer and then we remove the predecessor node.
		node->CopyDataFrom(predecessor);
		node->SetLeft(RemoveInternal(node->GetLeft(), predecessor->GetName()));
	}

	return node;
}

void BST::UpdateParentChild(NodeBST* parent, const NodeBST* child, NodeBST* newChild)
{
	if (parent != nullptr)
	{
		if (parent->GetLeft() == child)
			parent->SetLeft(newChild);
		else
			parent->SetRight(newChild);
	}
	else
	{
		m_Root = newChild;
	}

	if (newChild != nullptr)
		newChild->SetParent(parent);
}

int BST::GetCount() {
	return count;
}