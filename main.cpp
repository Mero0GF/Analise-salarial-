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

// mainBST.cpp
#include <iostream>
#include <string>
#include "BST.h"
#include "Utils.h"

void PrintNode(NodeBST* node)//Imprimir informações do nó
{
	if (node == nullptr) return;
	std::cout << "\nComplete Name: " << node->GetName()
		<< "\n Post: " << node->GetPost()
		<< "\n Month Salary: " << node->GetMonthSalary()
		<< "\n Gross Salary: " << node->GetGrossSalary()
		<< "\n Unit: " << node->GetUnit()
		<< "\n Jorney: " << node->GetJorney()
		<< "\n Parent: " << (node->GetParent() != nullptr ? node->GetParent()->GetName() : "-1")
		<< "\n Left: " << (node->GetLeft() != nullptr ? node->GetLeft()->GetName() : "-1")
		<< "\n Right: " << (node->GetRight() != nullptr ? node->GetRight()->GetName() : "-1")
		<< "\n Degree: " << node->GetDegree()
		<< "\n Depth: " << node->GetDepth()
		<< "\n Height: " << node->GetHeight() << "\n\n";
}

void Insert(BST* bst)
{

	std::string name, position, unit, jorney;
	float monthSalary, grossSalary;

	std::cout << "Insert name(all caps): ";
	std::getline(cin,name);
	cin.ignore();
	std::cout << "Insert position(all caps): ";
	std::getline(cin,position);
	cin.ignore();
	std::cout << "Insert month salary(write in float format): ";
	std::cin >> monthSalary;
	cin.ignore();
	std::cout << "Insert gross salary(write in float format): ";
	std::cin >> grossSalary;
	cin.ignore();
	std::cout << "Insert unit(all caps): ";
  std::getline(cin,unit);
	cin.ignore();
	std::cout << "Insert jorney(all caps): ";
  std::getline(cin,jorney);
  cin.ignore();


	Funcionario data = Funcionario(name, position, monthSalary, grossSalary, unit, jorney);

	NodeBST* node = bst->Insert(data);
	if (node)
	{
		std::cout << "Node inserted:\n";
		PrintNode(bst->Search(name));

	}
	else
		std::cout << "*** ERROR! Couldn't insert node!\n";
}

void Remove(BST* bst)
{
	std::string name;
	std::cout << "Remove name: ";
	std::getline(cin,name);
	cin.ignore();
	bst->Remove(name);
}

void Search(BST* bst)
{
	std::string name;
	std::cout << "Search Name: ";
	std::getline(std::cin, name);
	cin.ignore();
	NodeBST* node = bst->Search(name);
	if (node != nullptr)
	{
		std::cout << "Node found:\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! Couldn't find node!\n";
}


void WriteToFile(BST* bst){
  bool saved;
  saved = (SaveArchive(bst, "arquivo_saída.csv"));
  if(!saved)
    std::cout << "\nÁrvore salvada com sucesso!\n";
  else  std::cout << "\nNão foi possível salvar a árvore no arquivio\n";
}


int main()
{

	BST* bst = new BST();
  std::string postEntry;
	int option = 0;
	while (true) {
		do
		{
			std::cout << "*** BST Tree ***\n"
				<< "[1] Insert Node\n"
				<< "[2] Remove Node\n"
				<< "[3] Search Node\n"
				<< "[4] Read Archive\n"
        << "[5] Save to Archive\n"
				<< "[6] Search number of people with a first name\n"
				<< "[7] Search average, lowest and biggest gross salary\n"
				<< "[8] Search the Most common job, and its percentage\n"
        << "[9] Search for the average salary of a specific job\n"
        << "[10] Search for the Top 10 Units with the most employees\n"
        << "[11] Search for unit, print all of the workers info\n"
        << "[12] Clear Tree\n"
				<< "[0] Exit\nOption: ";
			std::cin >> option;
			cin.ignore();
			std::cout << '\n';

			switch (option)
			{
			case 1: Insert(bst); break;
			case 2: Remove(bst); break;
			case 3: Search(bst); break;
			case 4: ReadArchive(bst); break;
      case 5: WriteToFile(bst); break;
			case 6: SearchFirstNames(bst); break;   
      case 7: GrossRemuneration(bst); break;
			case 8: MostCommonJob(bst); break;        
			case 9: AverageRemuneration(bst); break;
      case 10: Top10Units(bst); break;
      case 11: SearchUnit(bst); break;
      case 12: bst->Clear(); break;
			}

			std::cout << '\n';
		} while (option != 0);

		delete bst;
    bst = nullptr;
    return 0;
	}
}
