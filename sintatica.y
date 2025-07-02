%{
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <iterator>
#include <algorithm>

#define YYSTYPE atributos

using namespace std;

int mainStatus = 0;
int var_temp_qnt;
int var_lace_qnt;
int var_cond_qnt;
int var_linha_qnt = 1;
int var_lace_name_qnt = 0;
int controleLoop = 0;
int controleFunction = 0;

string error = "";
string warning = "";
string contLinha = "1";

struct atributos
{
	string label;
	string traducao;
	string tipo;
	string valor;
	string index;

	vector<string> valores;
	int linha = 0;
};

typedef struct
{
	string nomeVariavel;
	string tipoVariavel; 
	string labelVariavel;
	string valorVariavel;
}	TIPO_SIMBOLO;

typedef struct
{
	string tipoVariavel; 
	string labelVariavel;
	string valor;
}	TIPO_TEMP;

typedef struct
{
	string nomeLaco;
	string tipoLaco;
	string fimLaco;
	string inicioLaco;
	int contexto;
}	TIPO_LOOP;

typedef struct
{
	string nomeFunction;
	string tipoReturn;
	string inicioFunction;
	string fimFunction;
	vector<TIPO_SIMBOLO> parameters;
	string retornoTipo = "";
	string retornoLabel = "";
}	TIPO_FUNCTION;

vector<TIPO_LOOP> tabelaLoop;
vector<TIPO_FUNCTION> tabelaFunction;
vector<TIPO_SIMBOLO> parametersChamada;
vector<vector<TIPO_SIMBOLO>> mapa;
int contextoGlobal;
vector<TIPO_TEMP> tabelaTemp;
string atribuicaoVariavel;
string atribuicaoVariavelGlobais;
string traducaoFunction;

int yylex(void);
void yyerror(string);
int getContexto();
string gentempcode();
string genLacecode();
string genCondcode();
string genLaceNameCode();
void verificarVariavelRepetida(string variavel);
TIPO_SIMBOLO getSimbolo(string variavel);
void addSimbolo(string variavel, string tipo, string label);
void addString(string variavel, string tipo, string label);
int addTempString(string label, string tipo);
int getSize(string str);
void addTemp(string label, string tipo);
void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2);
void atualizarContexto(int num);
void contadorDeLinha();
void pushContexto();
void popContexto();
void pushLoop(string tipo);
void pushFunction();
TIPO_FUNCTION getFunction();
TIPO_LOOP getLace(string nome);
TIPO_LOOP getLaceBreak();
TIPO_FUNCTION getFunctionChamada(string nome);
void verificarAtributoRelacional(atributos tipo_1);
%}

%token TK_NUM TK_REAL TK_CHAR TK_TRUE TK_FALSE TK_STRING TK_VOID TK_FUNCTION
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_TIPO_STRING TK_CAST_FLOAT TK_CAST_INT TK_CAST_BOOL
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_IGUAL_IGUAL TK_DIFERENTE TK_MAIS_MAIS TK_MENOS_MENOS TK_OU TK_E TK_MAIS_IGUAL TK_MENOS_IGUAL TK_VEZES_IGUAL TK_DIVISAO_IGUAL
%token TK_IF TK_ELSE TK_WHILE TK_FOR TK_DO TK_SWITCH TK_CASE TK_BREAK TK_CONTINUE TK_PRINT TK_SCAN TK_RETURN
%token TK_ERROR 

%start S

%left '+'

%nonassoc TK_CAST_FLOAT 
%nonassoc TK_CAST_INT 
%nonassoc TK_CAST_CHAR

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				if(error == "")
					cout << "/*Compilador Neolingo*/\n" + warning + "\n"<< "#include <iostream>\n#include <string.h>\n#include <stdio.h>" + atribuicaoVariavelGlobais + "\n" + traducaoFunction  + "\nint main(void)\n{\n" <<  atribuicaoVariavel + "\n" + $5.traducao << "\treturn 0;\n}" << endl;
				else{
					cout << "\n" + warning + "\n";
					yyerror(error);
				} 
			}
			| DECLARACAO ';' S
			{
			}
			| ATRIBUICAO ';' S
			{
				traducaoFunction += $1.traducao;
			}
			| FUNCAO S
			{
			}
			;

FUNCAO     : DECLAFUNC '(' PARAMETERS ')' BLOCO
			{
				TIPO_FUNCTION function = getFunction();

				int size = tabelaFunction.size() - 1;
				tabelaFunction[size].nomeFunction = $1.label;

				if((function.retornoLabel == "") && ($1.tipo != "void"))
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Função não apresenta um retorno.\n";
				else if((function.retornoLabel != "") && ($1.tipo == "void"))
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Função void não poder conter um retorno.\n";
				else if($1.tipo != function.retornoTipo && ($1.tipo != "void"))
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Tipo de return não condiz com o tipo da função.\n";

				traducaoFunction += $5.traducao + "\tEndFunc" + ";\n\n";
			}
			;

DECLAFUNC  : TK_FUNCTION TIPOS TK_ID
		   {
			   int size = tabelaFunction.size() - 1;
			   for(int i = size; i >= 0; i--)
			   {
				   if($3.label == tabelaFunction[i].nomeFunction)
				   {
						error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Nome de função já existe.\n";
				   }
			   }

			   traducaoFunction += "    _" + $3.label + ":\n";
			   $$.label = $3.label;
			   $$.tipo = $2.tipo;
		   }
		   ;

PARAMETERS : PARAMETER
		   {
		   }
		   |
		   {
		   }
		   ;

PARAMETER   : DECLARACAO
		    {
		    }
		    | DECLARACAO ',' PARAMETER
		    {
		    }
		    ;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			| BLOCO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			| TK_IF '(' E ')' E ';' COMANDOS
			{
				verificarAtributoRelacional($3);
				$$.label = gentempcode();

				if(controleFunction > 0){
					traducaoFunction = traducaoFunction + "\t" + "int" + " " + $$.label +";\n";
				} else {
					atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				}

				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"if(" + $$.label + ") goto "+ cond + "\n" + 
				$5.traducao + "\t" + cond + "\n" + $7.traducao;
			}
			| TK_IF '(' E ')' E ';' TK_ELSE E ';' COMANDOS
			{
				verificarAtributoRelacional($3);
				$$.label = gentempcode();
				if(controleFunction > 0){
					traducaoFunction = traducaoFunction + "\t" + "int" + " " + $$.label +";\n";
				} else {
					atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				}
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"if(" + $$.label + ") goto ELSE;" + "\n" + 
				$5.traducao + "\tgoto " + cond + "\n" + "\tELSE:\n" + $8.traducao
				+ "\t" + cond +"\n" + $10.traducao;
			}
			| TK_IF '(' E ')' E ';' TK_ELSE BLOCO COMANDOS
			{
				verificarAtributoRelacional($3);
				$$.label = gentempcode();
				if(controleFunction > 0){
					traducaoFunction = traducaoFunction + "\t" + "int" + " " + $$.label +";\n";
				} else {
					atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				}
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"if(" + $$.label + ") goto ELSE;\n" + $5.traducao
				+ "\tgoto "+cond+"\n" + "\tELSE:\n" + $8.traducao + "\t"+cond+"\n" +
				$9.traducao;
			}
			| TK_IF '(' E ')' BLOCO COMANDOS
			{
				verificarAtributoRelacional($3);
				$$.label = gentempcode();

				if(!mainStatus){
					traducaoFunction = traducaoFunction + "\t" + "int" + " " + $$.label +";\n";
				} else {
					atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				}

				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"if(" + $$.label + ") goto " + cond + "\n"
				+ $5.traducao + "\t" + cond + "\n" + $6.traducao;
			}
			| TK_IF '(' E ')' BLOCO TK_ELSE E ';' COMANDOS
			{
				verificarAtributoRelacional($3);
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"if(" + $$.label + ") goto ELSE;\n" + $5.traducao +
				"\tgoto " + cond + "\n" + "\tELSE:\n" + $7.traducao
				+ "\t" + cond +"\n" + $9.traducao ;
			}
			| TK_IF '(' E ')' BLOCO TK_ELSE BLOCO COMANDOS
			{
				verificarAtributoRelacional($3);
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				string cond = genCondcode();

				$$.traducao = $3.traducao + "\t" 
				+ $$.label + " = !" + $3.label + ";\n" + "\t"
				"if(" + $$.label + ") goto ELSE;\n" + $5.traducao +
				"\tgoto " + cond + "\n" + "\tELSE:\n" + $7.traducao + "\t"+cond+"\n" + $8.traducao;
			}
			| TK_WHILE '(' E ')' BLOCO COMANDOS
			{
				verificarAtributoRelacional($3);
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				TIPO_LOOP loop = getLace($1.label);

				$$.traducao = loop.inicioLaco + $3.traducao + "\t" + $$.label + " = !" +
				$3.label + ";\n" + "\tIF(" + $$.label + ") goto " + loop.fimLaco + "\n" +
				$5.traducao + "\tgoto " + loop.inicioLaco + "\n\t" + loop.fimLaco + "\n" + $6.traducao;
			}
			| TK_DO BLOCO TK_WHILE '(' E ')' ';' COMANDOS
			{
				verificarAtributoRelacional($5);
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				TIPO_LOOP loop = getLace($1.label);

				$$.traducao = loop.inicioLaco + $2.traducao + $5.traducao + "\t" 
				+ $$.label + " = !" + $5.label + ";\n" + "\tIF(" + $$.label +") goto " 
				+ loop.fimLaco  + "\n" + "\tgoto " + loop.inicioLaco + "\n\t" + loop.fimLaco +" \n"+ $8.traducao;
			}
			| TK_FOR '(' ';' ';' ')' BLOCO COMANDOS
			{
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				TIPO_LOOP loop = getLace($1.label); 

				$$.traducao = loop.inicioLaco + $6.traducao + "\t" + "goto " + loop.inicioLaco + "\n\t" + loop.fimLaco +"\n" + $7.traducao;
			}
			| TK_FOR '(' ATRIBUICAO ';' RELACIONAL ';' E ')' BLOCO COMANDOS
			{
				$$.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + $$.label +";\n";
				string lace = genLacecode();
				string cond = genCondcode();

				$$.traducao = $3.traducao + lace + $5.traducao + "\t" + $$.label + 
				" = !" + $5.label + ";\n\t" + "if(" + $$.label + ") goto "+ cond + "\n" + 
				$9.traducao + $7.traducao + "\tgoto " + lace + "\n\t"+ cond +"\n" + $10.traducao;
			}
			| TK_SWITCH '(' P ')' '{' CASES '}' COMANDOS
			{
				$$.traducao = $3.traducao + $6.traducao + $8.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

CASES       : CASE CASES
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

CASE        : TK_CASE TK_NUM ':' COMANDOS
			{
			}
			;

COMANDO 	: E ';'
			{
			}
			| DECLARACAO ';'
			{
			}
			| TK_BREAK ';'
			{
				if(controleLoop == 0)
				{
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Break não existente em um loop.\n";
				} else {
					TIPO_LOOP loop = getLaceBreak();
					$$.traducao = "\tgoto " + loop.fimLaco + "\n";
				}
			}
			| TK_CONTINUE ';'
			{
				if(controleLoop == 0){
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Continue não existente em um loop.\n";
				} else {
					TIPO_LOOP loop = getLaceBreak();
					$$.traducao = "\tgoto " + loop.inicioLaco + "\n";
				}
			}
			| TK_RETURN E ';'
			{
				if(controleFunction == 0){
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Return não está dentro de uma função.\n";
				}
				
				int size = tabelaFunction.size() - 1;
				tabelaFunction[size].retornoLabel = $2.label;
				tabelaFunction[size].retornoTipo = $2.tipo;
				$$.traducao += $2.traducao + "\tReturn " + $2.label + ";\n";
			}
			;

DECLARACAO  : TIPOS TK_ID
			{
				if($1.tipo == "void")
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Void não é um tipo declarável.\n";

				if($1.tipo != "string"){
					int indiceTopo = tabelaFunction.size() - 1;
					if(controleFunction > 0 && getContexto() == 0){

						TIPO_SIMBOLO simb;
						simb.nomeVariavel = $2.label;
						simb.tipoVariavel = $1.tipo;
						simb.labelVariavel = gentempcode();

						if(tabelaFunction[indiceTopo].parameters.size() == 0)
						{
							tabelaFunction[indiceTopo].parameters.push_back(simb);

						} else {
							for (int i = tabelaFunction[indiceTopo].parameters.size(); i >= 0; i--)
							{
								if(tabelaFunction[indiceTopo].parameters[i].nomeVariavel == $2.label)
								{
									error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Nome do parâmetro '" + $2.label + "' ja utilizado na função.\n";
								}	
							}
							tabelaFunction[indiceTopo].parameters.push_back(simb);
						}
						traducaoFunction = traducaoFunction + "\t" + simb.tipoVariavel + " " + simb.labelVariavel +";\n";
						
					} else {

						if(controleFunction > 0 && getContexto() > 0){
							int indiceTopoParameters = tabelaFunction[indiceTopo].parameters.size();
							for (int i = indiceTopoParameters; i >= 0; i--)
							{ 
								if(tabelaFunction[indiceTopo].parameters[i].nomeVariavel == $2.label)
								{
									error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Váriavel '" + $2.label + "' não poderá ser de declarada nesta função.\n";
								}	
							}
						}

						verificarVariavelRepetida($2.label);
						addSimbolo($2.label, $1.tipo, gentempcode());
						$$.traducao = "";
						$$.label = "";
					}
				} else {
					int indiceTopo = tabelaFunction.size() - 1;
					if(controleFunction > 0 && getContexto() == 0){
						TIPO_SIMBOLO simb;
						simb.nomeVariavel = $2.label;
						simb.tipoVariavel = $1.tipo;
						simb.labelVariavel = gentempcode();

						if(tabelaFunction[indiceTopo].parameters.size() == 0)
						{
							tabelaFunction[indiceTopo].parameters.push_back(simb);
						} else {
							for (int i = tabelaFunction[indiceTopo].parameters.size(); i >= 0; i--)
							{ 
								if(tabelaFunction[indiceTopo].parameters[i].nomeVariavel == $2.label)
								{
									error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Nome do parâmetro '" + $2.label + "' ja utilizado na função.\n";
								}	
							}
							tabelaFunction[indiceTopo].parameters.push_back(simb);
						}
						traducaoFunction = traducaoFunction + "\t" + "char" + " *" + simb.labelVariavel + ";\n";
					} else {
						if(controleFunction > 0 && getContexto() > 0){
							int indiceTopoParameters = tabelaFunction[indiceTopo].parameters.size();
							for (int i = indiceTopoParameters; i >= 0; i--)
							{ 
								if(tabelaFunction[indiceTopo].parameters[i].nomeVariavel == $2.label)
								{
									error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Váriavel '" + $2.label + "' não poderá ser de declarada nesta função.\n";
								}	
							}
						}

						string label = gentempcode();
						verificarVariavelRepetida($2.label);
						addString($2.label, "string", label);
						$$.traducao = "";
						$$.tipo = "string";
						$$.label = "\tstrcpy(" + label + ", " + "\0" + ");\n";
					}
				}
			}
			| TIPOS TK_ID '=' E
			{
				verificarVariavelRepetida($2.label);

				string nome = $2.label;
				string tipo = $1.tipo;
				string label = gentempcode();

				addSimbolo(nome, tipo, label);

				string traducao = $4.traducao;

				if (tipo == $4.tipo) {
					traducao += "\t" + label + " = " + $4.label + ";\n";
				} 
				else if (tipo == "int" && $4.tipo == "float") {
					string castTemp = gentempcode();
					addTemp(castTemp, "int");
					traducao += "\t" + castTemp + " = (int) " + $4.label + ";\n";
					traducao += "\t" + label + " = " + castTemp + ";\n";
				} 
				else if (tipo == "float" && $4.tipo == "int") {
					string castTemp = gentempcode();
					addTemp(castTemp, "float");
					traducao += "\t" + castTemp + " = (float) " + $4.label + ";\n";
					traducao += "\t" + label + " = " + castTemp + ";\n";
				} 
				else {
					error += "\033[1;31mError\033[0m - Linha " + contLinha + ": Tipos incompatíveis em inicialização.\n";
				}

				$$.traducao = traducao;
			}
			| TIPOS TK_ID INDICES
			{
				string nome = $2.label;
				string tipo = $1.tipo;
				string declaracao = tipo + " " + nome;

				if ($3.label != "") {
					declaracao += $3.label; // ex: [10][20]
        			declaracao += ";";
					if (controleFunction > 0)
            			traducaoFunction += "\t" + declaracao + "\n";
        			else if (getContexto() == 0)
            			atribuicaoVariavelGlobais += "\t" + declaracao + "\n";
        			else
            			atribuicaoVariavel += "\t" + declaracao + "\n";

					TIPO_SIMBOLO simb;
					simb.nomeVariavel = nome;
					simb.tipoVariavel = tipo;
					simb.labelVariavel = nome; // para simplificar
					addSimbolo(nome, tipo, nome);
				}
			}
			| TIPOS TK_ID INDICES '=' INIT_MATRIZ
			{
				addSimbolo($2.label, $1.tipo, $2.label);

				string tipo = $1.tipo;
				string nome = $2.label;
				string indices = $3.label;

				string declaracao = tipo + " " + nome + indices + ";\n";
    			string atribuicoes = $5.traducao;

				if (controleFunction > 0)
					traducaoFunction += "\t" + declaracao + atribuicoes;
				else if (getContexto() == 0)
					atribuicaoVariavelGlobais += "\t" + declaracao + atribuicoes;
				else
					atribuicaoVariavel += "\t" + declaracao + atribuicoes;
			}
			;

TIPOS       : TK_TIPO_INT
			{
				$$.tipo = "int";
			}			
			| TK_TIPO_FLOAT
			{
				$$.tipo = "float";
			}
			| TK_TIPO_CHAR
			{
				$$.tipo = "char";
			}
			| TK_TIPO_STRING
			{
				$$.tipo = "string";
			}
			| TK_TIPO_BOOL
			{
				$$.tipo = "bool";
			}
			| TK_VOID
			{
				$$.tipo = "void";
			}
			;

INDICES : '[' TK_NUM ']' INDICES
        {
            $$.label = "[" + $2.label + "]" + $4.label;
        }
        | '[' TK_NUM ']'
        {
            $$.label = "[" + $2.label + "]";
        }
		;

INIT_MATRIZ : '{' LINHAS_MATRIZ '}'
			{
				$$.traducao = $2.traducao;
			}
			;

LINHAS_MATRIZ : '{' LISTA_VALORES '}'
			{
				$$.linha = 0;
				$$.traducao = "";

				for (int i = 0; i < $2.valores.size(); i++) {
					$$.traducao += "\tm[0][" + std::to_string(i) + "] = " + $2.valores[i] + ";\n";
				}

				$$.valores = $2.valores;
			}
			| LINHAS_MATRIZ ',' '{' LISTA_VALORES '}'
			{
				$$.linha = $1.linha + 1;
				$$.traducao = $1.traducao;

				for (int i = 0; i < $4.valores.size(); i++) {
					$$.traducao += "\tm[" + std::to_string($$.linha) + "][" + std::to_string(i) + "] = " + $4.valores[i] + ";\n";
				}
			}
			;

LISTA_VALORES : TK_NUM
			{
				$$.valores.push_back($1.label);
			}
			| LISTA_VALORES ',' TK_NUM
			{
				$$.valores = $1.valores;
				$$.valores.push_back($3.label);
			}
			;

E 			: M '+' E
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;
				
				//cout << $1.tipo;

				if($1.tipo == "string" && $3.tipo == "string"){
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Concatenação de string em breve.\n";
				}

				if($1.tipo == $3.tipo){
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " + " + $3.label + ";\n";
					addTemp($$.label, $$.tipo);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					$$.tipo = $3.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " + " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					$$.tipo = $1.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " + " + labelAux + ";\n";
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}
			}
			| M '-' E
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " - " + $3.label + ";\n";
					addTemp($$.label, $$.tipo);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					$$.tipo = $3.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " - " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					$$.tipo = $1.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " - " + labelAux + ";\n";
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}
			}
			| TK_ID TK_MAIS_MAIS
			{
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label);
				if(variavel_1.tipoVariavel == "char" || variavel_1.tipoVariavel == "string" || variavel_1.tipoVariavel == "bool" || variavel_1.tipoVariavel == "float"){
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Tipo inválido para operação unária.\n";
				}
				$$.traducao = $1.traducao + $2.traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " + 1" + ";\n";
			}
			| TK_ID TK_MENOS_MENOS
			{
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label);
				if(variavel_1.tipoVariavel == "char" || variavel_1.tipoVariavel == "string" || variavel_1.tipoVariavel == "bool" || variavel_1.tipoVariavel == "float"){
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Tipo inválido para operação unária.\n";
				}
				$$.traducao = $1.traducao + $2.traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " - 1" + ";\n";
			}
			| TK_TIPO_FLOAT '(' E ')'
			{		
				$$.label = gentempcode();
				$$.tipo  = "float";

				addTemp($$.label, $$.tipo);
				
				if($3.tipo == "int")
				{	
					$$.traducao = $3.traducao + "\t" + 
					$$.label + " = " + "(float) " + $3.label + ";\n";  
				} else if ($3.tipo == "float")
				{
					$$.traducao = $3.traducao + "\t" + 
					$$.label + " = " + "(float) " + $3.label + ";\n";
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha +  ": as variáveis já apresentam o mesmo tipo.\n";
				}
				else
				{
					error += "\n\033[1;31mError\033[0m - Linha " + contLinha +  ": Casting inválido";
				}
			}
			| TK_CAST_FLOAT E
			{
				$$.label = gentempcode();
				$$.tipo  = "float";
				addTemp($$.label, $$.tipo);

				if($2.tipo == "int")
				{
					$$.traducao = $2.traducao + "\t" + 
					$$.label + " = (float) " + $2.label + ";\n";
				}
				else if ($2.tipo == "float")
				{
					$$.traducao = $2.traducao + "\t" + 
					$$.label + " = (float) " + $2.label + ";\n";
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha + ": as variáveis já apresentam o mesmo tipo.\n";
				}
				else
				{
					error += "\033[1;31mError\033[0m - Linha " + contLinha + ": Casting inválido para float.\n";
				}
			}
            | TK_CAST_INT E
			{
				$$.label = gentempcode();
				$$.tipo  = "int";
				addTemp($$.label, $$.tipo);

				if($2.tipo == "float")
				{
					$$.traducao = $2.traducao + "\t" + 
					$$.label + " = (int) " + $2.label + ";\n";
				}
				else if ($2.tipo == "int")
				{
					$$.traducao = $2.traducao + "\t" + 
					$$.label + " = (int) " + $2.label + ";\n";
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha + ": as variáveis já apresentam o mesmo tipo.\n";
				}
				else
				{
					error += "\033[1;31mError\033[0m - Linha " + contLinha + ": Casting inválido para int.\n";
				}
			}
            | TK_CAST_CHAR E
			{
				$$.label = gentempcode();
				$$.tipo  = "char";
				addTemp($$.label, $$.tipo);

				if($2.tipo == "int")
				{
					$$.traducao = $2.traducao + "\t" + 
					$$.label + " = (char) " + $2.label + ";\n";
				}
				else if($2.tipo == "char")
				{
					$$.traducao = $2.traducao + "\t" + 
					$$.label + " = (char) " + $2.label + ";\n";
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha + ": as variáveis já apresentam o mesmo tipo.\n";
				}
				else
				{
					error += "\033[1;31mError\033[0m - Linha " + contLinha + ": Casting inválido para char.\n";
				}
			}
			| TK_TIPO_INT '(' E ')'
			{	
				$$.label = gentempcode();
				$$.tipo  = "int";
				addTemp($$.label, $$.tipo);

				if($3.tipo == "float")
				{
					$$.traducao = $3.traducao + "\t" + 
					$$.label + " = " + "(int) " + $3.label + ";\n";
				} else if ($3.tipo == "int"){
					$$.traducao = $3.traducao + "\t" + 
					$$.label + " = " + "(int) " + $3.label + ";\n";
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha +  ": as variáveis já apresentam o mesmo tipo.\n";
				}else{
					error += "\033[1;31mError\033[0m - Linha " + contLinha +  ": Casting inválido\n";
				}
			}
			| RELACIONAL
			{
			}
			| ATRIBUICAO
			{
			}
			| TK_ID '(' CHAMADAS ')'
			{
				TIPO_FUNCTION aux = getFunctionChamada($1.label);
				int index;
				int j = parametersChamada.size() - 1;
				string params;

				for(int k = tabelaFunction.size() - 1; k >= 0; k--)
				{
					if(tabelaFunction[k].nomeFunction == $1.label){
						index = k;
						break;
					}
				}

				if(aux.parameters.size() != parametersChamada.size())
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Quantidade de parâmetros inválida.\n";
				else{
					for(int i = 0; i < aux.parameters.size(); i++)
					{
						if(aux.parameters[i].tipoVariavel != parametersChamada[j].tipoVariavel)
						{
							error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m O parâmetro da função '" + aux.parameters[i].nomeVariavel + "' recebe tipo diferente.\n";
						} else {
							tabelaFunction[index].parameters[i].valorVariavel = parametersChamada[j].labelVariavel;
							params += "\tparam " + parametersChamada[j].labelVariavel + ";\n";
						}
						j--;
					}
				}
				
				$$.traducao += $3.traducao + params;
				$$.tipo = aux.retornoTipo; 
			    $$.label = "call " + aux.nomeFunction + ", " + std::to_string(parametersChamada.size());

				while( parametersChamada.size() != 0){
					parametersChamada.pop_back();
				}
			}
			| M
			{
				$$.traducao = $1.traducao;
			}
			;

CHAMADAS   : CHAMADA
		   {
			   $$.traducao = $1.traducao;
		   }
		   |
		   {
		   }
		   ;

CHAMADA    : E
		   {
			   TIPO_SIMBOLO aux;
			   aux.tipoVariavel = $1.tipo;
			   aux.labelVariavel = $1.label;
			   parametersChamada.push_back(aux);

			   $$.traducao = $1.traducao;
		   }
		   | E ',' CHAMADA
		   {
			   TIPO_SIMBOLO aux;
			   aux.tipoVariavel = $1.tipo;
			   aux.labelVariavel = $1.label;
			   parametersChamada.push_back(aux);

			   $$.traducao = $1.traducao + $3.traducao; 
		   }
		   ;

RELACIONAL  : E '>' E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " > " + $3.label + ";\n";
			}
			| E '<' E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " < " + $3.label + ";\n";
			}
			| E TK_MAIOR_IGUAL E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " >= " + $3.label + ";\n";
			}
			| E TK_MENOR_IGUAL E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " <= " + $3.label + ";\n";
			}
			| E TK_IGUAL_IGUAL E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " == " + $3.label + ";\n";
			}
			| E TK_DIFERENTE E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " != " + $3.label + ";\n";
			}
			| E TK_OU E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " || " + $3.label + ";\n";
			}
			| E TK_E E
			{
				verificarOperacaoRelacional($1, $3);
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " && " + $3.label + ";\n";
			}
			| '!' E
			{
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = $2.traducao + "\t" + 
				$$.label + " = " + "!" + $2.label + ";\n";
			}
			;

ATRIBUICAO  : TK_ID '=' E
			{
				TIPO_SIMBOLO variavel = getSimbolo($1.label);

				string traduzir;
				if(variavel.tipoVariavel == $3.tipo){
					if($3.tipo == "string"){

						traduzir = $1.traducao
						+ "\tstrcpy(" + $3.label +", " + $3.valor +");\n\t" + 
						variavel.labelVariavel + " = " + "(char*) malloc(" + $3.index +");" +
						"\n\tstrcpy(" + variavel.labelVariavel +", " + $3.label +");\n";

						if(getContexto() != 0)
							$$.traducao = traduzir;
						else
							traducaoFunction += traduzir + '\n';
							
					} else {
						traduzir = $1.traducao + $3.traducao + "\t" + 
				    	variavel.labelVariavel + " = " + $3.label + ";\n";
						if(getContexto() != 0)
							$$.traducao = traduzir;
						else
							traducaoFunction += traduzir + '\n';
					}
				}
				else if (variavel.tipoVariavel == "int" & $3.tipo == "float")
				{
					$$.label = gentempcode();
					addTemp($$.label, "int");
					traduzir = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (int) " + $3.label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + $$.label + ";\n";

					if(getContexto() != 0)
							$$.traducao = traduzir;
						else
							traducaoFunction += traduzir + '\n';
				}
				else if (variavel.tipoVariavel == "float" & $3.tipo == "int")
				{
					$$.label = gentempcode();
					addTemp($$.label, "float");
					traduzir = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + $$.label + ";\n";

					if(getContexto() != 0)
							$$.traducao = traduzir;
						else
							traducaoFunction += traduzir + '\n';
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Atribuição inválida, tipos diferentes.\n";
				}
			}
			| TK_ID '[' E ']' '[' E ']' '=' E
			{
				TIPO_SIMBOLO var = getSimbolo($1.label);
    			string traducao = $3.traducao + $6.traducao + $9.traducao;

				if (var.tipoVariavel != $9.tipo) {
					error += "\033[1;31mError\033[0m - Linha " + contLinha + ": Tipos incompatíveis na atribuição de matriz.\n";
				}

				traducao += "\t" + var.labelVariavel + "[" + $3.label + "][" + $6.label + "] = " + $9.label + ";\n";

				if (getContexto() != 0)
					$$.traducao = traducao;
				else
					traducaoFunction += traducao;
			}
			| TK_ID TK_MAIS_IGUAL E
			{
				TIPO_SIMBOLO simbolo = getSimbolo($1.label);

				string tempSoma = gentempcode();
				addTemp(tempSoma, simbolo.tipoVariavel);

				string traducao = $3.traducao;
				traducao += "\t" + tempSoma + " = " + simbolo.labelVariavel + " + " + $3.label + ";\n";
				traducao += "\t" + simbolo.labelVariavel + " = " + tempSoma + ";\n";

				$$.traducao = traducao;
			}
			| TK_ID TK_MENOS_IGUAL E
			{
				TIPO_SIMBOLO simbolo = getSimbolo($1.label);

				string tempSub = gentempcode();
				addTemp(tempSub, simbolo.tipoVariavel);

				string traducao = $3.traducao;
				traducao += "\t" + tempSub + " = " + simbolo.labelVariavel + " - " + $3.label + ";\n";
				traducao += "\t" + simbolo.labelVariavel + " = " + tempSub + ";\n";

				$$.traducao = traducao;
			}
			| TK_ID TK_VEZES_IGUAL E
			{
				TIPO_SIMBOLO simbolo = getSimbolo($1.label);

				string tempSub = gentempcode();
				addTemp(tempSub, simbolo.tipoVariavel);

				string traducao = $3.traducao;
				traducao += "\t" + tempSub + " = " + simbolo.labelVariavel + " * " + $3.label + ";\n";
				traducao += "\t" + simbolo.labelVariavel + " = " + tempSub + ";\n";

				$$.traducao = traducao;
			}
			| TK_ID TK_DIVISAO_IGUAL E
			{
				TIPO_SIMBOLO simbolo = getSimbolo($1.label);

				string tempSub = gentempcode();
				addTemp(tempSub, simbolo.tipoVariavel);

				string traducao = $3.traducao;
				traducao += "\t" + tempSub + " = " + simbolo.labelVariavel + " / " + $3.label + ";\n";
				traducao += "\t" + simbolo.labelVariavel + " = " + tempSub + ";\n";

				$$.traducao = traducao;
			}
			;

M 			: M '*' P
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " * " + $3.label + ";\n";
					addTemp($$.label, $$.tipo);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					$$.tipo = $3.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " * " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					$$.tipo = $1.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " * " + labelAux + ";\n";
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}
			}
			| M '/' P
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " / " + $3.label + ";\n";
					addTemp($$.label, $$.tipo);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					$$.tipo = $3.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " / " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					$$.tipo = $1.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " / " + labelAux + ";\n";
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}

				string aux = $3.valor;
				int cont = 0;
				int ponto = 0;

				for(int i = 0; i < aux.size(); i++)
				{
					if(aux[i] == '.')
					{
						ponto = 1;
					}
					if(aux[i] == '0')
					{
						cont++;
					}
				}

				if(cont == aux.size() || (cont + ponto) == aux.size()){
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operação inválida, divisão por 0.\n";
				}
			}
			| M '%' P
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == "int" & $3.tipo == "int"){
					tipoAux = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " % " + $3.label + ";\n";
					addTemp($$.label, tipoAux);
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos inválidos para %, (ou presença de float).\n";
				}
			}
			| P
			{
				$$.traducao = $1.traducao;
			}
			;

P 			: '(' E ')'
			{
				$$.traducao = $2.traducao;
				$$.tipo = $2.tipo;
				$$.label = $2.label;
			}
			| TK_NUM
			{
				$$.tipo = "int";
				$$.label = gentempcode();
				addTemp($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
				$$.valor = $1.label;
			}
			| TK_REAL
			{
				$$.tipo = "float";
				$$.label = gentempcode();
				addTemp($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
				$$.valor = $1.label;
			}
			| TK_CHAR
			{
				$$.tipo = "char";
				$$.label = gentempcode();
				addTemp($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_STRING
			{
				$$.tipo = "string";
				$$.label = gentempcode();
				$$.traducao = "\tstrcpy(" + $$.label +", " + $1.valor + ");\n";
				$$.index = std::to_string(addTempString($$.label, $$.valor));
			}
			| TK_TRUE
			{
				$$.tipo = "bool";
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = "\t" + $$.label + " = " + "1" + ";\n";	
			}
			| TK_FALSE
			{
				$$.tipo = "bool";
				$$.label = gentempcode();
				addTemp($$.label, "int");
				$$.traducao = "\t" + $$.label + " = " + "0" + ";\n";		
			}
			| TK_ID
			{
				TIPO_SIMBOLO variavel = getSimbolo($1.label);
				$$.tipo = variavel.tipoVariavel;
				$$.label = variavel.labelVariavel;
				$$.traducao = "";
			}
			| TK_ID '[' E ']' '[' E ']'
			{
				TIPO_SIMBOLO var = getSimbolo($1.label);
        		if (var.tipoVariavel != "int" && var.tipoVariavel != "float" && var.tipoVariavel != "char") {
            		error += "\033[1;31mError\033[0m - Linha " + contLinha + ": Apenas tipos primitivos podem ser usados como matrizes.\n";
        		}

        		$$.label = gentempcode();
				$$.tipo = var.tipoVariavel;
				$$.traducao = $3.traducao + $6.traducao + "\t" + $$.label + " = " + var.labelVariavel + "[" + $3.label + "][" + $6.label + "];\n";
				addTemp($$.label, $$.tipo);
			}
			| TK_PRINT '(' E ')'
			{
				$$.traducao = $3.traducao + "\t" + "cout << " + $3.label + ";\n";
			}
			| TK_SCAN '(' TK_ID ')'
			{
				TIPO_SIMBOLO variavel = getSimbolo($3.label);
				$$.traducao = $3.traducao + "\t" "STD::CIN >> " + variavel.labelVariavel + ";\n";
			}
			;
%%

#include "lex.yy.c"

int yyparse();
int getContexto(){
	return mapa.size() - 1;
}

string gentempcode(){
	var_temp_qnt++;
	return "t" + std::to_string(var_temp_qnt);	
}

string genLacecode(){
	var_lace_qnt++;
	return "_L" + std::to_string(var_lace_qnt) + ":";	
}

string genCondcode(){
	var_cond_qnt++;
	return "FIM_IF_" + std::to_string(var_cond_qnt) + ":";
}

string genLaceNameCode(){
	var_lace_name_qnt++;
	return "loop_" + std::to_string(var_lace_name_qnt);
}

void verificarVariavelRepetida(string variavel){

	int contexto = mapa.size() - 1;
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	tabelaSimbolos = mapa[contexto];

	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel)
		{
			error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m A variável '" + variavel + "' já existe.\n";
		}
	}
}

TIPO_SIMBOLO getSimbolo(string variavel){

	int contexto = mapa.size() - 1;
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	tabelaSimbolos = mapa[contexto];

	while(contexto >= 0)
	{
		for (int i = tabelaSimbolos.size() - 1; i >= 0; i--)
		{
			if(tabelaSimbolos[i].nomeVariavel == variavel)
			{
				return tabelaSimbolos[i];
			}				
		}
		
		contexto -= 1;
		if(contexto >= 0){
			tabelaSimbolos = mapa[contexto];
		}
	}

	if(controleFunction > 0){

		int sizeFunctions = tabelaFunction.size() - 1;
		int sizeFunctionsParameters = tabelaFunction[sizeFunctions].parameters.size();

		for (int i = sizeFunctionsParameters; i >= 0; i--)
		{
			if(tabelaFunction[sizeFunctions].parameters[i].nomeVariavel == variavel)
			{
				return tabelaFunction[sizeFunctions].parameters[i];
			}				
		}
		
	}

	error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m A variável '" + variavel + "' não foi instanciada.\n";
}

void addSimbolo(string variavel, string tipo, string label){
	
	TIPO_SIMBOLO valor;

	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;

	int contexto = mapa.size() - 1;
	mapa[contexto].push_back(valor);

	if(valor.tipoVariavel == "bool"){
		valor.tipoVariavel = "int";
	}


	if(controleFunction > 0)
	{
		traducaoFunction = traducaoFunction + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";

	}else if(contexto == 0 && controleFunction == 0)
	{
		atribuicaoVariavelGlobais = atribuicaoVariavelGlobais  + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";

	} else 
	{
		atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
	}
}

void addString(string variavel, string tipo, string label){
	TIPO_SIMBOLO valor;
	
	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;

	int contexto = mapa.size() - 1;
	mapa[contexto].push_back(valor);

	valor.tipoVariavel = "char";
	if(controleFunction > 0){
		traducaoFunction = traducaoFunction + "\t" + valor.tipoVariavel + " *" 
		+ valor.labelVariavel + ";\n";
	} else if(contexto == 0 && controleFunction == 0){
		atribuicaoVariavelGlobais = atribuicaoVariavelGlobais + "\t" + valor.tipoVariavel + " *" 
		+ valor.labelVariavel + ";\n";
	} else {
		atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " *" 
		+ valor.labelVariavel + ";\n";
	}
}

void addTemp(string label, string tipo){
	TIPO_TEMP valor;
	valor.labelVariavel = label;
	valor.tipoVariavel = tipo;
	tabelaTemp.push_back(valor);

	if(valor.tipoVariavel == "bool"){
		valor.tipoVariavel = "int";
	}

	int contexto = getContexto();

	if(controleFunction > 0)
		traducaoFunction = traducaoFunction + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
	else if(contexto == 0 && controleFunction == 0)
		atribuicaoVariavelGlobais = atribuicaoVariavelGlobais + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
	else
		atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

int addTempString(string label, string conteudo){
	TIPO_TEMP valor;
	valor.labelVariavel = label;
	valor.tipoVariavel = "string";
	valor.valor = conteudo;
	tabelaTemp.push_back(valor);
	valor.tipoVariavel = "char";

	int size = getSize(conteudo) - 1;
	int contexto = mapa.size() - 1;

	if(controleFunction > 0){
		traducaoFunction = traducaoFunction + "\t" + valor.tipoVariavel + " " + 
		valor.labelVariavel + "[" + std::to_string(size) + "]" + ";\n";
	} else if(contexto == 0 && controleFunction == 0){
		atribuicaoVariavelGlobais = atribuicaoVariavelGlobais + "\t" + valor.tipoVariavel + " " + 
		valor.labelVariavel + "[" + std::to_string(size) + "]" + ";\n";
	} else {
		atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + 
		valor.labelVariavel + "[" + std::to_string(size) + "]" + ";\n";
	}
	return size;
}

int getSize(string str){
	int i = 0;
	while (str[i] != '\0')
		i++;

	return i;
}

void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2){
	if((tipo_1.tipo == "char" || tipo_2.tipo == "char") || (tipo_1.tipo == "string" || tipo_2.tipo == "string"))
	{
		error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operação relacional inválida.\n";
	}
}

void verificarAtributoRelacional(atributos tipo_1){
	if(tipo_1.tipo == "char" || tipo_1.tipo == "string" || tipo_1.tipo == "void")
	{
		error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operação relacional inválida.\n";
	}
}

int main(int argc, char* argv[]){
	var_temp_qnt = 0;
	contextoGlobal = 0;
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	mapa.push_back(tabelaSimbolos);
	yyparse();
	return 0;
}

void pushContexto(){
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	mapa.push_back(tabelaSimbolos);
}

void popContexto(){
	mapa.pop_back();

	if(controleLoop != 0)
		controleLoop--;

	if(controleFunction != 0)
		controleFunction--;
}

void pushLoop(string tipo){

	controleLoop++;
	int size = tabelaLoop.size();
	TIPO_LOOP aux;
	aux.nomeLaco = "loop_" + std::to_string(var_lace_name_qnt);
	aux.tipoLaco = tipo;

	if(tipo == "while" && size != 0)
	{
		if(!(tabelaLoop[size - 1].tipoLaco == "do"))
		{
			aux.fimLaco = genCondcode();
			aux.inicioLaco = genLacecode();
			aux.contexto = getContexto();
			tabelaLoop.push_back(aux);
		}

	} else {
		aux.fimLaco = genCondcode();
		aux.inicioLaco = genLacecode();
		aux.contexto = mapa.size();
		tabelaLoop.push_back(aux);
	}
}

TIPO_LOOP getLace(string nome){

	for (int i = tabelaLoop.size() - 1; i >= 0; i--)
	{ 
		if(tabelaLoop[i].nomeLaco == nome)
		{
			return tabelaLoop[i];
		}
	}
}

TIPO_LOOP getLaceBreak(){
	int size = tabelaLoop.size();
	return tabelaLoop[size - 1];
}

void pushFunction(){
	TIPO_FUNCTION aux;
	aux.inicioFunction = genLacecode();
	aux.fimFunction = genLacecode();
	tabelaFunction.push_back(aux);
	controleFunction++;
}

TIPO_FUNCTION getFunction(){
	int size = tabelaFunction.size() - 1;
	return tabelaFunction[size];
}

TIPO_FUNCTION getFunctionChamada(string nome){

	TIPO_FUNCTION aux;
	int achou = 0;

	for(int i = 0; i < tabelaFunction.size(); i++){
		if(tabelaFunction[i].nomeFunction == nome){
			aux = tabelaFunction[i];
			achou = 1;
		}
	}

	if(achou == 0)
		error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Nome da função não existe.\n";
	return aux;
}

void contadorDeLinha(){
	var_linha_qnt++;
	contLinha = std::to_string(var_linha_qnt);
}

void yyerror(string MSG){
	cout << MSG << endl;
	exit (0);
}