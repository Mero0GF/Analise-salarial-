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
// Funcionario.h
#ifndef __FUNCIONARIO_H__
#define __FUNCIONARIO_H__

#include <string>

using namespace std;
class Funcionario {
private:
    string f_completeName;
    string f_post;
    float f_monthSalary;
    float f_grossSalary;
    string f_unit;
    string f_jorney;

public:
    Funcionario(string completeName, string post, float monthSalary,
        float grossSalary, string unit, string jorney);

    ~Funcionario();

    string GetName() const;
    void SetName(string completeName);

    string GetPost() const;
    void SetPost(string Post);

    float GetMonthSalary() const;
    void SetMonthSalary(float monthSalary);

    float GetGrossSalary() const;
    void SetGrossSalary(float grossSalary);

    string GetUnit() const;
    void SetUnit(string unit);

    string GetJorney() const;
    void SetJorney(string jorney);
};

#endif