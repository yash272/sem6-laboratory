%{

%}

%%
[a-z] {printf("%c",yytext[0]-32);}
[A-z] {printf("%c",yytext[0]+32);}

%%

	int yywrap(void){}
	int main(){ yylex();
	
	return 0;}

