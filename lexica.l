%{
#include <string>
#include <vector>
%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
SINAL [-]
SIMBOLO [-+*/=.":;<=>!#$£%¢&?@[\]^`{|}¹²³ 0x0020]

DELIM {ESPACO}+
NUM ({SINAL}({DIGITO}+)|{DIGITO}+)
REAL {NUM}+("."{DIGITO}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*
STRING \"({LETRA}|{NUM}|{SIMBOLO})*\"

%%

"\n"		        {contadorDeLinha();}

{DELIM} 	        {}

"main"		        { mainStatus = 1; return TK_MAIN;}

"(float)"   {return TK_CAST_FLOAT;}

"(int)"     {return TK_CAST_INT;}

"(char)"    {return TK_CAST_CHAR;}

"void"		        { return TK_VOID;}

"int"		        { return TK_TIPO_INT;}

"float"		        { return TK_TIPO_FLOAT;}

"char"		        { return TK_TIPO_CHAR;}

"string"		    { return TK_TIPO_STRING;}

"bool"	        { return TK_TIPO_BOOL;}

"true"              { return TK_TRUE; }

"false"             { return TK_FALSE; }

"if"                { return TK_IF; }

"else"              { return TK_ELSE; }

"while"             { yylval.label = genLaceNameCode(); pushLoop("while"); return TK_WHILE; }

"for"               { yylval.label = genLaceNameCode(); pushLoop("for"); return TK_FOR; }

"do"                { yylval.label = genLaceNameCode(); pushLoop("do");  return TK_DO; }

"switch"            { yylval.label = genLaceNameCode(); pushLoop("switch"); return TK_SWITCH; }

"case"              { return TK_CASE; }

"break"             { return TK_BREAK; }

"continue"          { return TK_CONTINUE; }

"return"            { return TK_RETURN; }

"print"             { return TK_PRINT; }

"scan"              { return TK_SCAN; }

"function"          { pushFunction(); return TK_FUNCTION; }

"{"                 { pushContexto(); return *yytext;}

"}"                 { popContexto(); return *yytext;}

[()[\];,:]	        { return *yytext; }

[+\-*/%!&|<>""]		{ return *yytext; }

"="		            { return *yytext; }

">="		        { return TK_MAIOR_IGUAL; }

"<="		        { return TK_MENOR_IGUAL; }

"=="		        { return TK_IGUAL_IGUAL; }

"!="		        { return TK_DIFERENTE; }

"++"		        { return TK_MAIS_MAIS; }

"--"		        { return TK_MENOS_MENOS; }

"||"		        { return TK_OU; }

"&&"		        { return TK_E; }

"+="		        { return TK_MAIS_IGUAL; }

"-="		        { return TK_MENOS_IGUAL; }

"*="                { return TK_VEZES_IGUAL; }

"/="                { return TK_DIVISAO_IGUAL; }

{NUM}		{yylval.label = yytext; return TK_NUM;}
{REAL}		{yylval.label = yytext; return TK_REAL;}
{CHAR}		{yylval.label = yytext; return TK_CHAR;}
{STRING}	{yylval.valor = yytext; return TK_STRING;}
{ID}		{yylval.label = yytext; return TK_ID;}

.			{ *yytext; }
%%