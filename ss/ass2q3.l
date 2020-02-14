%{
    int identifier=0;
%}

%%
[-]?[0]+[.]?[0]* {printf("zero : %s\n",yytext);}
[0-9]+[.]?[0-9]* {printf("positive : %s\n",yytext);}
[-][0-9]+[.]?[0-9]* {printf("negative : %s\n",yytext);}
[ |\t\n] {;}
%%

	int yywrap(void){}
	int main(){ yylex();
	
	return 0;}

