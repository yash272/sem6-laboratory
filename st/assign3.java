import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        int n,m;
        double p;

        Scanner s=new Scanner(System.in);
        System.out.println("Enter n:");
        n=s.nextInt();
        
        System.out.println("Enter m:");
        m=s.nextInt();
        
        System.out.println("Enter p:");
        p=s.nextDouble();
        
        char arr[][]=new char[n+2][m+2];

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                double r = Math.random()*1;
                if(r>=p)
                   arr[i][j]='*';
                else
                   arr[i][j]='.';

                System.out.print(arr[i][j]+" ");      
            }
            System.out.println();
        }        
        System.out.println();
        

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(arr[i][j]=='.')
                {
                    int count=0;
                    if(arr[i-1][j-1]=='*' && i-1>=1 && i-1<=n && j-1>=1 && j-1<=m)
                     count++;
                    if(arr[i-1][j]=='*' && i-1>=1 && i-1<=n && j>=1 && j<=m)
                     count++;
                    if(arr[i-1][j+1]=='*' && i-1>=1 && i-1<=n && j+1>=1 && j+1<=m)
                     count++;
                    if(arr[i][j-1]=='*' && i>=1 && i<=n && j-1>=1 && j-1<=m)
                     count++;
                    if(arr[i][j+1]=='*' && i>=1 && i<=n && j+1>=1 && j+1<=m)
                     count++;
                    if(arr[i+1][j-1]=='*' && i+1>=1 && i+1<=n && j-1>=1 && j-1<=m)
                     count++;
                    if(arr[i+1][j]=='*' && i+1>=1 && i+1<=n && j>=1 && j<=m)
                     count++;
                    if(arr[i+1][j+1]=='*' && i+1>=1 && i+1<=n && j+1>=1 && j+1 <=m)
                     count++;       

                    arr[i][j]=Character.forDigit(count,10);  ; 
                }
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
}



