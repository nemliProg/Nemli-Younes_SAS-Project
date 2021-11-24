#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

int ajoutCompte(int indx,char cn[500][10],char n[500][50],char p[500][50],double m[500]);
int recherchParCIN(char cinR[10],char tCin [500][10],int indx);
void strswitch(char string1[50],char string2[50]);
void aff(int indx,char cn[500][10],char n[500][50],char p[500][50],double m[500],int floor);
void triAs(int indx,char cn[500][10],char n[500][50],char p[500][50],double m[500]);
void trides(int indx,char cn[500][10],char n[500][50],char p[500][50],double m[500]);
void welcome();
void intro();
void animationMenu();

int main()
{
//    INTRO
    intro();

    char CINs[10][10] = {"AA12345","BB12345","CC12345","DD12345","EE12345","FF12345","GG12345","HH12345","II12345","JJ12345"};
    char noms[10][50] = {"Nemli","Harira","Monsif","Tazzi","Rachidi","Youssfi","EL-hamdouni","Hakimi","Jomari","Bcharri"};
    char prenoms[10][50] =  {"Younes","Kamal","Hassan","Badr","Karim","Hassna","Rania","Oumaima","Salma","Marwan"};
    double montans[10] = {100000,3000,2500,50000,3214,6785,5000,45000,2500,100};
    // variables auxiliaires
    int m,i,j,check,check2,c;
    char rech[10];
    double m1,m2,m3;
    // variables principaux
    char cin [500][10],nom [500][50],prenom [500][50];
    double montant[500];
    int index = 0,floor;



menu :
    system("cls");
//	ANIMATION de MENU
    animationMenu();

    int chois;

    do
    {
        printf("\t\tchoisis une operation :\t");
        scanf("%d",&chois);
    }
    while(chois<0 || chois >7);

    switch(chois)
    {
    case 0:

        printf("");
        j=0;
        int indexCpy=index;
        for(i = indexCpy;i< indexCpy+10 ;i++){
            strcpy(cin[i],CINs[j]);
            strcpy(nom[i],noms[j]);
            strcpy(prenom[i],prenoms[j]);
            montant[i] = montans[j];
            j++;
            index++;
        }

        printf("Bien Ajouté");


        printf("go back to the menu press 1 and enter\n");
        do
        {
            printf("\t\t\t\t");
            scanf("%d",&m);
        }
        while(m != 1);

        if(m == 1)
        {
            goto menu;
        }


        break;
    case 1:
ajout :
        system("cls");
        printf("\n\n");
        printf("\t\t\t\t\tGestion Bancaire\n\n\n");
        printf("\t\t\tL'ajout d'un compte bancaire\n\n\n");




        index = ajoutCompte(index,cin,nom,prenom,montant);


        printf("go back to the menu press 1 and enter\n");
        printf("go back to the L'Ajout press 2 and enter\n");
        do
        {
            printf("\t\t\t\t");
            scanf("%d",&m);
        }
        while(m != 1 && m != 2);

        if(m == 1)
        {
            goto menu;
        }
        else
        {
            goto ajout;
        }


        break;
    case 2:

ajoutp :
        system("cls");
        printf("\n\n");
        printf("\t\t\t\t\tGestion Bancaire\n\n\n");
        printf("\t\t\tL'ajout plusieurs comptes bancaires\n\n\n");
        int nc;

        printf("\t\t\t\tCombien des compte vous voulez ajouter\t");
        scanf("%d",&nc);

        for(i=0; i<nc; i++)
        {
            printf("Donnez les information du compte %d\n",i+1);
            index = ajoutCompte(index,cin,nom,prenom,montant);
        }



        printf("go back to the menu press 1 and enter\n");
        printf("go back to the L'Ajout press 2 and enter\n");
        do
        {
            printf("\t\t\t\t");
            scanf("%d",&m);
        }
        while(m != 1 && m != 2);

        if(m == 1)
        {
            goto menu;
        }
        else
        {
            goto ajout;
        }

        break;
    case 3:
operation:
        system("cls");
        printf("\n\n");
        printf("\t\t\t\t\tGestion Bancaire\n\n\n");
        printf("\t\t\t\t\tMENU Operatios\n\n");
        printf("\t\t 1- Retrait\n");
        printf("\t\t 2- Depot \n");
        printf("\t\t 3- Transfert \n");
        printf("\t\t 4- go to menu principale \n\n\n");

        do
        {
            printf("Choisissez l'option souhaitee dans cette liste\t");
            scanf("%d",&c);
        }
        while(c <= 0 || c>4);

        switch(c)
        {
        case 1:
retrait :
            system("cls");
            printf("\n\n");
            printf("\t\t\t\t\tGestion Bancaire\n\n\n");
            printf("\t\t\tRetrait\n\n\n");

            double ret;

            printf("\t\tDonnez le CIN :\t");
            scanf("%s",rech);

            check = recherchParCIN(rech,cin,index);

            if(check == -1)
            {
                printf("\n\t\t\t\tNOT FOUND\a\n\n\n");
            }
            else
            {
                printf("\t\t CIN:%s | NOM:%s | PRENOM:%s | MONTANT:%f \n\n\n\n",cin[check],nom[check],prenom[check],montant[check]);
                do
                {
                    printf("Tapez le montant de retrait \t");
                    scanf("%lf",&ret);
                }
                while(ret <=0 ||  ret > montant[check]);





                montant[check] -= ret;
                printf("\n\t\t\t\tL'operation a ete effectuee avec Succes\n\n\n");
            }

            printf("go back to the menu press 1 and enter\n");
            printf("go back to the Operation press 2 and enter\n");
            printf("go back to the retrait press 3 and enter\n");
            do
            {
                printf("\t\t\t\t");
                scanf("%d",&m);
            }
            while(m != 1 && m != 2 && m != 3);

            if(m == 1)
            {
                goto menu;
            }
            else if(m == 2)
            {
                goto operation;
            }
            else
            {
                goto retrait;
            }

            break;
        case 2:
depot :
            system("cls");
            printf("\n\n");
            printf("\t\t\t\t\tGestion Bancaire\n\n\n");
            printf("\t\t\tDepot\n\n\n");

            double dep;

            printf("\t\tDonnez le CIN :\t");
            scanf("%s",rech);

            check = recherchParCIN(rech,cin,index);

            if(check == -1)
            {
                printf("\n\t\t\t\tNOT FOUND\a\n\n\n");
            }
            else
            {
                printf("\t\t CIN:%s | NOM:%s | PRENOM:%s | MONTANT:%f \n\n\n\n",cin[check],nom[check],prenom[check],montant[check]);
                do
                {
                    printf("Tapez le montant de depot \t");
                    scanf("%lf",&dep);
                }
                while(dep <=0 );

                montant[check] += dep;
                printf("\n\t\t\t\tL'operation a ete effectuee avec Succes\n\n\n");
            }

            printf("go back to the menu press 1 and enter\n");
            printf("go back to the retrait press 2 and enter\n");
            do
            {
                printf("\t\t\t\t");
                scanf("%d",&m);
            }
            while(m != 1 && m != 2);

            if(m == 1)
            {
                goto menu;
            }
            else
            {
                goto depot;
            }

            break;

        case 3:
transfert :
            system("cls");
            printf("\n\n");
            printf("\t\t\t\t\tGestion Bancaire\n\n\n");
            printf("\t\t\tTransfert\n\n\n");

            double trans;

            printf("\t\tDonnez le CIN expediteur :\t");
            scanf("%s",rech);

            check = recherchParCIN(rech,cin,index);

            int invalid = 0;

            do
            {
                if(invalid != 0)
                {
                    printf("Ce numéro n'existe pas. Vérifiez les informations s'il vous plais.\n");
                }

                printf("\t\tDonnez le CIN destinataire :\t");
                scanf("%s",rech);
                check2 = recherchParCIN(rech,cin,index);

            }
            while(check2 == -1);



            if(check == -1 )
            {
                printf("\n\t\t\t\t Sender NOT FOUND\a\n\n\n");
            }
            else
            {
                printf("\n\t\tExpediteur : CIN:%s | NOM:%s | PRENOM:%s | MONTANT:%f \n",cin[check],nom[check],prenom[check],montant[check]);
                printf("\t\tDestinataire : CIN:%s | NOM:%s | PRENOM:%s | MONTANT:%f \n\n",cin[check2],nom[check2],prenom[check2],montant[check2]);


                do
                {
                    printf("Tapez le montant de Transfert \t");
                    scanf("%lf",&trans);
                }
                while(trans <=0 ||  trans > montant[check]);

                montant[check] -= trans;
                montant[check2] += trans;
                printf("\n\t\t\t\tL'operation a ete effectuee avec Succes\n\n\n");


                printf("\n\n\t\tExpediteur : CIN:%s | NOM:%s | PRENOM:%s | MONTANT:%f \n",cin[check],nom[check],prenom[check],montant[check]);
                printf("\t\tDestinataire : CIN:%s | NOM:%s | PRENOM:%s | MONTANT:%f \n\n\n\n",cin[check2],nom[check2],prenom[check2],montant[check2]);
            }

            printf("go back to the menu press 1 and enter\n");
            printf("go back to the transfert press 2 and enter\n");
            do
            {
                printf("\t\t\t\t");
                scanf("%d",&m);
            }
            while(m != 1 && m != 2);

            if(m == 1)
            {
                goto menu;
            }
            else
            {
                goto transfert;
            }


            break;

        case 4:

            goto menu;

            break;


        }
        printf("go back to the menu press 1 and enter\n");
        printf("go back to the Affichage menu press 2 and enter\n");
        printf("go back to the Retrait menu press 3 and enter\n");

        do
        {
            printf("\t\t\t\t");
            scanf("%d",&m);
        }
        while(m != 1 && m != 2);

        if(m == 1)
        {
            goto menu;
        }
        else
        {
            goto affichage;
        }
        break;
    case 4:

affichage :
        system("cls");
        printf("\n\n");
        printf("\t\t\t\t\tGestion Bancaire\n\n\n");
        printf("\t\t\t\t\tMENU Affichage\n\n");
        printf("\t\t 1- Affichage Par Ordre Ascendant\n");
        printf("\t\t 2- Affichage Par Ordre Descendant \n");
        printf("\t\t 3- Affichage Par Ordre Ascendant \n");
        printf("\t\t 4- Affichage Par Ordre Ascendant \n");
        printf("\t\t 5- Recherche Par CIN \n");
        printf("\t\t 6- go to menu principale \n\n\n");

        double bowl;


        do
        {
            printf("Choisissez l'option souhaitee dans cette liste\t");
            scanf("%d",&c);
        }
        while(c <= 0 || c>6);

        printf("\n\n\n\n");
        switch(c)
        {
        case 1:
            printf("\t\t\t Affichage Par Ordre Ascendant\n\n\n\n");

            triAs(index,cin,nom,prenom,montant);
            if(index == 0)
            {
                printf("\t\t\t\t\tIl n'y a pas de compte\a\n\n\n\n");
            }
            else
            {

                aff(index,cin,nom,prenom,montant,0);

            }
            break;
        case 2:

            printf("\t\t\t Affichage Par Ordre Descendant \n");

            triDes(index,cin,nom,prenom,montant);

            if(index == 0)
            {
                printf("\t\t\t\t\tIl n'y a pas de compte\a\n\n\n\n");
            }
            else
            {

                aff(index,cin,nom,prenom,montant,0);

            }
            break;
        case 3:

            printf("\t\t\t Affichage Par Ordre Ascendant\n");
            triAs(index,cin,nom,prenom,montant);


            do
            {
                printf("\t\t\tAfficher les comptes dont le montant est supérieur a : ");
                scanf("%d",&floor);
            }
            while(floor < 0);



            if(index == 0)
            {
                printf("\t\t\t\t\tIl n'y a pas de compte\a\n\n\n\n");
            }
            else
            {

                aff(index,cin,nom,prenom,montant,floor);

            }

            break;
        case 4:

            printf("\t\t\t Affichage Par Ordre Descendant \n");
            triDes(index,cin,nom,prenom,montant);

            do
            {
                printf("\t\t\tAfficher les comptes dont le montant est supérieur a : ");
                scanf("%d",&floor);
            }
            while(floor < 0);



            if(index == 0)
            {
                printf("\t\t\t\t\tIl n'y a pas de compte\a\n\n\n\n");
            }
            else
            {

                aff(index,cin,nom,prenom,montant,floor);

            }
            break;
        case 5:
recherch :
            system("cls");
            printf("\n\n");
            printf("\t\t\t\t\tGestion Bancaire\n\n\n");
            printf("\t\t\t\t\t\tRecherche\n\n\n");

            printf("\t\tDonnez le CIN :\t");
            scanf("%s",rech);

            check = recherchParCIN(rech,cin,index);


            if(check == -1)
            {
                printf("\n\t\t\t\tNOT FOUND\a\n\n\n");
            }
            else
            {
                printf("\t\t CIN : %s | NOM : %s | PRENOM : %s | MONTANT : %f \n\n\n",cin[check],nom[check],prenom[check],montant[check]);
            }



            printf("go back to the menu press 1 and enter\n");
            printf("go back to the recherche press 2 and enter\n");
            do
            {
                printf("\t\t\t\t");
                scanf("%d",&m);
            }
            while(m != 1 && m != 2);

            if(m == 1)
            {
                goto menu;
            }
            else
            {
                goto recherch;
            }

            break;
        case 6:
            goto menu;
            break;
        }

        printf("go back to the menu press 1 and enter\n");
        printf("go back to the Affichage menu press 2 and enter\n");
        do
        {
            printf("\t\t\t\t");
            scanf("%d",&m);
        }
        while(m != 1 && m != 2);

        if(m == 1)
        {
            goto menu;
        }
        else
        {
            goto affichage;
        }


        break;
    case 5:
fidelisation :
        system("cls");
        printf("\n\n");
        printf("\t\t\t\t\tGestion Bancaire\n\n\n");
        printf("\t\t\tFidelisation\n\n\n");
        if(index != 0)
        {
            m1 = -1;
            m2 = -1;
            m3 = -1;

            for(i=0; i<index; i++)
            {
                if(m1 < montant[i] )
                {
                    m3 = m2;
                    m2 = m1;
                    m1 = montant[i];
                }
                if(m2 < montant[i] && m1 > montant[i])
                {
                    m3 = m2;
                    m2 = montant[i];

                }
                if(m3 < montant[i] && m2 > montant[i])
                {
                    m3 = montant[i];
                }
            }

            char sure[10];
            do
            {
                printf("Are you sure ?\n");
                printf("write 'YES' if you are sure and 'NO' if you are not sure : \t");
                scanf("%s",sure);
                printf("\n\n\nmax1 : %f |max2 : %f |max2 : %f \n\n\n",m1,m2,m3);
                for(i=0; i<index; i++)
                {
                    if(montant[i] >= m3)
                    {
                        printf("\t\t CIN : %s | NOM : %s | PRENOM : %s | MONTANT : %f \n",cin[i],nom[i],prenom[i],montant[i]);
                    }
                }

            }
            while(strcmp(sure,"YES") != 0 && strcmp(sure,"NO") != 0 );

            if(strcmp(sure,"YES") == 0 )
            {

                for(i=0; i<index; i++)
                {
                    if(montant[i] >= m3)
                    {
                        montant[i] += (montant[i]*0.013);
                    }
                }

                printf("\n\t\t\t\tL'operation a ete effectuee avec Succes\n\n\n");
            }
            else
            {
                printf("\n\t\t\t\tL'operation a ete non effectuee\n\n\n");
            }
            for(i=0; i<index; i++)
            {
                if(montant[i] >= m3)
                {
                    printf("\t\t CIN : %s | NOM : %s | PRENOM : %s | MONTANT : %f \n",cin[i],nom[i],prenom[i],montant[i]);
                }
            }


        }
        else
        {
            printf("\t\t\t\t\tIl n'y a pas de compte\a\n\n\n\n");
        }


        printf("go back to the menu press 1 and enter\t");
        do
        {
            scanf("%d",&m);
        }
        while(m != 1 );

        if(m == 1)
        {
            goto menu;
        }

        break;
    case 6:
        exit( EXIT_SUCCESS );
        break;

    default:
        goto menu;
        break;

    }

    return 0;
}

int ajoutCompte(int indx,char cn[30][10],char n[30][50],char p[30][50],double m[30])
{

    printf("\t\tdonnez le CIN\t");
    scanf("%s",cn[indx]);
    printf("\t\tdonnez le NOM\t");
    scanf("%s",n[indx]);
    printf("\t\tdonnez le PRENOM\t");
    scanf("%s",p[indx]);
    printf("\t\tdonnez le montant\t");
    scanf("%lf",&m[indx]);
    indx++;
    printf("\t\t l'index : %d",indx);
    printf("\t\tLe compte bancaire est bien ajoute\n\n");


    return indx;
}

void triAs(int indx,char cn[500][10],char n[500][50],char p[500][50],double m[500])
{
    int i,j;
    double bowl;

    for(i = 0; i<indx-1; i++)
    {
        for(j=i+1; j<indx; j++)
        {
            if(m[i] > m[j])
            {
                bowl = m[i];
                m[i] = m[j];
                m[j] = bowl;
                strswitch(cn[i],cn[j]);
                strswitch(n[i],n[j]);
                strswitch(p[i],p[j]);
            }
        }
    }
}

void triDes(int indx,char cn[500][10],char n[500][50],char p[500][50],double m[500])
{
    int i,j;
    double bowl;

    for(i = 0; i<indx-1; i++)
    {
        for(j=i+1; j<indx; j++)
        {
            if(m[i] < m[j])
            {
                bowl = m[i];
                m[i] = m[j];
                m[j] = bowl;
                strswitch(cn[i],cn[j]);
                strswitch(n[i],n[j]);
                strswitch(p[i],p[j]);
            }
        }
    }
}


void aff(int indx,char cn[500][10],char n[500][50],char p[500][50],double m[500],int floor)
{
    int i;
    for(i=0; i<indx; i++)
    {
        if(m[i] >= floor)
        {
            printf("\t\t CIN : %s | NOM : %s | PRENOM : %s | MONTANT : %f \n",cn[i],n[i],p[i],m[i]);
        }

    }
}

void strswitch(char string1[50],char string2[50])
{
    char bowl[50];
    strcpy(bowl,string1);
    strcpy(string1,string2);
    strcpy(string2,bowl);
}

int recherchParCIN(char cinR[10],char tCin [500][10],int indx)
{
    int test = -1;
    int i;
    for(i=0; i<indx; i++)
    {
        if(strcmp(cinR,tCin[i]) == 0)
        {
            return i;
        }
    }

    return test;
}

void intro()
{
    system("COLOR a0");
    welcome();
    Sleep(1000);
    system("COLOR 59");
    Sleep(800);
    system("COLOR b8");
    Sleep(600);
    system("COLOR c7");
    Sleep(400);
    system("color d6");
    Sleep(200);
    system("COLOR e5");
    Sleep(100);
    system("COLOR f4");
    Sleep(100);
    system("COLOR 03");
    Sleep(100);
    system("COLOR 12");
    Sleep(100);
    system("COLOR 81");
    Sleep(100);
    system("COLOR 8f");
    Sleep(100);
    system("cls");
}

void welcome()
{
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t _       __          __                                \n");
    printf("\t\t\t\t| |     / /  ___    / /  _____  ____    ____ ___   ___ \n");
    printf("\t\t\t\t| | /| / /  / _ \\  / /  / ___/ / __ \\  / __ `__ \\ / _ \\\n");
    printf("\t\t\t\t| |/ |/ /  /  __/ / /  / /__  / /_/ / / / / / / //  __/\n");
    printf("\t\t\t\t|__/|__/   \\___/ /_/   \\___/  \\____/ /_/ /_/ /_/ \\___/ \n");

    printf("\n\n\n\n");

    printf("\t   ____                _     _                     ____                                   _               \n");
    printf("\t  / ___|   ___   ___  | |_  (_)   ___    _ __     | __ )    __ _   _ __     ___    __ _  (_)  _ __    ___ \n");
    printf("\t | |  _   / _ \\ / __| | __| | |  / _ \\  | '_ \\    |  _ \\   / _` | | '_ \\   / __|  / _` | | | | '__|  / _ \\\n");
    printf("\t | |_| | |  __/ \\__ \\ | |_  | | | (_) | | | | |   | |_) | | (_| | | | | | | (__  | (_| | | | | |    |  __/\n");
    printf("\t  \\____|  \\___| |___/  \\__| |_|  \\___/  |_| |_|   |____/   \\__,_| |_| |_|  \\___|  \\__,_| |_| |_|     \\___|\n");
}


void animationMenu()
{
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t***************************************************\n");
    printf("\t\t\t\t\t\t\t\t*                                                 *\n");
    printf("\t\t\t\t\t\t\t\t* 0- remplissage du tableau automatiquemant(test) *\n");
    printf("\t\t\t\t\t\t\t\t* 1- Ajouter un compte bancaire                   *\n");
    printf("\t\t\t\t\t\t\t\t* 2- Ajouter plusieurs comptes bancaires          *\n");
    printf("\t\t\t\t\t\t\t\t* 3- Operations                                   *\n");
    printf("\t\t\t\t\t\t\t\t* 4- Affichage                                    *\n");
    printf("\t\t\t\t\t\t\t\t* 5- Fidelisation                                 *\n");
    printf("\t\t\t\t\t\t\t\t* 6- Quitter l'application                        *\n");
    printf("\t\t\t\t\t\t\t\t*                                                 *\n");
    printf("\t\t\t\t\t\t\t\t***************************************************\n\n");
    Sleep(50);
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t***************************************************\n");
    printf("\t\t\t\t\t\t\t*                                                 *\n");
    printf("\t\t\t\t\t\t\t* 0- remplissage du tableau automatiquemant(test) *\n");
    printf("\t\t\t\t\t\t\t* 1- Ajouter un compte bancaire                   *\n");
    printf("\t\t\t\t\t\t\t* 2- Ajouter plusieurs comptes bancaires          *\n");
    printf("\t\t\t\t\t\t\t* 3- Operations                                   *\n");
    printf("\t\t\t\t\t\t\t* 4- Affichage                                    *\n");
    printf("\t\t\t\t\t\t\t* 5- Fidelisation                                 *\n");
    printf("\t\t\t\t\t\t\t* 6- Quitter l'application                        *\n");
    printf("\t\t\t\t\t\t\t*                                                 *\n");
    printf("\t\t\t\t\t\t\t***************************************************\n\n");
    Sleep(50);
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t***************************************************\n");
    printf("\t\t\t\t\t\t*                                                 *\n");
    printf("\t\t\t\t\t\t* 0- remplissage du tableau automatiquemant(test) *\n");
    printf("\t\t\t\t\t\t* 1- Ajouter un compte bancaire                   *\n");
    printf("\t\t\t\t\t\t* 2- Ajouter plusieurs comptes bancaires          *\n");
    printf("\t\t\t\t\t\t* 3- Operations                                   *\n");
    printf("\t\t\t\t\t\t* 4- Affichage                                    *\n");
    printf("\t\t\t\t\t\t* 5- Fidelisation                                 *\n");
    printf("\t\t\t\t\t\t* 6- Quitter l'application                        *\n");
    printf("\t\t\t\t\t\t*                                                 *\n");
    printf("\t\t\t\t\t\t***************************************************\n\n");
    Sleep(50);
    system("cls");
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t***************************************************\n");
    printf("\t\t\t\t\t*                                                 *\n");
    printf("\t\t\t\t\t* 0- remplissage du tableau automatiquemant(test) *\n");
    printf("\t\t\t\t\t* 1- Ajouter un compte bancaire                   *\n");
    printf("\t\t\t\t\t* 2- Ajouter plusieurs comptes bancaires          *\n");
    printf("\t\t\t\t\t* 3- Operations                                   *\n");
    printf("\t\t\t\t\t* 4- Affichage                                    *\n");
    printf("\t\t\t\t\t* 5- Fidelisation                                 *\n");
    printf("\t\t\t\t\t* 6- Quitter l'application                        *\n");
    printf("\t\t\t\t\t*                                                 *\n");
    printf("\t\t\t\t\t***************************************************\n\n");
    Sleep(50);
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t***************************************************\n");
    printf("\t\t\t\t*                                                 *\n");
    printf("\t\t\t\t* 0- remplissage du tableau automatiquemant(test) *\n");
    printf("\t\t\t\t* 1- Ajouter un compte bancaire                   *\n");
    printf("\t\t\t\t* 2- Ajouter plusieurs comptes bancaires          *\n");
    printf("\t\t\t\t* 3- Operations                                   *\n");
    printf("\t\t\t\t* 4- Affichage                                    *\n");
    printf("\t\t\t\t* 5- Fidelisation                                 *\n");
    printf("\t\t\t\t* 6- Quitter l'application                        *\n");
    printf("\t\t\t\t*                                                 *\n");
    printf("\t\t\t\t***************************************************\n\n");
    Sleep(50);
    system("cls");
    Sleep(50);
    printf("\n\n\n");
    printf("\t\t\t\t\tGestion Bancaire\n\n\n");
    printf("\t\t\t\t\tMENU Principale\n\n");
    printf("\t\t\t\t***************************************************\n");
    printf("\t\t\t\t*                                                 *\n");
    printf("\t\t\t\t* 0- remplissage du tableau automatiquemant(test) *\n");
    printf("\t\t\t\t* 1- Ajouter un compte bancaire                   *\n");
    printf("\t\t\t\t* 2- Ajouter plusieurs comptes bancaires          *\n");
    printf("\t\t\t\t* 3- Operations                                   *\n");
    printf("\t\t\t\t* 4- Affichage                                    *\n");
    printf("\t\t\t\t* 5- Fidelisation                                 *\n");
    printf("\t\t\t\t* 6- Quitter l'application                        *\n");
    printf("\t\t\t\t*                                                 *\n");
    printf("\t\t\t\t***************************************************\n\n");
    Sleep(50);
}
