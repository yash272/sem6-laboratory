%{
    int count=0;
%}

%%
[/][/].* {count++;printf("single line comment, comment no : %d %s",count,yytext);}
[/][*][a-z0-9A-Z"\n"]*[*][/] {count++;printf("multiline comment, comment no : %d",count);}
.* {;}

%%

	int yywrap(void){}
	int main(){ yylex();
	
	return 0;}
