#include <mysql.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int qstate;

int mainMenu()
{
	cout << "\nMenu Options" << endl
		<< "1 - Artist Table" << endl 
		<< "2 - Artwork Table" << endl
		<< "3 - Artshow Table" << endl
		<< "4 - Customer Table" << endl
		<< "5 - Visits Table" << endl
		<< "6 - Creates Table"  << endl 
		<< "7 - Organized Table" << endl
		<< "8 - Exit" << endl << endl;
 	int ch;
	cin >> ch;
	return ch;
}

int subMenu()
{
	cout << "\nSub Menu Options" << endl
		<< "1 - Print Table" << endl
		<< "2 - Search and Sort Report" << endl
		<< "3 - Exit" << endl << endl;
	int ch;
	cin >> ch;
	return ch;
}



int main()
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES *res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "Vinhlong1@", "artgallery", 3306, NULL, 0);
	int choice;
	

	if (conn)
	{
		while (1)
		{
			choice = mainMenu();
			if (choice == 8)
				break;
			if (choice == 1)
			{
				while (1)
				{
					choice = subMenu();
					if (choice == 3) break;

					if (choice == 1)
					{
						string querry = "SELECT * FROM artist";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							cout << "Artist" << endl;
							cout << "Name" << " || " << "Birthplace" << " || " << "Age" << " || " << "Address" << " || " << "Phone" << " || " << "Style" << endl;
							while (row = mysql_fetch_row(res))
							{
								cout << row[0] << " || " << row[1] << " || " << row[2] << " || " << row[3] << " || " << row[4] << " || " << row[5] << endl;
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}

					if (choice == 2)
					{
						string key;
						cin.ignore();
						cout << "Enter a value to search: ";
						getline(cin, key);
						string querry = "SELECT * FROM artist WHERE Name = '" + key + "' or Birthplace = '" + key + "' or Age = '" + key + "' or Address = '"
							+ key + "' or Phone = '" + key + "' or Style = '" + key + "' ORDER BY Name asc";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							if ( res->row_count == 0)
							{
								cout << "Can not find a record!." << endl;
							}
							else
							{
								cout << "Artist Report" << endl;
								cout << "Name" << " || " << "Birthplace" << " || " << "Age" << " || " << "Address" << " || " << "Phone" << " || " << "Style" << endl;
								while (row = mysql_fetch_row(res))
								{
									cout << row[0] << " || " << row[1] << " || " << row[2] << " || " << row[3] << " || " << row[4] << " || " << row[5] << endl;
								}
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}
				}
			}

			if (choice == 2)
			{
				while (1)
				{
					choice = subMenu();
					if (choice == 3) break;

					if (choice == 1)
					{
						string querry = "SELECT * FROM artwork";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							cout << "Artwork" << endl;
							cout << "Title" << " || " << "Location" << " || " << "DateofCreation" << " || " << "DateAcquired" << " || " << "Price" << " || " << "Type" << endl;
							while (row = mysql_fetch_row(res))
							{
								cout << row[0] << " || " << row[1] << " || " << row[2] << " || " << row[3] << " || " << row[4] << " || " << row[5] << endl;
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}

					if (choice == 2)
					{
						string key;
						cin.ignore();
						cout << "Enter a vaule to search: ";
						getline(cin, key);

						string querry = "SELECT * FROM artwork WHERE Title = '" + key + "' or Location = '" + key + "' or Price = '" + key + "' or Type = '" + key + "' ORDER BY Title asc";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							if (res->row_count == 0)
							{
								cout << "Can not find a record!." << endl;
							}
							else
							{
								cout << "Artwork" << endl;
								cout << "Title" << " || " << "Location" << " || " << "DateofCreation" << " || " << "DateAcquired" << " || " << "Price" << " || " << "Type" << endl;
								while (row = mysql_fetch_row(res))
								{
									cout << row[0] << " || " << row[1] << " || " << row[2] << " || " << row[3] << " || " << row[4] << " || " << row[5] << endl;
								}
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}
				}
			}

			if (choice == 3)
			{
				while (1)
				{
					choice = subMenu();
					if (choice == 3) break;
					if (choice == 1)
					{
						string querry = "SELECT * FROM artshows";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							cout << "Artshow" << endl;
							cout << "ShowID" << " || " << "DateandTime" << " || " << "Location" << " || " << "ContactPerson" << " || " << "ContactNumber" << endl;
							while (row = mysql_fetch_row(res))
							{
								cout << row[0] << " || " << row[1] << " || " << row[2] << " || " << row[3] << " || " << row[4] << endl;
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}

					if (choice == 2)
					{
						string key;
						cin.ignore();
						cout << "Enter a vaule to search: ";
						getline(cin, key);
						string querry = "SELECT * FROM artshows WHERE ShowID = '" + key + "' or Location = '" + key + "' or ContactPerson = '" + key + "' or ContactNumber = '" + key + "' ORDER BY ShowID asc";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							if (res->row_count == 0)
							{
								cout << "Can not find a record!." << endl;
							}
							else
							{
								cout << "Artshow" << endl;
								cout << "ShowID" << " || " << "DateandTime" << " || " << "Location" << " || " << "ContactPerson" << " || " << "ContactNumber" << endl;
								while (row = mysql_fetch_row(res))
								{
									cout << row[0] << " || " << row[1] << " || " << row[2] << " || " << row[3] << " || " << row[4] << endl;
								}
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}
				}

			}

			if (choice == 4)
			{
				while (1)
				{
					choice = subMenu();
					if (choice == 3) break;
					if (choice == 1)
					{
						string querry = "SELECT * FROM customer";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							cout << "Customer" << endl;
							cout << "CustomerNumber" << " || " << "Phone" << " || " << "ArtPreference" << endl;
							while (row = mysql_fetch_row(res))
							{
								cout << row[0] << " || " << row[1] << " || " << row[2] << endl;
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}

					if (choice == 2)
					{
						string key;
						cin.ignore();
						cout << "Enter a vaule to search: ";
						getline(cin, key);
						string querry = "SELECT * FROM customer WHERE CustomerNumber = '" + key + "' or Phone = '" + key + "' or ArtPreference = '" + key + "' ORDER BY CustomerNumber asc";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							if (res->row_count == 0)
							{
								cout << "Can not find a record!." << endl;
							}
							else
							{
								cout << "Customer" << endl;
								cout << "CustomerNumber" << " || " << "Phone" << " || " << "ArtPreference" << endl;
								while (row = mysql_fetch_row(res))
								{
									cout << row[0] << " || " << row[1] << " || " << row[2] << endl;
								}
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}
				}
			}

			if (choice == 5)
			{
				while (1)
				{
					choice = subMenu();
					if (choice == 3) break;
					if (choice == 1)
					{
						string querry = "SELECT * FROM visits";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							cout << "Visits" << endl;
							cout << "CustomerNumber" << " || " << "ShowID" << endl;
							while (row = mysql_fetch_row(res))
							{
								cout << row[0] << " || " << row[1] << endl;
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}

					if (choice == 2)
					{
						string key;
						cin.ignore();
						cout << "Enter a vaule to search: ";
						getline(cin, key);
						string querry = "SELECT * FROM visits WHERE CustomerNumber = '" + key + "' or ShowID = '" + key + "' ORDER BY CustomerNumber asc";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							if (res->row_count == 0)
							{
								cout << "Can not find a record!." << endl;
							}
							else
							{
								cout << "Visits" << endl;
								cout << "CustomerNumber" << " || " << "ShowID" << endl;
								while (row = mysql_fetch_row(res))
								{
									cout << row[0] << " || " << row[1] << endl;
								}
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}
				}
			}

			if (choice == 6)
			{
				while (1)
				{
					choice = subMenu();
					if (choice == 3) break;
					if (choice == 1)
					{
						string querry = "SELECT * FROM creates";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							cout << "Creates" << endl;
							cout << "ArtistName" << " || " << "Title" << endl;
							while (row = mysql_fetch_row(res))
							{
								cout << row[0] << " || " << row[1] << endl;
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}

					if (choice == 2)
					{
						string key;
						cin.ignore();
						cout << "Enter a vaule to search: ";
						getline(cin, key);
						string querry = "SELECT * FROM creates WHERE ArtistName = '" + key + "' or Title = '" + key + "' ORDER BY ArtistName asc";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							if (res->row_count == 0)
							{
								cout << "Can not find a record!." << endl;
							}
							else
							{
								cout << "Creates" << endl;
								cout << "ArtistName" << " || " << "Title" << endl;
								while (row = mysql_fetch_row(res))
								{
									cout << row[0] << " || " << row[1] << endl;
								}
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}
				}
			}

			if (choice == 7)
			{
				while (1)
				{
					choice = subMenu();

					if (choice == 3) break;
					if (choice == 1)
					{
						string querry = "SELECT * FROM organized";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							cout << "Organized" << endl;
							cout << "ShowID" << " || " << "Artist" << endl;
							while (row = mysql_fetch_row(res))
							{
								cout << row[0] << " || " << row[1] << endl;
							}
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}

					if (choice == 2)
					{
						string key;
						cin.ignore();
						cout << "Enter a vaule to search: ";
						getline(cin, key);
						string querry = "SELECT * FROM organized WHERE ShowID = '" + key + "' or Artist = '" + key + "' ORDER BY Artist asc";
						const char* q = querry.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							if (res->row_count == 0)
							{
								cout << "Can not find a record!." << endl;
							}
							else
							{
								cout << "Organized" << endl;
								cout << "ShowID" << " || " << "Artist" << endl;
								while (row = mysql_fetch_row(res))
								{
									cout << row[0] << " || " << row[1] << endl;
								}
							}
								
						}
						else
						{
							cout << "Querry failed: " << mysql_error(conn) << endl;
						}
					}
				}
			}
		}
	}
	else {
		cout << "Connection to database has failed";
	}
	return 0;
}