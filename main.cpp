 /*
    Glenn Ahearne
    06/11/17
    Exercise 8
    Op Amp
  */

    /**Preprocessive Directives*/
#include <iostream>


    /**Function prototypes*/
void invertInput();
void noninvertInput();

void invertCalculation(double, double, double, double, double, double *, double *);
void noninvertCalculation(double, double, double, double, double, double *, double *);

using namespace std;

    /**Main Function*/
int main()
{
        /**variable declarations of type char*/
    char userChoice;
    char menu (void);

        /**Read out Title*/
    cout<<"\n\t\tOperation Amplifier Calculator\t\t"<<endl;


        /**do while loop for user to choose function within switch case */
    do
    {
        userChoice = menu();

        switch (userChoice)

        {

            case 'a': invertInput();
            break;

            case 'b': noninvertInput();
            break;

            case 'q': cout<<"\n\n\t\tGoodbye!\t\t"<<endl;
            break;

            default: cout<<"\n\n\t\tPlease Try Again!"<<endl;
        }

    }
        /**keep looping while userchoice is not equal to Q*/
    while (userChoice != 'q');

    return 0;
}

    /**Inverting Amp Function*/
void invertInput()
{
        /**Variabe declarations*/
    double Vcc, Vee, Vin, Rin, Rf, Av, Vout, *Av_ptr, *Vout_ptr;

        /**Assigning points to address of Av and Vout*/
    Av_ptr = &Av;
    Vout_ptr = &Vout;

        /**Read in values from user*/
        cout<<"\n\t\tEnter Value for Vcc : ";
        cin>>Vcc;
        cout<<"\n\t\tEnter Value for Vee : ";
        cin>>Vee;
        cout<<"\n\t\tEnter Value for Vin : ";
        cin>>Vin;

            /**Do While for Rin greater than zero*/
            do
            {
                cout<<"\n\t\tEnter Value for Rin greater than zero : ";
                cin>>Rin;
            }
            while (Rin<=0);

            /**Do While for Rf greater than zero*/
            do
            {
                cout<<"\n\t\tEnter Value for Rf greater than Zero : ";
                cin>>Rf;
            }
            while (Rf <=0);


        /**Calling inverting Op Amp calculation function*/
    invertCalculation(Vcc, Vee, Vin, Rin, Rf, Av_ptr, Vout_ptr);

    /**Read out results to user*/
    cout <<"\n\t\tResult For Inverting Amplifier"<<endl;
    cout <<"\n\t\tVoltage Gain (Av) is : "<< Av <<endl;
    cout <<"\n\t\tOuput Voltage (Vout) is  : "<< Vout << endl;


}

    /**inverting op amp calculation function*/
void invertCalculation(double Vcc, double Vee, double Vin, double Rin, double Rf, double *Av_ptr, double *Vout_ptr)
{
    /**calculating gain and vout and assigning to address of pointer*/
    *Av_ptr = - (Rf / Rin);

    *Vout_ptr = *Av_ptr * Vin;

    if (*Vout_ptr > Vcc)
    {
        *Vout_ptr = Vcc;
    }
     else if (*Vout_ptr < Vee)
    {
        *Vout_ptr = Vee;
    }
    else
        *Vout_ptr = *Vout_ptr;

}

    /**non inverting op amp function*/
void noninvertInput()
{
    /**Variable declarations*/
    double Vcc, Vee, Vin, R1, R2, Av, Vout, *Av_ptr, *Vout_ptr;

    /**Assigning pointer to address for AV and Vout*/
    Av_ptr = &Av;
    Vout_ptr = &Vout;

    /**Read in values from user*/
        cout<<"\n\t\tEnter Value for Vcc : ";
        cin>>Vcc;
        cout<<"\t\tEnter Value for Vee : ";
        cin>>Vee;
        cout<<"\t\tEnter Value for Vin : ";
        cin>>Vin;

    /**do while R1 is greater than zero*/
            do
            {
                cout<<"\t\tEnter Value for R1 greater than zero : ";
                cin>>R1;
            }
            while (R1<=0);

    /**Do While for R2 greater than zero*/
            do
            {
                cout<<"\t\tEnter Value for R2 greater than Zero : ";
                cin>>R2;
            }
            while (R2 <=0);

    /**Calling Non inverting op amp calculation function*/
            noninvertCalculation(Vcc, Vee, Vin, R1, R2, Av_ptr, Vout_ptr);

            cout <<"\n\t\tResult For Non - Inverting Amplifier\n"<<endl;
            cout <<"\t\tVoltage Gain (Av) is : "<< Av <<endl;
            cout <<"\t\tOuput Voltage (Vout) is  : "<< Vout << endl;

}
    /**non inverting op amp calculation function*/
void noninvertCalculation(double Vcc, double Vee, double Vin, double R1, double R2, double *Av_ptr, double *Vout_ptr)
{
    /**Calculating Gain and Vout and using IF ELSE statement to ensure Vout doesnt go bigger than Vcc or Vee*/

    *Av_ptr = 1 + ( R2 / R1);

    *Vout_ptr = *Av_ptr * Vin;

    if (*Vout_ptr < Vee)
    {
        *Vout_ptr = Vee;
    }
    else if (*Vout_ptr > Vcc)
    {
        *Vout_ptr = Vee;
    }
    else
        *Vout_ptr = *Vout_ptr;
}

    /**menu for user to select which menu to use*/
char menu(void)
{
    char choice;

    cout<<"\n\n\t\tChoose a for Inverting Amplifier!\t";
    cout<<"\n\n\t\tChoose b for Non-Inverting Amplifier!\t";
    cout<<"\n\n\t\tChoose q To Quit!\t";

    /**Display menu selected */
    cout<<"\n\n\t\tMenu Select Is : ";

    /**Read in choice form user*/
    cin>> choice;

    return choice;
}

