#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256];
    int i,n,pd,pi,ok,nr;
    i=0;
    pd=0;//paranteze deschise
    pi=0;
    ok=0;
    nr=0;
    cin.get(s,256);
    n=strlen(s)-1;
    ok=1;//presupunem ca formula data este o formula bine formata
    while(i<=n&&ok==1)
    {
        if(s[i]=='('&&ok==1)
        {
            cout<<i<<" : ( -urmeaza o formula compusa"<<endl;

            pd++;
            if(s[i+1]!='~'&&(s[i+1]<'A'||s[i+1]>'Z')&&(s[i+1]<'a'||s[i+1]>'z')&&s[i+1]!='(')
            {
                ok=0;
                cout<<i+1<<" : "<<s[i+1]<<" Contradictie"<<endl;

            }
            i++;

        }


        if(s[i]=='~'&&ok==1)
        {
            cout<<i<<" : ~ -conector logic unar de negatie, asteapta o propozitie atomica sau o formula compusa"<<endl;
            nr++;
            if(s[i-1]!='(')
            {
                ok=0;
                cout<<"Nu prezinta paranteze-Contradictie"<<endl;
            }

            if((s[i+1]<'A'||s[i+1]>'Z')&&(s[i+1]<'a'||s[i+1]>'z')&&(s[i+1]!='('))
            {
                ok=0;
                cout<<i+1<<" : "<<s[i+1]<<" Contradictie"<<endl;

            }
            if(s[i+2]!=')'&&s[i+2]!='~'&&(s[i+2]<'A'||s[i+2]>'Z')&&(s[i+2]<'a'||s[i+2]>'z'))
            {

                ok=0;
                cout<<i+2<<" : "<<s[i+2]<<" Contradictie"<<endl;

            }
            i++;
        }

        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')&&ok==1)
        {
            cout<<i<<" : "<<s[i]<<" - propozitie atomica, formula bine formata, asteapta un conector logic sau o paranteza"<<endl;
            if(s[i+1]!=')' && s[i+1]!='&'&&s[i+1]!='|'&&s[i+1]!='<'&&s[i+1]!='=')
            {
                ok=0;
                cout<<i+1<<" : "<<s[i+1]<<" Contradictie"<<endl;

            }
            if(s[i-1]=='&'||s[i-1]=='|'||s[i-1]=='>')
                if(s[i+1]!=')')
                {
                    ok=0;
                    cout<<i+1<<" : "<<s[i+1]<<" Contradictie. Lipsa paranteza"<<endl;
                }
            i++;
        }

        if(s[i]=='&'&&ok==1)
            if(s[i+1]!='&')
            {
                ok=0;
                cout<<"Nu respecta conventia";

            }
            else
            {
                cout<<i<<" : "<<s[i]<<s[i]<<" - conector logic binar, asteapta o propozitie atomica sau o formula compusa"<<endl;
                nr++;
                i=i+2;
                if((s[i]<'A'||s[i]>'Z')&&(s[i]<'a'||s[i]>'z'))
                    if(s[i]!='(')
                    {
                        ok=0;
                        cout<<i<<" : "<<s[i]<<" Contradictie"<<endl;
                        if(s[i]=='~')
                            cout<<"Lipsa paranteze-Contradictie"<<endl;

                    }
            }



        if(s[i]=='|'&&ok==1)
            if(s[i+1]!='|')
            {
                ok=0;
                cout<<"Nu respecta conventia";
            }
            else
            {
                cout<<i<<" : "<<s[i]<<s[i]<<" - conector logic binar, asteapta o propozitie atomica sau o formula compusa"<<endl;
                nr++;
                i=i+2;
                if((s[i]<'A'||s[i]>'Z')&&(s[i]<'a'||s[i]>'z'))
                    if(s[i]!='(')
                    {

                        ok=0;
                        cout<<i<<" : "<<s[i]<<" Contradictie"<<endl;
                        if(s[i]=='~')
                            cout<<"Lipsa paranteze-Contradictie"<<endl;


                    }
            }



        if(s[i]=='<'&&ok==1)
            if(s[i+1]!='=')
                ok=0;
            else if(s[i+2]!='>')
            {

                ok=0;
                cout<<i<<" Nu este conjunctie"<<endl;
            }
            else
            {
                cout<<i<<" : "<<s[i]<<s[i+1]<<s[i+2]<<" - conector logic binar, asteapta o propozitie atomica sau o formula compusa"<<endl;
                nr++;
                i+=3;
                if((s[i]<'A'||s[i]>'Z')&&(s[i]<'a'||s[i]>'z'))
                    if(s[i]!='(')
                    {
                        ok=0;
                        cout<<i<<" : "<<s[i]<<" Contradictie"<<endl;
                        if(s[i]=='~')
                            cout<<"Lipsa paranteze-Contradictie"<<endl;

                    }
            }


        if(s[i]=='='&&ok==1)
            if(s[i+1]!='>')
            {

                ok=0;
                cout<<i<<" Nu este conjunctie"<<endl;
            }
            else
            {
                cout<<i<<" : "<<s[i]<<s[i+1]<<" - conector logic binar, asteapta o propozitie atomica sau o formula compusa"<<endl;
                nr++;
                i=i+2;
                if((s[i]<'A'||s[i]>'Z')&&(s[i]<'a'||s[i]>'z'))
                    if(s[i]!='(')
                    {
                        ok=0;
                        cout<<i<<" : "<<s[i]<<" Contradictie"<<endl;
                        if(s[i]=='~')
                            cout<<"Lipsa paranteze-Contradictie"<<endl;

                    }

            }



        if(s[i]==')'&&ok==1)
        {
            cout<<i<<" : ) -rezolva paranteza deschisa"<<endl;
            pi++;
            if(i<n)
                if(s[i+1]!=')')
                    if(s[i+1]!='|'&&s[i+1]!='&'&&s[i+1]!='<'&&s[i+1]!='=')
                    {
                        ok=0;
                        cout<<i+1<<" : "<<s[i+1]<<" Contradictie"<<endl;

                    }



            i++;
        }


    }
    if(pi!=pd&&i==n+1)
    {
        ok=0;
        cout<<"Numarul de paranteze nu este corect"<<endl;
    }
    if(pi==pd&&pi!=nr&&i==n+1)
    {
        ok=0;
        cout<<"Numarul de paranteze nu este corect"<<endl;
    }
    if(ok==0)
        cout<<"nu este formula bine formata";
    else
        cout<<"este formula bine formata";
}

