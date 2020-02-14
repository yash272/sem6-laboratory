%{
    int identifier=0;
%}

%%
void|if|main|for|while|int|float|double|else|case|break|return  {printf("keywords : %s\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("identifier : %s\n",yytext);}
[0-9]+[.]?[0-9]* {printf("constant : %s\n",yytext);}
. {printf("lex breaker\n");}
%%

	int yywrap(void){}
	int main(){ yylex();
	
	return 0;}

