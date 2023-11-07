

#include "Calculate.h"

float MIN(float x, float y){
    if (x < y)
        return x;
    else
        return y;
}
float MAX(float x, float y)
{
    if (x > y)
        return x;
    else
        return y;
}

float CalculateYearOfWork(short YearOfWork)
{
    return min(YearOfWork * 2.5f, YearOfWork * 80.0f);
}

//&     RG7 :
//    * Le montant de l’IRG (Impôt sur le Revenu)
//    * Pour des raisons de simplification, on considère que le montant de l’IRG est calculé comme suit :
//    * - Pour les revenues inférieur à 20.000, 00 DA pas d’imposition (IRG=0)
//    * - Pour les revenues compris entre 20.000,00 DA et 30.000, 00 DA un taux de retenue égale à 5% sur
//    * l’avantage principale est appliqué.
//  * - Pour les revenues supérieurs à 30.000, 00 DA un taux de retenue de 10% est appliqué.
float IRG(float AverageSalaries)
{
    if (AverageSalaries < 20000.00)
        return 0;
    else if (AverageSalaries > 30000.00)
        return AverageSalaries * (0.1f); /*  AverageSalaries * (10%)  */
    else
        return AverageSalaries * (0.05f); /*  AverageSalaries * (5%)  */
}
float AS(float AverageSalaries)
{
    return AverageSalaries * (0.02f); /*  AverageSalaries * (2%)  */
}

// & RG6 :
//     * Le montant de la pension connaît les deux limites suivantes.
//     * - Un maximum de 15 fois le SNMG (Si net à s le SNMG alors le ramener à 300.000,00 DA ).
//     * - Un minimum : le net à payer ne peut être inférieur à 75% du SNMG (Si net à payer <15.000 alors lepayer > 15 foi
//     * ramener à 15.000,00 DA). Cette limite est valable uniquement pour les pensions. Cependant, pour une
//     * allocation de retraite elle peut être inférieure à 15.000,00 DA
float Normalize(float NET)
{
    if (NET > SNMG * 15)
        return 300000.0f;
    else if (NET < 15000.0f)
        return 15000.0f;
    else
        return NET;
}

float CalculateMajorationConjoint(Person sotial)
{
    return (((sotial.Mired) && (!sotial.ThePartnerHaveJob)) * 2500.0f);
}

// & G 5 : 
//     * Montant de la pension
//     * L'avantage principal de la retraite est le produit du salaire de poste mensuel moyen (calculé par RG3)
//     * multipilié par le taux global des années validées (introduit par RG2) (formule a ci-dessous).
//     * Le montant net mensuel de la retraite est égale à l'avantage principale calculé avec la formule (a) auquel il
//     * faut déduire les retenues de sécurité sociale et IRG, puis ajouter la majoration conjoint (formule b).
//     * Avantage principal= SPMM x Nombre années x 2,5% (a)
//     * Montant net mensuel = (Avantage principal) - (AS + IRG) + Majoration conjoint (b)
void Calculate(Retired *retired)
{
    if ( !retired->CanGetMoney ) 
    {
        printf("error: Retired cannot get money " ) ; 
        exit(CanntGetMoney);
        return ;
        /* code */
    }
    
    float AverageSalaries = CalculateSPMM(retired->spmm);
    float AP = AverageSalaries * CalculateYearOfWork(retired->YearOfWork) * 0.01f;
    float MajorationConjoint = CalculateMajorationConjoint(retired->person);
    float NET = AP - (AS(AverageSalaries) + IRG(AverageSalaries)) + MajorationConjoint;
    retired->Money = Normalize(NET);
}
