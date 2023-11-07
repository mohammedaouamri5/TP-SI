#include "Retireds.h"

PGconn *connectToDatabase()
{
  const char *conninfo = "host=localhost port=5432 dbname=Test_C user=postgres password=MohammedGuelma24@";
  PGconn *conn = PQconnectdb(conninfo);

  if (PQstatus(conn) != CONNECTION_OK)
  {
    fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
    PQfinish(conn);
    return NULL;
  }

  return conn;
}

int insertRetired(PGconn *conn, Retired retired)
{
  int ID = -1;
  if (!retired.CanGetMoney) 
  {
   return ID ; 
  }
  
  const char *insertQuery = "INSERT INTO RETIRED (person_name, person_age, person_yearofwork, person_gender, person_Birthday, person_mired, person_partner_havejob, spmm_data, money) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9) RETURNING ID";

  const char *paramValues[9];
  char buf1[20], buf2[20], buf3[20], buf4[20], buf5[20], buf6[20], buf7[256], buf8[20], buf9[32];{

    paramValues[0] = retired.person.name;
    snprintf(buf1, sizeof(buf1), "%d", retired.person.age);
    paramValues[1] = buf1;
    snprintf(buf2, sizeof(buf2), "%d", retired.person.yearofwork);
    paramValues[2] = buf2;
    snprintf(buf3, sizeof(buf3), "%d", retired.person.gender);
    paramValues[3] = buf3;
    snprintf(buf4, sizeof(buf4), "%d-%02d-%02d", retired.person.Birthday.year, retired.person.Birthday.month, retired.person.Birthday.day);
    paramValues[4] = buf4;
    snprintf(buf5, sizeof(buf5), "%d", retired.person.Mired);
    paramValues[5] = buf5;
    snprintf(buf6, sizeof(buf6), "%d", retired.person.ThePartnerHaveJob);
    paramValues[6] = buf6;

    snprintf(buf7, sizeof(buf7), "{{%f, %d},{%f, %d},{%f, %d},{%f, %d},{%f, %d}}",
             retired.spmm[0].AverageSalaries, retired.spmm[0].Year,
             retired.spmm[1].AverageSalaries, retired.spmm[1].Year,
             retired.spmm[2].AverageSalaries, retired.spmm[2].Year,
             retired.spmm[3].AverageSalaries, retired.spmm[3].Year,
             retired.spmm[4].AverageSalaries, retired.spmm[4].Year);
    paramValues[7] = buf7;

    snprintf(buf8, sizeof(buf8), "%d", retired.YearOfWork);
    paramValues[8] = buf8;
  }
  int paramLengths[9];
  int paramFormats[9];
  for (int i = 0; i < 9; i++)
  {
    paramLengths[i] = strlen(paramValues[i]);
    paramFormats[i] = 0;
  }

  printf("-------------------------------------[(insertQuery)]-------------------------------------\n");
  puts(insertQuery);
  printf("-------------------------------------[(insertQuery)]-------------------------------------\n");

  PGresult *result = PQexecParams(conn, insertQuery, 9, NULL, paramValues, paramLengths, paramFormats, 0);

  if (PQresultStatus(result) == PGRES_TUPLES_OK)
  {
    ID = atoi(PQgetvalue(result, 0, 0));
  }
  else
  {
    fprintf(stderr, "Insert query failed: %s\n", PQerrorMessage(conn));
  }

  PQclear(result);

  return ID;
}

int insertHistory(PGconn *conn, Retired retired)
{

  int ID = -1;
  if (!retired.CanGetMoney) 
  {
   return ID ; 
  }
  const char *insertQuery = "INSERT INTO HISTORY (person_name, person_age, person_yearofwork, person_gender, person_Birthday, person_mired, person_partner_havejob, spmm_data, money , retired_id) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10) RETURNING ID";

  const char *paramValues[10];
  char buf1[20], buf2[20], buf3[20], buf4[20], buf5[20], buf6[20], buf7[256], buf8[20], buf9[32];
  {

    paramValues[0] = retired.person.name;
    snprintf(buf1, sizeof(buf1), "%d", retired.person.age);
    paramValues[1] = buf1;
    snprintf(buf2, sizeof(buf2), "%d", retired.person.yearofwork);
    paramValues[2] = buf2;
    snprintf(buf3, sizeof(buf3), "%d", retired.person.gender);
    paramValues[3] = buf3;
    snprintf(buf4, sizeof(buf4), "%d-%02d-%02d", retired.person.Birthday.year, retired.person.Birthday.month, retired.person.Birthday.day);
    paramValues[4] = buf4;
    snprintf(buf5, sizeof(buf5), "%d", retired.person.Mired);
    paramValues[5] = buf5;
    snprintf(buf6, sizeof(buf6), "%d", retired.person.ThePartnerHaveJob);
    paramValues[6] = buf6;

    snprintf(buf7, sizeof(buf7), "{{%f, %d},{%f, %d},{%f, %d},{%f, %d},{%f, %d}}",
             retired.spmm[0].AverageSalaries, retired.spmm[0].Year,
             retired.spmm[1].AverageSalaries, retired.spmm[1].Year,
             retired.spmm[2].AverageSalaries, retired.spmm[2].Year,
             retired.spmm[3].AverageSalaries, retired.spmm[3].Year,
             retired.spmm[4].AverageSalaries, retired.spmm[4].Year);
    paramValues[7] = buf7;

    snprintf(buf8, sizeof(buf8), "%d", retired.Money);
    paramValues[8] = buf8;

    snprintf(buf9, sizeof(buf9), "%d", retired.ID);
    paramValues[9] = buf9;
  }
  int paramLengths[10];
  int paramFormats[10];
  for (int i = 0; i < 10; i++)
  {
    paramLengths[i] = strlen(paramValues[i]);
    paramFormats[i] = 0;
  }

  PGresult *result = PQexecParams(conn, insertQuery, 10, NULL, paramValues, paramLengths, paramFormats, 0);

  if (PQresultStatus(result) == PGRES_TUPLES_OK)
  {
    ID = atoi(PQgetvalue(result, 0, 0));
  }
  else
  {
    fprintf(stderr, "Insert query failed: %s\n", PQerrorMessage(conn));
  }

  PQclear(result);

  return ID;
}

int updateRetired(PGconn *conn, const char *changes, int ID)
{
  char *query;
    
  /* making the qeury */ {
    const char *HeadOfTheQuery = "UPDATE public.retired SET ";

    char *Condition[20];

    snprintf(Condition, sizeof(Condition), "  WHERE ID = %d", ID);

    const int LEN_QUERY = strlen(HeadOfTheQuery) + strlen(changes) + 2 + sizeof(Condition);

    query = ((char *)malloc(LEN_QUERY));
    query[LEN_QUERY - 1] = '\0';

    strcpy(query, HeadOfTheQuery);
    strcat(query, changes);
    strcat(query, Condition);
  }
  
  puts( query ); 
  PGresult *result = PQexec(conn, query);

  if (PQresultStatus(result) == PGRES_TUPLES_OK)
  {
    fprintf(stderr, "Insert query failed: %s\n", PQerrorMessage(conn));
    free(query);
    return 0;
  }

  free(query);
  return 1;
}

void atoRetired(PGresult *selectResult, Retired *retired)
{
  if (PQresultStatus(selectResult) == PGRES_TUPLES_OK && PQntuples(selectResult) > 0)
  {
    // Populate the Retired structure with data from the database
    retired->ID = atoi(PQgetvalue(selectResult, 0, PQfnumber(selectResult, "id")));
 
    // retired->person.name[199] = '\0' ; 
    strcpy(retired->person.name , PQgetvalue(selectResult, 0, PQfnumber(selectResult, "person_name")) ) ; 
 
    retired->person.age = atoi(PQgetvalue(selectResult, 0, PQfnumber(selectResult, "person_age")));
    retired->person.yearofwork = atoi(PQgetvalue(selectResult, 0, PQfnumber(selectResult, "person_yearofwork")));
    retired->person.gender = atoi(PQgetvalue(selectResult, 0, PQfnumber(selectResult, "person_gender")));
    sscanf(PQgetvalue(selectResult, 0, PQfnumber(selectResult, "person_Birthday")),
           "%d-%d-%d",
           &retired->person.Birthday.year,
           &retired->person.Birthday.month,
           &retired->person.Birthday.day);
    retired->person.Mired = atoi(PQgetvalue(selectResult, 0, PQfnumber(selectResult, "person_mired")));
    retired->person.ThePartnerHaveJob = atoi(PQgetvalue(selectResult, 0, PQfnumber(selectResult, "person_partner_havejob")));
    // Fetch the 'spmm_data' as a string and parse it to populate the 'spmm' array
    char *spmmData = PQgetvalue(selectResult, 0, PQfnumber(selectResult, "spmm_data"));
    sscanf(spmmData, "{{%f,%hu},{%f,%hu},{%f,%hu},{%f,%hu},{%f,%hu}}",
           &retired->spmm[0].AverageSalaries, &retired->spmm[0].Year,
           &retired->spmm[1].AverageSalaries, &retired->spmm[1].Year,
           &retired->spmm[2].AverageSalaries, &retired->spmm[2].Year,
           &retired->spmm[3].AverageSalaries, &retired->spmm[3].Year,
           &retired->spmm[4].AverageSalaries, &retired->spmm[4].Year);

    retired->Money = atof(PQgetvalue(selectResult, 0, PQfnumber(selectResult, "money")));
  }
}




/*
Retired getRetiredData(PGconn *conn, int retiredID)
{
  Retired retired;
  memset(&retired, 0, sizeof(Retired)); // Initialize the Retired structure

  // Retrieve data from the database and populate the Retired structure
  const char *selectQuery = "SELECT * FROM Retired WHERE id = $1";

  const char *selectParamValues[1];
  char bufRetiredID[20];
  selectParamValues[0] = bufRetiredID;
  snprintf(bufRetiredID, sizeof(bufRetiredID), "%d", retiredID);

  int selectParamLengths[1];
  int selectParamFormats[1];
  selectParamLengths[0] = strlen(bufRetiredID);
  selectParamFormats[0] = 0;

  PGresult *selectResult = PQexecParams(conn, selectQuery, 1, NULL, selectParamValues, selectParamLengths, selectParamFormats, 0);

  if (PQresultStatus(selectResult) == PGRES_TUPLES_OK && PQntuples(selectResult) > 0)
  {

    atoRetired(selectResult, &retired);
  }

  PQclear(selectResult);

  return retired;
}
*/
 