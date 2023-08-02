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
#include "Utils.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

std::string RemoveCaracter(std::string frase, char caracter) {

    frase.erase(std::remove(frase.begin(), frase.end(), caracter), frase.end());
    return frase;
}

void ReadArchive(BST* bst) {
    std::ifstream ifs;
    std::string str;
    try {
        ifs.open("teste.csv"); // abre arquivo

        if (ifs.is_open()) {
            std::getline(ifs, str);// ler a primeira linha

            while (!ifs.eof()) { // ler resto do arquivo
                std::getline(ifs, str);
                Funcionario data = Funcionario("", "", 0, 0, "", "");

                std::istringstream iss(str);
                std::string element;
                std::string correctFloatString;
                int count = 1;
                float aux = 0;

                while (std::getline(iss, element, ';')) { // ler cada elemento da linha
                    switch (count) { // inserir dados na classe Funcionario
                    case 1:
                        data.SetName(element);
                        break;
                    case 2:
                        data.SetPost(element);
                        break;
                    case 3: //transformar string em float
                        correctFloatString = element;
                        for (int i = 0; i < element.length();i++)
                        {
                            if (element[i] != '.' && element[i] != ',')
                                correctFloatString[i] = element[i];
                            if (element[i] == '.')
                                correctFloatString[i] = ' ';
                            if (element[i] == ',')
                                correctFloatString[i] = '.';
                        }
                        correctFloatString = RemoveCaracter(correctFloatString, ' ');
                        aux = std::stof(correctFloatString);
                        data.SetMonthSalary(aux);
                        break;
                    case 4: //transformar string em float
                        correctFloatString = element;
                        for (int i = 0; i < element.length();i++)
                        {
                            if (element[i] != '.' && element[i] != ',')
                                correctFloatString[i] = element[i];
                            if (element[i] == '.')
                                correctFloatString[i] = ' ';
                            if (element[i] == ',')
                                correctFloatString[i] = '.';
                        }
                        correctFloatString = RemoveCaracter(correctFloatString, ' ');
                        aux = std::stof(correctFloatString);
                        data.SetGrossSalary(aux);
                        break;
                    case 5:
                        data.SetUnit(element);
                        break;
                    case 6:
                        data.SetJorney(element);
                        break;
                    }
                    count++;
                }
                bst->Insert(data); // insere a classe na arvore
            } // end while externo
            ifs.close(); // fecha arquivo
            std::cout << "\nArquivo Lido Com Sucesso!\n";
        } // end if
    }   // end try
    catch (...) {
        std::cout << "\nNão foi possível ler o Arquivo\n";
    }
}

void PutLine(NodeBST* node, std::ofstream *ofs){ //Inserir linha no arquivo de saída
  if(node != nullptr){
    
    PutLine(node->GetLeft(), ofs);
    PutLine(node->GetRight(), ofs);
    std::string line;
    std::string monthSalary = std::to_string(node->GetMonthSalary());//transformar o float em string
    std::string grossSalary = std::to_string(node->GetGrossSalary());//transformar o float em string

    //gerar a linha
    line = node->GetName() + ";" + node->GetPost() + ";" + monthSalary + ";" +
      grossSalary + ";" + node->GetUnit() + ";" + node->GetJorney();
    
    *ofs << line << std::endl; //insere a linha no arquivo
  }
  return;
}

bool SaveArchive(BST *bst, const std::string& filename){ // salvar o arquivo
  std::ofstream ofs;
  try{
    ofs.open(filename, std::ios::out);//abrir arquivo para salvar
    if(ofs.is_open()){
      //primeira linha a inserir
      std::string line = "Nome completo;Cargo Base;Remunera�o do M�s;Remunera�o Bruta;Unidade;Jornada"; 
      NodeBST *node = bst->GetRoot();
      ofs << line << std::endl;//insere a primeira liha
      PutLine(node, &ofs);//insere os nós
      ofs.close();
    }

  }
  catch(...){
  }
  return false;
    
}

//----------------------------------------------------------------------------------------------
//dentro desta seção é para o item 6 do menu
float SearchFirstNamesInternal(NodeBST* node, std::string nameToFind, float countNamesFound, float &countTotal) {

    float countEqualLetters = 0.0;
    if (node != nullptr) {
        countNamesFound = SearchFirstNamesInternal(node->GetLeft(), nameToFind, countNamesFound,countTotal);
        countNamesFound = SearchFirstNamesInternal(node->GetRight(), nameToFind, countNamesFound,countTotal);
        countTotal += 1;
        for (int i = 0;i < nameToFind.length();i++) { //percorrer o nome do nó para contar o nº de letras iguais
            if (node->GetName()[i] != nameToFind[i]) { 
                return countNamesFound;
            }
            else {
                countEqualLetters++;
            }
        }
        //se nº de letras iguais for igual ao tamanho do nome, encontrou o nome
        if (countEqualLetters == nameToFind.length()) {
            countNamesFound++;
            std::cout << node->GetName() << std::endl;
        }
        return countNamesFound;
    }
    return countNamesFound;
}

//função referente à procura do primeiro nome na árvore
void SearchFirstNames(BST* bst) {
  std::string name;
	float count = 0.0, percentage = 0.0, total = 0.0;
	std::cout << "Digite um primeiro nome para encontrar na árvore: ";
	std::cin >> name;
  name += " ";
  float countNamesFound = 0.0; //contador para nomes iguais ao que foi dado
  float countTotal = 0.0; //nº total de nomes na árvore
  NodeBST* node = bst->GetRoot();
  
  countNamesFound = SearchFirstNamesInternal(node, name, countNamesFound,countTotal);
  name = RemoveCaracter(name, ' ');
  std::cout << "\nHá " << countNamesFound << " " << name << "'s\n"; 
  percentage = (countNamesFound / countTotal) *100; //porcentagem de nomes encontrados
  std::cout << "O que corresponde a " << percentage << "% de nomes na árvore\n\n";
}
//__________________________________________________________________________
void MostCommonJob(BST* bst) //dentro desta seção tudo é relativo ao item 8 do menu.
{//função principal
  //usei dois vetors, um que guarda a string com os nomes dos cargos, e outra que guarda exatamente no mesmo indice correspondente quantas vezes aquele cargo apareceu.
    int index = 0, indexOfHighest = 0;
    std::string JobsList[1000], mostCommonJob;//jobslist é o vetor com as strings
    int joblistCount[1000];//esse éo vetor com a contagem de quantas vezes cada cargo unico apareceu
    for (int i = 0; i < 1000; i++)
    {
        joblistCount[i] = 0;//apenas inicializando a lista que conta repetições de cargos
    }
    float total = 0.0;
    FillJobList(bst->GetRoot(), JobsList, joblistCount, index, total);
    //a função acima retorna o array preenchido com todos os nomes UNICOS de cargos encontrados
    indexOfHighest = FindIndexOfMostCommon(joblistCount, index);
    //a função acima retornará o indice do cargo com mais repetições, para acha-lo no outro array que guarda as strings
    mostCommonJob = JobsList[indexOfHighest];//achando o cargo no array com strings
    float totalMostCommon = joblistCount[indexOfHighest];//seta a string do cargo mais achado
    float percentage = (totalMostCommon/total)*100;

    std::cout << "\nO Cargo mais comum eh: " << mostCommonJob 
        << ", Com " << joblistCount[indexOfHighest] 
        << " pessoas no cargo, representando aproximadamente " 
        << percentage << "% dos cargos.\n";
}

void FillJobList(NodeBST* node, std::string jobList[1000], int joblistCount[1000], int& index, float &count)
{//esta função retorna o array preenchido com todos os nomes UNICOS de cargos encontrados
    if (node != nullptr)
    { //aqui é apenas um traverse modificado
        count++;//count para contar quantos nós foram lidos.
        std::string job = node->GetPost();
        if (!JobIsInList(job,jobList,joblistCount,index))//a função chamada aqui verifica se o cargo já está na lista, caso esteja, a propria função atualiza a contagem de quantas vezes o cargo apareceu
        {
            if (index < 1000)
            {
                jobList[index] = job;//cai aqui quando não achou o cargo, adiciona ele na lista
                joblistCount[index]++;//se é um job diferente, tem pelo menos 1 no contador
                index++;//anda no indice atual, faço assim pro indice não se perder na recursão
            } 
        }
        FillJobList(node->GetLeft(),jobList,joblistCount,index,count);//olha o resto dos nós
        FillJobList(node->GetRight(),jobList,joblistCount,index,count);
    }    
}
bool JobIsInList(std::string job,std::string jobList[1000], int joblistCount[1000],int &index)
{//este metodo verifica se o cargo já está na lista
    for (int i = 0;i < index;i++)
    {//usa o index para não estourar o tamanho da lista e evitar verificações de valores não instanciados
        if (jobList[i] == job) //se achou o cargo
        {
            joblistCount[i]++;//se ja está na lista, aproveita para atualizar o count
            return true;
        }
    }
    return false;// se percorreu a lista e não achou
}

int FindIndexOfMostCommon(int joblistCount[1000], int& index)
{//este metodo apenas percorre o vetor com a contagem dos cargos, e devolve o maior valor encontrado
    int aux = 0;
    int indexOfHighest = 0;
    for(int i = 0;i<index;i++)
        if (joblistCount[i] > aux)
        {
            aux = joblistCount[i];
            indexOfHighest = i;
        }
    return indexOfHighest;
}
//_____________________________________________________________________________________
//dentro desta seção tudo é relativo ao item 9 do menu
void AverageRemuneration(BST* bst){ // Imprime a média salarial mensal de um cargo que o usuário digita
  NodeBST* m_Root = bst -> GetRoot();
  std::string postEntry; // Entrada do usuário
  std::cout << "Insert your desired post to analyse: ";
  getline(std::cin,postEntry);
  std::string str_num = AverageSalaryInternal(m_Root,postEntry); // Essa função retorna uma string com todos os salários mensais separados por um ";"
  std::string value = "";
  int value_aux = 0; // Valor auxiliar para uso interno da função
  int average = 0; // Valor da média total dos salários do cargo
  int count = 0; // Uma contagem de quantas pessoas tem no cargo especificado
  if (str_num.length() != 0){
    for (int i = 0;i < str_num.length();i++){
      if (str_num[i] == ';'){
        if (std::stof(value) == (int)std::stof(value)){
          value[value_aux] = '.'; value[value_aux+1] = '0';
        }
        average += std::stof(value);
        count++;
        value = "";
        value_aux = 0;
    }
    else{ 
        value[value_aux] = str_num[i];
        value_aux++;
      }
    }
  average = average/count;
  }
  if (average == 0) std::cout << "\nNao encontramos uma media para o cargo citado, digite um cargo valido.\n";
  else std::cout << "\nMedia salarial do cargo " << postEntry << ": R$" << average << "\n";
}

std::string AverageSalaryInternal(const NodeBST *node,std::string postEntry){
	if (node != nullptr)
	{
    int count_check = 0; // Variável responsável pela checagem entre ser ou não o cargo especificado pelo usuário
    string frase_arvore = RemoveCaracter(node->GetPost(),' ');
    string frase_entrada = RemoveCaracter(postEntry,' ');
		std::ostringstream oss; // String que será retornada com todos os salários mensais
    for (int i = 0;i < frase_entrada.length();i++){
      if ((frase_arvore.length() == frase_entrada.length()) && (frase_arvore[i] == frase_entrada[i])){
        count_check++;
      }
    }
		oss << AverageSalaryInternal(node->GetLeft(),postEntry);
    if (count_check == frase_entrada.length()) oss << node->GetMonthSalary() << ";"; 
		oss << AverageSalaryInternal(node->GetRight(),postEntry);
		return oss.str();
	}
  return "";
}
//-----------------------------------------------------------------------------------------------------------
//dentro desta seção tudo é relativo ao item 7 do menu.
void GrossRemuneration(BST* bst){//imprime a média do salário bruto, o maior e menor salários brutos

  NodeBST* m_Root = bst->GetRoot();

  float bruteSalary = m_Root->GetGrossSalary();



  float acum = 0.0; //soma dos salários brutos
  float lowest = bruteSalary; //menor salário
  float biggest = bruteSalary; //maior salário
  float average = 0.0;
  int acount = 0;
  GrossRemunerationInternal(m_Root,acum,biggest,lowest,acount);//procura os maior e menor salários e a soma dos salários brutos

  

  // Usamos o fixed para trocar o numero em cientifico para extenso 
   std::cout << std::fixed << setprecision(2) 
            << "A média da remuneração bruta é igual a: R$ " << (acum/acount)
            << "\nMenor remuneração é de: R$ " << lowest
            << "\nMaior remuneração é de: R$ " << biggest << "\n\n";
}

//procura os maior e menor salários e a soma dos salários brutos
void GrossRemunerationInternal(const NodeBST *node,float &acumulador,float &maior,float &menor,int &acount){
	if (node != nullptr)
	{
    acumulador += node->GetGrossSalary();
    acount++;
    if(node->GetGrossSalary() < menor) //novo menor salário
      menor = node->GetGrossSalary();
    if(node->GetGrossSalary() > maior) //novo maior salário
      maior = node->GetGrossSalary();
    GrossRemunerationInternal(node->GetLeft(),acumulador,maior,menor,acount);
    GrossRemunerationInternal(node->GetRight(),acumulador,maior,menor,acount);
	}
}

//-----------------------------------------------------------------------------------------------------------
//dentro desta seção tudo é relativo ao item 10 do menu.
const int MAX_UNIDADES = 5000;
const int TOP_UNIDADES = 10;

void Top10Units(BST* bst)
{
  NodeBST* m_Root = bst->GetRoot();

  
  //Conta o número de unidades diferentes
  int index = 0;

  //Lista de todas as unidades 
  std::string unitlist[MAX_UNIDADES];
  
  //Lista das 10 unidades com mais funcionários
  std::string topunits[TOP_UNIDADES]; 
  
  //Lista com o número de funcionários de todas as unidades 
  int unitcount[MAX_UNIDADES];
  
  //Lista com o número de funcionários das 10 unidades com mais funcionários
  int topcount[TOP_UNIDADES]; 

  for(int i = 0; i < MAX_UNIDADES; i++)
  {
    unitlist[i] = "";
    unitcount[i] = 0;
  }

  for(int i = 0; i < TOP_UNIDADES; i++)
  {
    topunits[i] = "";
    topcount[i] = 0;
  }
  
  CountUnitsInternal(m_Root, unitlist, unitcount, index);
  
  std::string aux_unit = "";
  int aux_count = 0;

  //Encontra as top 10 unidades com mais funcionários
  for(int i = 0; i < index; i++)
      {
        for(int j = 0; j < TOP_UNIDADES; j++)
          {
            if(unitcount[i] > topcount[j])
            {
              aux_count = topcount[j];
              aux_unit = topunits[j];
              
              topcount[j] = unitcount[i];
              topunits[j] = unitlist[i];

              UpdateTop(topunits, topcount, aux_unit, aux_count, j); //Atualiza o top 10
              
              j = 10; //Sair do laço interno
            }
          }
      }
  
  //Imprime as top 10 unidades com mais funcionários e suas quantidades
  for(int i = 0; i < 10; i++) 
    {
      std::cout << i+1 << ". " << topunits[i] << ": " << topcount[i] << std::endl;
    }


}

//Função que percorre a BST em pré-ordem e armazena todas as unidades diferentes (unitlist[]), conta quantas existem (index) e conta a quantidade de funcionários em cada uma (unitcount[])
void CountUnitsInternal(const NodeBST* node, std::string unitlist[], int unitcount[], int& index)
{
  bool flag = false;
  
  if(node != nullptr)
  {
    
    //Verificar se a unidade já não está na lista
    for(int i = 0; i < index; i++)
    {
      if(node->GetUnit() == unitlist[i])
      {
        flag = true;
        unitcount[i]++;
        i = index; //Sair do laço
      }
    }

    //Se a unidade não estiver na lista, ela é armazenada
    if(!flag)
    {
      unitlist[index] = node->GetUnit();
      unitcount[index]++;
      index++;
    }

    CountUnitsInternal(node->GetLeft(), unitlist, unitcount, index);
    CountUnitsInternal(node->GetRight(), unitlist, unitcount, index);
  
  
  }
  
}

//Atualiza o ranking das top 10 unidades com mais funcionários. Exemplo: Se foi encontrada uma unidade com mais funcionários que a de rank 2, a de rank 2 vira rank 3, a de rank 3 vira de rank 4 e assim por diante.
void UpdateTop(std::string topunits[TOP_UNIDADES], int topcount[TOP_UNIDADES], std::string unit, int count, int j)
{
  std::string aux_unit = "";
  int aux_count = 0;
  
  if(j < TOP_UNIDADES-1)
  {
    aux_unit = topunits[j+1];
    aux_count = topcount[j+1];
    
    topunits[j+1] = unit;
    topcount[j+1] = count;

    UpdateTop(topunits, topcount, aux_unit, aux_count, j+1);
  }
}
//--------------------------------------------------------------------
//dentro desta seção tudo é relativo ao item 11 do menu.
//imprime informações de cada funcionário que trabalha na unidade dada e retorna o nº de pessoas que trabalham nela
float SearchUnitInternal(NodeBST* node, std::string unitToFind, float countUnitsFound){ 
    if(node != nullptr) {
      float equalLetters = 0;
      countUnitsFound = SearchUnitInternal(node->GetLeft(), unitToFind, countUnitsFound);
      countUnitsFound = SearchUnitInternal(node->GetRight(), unitToFind, countUnitsFound);
      
      for(int i = 0; i < unitToFind.length();i++){ //contar o nº de letrais iguais
        if (node->GetUnit()[i] != unitToFind[i]) return countUnitsFound;
        else equalLetters++;
      }
      //se nº de letras iguais for igual ao tamanho da unidade, encontrou a unidade
      if (equalLetters == unitToFind.length()) { 
        countUnitsFound++;
        std::cout << "\nNome: " << node->GetName() << "\n" <<  "Cargo: " << node->GetPost() << "\n" << "Salário mensal: " << node->GetMonthSalary() << "\n" << "Salário total: " << node->GetGrossSalary() << "\n" << "Horas semanais: " << node->GetJorney() << "\n\n";
      } 
      return countUnitsFound;
    } 
    return countUnitsFound;
}

void SearchUnit(BST* bst){ //apresenta o nº de pessoas que trabalham em uma unidade específica
  std::string unit;
  std::cout << "Digite a unidade que voce quer encontrar na árvore: \n";
  getline(std::cin,unit);
  float countUnitsFound = 0;
  NodeBST* node = bst->GetRoot();

  //imprime informações de cada funcionário que trabalha na unidade dada e retorna o nº de pessoas que trabalham nela 
  countUnitsFound = SearchUnitInternal(node, unit, countUnitsFound);
  std::cout << "Há " << countUnitsFound << " pessoas trabalhando na unidade " << unit << std::endl;
}
  
