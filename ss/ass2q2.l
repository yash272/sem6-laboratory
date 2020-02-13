%{
    int identifier=0;
%}

%%
[o][x|X][0-9A-Fa-f]+[.]?[0-9A-Fa-f]* {printf("hexadecimal : %s\n",yytext);}
[o][0-7]+[.]?[0-7]* {printf("octal : %s\n",yytext);}
[ |\t|\n] {;}
%%

	int yywrap(void){}
	int main(){ yylex();
	
	return 0;}

