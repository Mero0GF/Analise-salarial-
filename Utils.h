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
// Utils.h
#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include "Funcionario.h"
#include "NodeBST.h"
#include "BST.h"

namespace Utils
{
	template <typename T>
	static T Max(T l, T r)
	{
		return (l > r) ? l : r;
	}
}

void ReadArchive(BST* bst);
bool SaveArchive(BST *bst, const std::string& filename);
void PutLine(NodeBST* node,std::ofstream *ofs);

void SearchFirstNames(BST* bst);
float SearchFirstNamesInternal(BST* node, std::string nameToFind, float countNamesFound);
void MostCommonJob(BST* bst);

void FillJobList(NodeBST* node, std::string jobList[1000], int joblistCount[1000], int& index, float &count);
bool JobIsInList(std::string job, std::string jobList[1000], int joblistCount[1000], int& index);
int FindIndexOfMostCommon(int joblistCount[1000], int& index);

void GrossRemuneration(BST* bst);
void GrossRemunerationInternal(const NodeBST* node, float &acum, float &maior, float &menor,int &acount);

void AverageRemuneration(BST* bst);
std::string AverageSalaryInternal(const NodeBST *node,std::string postEntry);

void Top10Units(BST* bst);
void CountUnitsInternal(const NodeBST* node, std::string unitlist[], int unitcount[], int& index);
void UpdateTop(std::string topunits[], int topcount[], std::string unit, int count, int j);

float SearchUnitInternal(NodeBST* node, std::string unitToFind, float countUnitsFound);
void SearchUnit(BST* bst);

#endif
