//CODED BY: MUHAMMAD HAIDER
//PROJECT
//PHARMACY MANAGEMENT SYSTEM
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

/*________________________________________________________________________________________________________________________________*/

//STRUCTURE MEDICINE
struct medicine {
	int m_id;
	char m_name[40];
	int m_pot;
	char manuf[40];
	int tua;  //total_unit_available
} m;
long int size_m = sizeof(m);
FILE* fptr, * ftmp;

//FUNCTIONS MEDICINE
void addrecord();
void deleterecord();
void searchrecord();
void modifyrecord();

/*________________________________________________________________________________________________________________________________*/

//STRUCTURE SUPPLIERS
struct supplier {
	int s_id;
	int e_date;
	int e_mon;
	int e_y;
	char c_name[40];
	char s_add[50];
	char rep[40];
	char des[50];
} s;
long int size_s = sizeof(s);
FILE* fptr2, * ftmp2;

//FUNCTION SUPPLIER
void addsup();
void deletesupp();
void modifysup();
void searchsup();

/*________________________________________________________________________________________________________________________________*/

//STRUCTURE SALE INVOICE
struct sale_invoice {
	char s_inv[10]; //sale_invoice
	int m_id;
	char m_name[40];
	int m_pot;
	int p_p_u; //price_per_unit
	int ua;   //unit_available
	int e_date;
	int e_mon;
	int e_y;
	int dis_a;//discount_amount
	int n_b_a;//net_bill_amonnt
	int t_a; //TOTAL amount
} sal;

long int size_v = sizeof(sal);
FILE* fptr3,* ftmp3;

//FUNCTION SALE INVOICE
void addlist();
void deletelist();
void searchlist();
void modifylist();

/*________________________________________________________________________________________________________________________________*/

//STRUCTURE CUSTOMER
struct customer {
	char cnic[30];
	int e_date;
	int e_mon;
	int e_y;
	char cus_name[40];
	char purmed_name[40];
	int qua;

} cus;

long int size_cus = sizeof(cus);
FILE* fptr4, * ftmp4;

//FUNCTION CUSTOMERS
void addc();
void deletec();
void searchc();
void modifyc();

/*________________________________________________________________________________________________________________________________*/

//STRUCTURE PHARMACIST
struct pharmacist {
	char p_ph[20];
	char p_name[40];
	char p_city[50];
	char p_tim[40];
} p;
long int size_p = sizeof(p);
FILE* fptr5, * ftmp5;

//FUNCTION PHARMACIST
void addp();
void deletep();
void modifyp();
void searchp();

/*________________________________________________________________________________________________________________________________*/

//STRUCTURE ORDER
struct order {
	int o_gd;//order given date
	int o_gmon;
	int o_gy;
	int o_rd;//order receive date
	int o_rmon;
	int o_ry;
	char o_name[40];
	char o_med[50];
	int o_quan;
} o;
long int size_o = sizeof(o);
FILE* fptr6, * ftmp6;

//FUNCTION ORDER
void addo();
void deleteo();
void modifyo();
void searcho();

/*________________________________________________________________________________________________________________________________*/

struct stock {
	int st_unit;
} st;

long int size_st = sizeof(st);
FILE* fptr7,* ftmp7;

void stock();

/*________________________________________________________________________________________________________________________________*/

//FUCTIONS
void pres();
void timing();
void stock();

/*________________________________________________________________________________________________________________________________*/

//DRIVER FUNCTION
int main() {
	system("color 2");
	int choice;

	//MEDICINE FILE
	fptr = fopen("Medicine_Details.txt", "rb+");

	if (fptr == NULL) {
		fptr = fopen("Medicine_Details.txt", "wb+");
		if (fptr == NULL) {
			printf("\nCannot open file...");
			exit(0);
		}
	}

	//SUPPLIER FILE
	fptr2 = fopen("Suppliers_Details.txt", "rb+");

	if (fptr2 == NULL) {
		fptr2 = fopen("Suppliers_Details.txt", "wb+");
		if (fptr2 == NULL) {
			printf("\nCannot open file...");
			exit(0);
		}
	}

	//SALE_INVOICE FILE
	fptr3 = fopen("Sale_Invoice Details.txt", "rb+");

	if (fptr3 == NULL) {
		fptr3 = fopen("Sale_Invoice Details.txt", "wb+");
		if (fptr3 == NULL) {
			printf("\nCannot open file...");
			exit(0);
		}
	}

	//CUSTOMER FILE
	fptr4 = fopen("Customer_Details.txt", "rb+");

	if (fptr4 == NULL) {
		fptr4 = fopen("Customer_Details.txt", "wb+");
		if (fptr4 == NULL) {
			printf("\nCannot open file...");
			exit(0);
		}
	}

	//PHARMACIST FILE
	fptr5 = fopen("Pharmacist_Details.txt", "rb+");

	if (fptr5 == NULL) {
		fptr5 = fopen("Pharmacist_Details.txt", "wb+");
		if (fptr5 == NULL) {
			printf("\nCannot open file...");
			exit(0);
		}
	}

	//ORDER_DETAILS FILE
	fptr6 = fopen("order_Details.txt", "rb+");

	if (fptr6 == NULL) {
		fptr6 = fopen("order_Details.txt", "wb+");
		if (fptr6 == NULL) {
			printf("\nCannot open file...");
			exit(0);
		}
	}

	//STOCK FILE
	fptr7 = fopen("stock_Details.txt", "rb+");

	if (fptr7 == NULL) {
		fptr7 = fopen("stock_Details.txt", "wb+");
		if (fptr7 == NULL) {
			printf("\nCannot open file...");
			exit(0);
		}
	}

	while (1) {
		system("cls");

		printf("\t\t\t\t\t\t  ______________________________________________\n");
		printf("\t\t\t\t\t\t||\t     PHARMACY MANAGEMENT SYSTEM  \t||");
		printf("\n\t\t\t\t\t\t||----------------------------------------------||");
		printf("\n\t\t\t\t\t\t||Select Choice.\t\t\t\t||");
		printf("\n\t\t\t\t\t\t||----------------------------------------------||");
		printf("\n\t\t\t\t\t\t|| Press 1 to add the medicine.\t\t\t||");
		printf("\n\t\t\t\t\t\t|| press 2 to delete the detail of medicine.\t||");
		printf("\n\t\t\t\t\t\t|| Press 3 to search the medicine.\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 4 to edit the details of medicine.\t||");
		printf("\n\t\t\t\t\t\t||______________________________________________||");
		printf("\n\t\t\t\t\t\t||\t\t\t\t\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 5 to add the Supplier.\t\t\t||");
		printf("\n\t\t\t\t\t\t|| press 6 to delete the detail of Supplier.\t||");
		printf("\n\t\t\t\t\t\t|| Press 7 to search the Supplier.\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 8 to edit the details of Supplier.\t||");
		printf("\n\t\t\t\t\t\t||______________________________________________||");
		printf("\n\t\t\t\t\t\t||\t\t\t\t\t\t||");
		printf("\n\t\t\t\t\t\t|| Press  9 to add the details for Sale Invoice.||");
		printf("\n\t\t\t\t\t\t|| Press 10 to delete detail of Sale Invoice.\t||");
		printf("\n\t\t\t\t\t\t|| Press 11 to search the Sale Invoice.\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 12 to edit the details of Sale Invoice.||");
		printf("\n\t\t\t\t\t\t||______________________________________________||");
		printf("\n\t\t\t\t\t\t||\t\t\t\t\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 13 to add the details of Customer.\t||");
		printf("\n\t\t\t\t\t\t|| Press 14 to delete detail of Customer.\t||");
		printf("\n\t\t\t\t\t\t|| Press 15 to search the Customer.\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 16 to edit the details of Customer.\t||");
		printf("\n\t\t\t\t\t\t||______________________________________________||");
		printf("\n\t\t\t\t\t\t||\t\t\t\t\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 17 to add the details of Pharmacist.\t||");
		printf("\n\t\t\t\t\t\t|| Press 18 to delete detail of Pharmacist.\t||");
		printf("\n\t\t\t\t\t\t|| Press 19 to search the Pharmacist.\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 20 to edit the details of Pharmacist.\t||");
		printf("\n\t\t\t\t\t\t||______________________________________________||");
		printf("\n\t\t\t\t\t\t||\t\t\t\t\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 21 to add the details of Order.\t||");
		printf("\n\t\t\t\t\t\t|| Press 22 to delete detail of Order.\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 23 to search the Order.\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 24 to edit the details of Order.\t||");
		printf("\n\t\t\t\t\t\t||______________________________________________||");
		printf("\n\t\t\t\t\t\t||\t\t\t\t\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 25 to Medicine E-Prescription.\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 26 to Pharmacist Timing.\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 27 to Stock Availability.\t\t||");
		printf("\n\t\t\t\t\t\t||______________________________________________||");
		printf("\n\t\t\t\t\t\t||\t\t\t\t\t\t||");
		printf("\n\t\t\t\t\t\t|| Press 28 to Exit.\t\t\t\t||");
		printf("\n\t\t\t\t\t\t||______________________________________________||\n");
		printf("\nEnter Your Choice: ");

		fflush(stdin);
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				addrecord();
				break;
			case 2:
				deleterecord();
				break;
			case 3:
				searchrecord();
				break;
			case 4:
				modifyrecord();
				break;
			case 5:
				addsup();
				break;
			case 6:
				deletesupp();
				break;
			case 7:
				searchsup();
				break;
			case 8:
				modifysup();
				break;
			case 9:
				addlist();
				break;
			case 10:
				deletelist();
				break;
			case 11:
				searchlist();
				break;
			case 12:
				modifylist();
				break;
			case 13:
				addc();
				break;
			case 14:
				deletec();
				break;
			case 15:
				searchc();
				break;
			case 16:
				modifyc();
				break;
			case 17:
				addp();
				break;
			case 18:
				deletep();
				break;
			case 19:
				searchp();
				break;
			case 20:
				modifyp();
				break;
			case 21:
				addo();
				break;
			case 22:
				deleteo();
				break;
			case 23:
				searcho();
				break;
			case 24:
				modifyo();
				break;
			case 25:
				pres();
				break;
			case 26:
				timing();
				break;
			case 27:
				stock();
				break;
			case 28:
				fclose(fptr);
				fclose(fptr2);
				fclose(fptr3);
				fclose(fptr4);
				fclose(fptr5);
				fclose(fptr6);

				exit(0);
			default:
				printf("\nINVALID CHOICE...\n");
		}
	}
}
/*________________________________________________________________________________________________________________________________*/

//ADD_MEDICINE_DETAILS
void addrecord() {
	system("color 2");
	system("cls");
	fseek(fptr, 0, SEEK_END);

	char add_another = 'y';

	while (add_another == 'y') {
		printf("\n\nEnter the Medicine ID: ");
		scanf("%d", &m.m_id);

		printf("\nEnter the Medicine name: ");
		scanf(" %[^\n]s", m.m_name);

		printf("\nEnter the Medicine Potency: ");
		scanf("%d", &m.m_pot);

		printf("\nEnter the Manufactured Company name: ");
		scanf(" %[^\n]", m.manuf);

		printf("\nEnter the Unit: ");
		scanf("%d", &m.tua);

		fwrite(&m, sizeof(m), 1, fptr);

		printf("\nWant to add another Medicine Details (y/n): ");
		fflush(stdin);

		scanf("%c", &add_another);
	}
}

//DELETE_MEDICINE_DETAILS
void deleterecord() {
	system("cls");
	char name[40];
	char add_another = 'y';

	while (add_another == 'y') {
		printf("Enter the Medicine name you want to delete: ");
		scanf("%s", name);

		ftmp = fopen("temprary.txt", "wb+"); // temprary file

		rewind(fptr);
		while (fread(&m, sizeof(m), 1, fptr) == 1) {
			if (strcmp(m.m_name, name) != 0) {
				fwrite(&m, sizeof(m), 1, ftmp);
			}

			fclose(fptr);
			fclose(ftmp);

			remove("Medicine_Details.txt");
			rename("temprary.txt", "Medicine_Details.txt");

			fptr = fopen("Medicine_Details.txt", "rb+");
			printf("Want to Delate another Medicine Details (y/n): ");
			fflush(stdin);

			scanf("%c", &add_another);
		}
	}
}

//SEARCH_MEDICINE_DETAILS
void searchrecord() {
	system("cls");
	char another = 'y';
	char name[40];
	int flag = 0;

	while (another == 'y') {
		printf("\n\nEnter the Medicine name you want to search: ");
		scanf(" %[^\n]", name);
		rewind(fptr);

		int temp2=0;
		while (fread(&m, sizeof(m), 1, fptr) == 1) {
			if (strcmp(m.m_name, name) == 0) {
				printf("\n===================================================================================\n");
				printf("Medicine_ID\tMedicine_Name\tPotency\t\tManuf_By\tUnits_Avialable");
				printf("\n-----------------------------------------------------------------------------------\n");
				printf("%d\t\t%s\t\t%d\t\t%s\t\t%d", m.m_id, m.m_name, m.m_pot, m.manuf, m.tua);
				printf("\n-----------------------------------------------------------------------------------");
				printf("\n\t");
				temp2+=1;
				break;
			}
		}

		if(!temp2) {
			printf("\n.....This medicine is not Available.....\n");
		}

		printf("\nWant to Search another Medicine Details (y/n): ");
		fflush(stdin);

		scanf("%c", &another);

		//system("pause");
	}
}

//EDIT_MEDICINE_DETAILS
void modifyrecord() {
	system("cls");

	char name[40];
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter the Medicine name which you want to modify: ");
		scanf(" %[^\n]", name);

		rewind(fptr);

		while (fread(&m, sizeof(m), 1, fptr) == 1) {
			if (strcmp(m.m_name, name) == 0) {
				printf("\nEnter the Medicine's new ID: ");
				scanf("%d", &m.m_id);

				printf("\nEnter the Medicine's new Potency: ");
				scanf("%d", &m.m_pot);

				printf("\nEnter the Medicine's new Manufactured Company name: ");
				scanf(" %[^\n]", m.manuf);

				printf("\nEnter the Medicine's new Total Unit Avaiable: ");
				scanf("%d", &m.tua);

				fseek(fptr, -size_m, SEEK_CUR);
				fwrite(&m, sizeof(m), 1, fptr);
			}
		}
		printf("\nWant to Edit another Medicine Details (y/n): ");
		fflush(stdin);

		scanf("%c", &another);
	}
}
/*________________________________________________________________________________________________________________________________*/

//ADD SUPPLIER DETAILS
void addsup() {
	system("cls");
	fseek(fptr2, 0, SEEK_END);

	char add_another = 'y';

	while (add_another == 'y') {
		printf("\nEnter the Supplier ID: ");
		scanf("%d", &s.s_id);

		printf("\nEnter the Company name: ");
		scanf(" %[^\n]", s.c_name);

		printf("\nEnter the Representative Name: ");
		scanf(" %[^\n]", s.rep);

		printf("\nEnter the Address(City Name): ");
		scanf(" %[^\n]", s.s_add);

		printf("\nEnter the Description(4 to 6 alphabets): ");
		scanf(" %[^\n]", s.des);

		// ---  Year Validation --- //
		do {
			printf("\nEnter the Supplier's Established Year : ");
			scanf("%d", &s.e_y);

			if (s.e_y < 2000 ||  s.e_y > 2022) {
				printf("\n\n --- Invalid Year Entered --- \n");
			}

		} while (s.e_y < 2000 || s.e_y > 2022);

		// ---  Month Validation --- //
		do {
			printf("\nEnter the Supplier's Established Month: ");
			scanf("%d", &s.e_mon);

			if (s.e_mon < 1 || s.e_mon > 12) {
				printf("\n\n --- Invalid Month Entered --- \n");
			}

		} while (s.e_mon < 1 || s.e_mon > 12);

		// ---  Date Validation --- //
		do {
			printf("\nEnter the Supplier's Established Date : ");
			scanf("%d", &s.e_date);

			if (s.e_date < 1 || s.e_date > 31) {
				printf("\n\n --- Invalid Date Entered --- ");
			}

		} while (s.e_date < 1 || s.e_date > 31);


		fwrite(&s, sizeof(s), 1, fptr2);

		printf("\n\nWant to add another Supplier Details (y/n): ");
		fflush(stdin);

		scanf("%c", &add_another);
	}
}

//DELETE_SUPPLIER_DETAILS
void deletesupp() {
	system("cls");

	char add_another = 'y';
	char name[40];
	while (add_another == 'y') {
		printf("\nEnter the Supplier's Company name you want to delete: ");
		scanf(" %[^\n]", name);

		ftmp2 = fopen("temprary.txt", "wb+"); // temprary file

		rewind(fptr2);
		while (fread(&s, sizeof(s), 1, fptr2) == 1) {
			if (strcmp(s.c_name, name) != 0) {
				fwrite(&s, sizeof(s), 1, ftmp2);
			}

			fclose(fptr2);
			fclose(ftmp2);

			remove("Suppliers_Details.txt");
			rename("temprary.txt", "Suppliers_Details.txt");

			fptr2 = fopen("Suppliers_Details.txt", "rb+");

			printf("\n\nWant to Delete another Supplier Details (y/n): ");
			fflush(stdin);

			scanf("%c", &add_another);
		}
	}
}

//EDIT_Supplier_DETAILS
void modifysup() {
	system("cls");

	char name[40];
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter the Supplier's Company name which you want to modify: ");
		scanf(" %[^\n]", name);

		rewind(fptr2);

		while (fread(&s, sizeof(s), 1, fptr2) == 1) {
			if (strcmp(s.c_name, name) == 0) {
				printf("\nEnter the Supplier's new ID: ");
				scanf("%d", &s.s_id);

				printf("\nEnter the Supplier's new Representative name: ");
				scanf(" %[^\n]", s.rep);

				printf("\nEnter the Supplier's new Address: ");
				scanf(" %[^\n]", s.s_add);

				// ---  Year Validation --- //
				do {
					printf("\nEnter the Supplier's New Established Year : ");
					scanf("%d", &s.e_y);

					if (s.e_y < 2000 ||  s.e_y > 2022) {
						printf("\n\n --- Invalid Year Entered --- \n");
					}

				} while (s.e_y < 2000 || s.e_y > 2022);

				// ---  Month Validation --- //
				do {
					printf("\nEnter the Supplier's New Established Month: ");
					scanf("%d", &s.e_mon);

					if (s.e_mon < 1 || s.e_mon > 12) {
						printf("\n\n --- Invalid Month Entered --- \n");
					}

				} while (s.e_mon < 1 || s.e_mon > 12);

				// ---  Date Validation --- //
				do {
					printf("\nEnter the Supplier's New Established Date : ");
					scanf("%d", &s.e_date);

					if (s.e_date < 1 || s.e_date > 31) {
						printf("\n\n --- Invalid Date Entered --- ");
					}

				} while (s.e_date < 1 || s.e_date > 31);



				fseek(fptr2, -size_s, SEEK_CUR);
				fwrite(&s, sizeof(s), 1, fptr2);
			}
		}
		printf("\nWant to Edit another Medicine Details (y/n): ");
		fflush(stdin);

		scanf("%c", &another);
	}
}

//SEARCH_SUPPLIERS_DETAILS
void searchsup() {
	system("cls");
	char another = 'y';
	char name[40];

	while (another == 'y') {
		printf("\n\nEnter the Supplier's Company name you want to search: ");
		scanf(" %[^\n]", name);
		rewind(fptr2);

		while (fread(&s, sizeof(s), 1, fptr2) == 1) {
			int temp2 = 0;
			if (strcmp(s.c_name, name) == 0) {
				printf("\n==========================================================================================================\n");
				printf("Supplier_ID\tCompany_Name\tRep_Name\tAddress\t\tDescription\tEstablished_Date");
				printf("\n----------------------------------------------------------------------------------------------------------\n");
				printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d-%d-%d", s.s_id, s.c_name, s.rep, s.s_add, s.des, s.e_date, s.e_mon, s.e_y);
				printf("\n----------------------------------------------------------------------------------------------------------");
				printf("\n\t");
				temp2+=1;
				break;
			}

			if(!temp2) {
				printf("\n.....The Details of this Supplier is not exists.....\n");
				break;
			}
		}

		printf("\nWant to Search another Supplier Details (y/n): ");
		fflush(stdin);

		scanf("%c", &another);
		//system("pause");
	}
}
/*________________________________________________________________________________________________________________________________*/

//ADD SALE INVOICE DETAILS
void addlist() {
	system("cls");
	fseek(fptr3, 0, SEEK_END);

	char add_another = 'y';

	while (add_another == 'y') {
		printf("\nEnter the Sale Invoice #(must be 4 alphabets): ");
		scanf(" %[^\n]", sal.s_inv);
		printf("\n_______________________________________________________________\n");

		printf("\nEnter the Medicine ID: ");
		scanf("%d", &sal.m_id);

		printf("\nEnter the Medicine name(must be 7 alphabets): ");
		scanf(" %[^\n]", sal.m_name);

		printf("\nEnter the Medicine Potency (mg): ");
		scanf("%d", &sal.m_pot);

		printf("\nEnter the Unit: ");
		scanf("%d", &sal.ua);

		printf("\nEnter the Price_per_Unit($): ");
		scanf("%d", &sal.p_p_u);

		printf("\nEnter the Discount(in Percent): ");
		scanf("%d", &sal.dis_a);

		// ---  Year Validation --- //
		do {
			printf("\nEnter the Year : ");
			scanf("%d", &sal.e_y);

			if (sal.e_y < 2000 ||  sal.e_y > 2022) {
				printf("\n\n --- Invalid Year Entered --- \n");
			}

		} while (sal.e_y < 2000 || sal.e_y > 2022);

		// ---  Month Validation --- //
		do {
			printf("\nEnter the Month: ");
			scanf("%d", &sal.e_mon);

			if (sal.e_mon < 1 || sal.e_mon > 12) {
				printf("\n\n --- Invalid Month Entered --- \n");
			}

		} while (sal.e_mon < 1 || sal.e_mon > 12);

		// ---  Date Validation --- //
		do {
			printf("\nEnter the Date : ");
			scanf("%d", &sal.e_date);

			if (sal.e_date < 1 || sal.e_date > 31) {
				printf("\n\n --- Invalid Date Entered --- ");
			}

		} while (sal.e_date < 1 || sal.e_date > 31);


		fwrite(&sal, sizeof(sal), 1, fptr3);

		printf("\n_______________________________________________________________");
		printf("\n\nWant to add Details of another invoice(y/n): ");
		fflush(stdin);

		scanf("%c", &add_another);
		printf("\n_______________________________________________________________");
	}
}

//DELETE_SALE INVOICE_DETAILS
void deletelist() {
	system("cls");

	char add_another = 'y';
	char num[10];
	while (add_another == 'y') {
		printf("\nEnter the Sale_Invoice # you want to delete: ");
		scanf(" %[^\n]", num);

		ftmp3 = fopen("temprary.txt", "wb+"); // temprary file

		rewind(fptr3);
		while (fread(&sal, sizeof(sal), 1, fptr3) == 1) {
			if (strcmp(sal.s_inv, num) == 0) {
				fwrite(&sal.s_inv, sizeof(sal), 1, ftmp3);
			}

			fclose(fptr3);
			fclose(ftmp3);

			remove("Sale_Invoice Details.txt");
			rename("temprary.txt", "Sale_Invoice Details.txt");

			fptr3 = fopen("Sale_Invoice Details.txt", "rb+");

			printf("\nWant to Delete another Sale Invoice Details (y/n): ");
			fflush(stdin);

			scanf("%c", &add_another);
		}
	}
}


//EDIT_SALE INVOICE_DETAILS
void modifylist() {
	system("cls");

	char num[10];
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter the Sale Invoice # which you want to modify: ");
		scanf(" %[^\n]", num);

		rewind(fptr3);

		while (fread(&sal, sizeof(sal), 1, fptr3) == 1) {
			if (strcmp(sal.s_inv, num) == 0) {
				printf("\nEnter the new Sale Invoice # (must be 4 alphabets): ");
				scanf("%s", sal.s_inv);

				printf("\nEnter the new Medicine ID: ");
				scanf("%d", &sal.m_id);

				printf("\nEnter the new Medicine name(must be 7 alphabets): ");
				scanf(" %[^\n]", sal.m_name);

				printf("\nEnter the new Medicine Potency (mg): ");
				scanf("%d", &sal.m_pot);

				printf("\nEnter the new Units: ");
				scanf("%d", &sal.ua);

				printf("\nEnter the new Price_per_Unit($): ");
				scanf("%d", &sal.p_p_u);

				printf("\nEnter the new Discount(in Percent): ");
				scanf("%d", &sal.dis_a);


				// ---  Year Validation --- //
				do {
					printf("\nEnter the Year : ");
					scanf("%d", &sal.e_y);

					if (sal.e_y < 2000 ||  sal.e_y > 2022) {
						printf("\n\n --- Invalid Year Entered --- \n");
					}

				} while (sal.e_y < 2000 || sal.e_y > 2022);

				// ---  Month Validation --- //
				do {
					printf("\nEnter the Month: ");
					scanf("%d", &sal.e_mon);

					if (sal.e_mon < 1 || sal.e_mon > 12) {
						printf("\n\n --- Invalid Month Entered --- \n");
					}

				} while (sal.e_mon < 1 || sal.e_mon > 12);

				// ---  Date Validation --- //
				do {
					printf("\nEnter the Date : ");
					scanf("%d", &sal.e_date);

					if (sal.e_date < 1 || sal.e_date > 31) {
						printf("\n\n --- Invalid Date Entered --- ");
					}

				} while (sal.e_date < 1 || sal.e_date > 31);

				fseek(fptr3, -size_v, SEEK_CUR);
				fwrite(&sal, sizeof(sal), 1, fptr3);
			}
		}

		printf("\nWant to Edit another sale invoice Details (y/n): ");
		fflush(stdin);

		scanf("%c", &another);
	}
}

//SEARCH_SALE INVOICE_DETAILS
void searchlist() {
	system("cls");
	char another = 'y';
	char num[20];

	while (another == 'y') {
		printf("\n\nEnter the Sale_Invoice # you want to search: ");
		scanf(" %[^\n]", num);
		rewind(fptr3);

		while (fread(&sal, sizeof(sal), 1, fptr3) == 1) {
			int temp2=0;
			double t = sal.p_p_u * sal.ua * (sal.dis_a / 100.0);
			if (strcmp(sal.s_inv, num) == 0) {
				printf("\n==================================================================================================================================================================\n");
				printf("Sale_Invoice#   Medicine_Name      Date_of_Sale    Medicine_ID \tPotency   Units    Price_per_unit($)     Total_Price($)     Discount(percent)");
				printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%s  \t\t%s\t\t   %d-%d-%d\t\t%d\t   %d\t   %d      %d\t\t\t $%.1lf\t\t    %d", sal.s_inv, sal.m_name, sal.e_date, sal.e_mon, sal.e_y, sal.m_id, sal.m_pot, sal.ua, sal.p_p_u, t, sal.dis_a);
				printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------");
				printf("\n\t");
				temp2+=1;
				break;
			}
			if(!temp2) {
				printf("\n.....The Details of this Sale_Invoice is not Available.....\n");
				break;
			}
		}
		printf("\nWant to Search another Sale_Invoice Details (y/n): ");
		fflush(stdin);

		scanf("%c", &another);
		//system("pause");
	}
}

/*__________________________________________________________________________________________________________________*/

//ADD_CUSTOMER_DETAILS
void addc() {
	system("cls");
	fseek(fptr, 0, SEEK_END);

	char add_another = 'y';

	while (add_another == 'y') {
		printf("\n\nEnter the Customer Name(5 to 6 alphabets): ");
		scanf(" %[^\n]", cus.cus_name);

		printf("\nEnter Customer CNIC(#####-#######-#): ");
		scanf(" %[^\n]", cus.cnic);

		printf("\nEnter Purchased Medicine name (must be 7 alphabets): ");
		scanf(" %[^\n]", cus.purmed_name);

		printf("\nEnter the quantity of medicine: ");
		scanf("%d", &cus.qua);

		// ---  Year Validation --- //
		do {
			printf("\nEnter the Year : ");
			scanf("%d", &cus.e_y);

			if (cus.e_y < 2000 ||  cus.e_y > 2022) {
				printf("\n\n --- Invalid Year Entered --- \n");
			}

		} while (cus.e_y < 2000 || cus.e_y > 2022);

		// ---  Month Validation --- //
		do {
			printf("\nEnter the Month: ");
			scanf("%d", &cus.e_mon);

			if (cus.e_mon < 1 || cus.e_mon > 12) {
				printf("\n\n --- Invalid Month Entered --- \n");
			}

		} while (cus.e_mon < 1 || cus.e_mon > 12);

		// ---  Date Validation --- //
		do {
			printf("\nEnter the Date : ");
			scanf("%d", &cus.e_date);

			if (cus.e_date < 1 || cus.e_date > 31) {
				printf("\n\n --- Invalid Date Entered --- ");
			}

		} while (cus.e_date < 1 || cus.e_date > 31);


		fwrite(&cus, sizeof(cus), 1, fptr4);

		printf("\nWant to add Details of another customer (y/n): ");
		fflush(stdin);

		scanf("%c", &add_another);
	}
}

//DELETE_CUSTOMER_DETAILS
void deletec() {
	system("cls");
	char name[40];
	char add_another = 'y';

	while (add_another == 'y') {
		printf("\nEnter the Customer name you want to delete: ");
		scanf(" %[^\n]", name);

		ftmp = fopen("temprary.txt", "wb+"); // temprary file

		rewind(fptr4);
		while (fread(&cus, sizeof(cus), 1, fptr4) == 1) {
			if (strcmp(cus.cus_name, name) != 0) {
				fwrite(&cus, sizeof(cus), 1, ftmp4);
			}

			fclose(fptr4);
			fclose(ftmp4);

			remove("Customer_Details.txt");
			rename("temprary.txt", "Customer_Details.txt");

			fptr4 = fopen("Customer_Details.txt", "rb+");

			printf("\nWant to Delete the  Details of another customer(y/n): ");
			fflush(stdin);

			scanf("%c", &add_another);
		}
	}
}

//SEARCH_CUSTOMER_DETAILS
void searchc() {
	system("cls");
	char another = 'y';
	char name[40];
	int flag = 0;

	while (another == 'y') {
		printf("\n\nEnter the Customer name you want to search: ");
		scanf(" %[^\n]", name);
		rewind(fptr4);

		int temp2=0;
		while (fread(&cus, sizeof(cus), 1, fptr4) == 1) {
			if (strcmp(cus.cus_name, name) == 0) {
				printf("\n================================================================================================\n");
				printf("Customer_Name\tPurchased Med_Name\t Customer CNIC\t\tQuantity_med\tDate_of_Purchase");
				printf("\n------------------------------------------------------------------------------------------------\n");
				printf("%s\t\t%s\t\t\t%s\t\t%d\t\t%d-%d-%d", cus.cus_name, cus.purmed_name, cus.cnic, cus.qua, cus.e_date, cus.e_mon, cus.e_y);
				printf("\n------------------------------------------------------------------------------------------------");
				printf("\n\t");
				temp2+=1;
				break;
			}
		}

		if(!temp2) {
			printf("\n.....This Customer's detail is not Available.....\n");
		}

		printf("\nWant to Search the Details of another customer (y/n): ");
		fflush(stdin);

		scanf("%c", &another);

		//system("pause");
	}
}

//EDIT_CUSTOMER_DETAILS
void modifyc() {
	system("cls");

	char name[40];
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter the Customer name which you want to modify: ");
		scanf(" %[^\n]", name);

		rewind(fptr4);

		while (fread(&cus, sizeof(cus), 1, fptr4) == 1) {
			if (strcmp(cus.cus_name, name) == 0) {
				printf("\nEnter the new Customer Name ( 4 to 6 alphabets): ");
				scanf(" %[^\n]", cus.cus_name);

				printf("\nEnter the Customer's new CNIC(#####-#######-#): ");
				scanf(" %[^\n]", cus.cnic);

				printf("\nEnter the Purchased medicine new Name (must be 7 alphabets): ");
				scanf(" %[^\n]", cus.purmed_name);

				printf("\nEnter the Quantity of new medicines: ");
				scanf("%d", &cus.qua);

				// ---  Year Validation --- //
				do {
					printf("\nEnter the new Year : ");
					scanf("%d", &cus.e_y);

					if (cus.e_y < 2000 ||  cus.e_y > 2022) {
						printf("\n\n --- Invalid Year Entered --- \n");
					}

				} while (cus.e_y < 2000 || cus.e_y > 2022);

				// ---  Month Validation --- //
				do {
					printf("\nEnter the  new Month: ");
					scanf("%d", &cus.e_mon);

					if (cus.e_mon < 1 || cus.e_mon > 12) {
						printf("\n\n --- Invalid Month Entered --- \n");
					}

				} while (cus.e_mon < 1 || cus.e_mon > 12);

				// ---  Date Validation --- //
				do {
					printf("\nEnter the new Date : ");
					scanf("%d", &cus.e_date);

					if (cus.e_date < 1 || cus.e_date > 31) {
						printf("\n\n --- Invalid Date Entered --- ");
					}

				} while (cus.e_date < 1 || cus.e_date > 31);

				fseek(fptr4, -size_cus, SEEK_CUR);
				fwrite(&cus, sizeof(cus), 1, fptr4);
			}
		}
		printf("Want to Edit another Medicine Details (y/n): ");
		fflush(stdin);

		scanf("%c", &another);
	}
}

/*________________________________________________________________________________________________________________________________*/

//ADD_PHARMACIST_DETAILS
void addp() {
	system("cls");
	fseek(fptr5, 0, SEEK_END);

	char add_another = 'y';

	while (add_another == 'y') {
		printf("\nEnter the Pharmacist name (4 to 6 alphabets): ");
		scanf("%s", p.p_name);

		printf("\nEnter the Address(City Name): ");
		scanf(" %[^\n]", p.p_city);

		printf("\nEnter the timing (only hours with am/pm): ");
		scanf(" %[^\n]", p.p_tim);

		printf("\nEnter the Pharmacist Phone no.(03##-#######): ");
		scanf(" %[^\n]", p.p_ph);

		fwrite(&p, sizeof(p), 1, fptr5);

		printf("\n\nWant to add another Pharmacist Details (y/n): ");
		fflush(stdin);

		scanf("%c", &add_another);
	}
}

//DELETE_PHARMACIST_DETAILS
void deletep() {
	system("cls");

	char add_another = 'y';
	char name[40];
	while (add_another == 'y') {
		printf("\nEnter the Pharmacist's name you want to delete: ");
		scanf(" %[^\n]", name);

		ftmp5 = fopen("temprary.txt", "wb+"); // temprary file

		rewind(fptr5);
		while (fread(&p, sizeof(p), 1, fptr5) == 1) {
			if (strcmp(p.p_name, name) != 0) {
				fwrite(&p, sizeof(p), 1, ftmp5);
			}

			fclose(fptr5);
			fclose(ftmp5);

			remove("Pharmacist_Details.txt");
			rename("temprary.txt", "Pharmacist_Details.txt");

			fptr5 = fopen("Pharmacist_Details.txt", "rb+");

			printf("\n\nWant to Delete another Pharmacist Details (y/n): ");
			fflush(stdin);

			scanf("%c", &add_another);
		}
	}
}

//EDIT_PHARMACIST_DETAILS
void modifyp() {
	system("cls");

	char name[40];
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter the Pharmacist's name which you want to modify: ");
		scanf(" %[^\n]", name);

		rewind(fptr5);

		while (fread(&p, sizeof(p), 1, fptr5) == 1) {
			if (strcmp(p.p_name, name) == 0) {
				printf("\nEnter the new Pharmacist name (4 to 6 alphabets): ");
				scanf(" %[^\n]", p.p_name);

				printf("\nEnter the new Address(City Name): ");
				scanf(" %[^\n]", p.p_city);

				printf("\nEnter the new timing (only hours with am/pm): ");
				scanf(" %[^\n]", p.p_tim);

				printf("\nEnter the Pharmacist new Phone no.(03##-#######): ");
				scanf(" %[^\n]", p.p_ph);

				fseek(fptr5, -size_p, SEEK_CUR);
				fwrite(&p, sizeof(p), 1, fptr5);
			}
		}
		printf("\nWant to Edit another Pharmacist's Details (y/n): ");
		fflush(stdin);

		scanf("%c", &another);
	}
}

//SEARCH_PHARMACIST_DETAILS
void searchp() {
	system("cls");
	char another = 'y';
	char name[40];

	while (another == 'y') {
		printf("\n\nEnter the Pharmacist's name you want to search: ");
		scanf("%s", name);
		rewind(fptr5);

		while (fread(&p, sizeof(p), 1, fptr5) == 1) {
			int temp2 = 0;
			if (strcmp(p.p_name, name) == 0) {
				printf("\n=======================================================================================\n");
				printf("Pharmacist Name\t\tAddress\t\tTiming of Pharmacist\t\tPhone Number");
				printf("\n---------------------------------------------------------------------------------------\n");
				printf("%s\t\t\t%s\t\t\t%s\t\t\t%s", p.p_name, p.p_city, p.p_tim, p.p_ph);
				printf("\n---------------------------------------------------------------------------------------");
				printf("\n\t");
				temp2+=1;
				break;
			}

			if(!temp2) {
				printf("\n.....The Details of this Pharmacist is not exists.....\n");
				break;
			}
		}

		printf("\nWant to Search another Pharmacist Details (y/n): ");
		fflush(stdin);

		scanf("%c", &another);
		//system("pause");
	}
}
/*________________________________________________________________________________________________________________________________*/

//ADD_ORDER_DETAILS
void addo() {

	system("cls");
	fseek(fptr6, 0, SEEK_END);

	char add_another = 'y';

	while (add_another == 'y') {
		printf("\n\nEnter the Order ID(4 alphabets): ");
		scanf(" %[^\n]", o.o_name);

		printf("\nEnter the Medicine name: ");
		scanf(" %[^\n]", o.o_med);

		printf("\nEnter the Medicine Quantity: ");
		scanf("%d", &o.o_quan);

		printf("\nEnter the order Receive:\n ");

		// ---  Year Validation --- //
		do {
			printf("\nYear : ");
			scanf("%d", &o.o_ry);

			if (o.o_ry < 2000 ||  o.o_ry > 2022) {
				printf("\n\n --- Invalid Year Entered --- \n");
			}

		} while (o.o_ry < 2000 || o.o_ry > 2022);

		// ---  Month Validation --- //
		do {
			printf("\nMonth: ");
			scanf("%d", &o.o_rmon);

			if (o.o_rmon < 1 || o.o_rmon > 12) {
				printf("\n\n --- Invalid Month Entered --- \n");
			}

		} while (o.o_rmon < 1 || o.o_rmon > 12);

		// ---  Date Validation --- //
		do {
			printf("\nDate : ");
			scanf("%d", &o.o_rd);

			if (o.o_rd < 1 || o.o_rd > 31) {
				printf("\n\n --- Invalid Date Entered --- ");
			}

		} while (o.o_rd < 1 || o.o_rd > 31);

		printf("\nEnter the order Given:\n ");

		// ---  Year Validation --- //
		do {
			printf("\nYear : ");
			scanf("%d", &o.o_gy);

			if (o.o_gy < 2000 ||  o.o_gy > 2022) {
				printf("\n\n --- Invalid Year Entered --- \n");
			}

		} while (o.o_gy < 2000 || o.o_gy > 2022);

		// ---  Month Validation --- //
		do {
			printf("\nMonth: ");
			scanf("%d", &o.o_gmon);

			if (o.o_gmon < 1 || o.o_gmon > 12) {
				printf("\n\n --- Invalid Month Entered --- \n");
			}

		} while (o.o_gmon < 1 || o.o_gmon > 12);

		// ---  Date Validation --- //
		do {
			printf("\nDate : ");
			scanf("%d", &o.o_gd);

			if (o.o_gd < 1 || o.o_gd > 31) {
				printf("\n\n --- Invalid Date Entered --- ");
			}

		} while (o.o_gd < 1 || o.o_gd > 31);

		fwrite(&o, sizeof(o), 1, fptr6);

		printf("\nWant to add another Order Details (y/n): ");
		fflush(stdin);

		scanf("%c", &add_another);
	}
}

//DELETE_ORDER_DETAILS
void deleteo() {
	system("cls");
	char name[40];
	char add_another = 'y';

	while (add_another == 'y') {
		printf("Enter the Order ID you want to delete: ");
		scanf("%s", name);

		ftmp6 = fopen("temprary.txt", "wb+"); // temprary file

		rewind(fptr6);
		while (fread(&o, sizeof(o), 1, fptr6) == 1) {
			if (strcmp(o.o_name, name) != 0) {
				fwrite(&o, sizeof(o), 1, ftmp6);
			}

			fclose(fptr6);
			fclose(ftmp6);

			remove("Order_Details.txt");
			rename("temprary.txt", "Order_Details.txt");

			fptr6 = fopen("Order_Details.txt", "rb+");
			printf("Want to Delete another Order Details (y/n): ");
			fflush(stdin);

			scanf("%c", &add_another);
		}
	}
}

//SEARCH_MEDICINE_DETAILS
void searcho() {
	system("cls");
	char another = 'y';
	char name[40];
	int flag = 0;

	while (another == 'y') {
		printf("\n\nEnter the Order ID you want to search: ");
		scanf(" %[^\n]", name);
		rewind(fptr6);

		int temp2=0;
		while (fread(&o, sizeof(o), 1, fptr6) == 1) {
			if (strcmp(o.o_name, name) == 0) {
				printf("\n=========================================================================================\n");
				printf("Order_ID\tMedicine_Name\tQuantity\torder Receive Date\tOrder Given Date");
				printf("\n-----------------------------------------------------------------------------------------\n");
				printf("%s\t\t%s\t\t%d\t\t%d-%d-%d\t\t%d-%d-%d", o.o_name, o.o_med, o.o_quan, o.o_rd, o.o_rmon, o.o_ry, o.o_gd, o.o_gmon, o.o_gy);
				printf("\n-----------------------------------------------------------------------------------------");
				printf("\n\t");
				temp2+=1;
				break;
			}
		}

		if(!temp2) {
			printf("\n.....This Order Details is not Available.....\n");
		}

		printf("\nWant to Search another Order Details (y/n): ");
		fflush(stdin);

		scanf("%c", &another);

		//system("pause");
	}
}

//EDIT_MEDICINE_DETAILS
void modifyo() {
	system("cls");

	char name[40];
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter the Order ID which you want to modify: ");
		scanf(" %[^\n]", name);

		rewind(fptr6);

		while (fread(&o, sizeof(o), 1, fptr6) == 1) {
			if (strcmp(o.o_name, name) == 0) {
				printf("\n\nEnter the new Order ID(4 alphabets): ");
				scanf(" %[^\n]", o.o_name);

				printf("\nEnter the new Medicine name: ");
				scanf(" %[^\n]", o.o_med);

				printf("\nEnter the new Medicine Quantity: ");
				scanf("%d", &o.o_quan);

				printf("\nEnter the  new order Receive: ");

				// ---  Year Validation --- //
				do {
					printf("\nYear : ");
					scanf("%d", &o.o_ry);

					if (o.o_ry < 2000 ||  o.o_ry > 2022) {
						printf("\n\n --- Invalid Year Entered --- \n");
					}

				} while (o.o_ry < 2000 || o.o_ry > 2022);

				// ---  Month Validation --- //
				do {
					printf("\nMonth: ");
					scanf("%d", &o.o_rmon);

					if (o.o_rmon < 1 || o.o_rmon > 12) {
						printf("\n\n --- Invalid Month Entered --- \n");
					}

				} while (o.o_rmon < 1 || o.o_rmon > 12);

				// ---  Date Validation --- //
				do {
					printf("\nDate : ");
					scanf("%d", &o.o_rd);

					if (o.o_rd < 1 || o.o_rd > 31) {
						printf("\n\n --- Invalid Date Entered --- ");
					}

				} while (o.o_rd < 1 || o.o_rd > 31);

				printf("\nEnter the new order Given: ");

				// ---  Year Validation --- //
				do {
					printf("\nYear : ");
					scanf("%d", &o.o_gy);

					if (o.o_gy < 2000 ||  o.o_gy > 2022) {
						printf("\n\n --- Invalid Year Entered --- \n");
					}

				} while (o.o_gy < 2000 || o.o_gy > 2022);

				// ---  Month Validation --- //
				do {
					printf("\nMonth: ");
					scanf("%d", &o.o_gmon);

					if (o.o_gmon < 1 || o.o_gmon > 12) {
						printf("\n\n --- Invalid Month Entered --- \n");
					}

				} while (o.o_gmon < 1 || o.o_gmon > 12);

				// ---  Date Validation --- //
				do {
					printf("\nDate : ");
					scanf("%d", &o.o_gd);

					if (o.o_gd < 1 || o.o_gd > 31) {
						printf("\n\n --- Invalid Date Entered --- ");
					}

				} while (o.o_gd < 1 || o.o_gd > 31);

				fseek(fptr6, -size_o, SEEK_CUR);
				fwrite(&o, sizeof(o), 1, fptr6);
			}
		}
		printf("\nWant to Edit another Order Details (y/n): ");
		fflush(stdin);

		scanf("%c", &another);
	}
}
/*________________________________________________________________________________________________________________________________*/

//MEDICINES USES/E-PRESCRIPTION
void pres() {
	system("cls");

	printf("\n_______________________________________________________________________");
	printf("\n||\t\t\t\t\t\t\t\t      ||");
	printf("\n||  MEDICINE    \t\t\tUSES\t\t\t      ||");
	printf("\n||____________________________________________________________________||");
	printf("\n||\t\t\t\t\t\t\t\t      ||");
	printf("\n||  Panadol    | headaches, toothaches, backaches, cold/flu aches     ||");
	printf("\n||  Brufen     | Analgesic and anti-inflammatory\t\t      ||");
	printf("\n||  Avil       | Allergic Reaction,Pruritis\t\t\t      ||");
	printf("\n||  Ecosprin   | Blot Clot Prevention\t\t\t\t      ||");
	printf("\n||  H Cort     | Allergy, Arthritis, Astama, Skin, Multiple Sclerosis ||");
	printf("\n||  Stemetil   | Nausea, Vomiting, Dizziness, Migraineous Headache    ||");
	printf("\n||  Perinorm   | Nausea, Vomiting\t\t\t\t      ||");
	printf("\n||  Pam        | Organophophorous poisoning\t\t\t      ||");
	printf("\n||  Superpas   | Abdominal Pain\t\t\t\t\t      ||");
	printf("\n||  Lori       | Anxiety, Muscle Spasm, Seizure\t\t\t      ||");
	printf("\n||  Emeset     | Nausea, Vomiting\t\t\t\t      ||");
	printf("\n||  Deriphyllin| Asthma, COPD\t\t\t\t\t      ||");
	printf("\n||  Avomin     | Motion Sickness, Nausea, Vomiting After Surgery      ||\n");
	printf("||____________________________________________________________________||\n\n");
	system("pause");
}
/*________________________________________________________________________________________________________________________________*/

//PHARMACIST's TIMING
void timing() {
	system("cls");

	printf("\n\t               TIMING");
	printf("\n __________________________________________________");
	printf("\n||\t\t\t\t\t          ||");
	printf("\n||\t  PHARMACY | 07:00am - 12:00am            ||");
	printf("\n||________________________________________________||");
	printf("\n||\t\t\t\t\t          ||");
	printf("\n|| MORNING SHIFT PHARMACIST | 07:00am - 05:00pm   ||");
	printf("\n||________________________________________________||");
	printf("\n||\t\t\t\t\t          ||");
	printf("\n|| EVENING SHIFT PHARMACIST | 05:00pm - 12:00am   ||");
	printf("\n||________________________________________________||\n\n\n");

	system("pause");
}
/*________________________________________________________________________________________________________________________________*/

//ADD_STOCK_DETAILS
void stock() {
	system("cls");
	fseek(fptr7, 0, SEEK_END);

	printf("\n\nEnter the Medicine Units Available in Stock: ");
	scanf("%d", &st.st_unit);
	printf("_____________________________________________________\n");
	printf("\nTotal Stock Units: %d\n", st.st_unit);
	printf("_____________________________________________________\n");
	printf("\nPurchased Unit in Stock: %d", cus.qua);
	printf("\nTotal Unit Avaiable in Stock: %d\n\n", st.st_unit - cus.qua);
	printf("_____________________________________________________\n");
	printf("\nUnit Added in Stock: %d\n", m.tua);
	printf("After Added new Stock: %d\n", st.st_unit + m.tua);
	printf("_____________________________________________________\n\n");

	system("pause");
}

/*________________________________________________________________________________________________________________________________*/


