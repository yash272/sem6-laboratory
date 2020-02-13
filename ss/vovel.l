%{
	int vov=0;
	int cons=0;
%}

%% 
[aeiouAEIOU] {vov++;}
[a-zA-Z] {cons++;}
"\?" {printf("Enter the string of vovels and consonents : ");}  
"\n" {printf("\n%d vovles and %d consonents\n?",vov,cons);vov=0;cons=0;}
%%

	int yywrap(void){}
	int main(){ yylex();return 0;}

