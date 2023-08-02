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
#include "Funcionario.h"
#include <string>

using namespace std;

Funcionario::Funcionario(string completeName, string post, float monthSalary,
    float grossSalary, string unit, string jorney)
    : f_completeName(completeName), f_post(post), f_monthSalary(monthSalary),
    f_grossSalary(grossSalary), f_unit(unit), f_jorney(jorney) {}

Funcionario::~Funcionario() { }

string Funcionario::GetName() const { return f_completeName; }

void Funcionario::SetName(string name) { f_completeName = name; }

string Funcionario::GetPost() const { return f_post; }

void Funcionario::SetPost(string post) { f_post = post; }

float Funcionario::GetMonthSalary() const { return f_monthSalary; }

void Funcionario::SetMonthSalary(float monthSalary) {
    f_monthSalary = monthSalary;
}

float Funcionario::GetGrossSalary() const { return f_grossSalary; }

void Funcionario::SetGrossSalary(float grossSalary) {
    f_grossSalary = grossSalary;
}

string Funcionario::GetUnit() const { return f_unit; }

void Funcionario::SetUnit(string unit) { f_unit = unit; }

string Funcionario::GetJorney() const { return f_jorney; }

void Funcionario::SetJorney(string jorney) { f_jorney = jorney; }
