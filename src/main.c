#include "io/mainLoop.h"
#include "Data/Retireds.h"
// #include "Logic/Retired.h"
#include "io/Option.h"
#include "Logic/Calculate.h"

int main()
{

  PGconn *conn = connectToDatabase();

  if (conn == NULL)
  {
    return 1;
  }

  Retired retired;
  {
    // retired.person.name  = "Brc vfr uh";
    retired.person.age = 50;
    retired.person.yearofwork = 40;
    retired.person.gender = 1;
    retired.person.Birthday.year = 2003;
    retired.person.Birthday.month = 3;
    retired.person.Birthday.day = 29;
    retired.person.Mired = 0;
    retired.person.ThePartnerHaveJob = 0;



    retired.spmm[0].AverageSalaries = 60000.0;
    retired.spmm[0].Year = 2022;
    retired.spmm[1].AverageSalaries = 62000.0;
    retired.spmm[1].Year = 2023;
    retired.spmm[2].AverageSalaries = 64000.0;
    retired.spmm[2].Year = 2024;
    retired.spmm[3].AverageSalaries = 66000.0;
    retired.spmm[3].Year = 2025;
    retired.spmm[4].AverageSalaries = 68000.0;
    retired.spmm[4].Year = 2026;
    // retired.CanGetMoney = false;

    retired.YearOfWork = 40;
    retired.Money = 2000.0;
  }

 


  // SELECT  * FROM public.retired 
	// return where id = 38  
	// PGresult *  result = PQexec(conn ,  "SELECT  * FROM public.retired return where id = 38" ) ;  
  // PrintRetired(&retired , "---------------------------------------\n ");
  // atoRetired(result , &retired );

  // PrintRetired(&retired , "---------------------------------------\n ");


  // Person person ; 
  // ScanPerson(&person) ;
  // PrintPerson(&person , "\nBRUH") ;
  for (int option =  0 ;GetOption(&option); )
  {
    switch (option)
    {
    case PUSH:
      UI_PUSH(conn);
      break;
    default:
      break;
    }
  }


  Calculate(&retired);

  // updateRetired(conn, "person_name = 'WOOW' ", 38);

  // PrintRetired(&retired, "\n-----------------------##-----------------------");

  // printf("-------------------------------------------------\n");
  // retired.ID = insertRetired(conn, retired);
  // printf("-------------------------------------------------\n");
  // // int ID = insertRetiredHistory(conn, retired);
  // if (retired.ID != -1)
  //   printf("Inserted record ID: %d\n", retired.ID);

  // printf("-------------------------------------------------\n");
  // retired.ID = updateRetired(conn, retired);
  // if (retired.ID != -1)
  //   printf("Inserted record ID: %d\n", retired.ID);
  // printf("-------------------------------------------------\n");

  PQfinish(conn);

  return 0;
}