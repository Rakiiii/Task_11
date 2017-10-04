#include <windef.h>
#include "Include_and_constants.h"


struct Characteristic
{
    int RepairTime;
    int LooseOutOfStay;
    int Number;
    float Coefficient;
};


/*void QSort(struct Characteristic* Arr , int N)//классический алгоритм быстрой сортировки
{
    int i = 0 , j = N - 1 , temp = 0 ;//два счетчика,переменнная для опорного элемента
    float p = 0.0 , tempf = 0;
    p = Arr[ N >> 1].Coefficient ;
    do
    {
        while( Arr[ i ].Coefficient < p) i++;
        while( Arr[ j ].Coefficient > p) j--;
        if(i <= j)
        {
            tempf = Arr[ i ].Coefficient;
            Arr[ i ].Coefficient = Arr[ j ].Coefficient;
            Arr[ j ].Coefficient = tempf;
            temp = Arr[ i ].RepairTime;
            Arr[ i ].RepairTime = Arr[ j ].RepairTime;
            Arr[ j ].RepairTime = temp ;
            temp = Arr[ i ].LooseOutOfStay;
            Arr[ i ].LooseOutOfStay = Arr[ j ].LooseOutOfStay;
            Arr[ j ].LooseOutOfStay = temp;
            temp = Arr[ i ].Number;
            Arr[ i ].Number = Arr[ j ].Number;
            Arr[ j ].Number = temp;
            i++;j--;
        }
    }while(i <= j);
    if( j > 0 )QSort( Arr, j);
    if( N > i )QSort(Arr+i , N -i);
}
*/

int OptimalRaw()
{
    system("cls");
    printf("Set amount of machines_\n");
    int AmountOfMachines = In() , TimeForAllMachines = 0 , j = 0  , temp = 0 ;
    double TotalLoseOutOfStay = 0.0;
    struct Characteristic *Machines = (struct Characteristic*)malloc( AmountOfMachines * sizeof( struct Characteristic ) );
    for( int i = 0 ; i < AmountOfMachines ; i++ )
    {
        printf("Set lose out of stay for %d-th machine\n" , i + 1);
        Machines[ i ].LooseOutOfStay = In();
        printf("Set repair time for %d-th machine\n" , i + 1);
        Machines[ i ].RepairTime = In();
        Machines[ i ].Coefficient = Machines[ i ].LooseOutOfStay / Machines[ i ].RepairTime;
        Machines[ i ].Number = i + 1 ;
    }
    //QSort(Machines , AmountOfMachines);
    /*float tempf = 0;
    for(int i = 1 ; i < AmountOfMachines ; i++ )
    {
        if(Machines[ i - 1 ].Coefficient < Machines[ i ].Coefficient)
        {
            tempf = Machines[ i ].Coefficient;
            Machines[ i ].Coefficient = Machines[ j ].Coefficient;
            Machines[ j ].Coefficient = tempf;
            temp = Machines[ i ].RepairTime;
            Machines[ i ].RepairTime = Machines[ j ].RepairTime;
            Machines[ j ].RepairTime = temp ;
            temp = Machines[ i ].LooseOutOfStay;
            Machines[ i ].LooseOutOfStay = Machines[ j ].LooseOutOfStay;
            Machines[ j ].LooseOutOfStay = temp;
            temp = Machines[ i ].Number;
            Machines[ i ].Number = Machines[ j ].Number;
            Machines[ j ].Number = temp;
            i++;j--;
        }
    }*/
    printf("You should repair machines in this order:\n");
    for( int i = 0 ; i < AmountOfMachines ; i++ )
    {
        int  Max = 0 , Num = 0;
        for( int j = 0 ; j < AmountOfMachines ; j ++ )
        {
            if( Machines[ j ].Coefficient > Max)
            {
                Max = Machines[ j ].Coefficient;
                Num = Machines[ j ].Number;
            }
        }
        Machines [ Num - 1 ].Coefficient = 0;
        printf("%d -th machine\n" , Num );
        TimeForAllMachines = TimeForAllMachines + Machines [ i ].RepairTime;
        TotalLoseOutOfStay = TotalLoseOutOfStay + ( Machines [ i ].LooseOutOfStay * TimeForAllMachines );
    }
    printf("Total losses is %f \n" , TotalLoseOutOfStay);
    /*for(int i = 0 ; i < AmountOfMachines ; i++)
    {
        printf("%d -th machine\n" , Machines[ i ].Number);
    }*/
    return 0;
}


int main()
{
    while(TRUE)
    {
        system("cls");
        printf("1.Find optimal raw\n2.Exit");
        char Choose = getch();
        switch (Choose)
        {
            case '1' :
                OptimalRaw();
                printf("Press any button to restart the programme_\n");
                getch();
                break;
            case '2' :
                return 0;
            default:
                break;

        }

    }
}