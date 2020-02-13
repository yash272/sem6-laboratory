%{
	int chr=-1;
	int word=0;
	int space=0;
	int eol=0;
%}

%%
[ ] {space++;word++;}
[^\t\n\?] {chr++;}
[\t] {word++;space++;}
[\n] {word++;eol++;}
"\?" {chr++;printf("\n%d character \n%d word \n%d space \n%d eol",chr,word,space,eol);chr=-1;word=0;space=0;eol=0;}
%%

	int yywrap(void){}
	int main(){ yylex();
	
	return 0;}

